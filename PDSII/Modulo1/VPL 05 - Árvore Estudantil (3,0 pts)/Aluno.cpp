#include "Aluno.hpp"

Aluno::Aluno() {}

Aluno::Aluno(int matricula, string nome) {
    this->matricula = matricula;
    this->nome = nome;
}

void Aluno::set_matricula(int matricula) {
    this->matricula = matricula;
}

int Aluno::get_matricula() {
    return this->matricula;
}

void Aluno::set_nome(string nome) {
    this->nome = nome;
}

string Aluno::get_nome() {
    return this->nome;
}

void Aluno::imprimir_dados() {
    cout << this->matricula << " " << this->nome << endl;
}