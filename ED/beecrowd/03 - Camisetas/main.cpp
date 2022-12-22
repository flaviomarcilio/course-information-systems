#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Camiseta
{
    private:
        string nome_;
        string cor_;
        char tam_;
        
    public:
        Camiseta();
        Camiseta(string nome, string cor, char tam);
        string to_string();
        friend bool operator< (Camiseta a, Camiseta b);
};

Camiseta::Camiseta()
{
    nome_ = "";
    cor_ = "";
    tam_ = ' ';
}

Camiseta::Camiseta(string nome, string cor, char tam)
{
    nome_ = nome;
    cor_ = cor;
    tam_ = tam;
}

string Camiseta::to_string()
{
    return cor_ + " " + tam_ + " " + nome_;
}

bool operator< (Camiseta a, Camiseta b)
{
    if (a.cor_.compare(b.cor_) == 0)
        if (a.tam_ == b.tam_)
            if (a.nome_.compare(b.nome_) < 0)
                return true;
            else
                return false;
        else
            return a.tam_ > b.tam_;
    else
        if (a.cor_.compare(b.cor_) < 0)
            return true;
        else
            return false;
}

int main(int argc, char const *argv[])
{
    int n;
    string nome, cor, aux, aux2;
    char tam;
    stringstream ss;
    vector<Camiseta> camisetas;

    getline(cin, aux);
    n = stoi(aux);
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            getline(cin, nome);
            getline(cin, aux2);
            ss << aux2;
            ss >> cor >> tam;
            Camiseta camiseta(nome, cor, tam);
            camisetas.push_back(camiseta);
        }
        sort(camisetas.begin(), camisetas.end());
        for (int i = 0; i < n; i++)
        {
            cout << camisetas[i].to_string() << endl;
        }
        camisetas.erase(camisetas.begin(), camisetas.end());
        getline(cin, aux);
        n = stoi(aux);
        if (n != 0)
            cout << endl;
    }
    
    return 0;
}
