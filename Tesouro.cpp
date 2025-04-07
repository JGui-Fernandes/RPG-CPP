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
    this->descricao = novaDescricao;
}

void Tesouro::setValor(int novoValor){
    this->valor = novoValor;
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
