#include <iostream>

using namespace std;

bool numeroPresente(int num, int v[], int index)
{
    for (int i = 0; i <= index; i++)
    {
        if (num == v[i]) {
            return true;
        }
    }
    return false;
}

void imprimeVetor(int v[], int index)
{
    for (int k = 0; k < index; k++)
    {
        cout << v[k] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n, i = 0, j = 0;
    int even[20];
    int odd[20];

    while (cin >> n)
    {
        if (n % 2 == 0 && !numeroPresente(n, even, i))
        {
            even[i] = n;
            i++;
        }
        else if (n % 2 != 0 && !numeroPresente(n, odd, j))
        {
            odd[j] = n;
            j++;
        }
        if (cin.get() == '\n')
        {
            break;
        }
    }
    imprimeVetor(even, i);
    imprimeVetor(odd, j);
    return 0;
}