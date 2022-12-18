#ifndef BST_H
#define BST_H

#include "Aluno.hpp"

struct NodeT {
    Aluno aluno;
    NodeT *esq;
    NodeT *dir;
};

struct BST {
    NodeT *root = nullptr;

    BST();
    void inserir_aluno(Aluno aluno);
    void imprimir_arvore();
    Aluno* procurar_aluno(int matricula);
};

#endif