#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/escalonador.h"
#include "../include/url.h"
#include "../include/memlog.h"

using std::string;
using std::cout;
using std::endl;

memlog_tipo ml;

int main(int argc, char const *argv[])
{
    string line, comando;
    string arqIn, arqOut, regem = "", estrategia = "";
    string urlString, host;
    string saidaExt = "-out.txt";
    string opcaoLocalidade = "-l";
    string opcaoEstrategia = "-b";

    const char *linhaComando[4];

    char des[] = "desempenho.out";
    char locref[] = "localidade-ref.out";


    int quantidade;   
    
    Escalonador escalonador;

    for (int i = 0; i < argc-1; i++)
    {
        linhaComando[i] = argv[i+1];
    }
    
    arqIn = linhaComando[0];
    for (int i = 1; i < argc-1; i++)
    {
        if (opcaoLocalidade.compare(linhaComando[i]) == 0)
            regem = linhaComando[i];
        else if (opcaoEstrategia.compare(linhaComando[i]) == 0)
            estrategia = "breadth";
    }

    if (regem.compare("-l") != 0)
    {
        iniciaMemLog(des);
        desativaMemLog();
    }
    else
    {
        iniciaMemLog(locref);
        ativaMemLog();
    }

    arqOut = arqIn.substr(0, arqIn.length()-4).append(saidaExt);
    escalonador.setOutput(arqOut);

    std::ifstream entrada(arqIn);

    if (entrada.is_open())
    {
        while (getline(entrada, line))
        {
            std::stringstream ss;
            ss << line;
            ss >> comando;

            if (comando.compare("ADD_URLS") == 0)
            {
                ss >> quantidade;

                defineFaseMemLog(0);

                for (int i = 0; i < quantidade; i++)
                {
                    getline(entrada, urlString);
                    Url url = Url(urlString);

                    bool val = url.isValid();
                    if (val)
                    {
                        escalonador.AddUrl(url);
                    }
                }
                comando = "";
                quantidade = 0;
            }
            else if (comando.compare("ESCALONA_TUDO") == 0)
            {
                defineFaseMemLog(1);

                if (estrategia.compare("breadth") == 0)
                    escalonador.EscalonaTudoBreadth();
                else
                    escalonador.EscalonaTudo();
            }
            else if (comando.compare("ESCALONA") == 0)
            {
                ss >> quantidade;

                defineFaseMemLog(2);

                if (estrategia.compare("breadth") == 0)
                    escalonador.EscalonaBreadth(quantidade);
                else
                    escalonador.Escalona(quantidade);

                comando = "";
                quantidade = 0;
            }
            else if (comando.compare("ESCALONA_HOST") == 0)
            {
                ss >> host;
                ss >> quantidade;

                defineFaseMemLog(3);

                escalonador.EscalonaHost(host, quantidade);

                host = "";
                quantidade = 0;
            }
            else if (comando.compare("VER_HOST") == 0)
            {
                ss >> host;

                defineFaseMemLog(4);

                escalonador.VerHost(host);

                host = "";
            }
            else if (comando.compare("LISTA_HOSTS") == 0)
            {
                defineFaseMemLog(5);

                escalonador.ListaHosts();

                comando = "";
            }
            else if (comando.compare("LIMPA_HOST") == 0)
            {
                ss >> host;

                defineFaseMemLog(6);

                escalonador.LimpaHost(host);
            }
            else if (comando.compare("LIMPA_TUDO") == 0)
            {             
                defineFaseMemLog(7);
                   
                escalonador.LimpaTudo();
            }
            
        }
        entrada.close();
    }
    else cout << "Não foi possível abrir o arquivo" << endl;

    return finalizaMemLog();
}

