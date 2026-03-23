#ifndef FILA_HPP
#define FILA_HPP
#include <string>


class Pessoa 
{
private:
std::string nome;
int idade;
public:
void setPessoa(std::string n, int i);
std::string getNome();
int getIdade();
};

Pessoa* criarPessoa();

void interacaoUsuario();
void executar();
#endif