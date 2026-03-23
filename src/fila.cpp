#include <iostream>
#include "fila.hpp"
#include <queue>

Pessoa* criarPessoa()
{
    Pessoa* p = new Pessoa();
    return p; 
}

void Pessoa::setPessoa(std::string n, int i)
{
    nome = n;
    idade = i;
}

std::string Pessoa::getNome()
{
    return nome;
}

int Pessoa::getIdade()
{
    return idade;
}

void interacaoUsuario()
{
    std::queue<Pessoa*> filadePessoas;
    int choice;
do
{

    std::cout << "\nBem-vindo ao gerenciamento utilizando a Estrutura de Dados Fila(Queue)\n";
    std::cout << "\nPara inserir um usuário na fila, digite 1: " << '\n';
    std::cout << "Para imprimir o usuário que está no começo da fila, digite 2" << '\n';
    std::cout << "Para imprimir o usuário que está no final da fila, digite 3" << "\n";
    std::cout << "Para chamar o usuário que está no início da fila, digite 4" << '\n';
    std::cout << "Para encerrar o programar, digite 5: " << '\n';
    do
    {
        std::cin >> choice;
        if(choice < 0 && choice > 6) std::cout << "Número inválido\n";
    } while (choice < 0 && choice > 6);
    
    switch (choice) {

    case 1: 
    {
       std::cout << "Digite o nome da pessoa para adcionar na fila: ";
       std::string nome;
       std::cin.ignore();
       std::getline(std::cin, nome);
       std::cout << "Digite a idade: ";
       int idade;
       std::cin >> idade;
       Pessoa* p = criarPessoa();
       p->setPessoa(nome, idade);
       filadePessoas.push(p);
        break;
    }
    case 2: 
    {
        if(filadePessoas.empty()) std::cout << "A fila está vazia\n";
        else
        {
            Pessoa* p = filadePessoas.front();
            std::cout << "Nome: " << p->getNome() << "\n";
            std::cout << "Idade: " << p->getIdade() << "\n";
        }
        break;
     }
       
    case 3:
     {
        if(filadePessoas.empty()) std::cout << "A fila está vazia\n";
        else
        {  
           Pessoa* p = filadePessoas.back();
           std::cout << "Nome: " << p->getNome() << "\n";
           std::cout << "Idade: " << p->getIdade() << "\n";
        }
        break;

    }

    case 4: 
    {
        Pessoa* p = filadePessoas.front();
        if(p && !filadePessoas.empty()) {
            std::cout << "Nome da pessoa que está no topo e será removida: " << p->getNome() << '\n';
            std::cout << "Idade: " << p->getIdade() << '\n';
            filadePessoas.pop();
            delete p;
            std::cout << "Memória liberada\n";
        } 
        else
        {
            std::cout << "Erro, fila vazia\n";
        }
        break;
    }

    case 5: 
    {
        while(!filadePessoas.empty())
        {
            Pessoa* p = filadePessoas.front();
            filadePessoas.pop();
            delete p;
        }
        if(filadePessoas.empty()) std::cout << "Fila limpa com sucesso\n";
        std::cout << "\nAté mais...\n";

        break;
    }
        
    default:
    {
        std::cout << "Nenhuma opção escolhida\n";
        break;
    }
    
  }
} while(choice != 5); 

}

