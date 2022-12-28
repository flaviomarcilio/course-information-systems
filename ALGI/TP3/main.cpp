#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

// Utilizado para representar retângulos e mesas
struct rectangle {
    int length, width, area;
};

// Representa as mesas disponíveis
vector<rectangle> tables;

// Representa os retângulos vazios
vector<rectangle> max_rect;

// Utilizado para auxiliar na determinação dos retãngulos
stack<ii> rectangles;

// Utilizado para auxiliar na determinação da quantidade de
// linhas vazias para cada coluna
vector<int> space;

// Utilizada para ordenar em ordem decrescente seguindo as 
// especificações e o critério de desempate
bool compare_table(rectangle a, rectangle b)
{
    if (a.area == b.area) return a.width < b.width;
    return a.area < b.area;
}

// Utilizada para ordenar os retângulos disponíveis em ordem decrescente
// considerando primeiro as dimensões e por último a área
bool compare_space(rectangle a, rectangle b)
{
    if (a.length == b.length)
    {
        if (a.width == b.width)
        {
            return a.area < b.area;
        }
        return a.width < b.width;
    }
    return a.length < b.length;
}

int main(int argc, char const *argv[])
{
    int rows, columns, max_area = 0;
    int number_tables, table_length, table_width;
    int comprimento = 0, largura = 0, comp_max = 0, larg_max = 0;
    char c;
    rectangle rect;
    rectangle table;

    cin >> rows >> columns;

    space.assign(columns, 0);

    // Determinação dos retângulos disponíveis na planta
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> c;
            if (c != '#')
                ++space[j];
            else
                space[j] = 0;
        }
        int length = 0;
        for (int j = 0; j < columns; j++)
        {
            if (space[j] > length)
            {
                // Abertura de um novo retângulo disponível
                rectangles.push(make_pair(j, length));
                length = space[j];
            }
            else if (space[j] < length)
            {
                ii element;
                int area;
                do
                {
                    // Fechamento do retângulo
                    element = rectangles.top();
                    rectangles.pop();
                    largura = length;
                    comprimento = j - element.first;
                    area = largura * comprimento;

                    // Determina a maior dimensão e coloca com sendo length
                    // Objetivo: Facilitar a ordenação e a verificação de compatibilidade
                    // com as mesas
                    if (largura > comprimento)
                    {
                        rect.length = largura;
                        rect.width = comprimento;
                    }
                    else 
                    {
                        rect.length = comprimento;
                        rect.width = largura;
                    }
                    rect.area = area;

                    // Vetor de retângulos disponíveis encontrados
                    max_rect.push_back(rect);

                    // Determinar a maior área disponível para descartar mesas
                    // com áreas maiores
                    if (area > max_area)
                    {
                        max_area = area;
                        comp_max = comprimento;
                        larg_max = largura;
                    }
                    length = element.second;
                } while (space[j] < length);

                length = space[j];

                if (length != 0)
                {
                    rectangles.push(element);
                }
            }
        }
        
    }
    // Ordenando os retângulos
    sort(max_rect.begin(), max_rect.end(), compare_space);
    
    cin >> number_tables;
    for (int i = 0; i < number_tables; i++)
    {
        cin >> table_length >> table_width;
        table.length = table_length;
        table.width = table_width;
        table.area = table_length * table_width;
        tables.push_back(table);
    }
    
    // Ordenando as mesas
    sort(tables.begin(), tables.end(), compare_table);

    // Determinando a maior mesa que pode ser colocada na casa
    do
    {
        table = tables.back();
        if (table.area > max_area)
        {
            tables.pop_back();
            continue;
        }
        else
        {
            rect = max_rect.back();

            // Determinando a maior e a menor dimensão da mesa
            int maior_dimensao, menor_dimensao;
            if (table.width >= table.length)
            {
               maior_dimensao = table.width;
               menor_dimensao = table.length;
            }
            else
            {
                maior_dimensao = table.length;
                menor_dimensao = table.width;
            }

            if (maior_dimensao > rect.length)
            {
                tables.pop_back();
            }
            else if (menor_dimensao > rect.width)
            {
                max_rect.pop_back();
            }
            else
            {
                break;
            }
        }
        
    } while (1);

    cout << table.length << " " << table.width << endl;
    return 0;
}