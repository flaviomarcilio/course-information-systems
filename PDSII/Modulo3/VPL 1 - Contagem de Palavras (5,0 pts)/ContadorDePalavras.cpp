#include "ContadorDePalavras.hpp"

// Inicializa o contador com uma lista vazia de palavras.
ContadorDePalavras::ContadorDePalavras() {
    
}

// Adiciona uma *ocorrência* da palavra armazenada em s.
void ContadorDePalavras::Adicionar(string s) {

    for (auto it = _lista_de_palavras.begin(); it != _lista_de_palavras.end(); ++it) {
        if (it->palavra() == s) {
            it->Incrementar();
            return;
        }
        if (it->palavra() > s) {
            Palavra p(s);
            _lista_de_palavras.insert(it, p);
            return;
        }
    }
    Palavra p(s);
    _lista_de_palavras.push_back(p);
    
    // Palavra p = Palavra(s);
    // if (this->_lista_de_palavras.empty()) {
    //     this->_lista_de_palavras.push_back(p);
    //     return;
    // } else {
    //     // Testar
    //     // for (Palavra& p : _lista_de_palavras) {
    //     //     if (p.palavra() == s) {
    //     //         p.Incrementar();
    //     //         return;
    //     //     }
    //     // }

    //     list<Palavra>::iterator it;
    //     for (it = this->_lista_de_palavras.begin(); it != this->_lista_de_palavras.end(); ++it) {
    //         if ((*it).palavra().compare(p.palavra()) == 0) {
    //             (*it).Incrementar();
    //             return;
    //         }
    //     }
            
    //     this->_lista_de_palavras.push_back(p);
    //     this->_lista_de_palavras.sort();
    // }
}

// Imprime as palavras ordenadas lexicograficamente,
// seguidas do número de ocorrências registradas.
void ContadorDePalavras::ImprimirOrdenado() {

    // Implementação com as palavras já ordenadas em _lista_de_palavras
    for (Palavra p : _lista_de_palavras) {
        cout << p.palavra() << " " << p.ocorrencias() << endl;
    }

    // list<Palavra>::iterator it;
    // for (it = this->_lista_de_palavras.begin(); it != this->_lista_de_palavras.end(); ++it) {
    //     cout << (*it).palavra() << " " << (*it).ocorrencias() << endl;
    // }
}