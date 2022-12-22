#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> Caracteres {{'A',0},{'B',1},{'D',3},{'C',2},{'E',4},\
{'F',5},{'G',6},{'H',7},{'I',8},{'J',9},{'K',10},{'L', 11},\
{'M',12},{'N',13},{'O',14},{'P',15},{'Q',16},{'R',17},{'S',18},{'T',19},{'U',20},\
{'V',21},{'W',22},{'X',23},{'Y',24},{'Z',25}};

int Hash(string elemento, int pos)
{
    int aux = 0;

    for (int i = 0; i < elemento.length(); i++)
    {
        aux += Caracteres.find(elemento[i])->second + pos + i;
    }
    return aux;
}

int main(int argc, char const *argv[])
{
    int casos, linhas, hash = 0, i = 0;
    string elemento;

    cin >> casos;
    while (casos > 0)
    {
        cin >> linhas;
        while (linhas > 0)
        {
            cin >> elemento;
            hash += Hash(elemento, i);
            i++;
            // cout << elemento << endl;
            linhas--;
        }
        cout << hash << endl;
        hash = 0;
        i = 0;
        casos--;
    }
    return 0;
}
