#pragma once

#include <vector>
#include <set>
#include <cassert>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializado anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do arranjo.
    int fim_;  // Último índice válido do arranjo.
    std::vector<Tipo> elementos_;  // Elementos do arranjo.
    std::set<int> indices_;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
  assert(fim >= inicio);
  elementos_.resize(fim - inicio + 1);
  indices_ = {};
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
  assert(i >= inicio_ && i <= fim_);
  int j = i - inicio_;
  elementos_[j] = valor;
  indices_.insert(j);
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const {
  assert(i >= inicio_ && i <= fim_);
  int j = i - inicio_;
  assert(indices_.find(j) != indices_.end());
  return elementos_[j];
}