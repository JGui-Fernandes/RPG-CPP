#include "Cena.h"
#include <cstring>

Cena::Cena(){
    descricao = nullptr;
    for(int i = 0; i < 5; i++){
        opcoes[i] = nullptr;
    }
}

Cena::Cena(char* novaDescricao){
    descricao = novaDescricao;
    strcpy(descricao, novaDescricao);
    for(int i = 0; i < 5; i++){
        opcoes[i] = nullptr;
    }
}

void Cena::setDescricao(char* novaDescricao){
    descricao = novaDescricao;
}

void Cena::setOpcoes(char* novasOpcoes[]){
    for(int i = 0; i < 5; i++){
        opcoes[i] = novasOpcoes[i];
    }
}

char* Cena::getDescricao(){
    return descricao;
}

void Cena::imprimeDescricao(){
    cout << descricao << "\n" << endl;
}

void Cena::imprimeOpcoes(){
    for(int i = 0; i < 5; i++){
        if(strcmp(opcoes[i], "") == 0 || strcmp(opcoes[i], " ") == 0){
            break;
        }
        cout << i+1 << ") " << opcoes[i] << endl;
    }
}
