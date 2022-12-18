// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bst.hpp"

int main() {
  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    int matricula;
    string nome;

    BST *alunos = new BST();
    Aluno *aluno = new Aluno();

    while (cin >> matricula >> nome) {
        aluno->set_matricula(matricula);
        aluno->set_nome(nome);
        alunos->inserir_aluno(*aluno);
    }

    delete aluno;

    alunos->imprimir_arvore();
    
    delete alunos;
    
    return 0;
}