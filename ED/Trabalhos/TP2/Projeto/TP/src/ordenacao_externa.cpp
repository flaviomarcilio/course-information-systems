#include "../include/ordenacao_externa.h"

#define ID_HEAP 30

OrdenacaoExterna::OrdenacaoExterna(string entrada, string saida, int numEntidades)
{
    string url;
    int views, cont = 0, rodada = 1;
    bool statusRead, statusWrite;

    char fita[20];
    Item *itens[numEntidades];

    ifstream arqIn;
    ofstream arqOut;

    // Geração da rodadas - QuickSort
    defineFaseMemLog(0);

    statusRead = readFile(arqIn, entrada);

    if (!statusRead)
    {
        cerr << "Não foi possível abrir o arquivo de entrada." << endl;
        exit(1);
    }
    else
    {
        while (1)
        {
            arqIn >> url >> views;

            if (arqIn.fail() && cont == 0)
            {
                rodada--;
                break;
            }

            if (arqIn.fail())
            {
                sprintf((char*)fita,"rodada-%d.txt",rodada);

                Ordenacao<Item> ordena(itens, cont, quickSort, rodada-1);
                statusWrite = writeFile(arqOut, fita);
                if (statusWrite)
                {
                    for (int i = 0; i < cont; i++)
                    {
                        arqOut << itens[i]->toString() << endl;
                        delete itens[i];
                        
                    }
                }
                arqOut.close();
                break;
            }

            Item *entidade = new Item(url, views, rodada);
            itens[cont] = entidade;
            cont++;

            if (cont == numEntidades)
            {
                sprintf((char*)fita,"rodada-%d.txt",rodada);

                Ordenacao<Item> ordena(itens, cont, quickSort, rodada-1);
                statusWrite = writeFile(arqOut, fita);
                if (statusWrite)
                {
                    for (int i = 0; i < cont; i++)
                    {
                        arqOut << itens[i]->toString() << endl;
                        delete itens[i];
                    }
                }
                arqOut.close();
                rodada++;
                cont = 0;
            }
        }
        
        arqIn.close();
    }

    // Intercalação das fitas - Heap
    defineFaseMemLog(1);
    Intercala(rodada, saida);
}

bool OrdenacaoExterna::writeFile(ofstream& file, string strFile)
{
    file.open(strFile);
    return !(file.fail()||!file.is_open()||!file.good());
}

bool OrdenacaoExterna::readFile(ifstream& ifile, string strFile)
{
    ifile.open(strFile);
    return !(ifile.fail()||!ifile.is_open()||!ifile.good());
}

void OrdenacaoExterna::Intercala(int qtdeFitas, string output)
{
    string str;
    int views, origin;

    Item *itens[qtdeFitas];
    Item *entidade;

    int fitas[qtdeFitas], j = 0;
    char fita[20];

    ifstream arqIn[qtdeFitas];
    ofstream arqOut;
    bool statusRead, statusWrite;

    for (int i = 0; i < qtdeFitas; i++)
    {
        sprintf((char*)fita,"rodada-%d.txt",i+1);
        statusRead = readFile(arqIn[i], fita);
        if (!statusRead)
        {
            cerr << "Não foi possível abrir o arquivo para leitura." << endl;
            exit(1);
        }
        else
        {
            arqIn[i] >> str >> views;
            Item *url = new Item(str, views, i);
            itens[i] = url;
            fitas[i] = 1;
        }
    }
    Heap<Item> heap = Heap<Item>(itens, qtdeFitas, ID_HEAP);
    statusWrite = writeFile(arqOut, output);
    if (!statusWrite)
    {
        cerr << "Não foi possível abrir o arquivo para escrita." << endl;
        exit(1);
    }
    else
    {
        while (!heap.empty())
        {
            // Retira o maior
            entidade = heap.pop();
            // Grava no arquivo final
            arqOut << entidade->toString() << endl;
            origin = entidade->Fita();
            delete entidade;

            // Le outra entidade da fita
            arqIn[origin] >> str >> views;

            if (!arqIn[origin].fail())
            {
                Item *url = new Item(str, views, origin);
                heap.add(url);
            }
            else
            {
                fitas[origin] = 0;
                j = 0;
                while (1)
                {
                    if (fitas[j])
                    {
                        arqIn[j] >> str >> views;
                        if (!arqIn[j].fail())
                        {
                            Item *url = new Item(str, views, j);
                            heap.add(url);
                            break;
                        }
                    }
                    j++;
                    if (j == qtdeFitas)
                        break;
                }
            }
        }
    }
    for (int i = 0; i < qtdeFitas; i++)
    {
        arqIn[i].close();
    }
    arqOut.close();
}