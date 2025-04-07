#include "Tesouro.h"

Tesouro::Tesouro(){

}

Tesouro::Tesouro(char* novoNome, char* novaDescricao, int novoValor){
    nome = novoNome;
    descricao = novaDescricao;
    valor = novoValor;
}

Tesouro::setNome(char* novoNome){
    nome = novoNome;
}

Tesouro::setDescricao(char* novaDescricao){
    this->descricao = novaDescricao;
}

Tesouro::setValor(int novoValor){
    this->valor = novoValor;
}
