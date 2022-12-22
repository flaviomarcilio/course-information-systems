#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct {
    float chave;
    int digito;
} Item;

#define Troca(A, B) {Item c = A; A = B; B = c; }

void Bolha (Item *v, int n)
{
    int i, j, trocou;
    for (i = 0; i < n - 1; i++)
    {
        trocou = 0;
        for ( j = 0; j < n - 1; j++)
        {
            if (v[j].chave < v[j + 1].chave)
            {
                Troca(v[j], v[j + 1]);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

int main(int argc, char const *argv[])
{
    int n, k = 1;
    Item valor;
    Item valores[10];

    while (cin >> n)
    {
        for (int i = 0; i < 10; i++)
        {
            cin >> valor.chave;
            valor.digito = i;
            valores[i] = valor;
        }
        Bolha(valores, 10);
        cout << "Caso " << k << ": ";
        for (int i = 0; i < n; i++)
        {
            cout << valores[i].digito;
        }
        cout << endl;
        k++;
    }
    

    return 0;
}
