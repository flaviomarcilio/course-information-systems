#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <sstream>

#define TAM 100

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

vector<int> nos;
int arvore[TAM][TAM];

string pruefer_code() {
    int n = nos.size();
    int d = nos.size();

    string code = "";
    vector<int> degree(n+1, 0);
    // degree.assign(n + 1, 0);
    
    sort(nos.begin(), nos.end(), myfunction);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (arvore[i][j])
                degree[i]++;
        }
    }

    int i = 0;
    while (d > 1)
    {
        if (degree[nos[i]] == 1)
        {
            for (int j = 0; j <= n; j++)
            {
                if (arvore[nos[i]][j])
                {
                    degree[nos[i]] = 0;
                    d--;
                    // code.push_back(j);
                    code += to_string(j);
                    code += " ";
                    arvore[nos[i]][j] = 0;
                    arvore[j][nos[i]] = 0;
                    degree[j]--;
                    i = 0;
                    break;
                }
            }
        }
        else
        {
            i++;
        }
    }
    code[code.length() - 1] = '\0';
    return code;
}

int main(int argc, char const *argv[])
{
    char c;
    int no1, no2, i = 0;
    stack<int> pilha;
    
    stringstream ss;
    string linha;

    cin >> c;
    do
    {
        if (c == '(')
        {
            i++;
            cin >> no1;
            pilha.push(no1);
            nos.push_back(no1);
        }
        else if (c == ')')
        {
            i--;
            no1 = pilha.top();
            pilha.pop();
            if (!pilha.empty())
            {
                no2 = pilha.top();
                arvore[no1][no2] = 1;
                arvore[no2][no1] = 1;
            }
        }
        if (i == 0)
        {
            string prufer = pruefer_code();
            printf("%s", prufer.c_str());
            cout << "\n";
            nos.erase(nos.begin(), nos.end());
            memset(arvore, 0, sizeof(arvore[0][0]) * TAM * TAM);
        }
        cin >> c;
    } while (!cin.eof());
    return 0;
}
