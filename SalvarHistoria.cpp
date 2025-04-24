#include "SalvarHistoria.h"
#include <fstream>
#include "string.h"

SalvarHistoria::SalvarHistoria(){
    arquivo = "salvamento.txt";
    qtdeCenas = 0;
}

SalvarHistoria::SalvarHistoria(Personagem* novoPersonagem){
    personagem = novoPersonagem;
    qtdeCenas = 0;
    arquivo = "salvamento.txt";
}

void SalvarHistoria::setPersonagem(Personagem* novoPersonagem){
    personagem = novoPersonagem;
}

void SalvarHistoria::setQtdeCenas(int qtde){
    qtdeCenas = qtde;
}

Personagem* SalvarHistoria::getPersonagem(){
    return personagem;
}

char* SalvarHistoria::getCena(int index){
    return cenas[index];
}

int SalvarHistoria::getQtdeCenas(){
    return qtdeCenas;
}

char* SalvarHistoria::getArquivo(){
    return arquivo;
}

void SalvarHistoria::escreverSalvamento(){
    ofstream arq(arquivo);

    arq << "P: " << personagem->getNome() << ";"
    << personagem->getHabilidade()<< ";"
    << personagem->getEnergia() << ";"
    << personagem->getSorte() << ";"
    << personagem->getProvisao() << ";"
    << personagem->getQtdeItens() << ";"
    << personagem->getTesouro() << endl;

    cout << "QUANTIDADE: " << personagem->getQtdeItens() << endl;

    for(int i = 0; i < personagem->getQtdeItens(); i++){
        Item* it = personagem->getItem(i);
        arq << "I: " << it->getNome() << ";"
        << it->getTipo() << ";"
        << it->getCombate() << ";"
        << it->getFA() << ";"
        << it->getDano() << endl;
    }

    for(int i = 0; i < qtdeCenas; i++){
        arq << cenas[i] << endl;
    }
}

void SalvarHistoria::adicionaCena(char* nomeCena){
    for(int i = 0; i < qtdeCenas; i++){
        if(strcmp(cenas[i], nomeCena) == 0){
            return;
        }
    }
    cenas[qtdeCenas] = nomeCena;
    qtdeCenas++;
}

