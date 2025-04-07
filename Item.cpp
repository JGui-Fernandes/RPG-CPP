#include "Item.h"

Item::Item(){

}

Item::Item(char* novoNome, TipoItem novoTipo, bool novoCombate, int novoFa, int novoDano){
    nome = novoNome;
    tipo = novoTipo;
    combate = novoCombate;
    fa = novoFa;
    dano = novoDano;
}

bool Item::getCombate(){
    return combate;
}

int Item::getDano(){
   return dano;
}

char* Item::getNome(){
    return nome;
}

TipoItem Item::getTipo(){
    return tipo;
}

int Item::getFA(){
    return fa;
}

void Item::setCombate(bool novoCombate){
    combate = novoCombate;
}

void Item::setDano(int novoDano){
    dano = novoDano;
}

void Item::setFA(int novoFa){
    fa = novoFa;
}

void Item::setNome(char* novoNome){
    nome = novoNome;
}

void Item::setTipo(TipoItem novoTipo){
    tipo = novoTipo;
}

void Item::escreveTipo(){
    if(tipo == 0){
        cout << "Item Comum";
    }
    if(tipo == 1){
        cout << "Armadura";
    }
    if(tipo == 2){
        cout << "Arma";
    }
}
