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

void Provisao::imprimeResumo(){
    cout << nome << " | " << pv << endl;
}

void Provisao::imprimeDetalhe(){
    cout << "Nome: " << nome << endl;
    cout << "Descricao: " << descricao << endl;
    cout << "PVs recuperados: " << pv << endl;
}
