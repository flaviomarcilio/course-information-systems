#include "BST.hpp"

BST::BST() {}

NodeT* createNode(Aluno aluno) {
    NodeT *aux = new NodeT;
    aux->aluno = aluno;
    aux->esq = nullptr;
    aux->dir = nullptr;

    return aux;
}

void insereAlunoAux(NodeT *n, Aluno aluno) {
    int aluno_matricula = aluno.get_matricula();
    int root_matricula = n->aluno.get_matricula();

    if (aluno_matricula < root_matricula) {
        if (n->esq == nullptr) {
            n->esq = createNode(aluno);
        } else {
            insereAlunoAux(n->esq, aluno);
        }
    } else if (aluno_matricula > root_matricula) {
        if (n->dir == nullptr) {
            n->dir = createNode(aluno);
        } else {
            insereAlunoAux(n->dir, aluno);
        }
    }
}

void BST::inserir_aluno(Aluno aluno) {
    if (root != nullptr) {
        insereAlunoAux(root, aluno);
    } else {
        root = createNode(aluno);
    }
}

void inorder(NodeT *n) {
    if (n == nullptr) {
        return;
    }
    
    inorder(n->esq);
    n->aluno.imprimir_dados();
    inorder(n->dir);
}

void BST::imprimir_arvore() {
    inorder(root);
    cout << endl;
}

Aluno* busca(NodeT *n, int matricula) {
    int root_matricula = n->aluno.get_matricula();
    
    if (matricula == root_matricula) {
        return &(n->aluno);
    } else if (matricula < root_matricula && n->esq != nullptr) {
        busca(n->esq, matricula);
    } else if (matricula > root_matricula && n->dir != nullptr) {
        busca(n->dir, matricula);
    } else {
        return nullptr;
    }
}

Aluno* BST::procurar_aluno(int matricula) {
    return busca(root, matricula);
}