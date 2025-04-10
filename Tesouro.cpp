#include "Tesouro.h"

Tesouro::Tesouro(){

}

Tesouro::Tesouro(char* novoNome, char* novaDescricao, int novoValor){
    nome = novoNome;
    descricao = novaDescricao;
    valor = novoValor;
}

void Tesouro::setNome(char* novoNome){
    nome = novoNome;
}

void Tesouro::setDescricao(char* novaDescricao){
    descricao = novaDescricao;
}

void Tesouro::setValor(int novoValor){
    valor = novoValor;
}

char* Tesouro::getNome(){
    return nome;
}

char* Tesouro::getDescricao(){
    return descricao;
}

int Tesouro::getValor(){
    return valor;
}

void Tesouro::imprimeResumo(){
    cout << nome << " | " << valor << endl;
}

void Tesouro::imprimeDetalhe(){
    cout << "Nome: " << nome << endl;
    cout << "Descricao: " << descricao << endl;
    cout << "Valor: " << valor << endl;
}
