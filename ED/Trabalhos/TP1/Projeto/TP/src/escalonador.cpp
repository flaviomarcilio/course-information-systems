#include "../include/escalonador.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;

Escalonador::Escalonador()
{
    hosts_ = new FilaEncadeada<Host>(0);
    output_ = "saida-out.txt";
}

Escalonador::~Escalonador()
{
    if (!hosts_->empty())
        LimpaTudo();
    delete hosts_;
}

void Escalonador::setOutput(string output)
{
    output_ = output;
}

void Escalonador::AddUrl(Url url)
{
    Host item;
    ListaEncadeada<Url> *urls = nullptr;

    int sizeFila = hosts_->size();
    string host = url.GetHost();
    int urlDepth = url.GetDepth();

    if (sizeFila != 0)
        urls = PesquisaHost(host);

    int idLista = sizeFila + 1;

    if (urls == nullptr)
    {
        item.host = host;
        item.urls = new ListaEncadeada<Url>(idLista);
        item.urls->push_back(url);
        hosts_->push_back(item);
    }
    else
    {
        int tam = urls->size();
        if (tam == 0)
        {
            urls->push_back(url);
        }
        else
        {
            Url a;
            bool deveInserir = true;
            for (int i = 1; i <= tam; i++)
            {
                a = urls->get_item(i);
                if (url == a)
                {
                    deveInserir = false;
                    break;
                }
                else if (urlDepth < a.GetDepth())
                {
                    urls->insert_at(url, i);
                    deveInserir = false;
                    break;
                }
            }
            if (deveInserir)
            {
                urls->push_back(url);
            }
        }   
    }
}

void Escalonador::EscalonaTudo()
{
    Host item;
    Url url;

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    int tam = hosts_->size();

    try
    {
        for (int i = 0; i < tam; i++)
        {
            item = hosts_->pop_front();

            while (!item.urls->empty())
            {
                url = item.urls->pop_front();
                arq << url << endl;
            }
            hosts_->push_back(item);
        }

        arq.close();
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
}

void Escalonador::EscalonaTudoBreadth()
{
    Host item;
    Url url;

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    int tam = hosts_->size();
    int hostsVazios = 0;

    try
    {
        while (1)
        {
            item = hosts_->pop_front();
            if (!item.urls->empty())
            {
                url = item.urls->pop_front();
                arq << url << endl;
            }
            else
            {
                hostsVazios++;
            }
            hosts_->push_back(item);
            if (hostsVazios == tam)
                break;
        }

        arq.close();
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
}

void Escalonador::Escalona(int quantidade)
{
    Url url;
    int tam = hosts_->size();

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    try
    {
        Host item = hosts_->pop_front();
        while (quantidade > 0)
        {
            if (item.urls->empty())
            {
                hosts_->push_back(item);
                tam--;
                item = hosts_->pop_front();
            }
            else {
                url = item.urls->pop_front();
                arq << url << endl;
                quantidade--;
                if (quantidade == 0)
                {
                    hosts_->push_back(item);
                    tam--;
                }
            }
        }
        arq.close();
        for (int i = 0; i < tam; i++)
        {
            item = hosts_->pop_front();
            hosts_->push_back(item);
        }
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
}

void Escalonador::EscalonaBreadth(int quantidade)
{
    Host item;
    Url url;
    int tam = hosts_->size();
    int hostsVazios = 0;

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    try
    {
        while (1)
        {
            item = hosts_->pop_front();
            if (!item.urls->empty())
            {
                url = item.urls->pop_front();
                arq << url << endl;
                quantidade--;
            }
            else
            {
                hostsVazios++;
            }
            hosts_->push_back(item);
            if (quantidade == 0 || hostsVazios == tam)
                break;
        }
        arq.close();
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
}

void Escalonador::EscalonaHost(string host, int quantidade)
{
    ListaEncadeada<Url> *urls = PesquisaHost(host);
    if (urls == nullptr) return;

    Url url;

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    try
    {
        for (int i = 0; i < quantidade; i++)
        {
            url = urls->pop_front();
            arq << url << endl;
            if (urls->empty())
                break;
        }
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
    
    arq.close();
}

void Escalonador::VerHost(string host)
{
    ListaEncadeada<Url> *urls = PesquisaHost(host);
    if (urls == nullptr) return;

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    Url url;

    int tam = urls->size();
    for (int i = 1; i <= tam; i++)
    {
        url = urls->get_item(i);
        arq << url << endl;
    }

    arq.close();
}

void Escalonador::ListaHosts()
{
    if (hosts_->empty()) return;

    Host item;
    int tam = hosts_->size();

    std::ofstream arq;
    arq.open(output_, std::ofstream::out | std::ofstream::app);

    try
    {
        for (int i = 0; i < tam; i++)
        {
            item = hosts_->pop_front();
            arq << item.host << endl;
            hosts_->push_back(item);
        }
        
        arq.close();
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
}

void Escalonador::LimpaHost(string host)
{
    ListaEncadeada<Url> *urls = PesquisaHost(host);
    if (urls == nullptr) return;

    delete urls;
}

void Escalonador::LimpaTudo()
{
    while (hosts_->size() > 0)
    {
        delete hosts_->pop_front().urls;
    }
}

ListaEncadeada<Url> *Escalonador::PesquisaHost(string host)
{
    int tam = hosts_->size();
    Host item;
    ListaEncadeada<Url> *lista = nullptr;

    try
    {
        for (int i = 0; i < tam; i++)
        {
            item = hosts_->pop_front();
            if (item.host == host)
                lista = item.urls;

            hosts_->push_back(item);
        }
    }
    catch(ExcecaoEmpty e)
    {
        cerr << e.msg << endl;
    }
    
    return lista;
}
