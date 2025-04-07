#include "Provisao.h"

Provisao::Provisao(){

}

Provisao::Provisao(char* novoNome, char* novaDescricao, int novoPv){
    nome = novoNome;
    descricao = novaDescricao;
    pv = novoPv;
}

void Provisao::setDescricao(char* novaDescricao){
    descricao = novaDescricao;
}

void Provisao::setNome(char* novoNome){
    nome = novoNome;
}

void Provisao::setPV(int novoPv){
    pv = novoPv;
}

char* Provisao::getNome(){
    return nome;
}

char* Provisao::getDescricao(){
    return descricao;
}

int Provisao::getPV(){
    return pv;
}
