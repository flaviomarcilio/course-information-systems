#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

class AddressInfo
{
    private:
        int offset_;
        int index_;
        string tag_;
    public:
        AddressInfo(int address, bool cache)
        {
            bitset<32> binary(address);

            //bitset<2> offset;
            // for (int i = 0; i < 2; i++)
            // {
            //     offset[i] = binary[i];
            // }
            bitset<4> offset;
            for (int i = 0; i < 4; i++)
            {
                offset[i] = binary[i];
            }

            if (cache)
            {
                bitset<6> index;
                // for (int i = 2; i < 8; i++)
                // {
                //     index[i-2] = binary[i];
                // }
                for (int i = 4; i < 10; i++)
                {
                    index[i-4] = binary[i];
                }
                index_ = index.to_ulong();

                // bitset<24> tag;
                // for (int i = 8; i < 32; i++)
                // {
                //     tag[i-8] = binary[i];
                // }
                bitset<22> tag;
                for (int i = 10; i < 32; i++)
                {
                    tag[i-10] = binary[i];
                }
                tag_ = tag.to_string();
            }
            else
            {
                bitset<8> index;
                for (int i = 2; i < 10; i++)
                {
                    index[i-2] = binary[i];
                }
                index_ = index.to_ulong();

                bitset<22> tag;
                for (int i = 10; i < 32; i++)
                {
                    tag[i-10] = binary[i];
                }
                tag_ = tag.to_string();
            }

            offset_ = offset.to_ulong();
            
        }
        int offset() { return offset_; };
        int index() { return index_; };
        string tag() { return tag_; };
};

class Block
{
    private:
        bool valid_;
        bool dirty_;
        string tag_;
    public:
        Block()
        {
            valid_ = false;
            dirty_ = false;
            tag_ = "";
        };
        void write(int offset, string tag)
        {
            valid_ = true;
            tag_ = tag;
        }
        bool is_valid() { return valid_; };
        bool is_dirty() { return dirty_; };
        void dirty() { dirty_ = true; };
        string tag() { return tag_; };
};

class Cache
{
    private:        
        vector<Block> cache;
        // Lê da Memória e grava na Cache
        void readMemory(int address)
        {
            AddressInfo addressInfo = AddressInfo(address, true); // Faz o mapeamento para cache
            Block block = cache[addressInfo.index()];

            // Verifica se o bloco na Cache é válido e está sujo, se sim escreve na Memória (Write-Back)
            if (block.is_valid() && block.is_dirty())
            {
                writeMemory(address, block);
            }

            // Substitui na Cache
            block.write(addressInfo.offset(), addressInfo.tag());
            cache[addressInfo.index()] = block;
        };
        void writeMemory(int address, Block block) {};
        
        int hit_;
        int miss_;
        int reads_;
        int writes_;
        int requests_;

    public:
        Cache(int size = 64)
        {
            cache.assign(size, Block());
            hit_ = 0;
            miss_ = 0;
            reads_ = 0;
            writes_ = 0;
            requests_ = 0;
        };
        ~Cache() {};
        char read(int address)
        {
            reads_ += 1;
            AddressInfo addressInfo = AddressInfo(address, true);

            // Verifica se o Bloco está na Cache e se o Dado está no Bloco
            if (cache[addressInfo.index()].is_valid() && cache[addressInfo.index()].tag().compare(addressInfo.tag()) == 0)
            {
                hit_ += 1;
                requests_ += 1;
                return 'H';
            }
            miss_ += 1;
            requests_ += 1;
            readMemory(address);
            return 'M';
        };
        char write(int address)
        {
            writes_ += 1;
            AddressInfo addressInfo = AddressInfo(address, true);

            // Verifica se o Bloco está na Cache e se o Dado está no Bloco
            // Caso esteja é escrito e marcado como sujo
            if (cache[addressInfo.index()].is_valid() && cache[addressInfo.index()].tag().compare(addressInfo.tag()) == 0)
            {
                //hit_ += 1;
                requests_ += 1;
                cache[addressInfo.index()].dirty();
                //return 'H'; // Hit de escrita
                return 'W';
            }
            // Caso o Bloco esteja mas o Dado não, o Bloco correspondente ao Dado deve ser lido da Memória e depois escrito e marcado como sujo
            else if (cache[addressInfo.index()].is_valid() && cache[addressInfo.index()].tag().compare(addressInfo.tag()) != 0)
            {
                //miss_ += 1;
                requests_ += 1;
                readMemory(address);
                cache[addressInfo.index()].dirty();
                //return 'M'; // Miss de escrita
                return 'W';
            }
            // Caso o Bloco não esteja na Cache
            //miss_ += 1;
            requests_ += 1;
            readMemory(address);
            cache[addressInfo.index()].dirty();
            //return 'M'; // Miss de escrita
            return 'W';
        };
        int reads() { return reads_; };
        int writes() { return writes_; };
        int hits() { return hit_; };
        int misses() { return miss_; };
        int requests() { return requests_; }
};

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        Cache cache = Cache();
        vector<string> execution;
        char result;
        ifstream arqIn;
        ofstream arqOut;

        int address, operation;
        string data;
        char const *input = argv[i];

        arqIn.open(input);
        char filename[20];
        sprintf((char*)filename, "out%d.txt", i);
        arqOut.open(filename);
    
        while (!arqIn.eof())
        {
            arqIn >> address >> operation;
            if (operation == 0)
            {
                result = cache.read(address);
                string instruction = to_string(address) + " " + to_string(operation) + " " + result;
                execution.push_back(instruction);
            }
            else
            {
                arqIn >> data;
                result = cache.write(address);
                string instruction = to_string(address) + " " + to_string(operation) + " " + data + " " + result;
                execution.push_back(instruction);
            }
        }
        arqIn.close();
        arqOut.precision(3);
        arqOut << "READS: " << cache.reads() << endl;
        arqOut << "WRITES: " << cache.writes() << endl;
        arqOut << "HITS: "  << cache.hits() << endl;
        arqOut << "MISSES: " << cache.misses() << endl;
        arqOut << "HIT RATE: " << fixed << (float)cache.hits()/cache.reads() << endl;
        arqOut << "MISS RATE: " << fixed << (float)cache.misses()/cache.reads() << endl;
        arqOut << endl;

        for (int j = 0; j < execution.size(); j++)
        {
            arqOut << execution[j] << endl;
        }

        arqOut.close();
    }
    return 0;
}
