#include "fila_de_prioridade.h"

struct No {
    string _nome;
    int _idade;

    No(string nome, int idade) {
        this->_nome = nome;
        this->_idade = idade;
    }

    // No(string nome, int idade) : _nome(nome), _idade(idade) { }

    No *proximo_;
};

// Constrói uma fila vazia.
FilaDePrioridade::FilaDePrioridade() {
    this->primeiro_ = nullptr;
    this->tamanho_ = 0;
};

// Retorna o elemento de maior prioridade.
// PRECONDIÇÃO: a fila tem pelo menos um elemento.
string FilaDePrioridade::primeiro() const {
    return this->primeiro_->_nome;
};

// Retorna o número de elementos na fila.
int FilaDePrioridade::tamanho() const {
    return this->tamanho_;
};

// Testa se a fila está vazia.
bool FilaDePrioridade::vazia() const {
    
    if (this->tamanho_ == 0) {
        return true;
    }
    return false;

};

// Remove o elemento de maior prioridade.
// PRECONDIÇÃO: a fila tem pelo menos um elemento.
void FilaDePrioridade::RemoverPrimeiro() {

    No *proximo = this->primeiro_->proximo_;

    delete this->primeiro_;

    this->primeiro_ = proximo;
    this->tamanho_--;

};

// Insere um elemento s fila com prioridade p;
// OBS: Pode haver repetição de elementos.
// Neste caso, os elementos podem ter prioridades iguais ou diferentes. 
No* insere(No *n, int idade, string nome) {

    if (idade > n->_idade) {
        No *novo = new No(nome, idade);
        novo->proximo_ = n;
        return novo;
    } else if (n->proximo_ == nullptr) {
        No *novo = new No(nome, idade);
        n->proximo_ = novo;
        return n;
    } else {
        No *primeiro = n;
        No *novo = insere(n->proximo_, idade, nome);
        primeiro->proximo_ = novo;
        return primeiro;
    }

};

void FilaDePrioridade::Inserir(int p, string s) {

    if (this->primeiro_ == nullptr) {
        this->primeiro_ = new No(s, p);
    } else {
        this->primeiro_ = insere(this->primeiro_, p, s);
    }

    this->tamanho_++;

};

// Remove todos os elementos da fila.
void FilaDePrioridade::Limpar() {

    while (!this->vazia()) {
        this->RemoverPrimeiro();
    }

};