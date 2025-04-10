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

char* Item::getTipoEscrito(){
    if(tipo == 0){
        return "Item Comum";
    }
    if(tipo == 1){
        return "Armadura";
    }
    if(tipo == 2){
        return "Arma";
    }
}

void Item::imprimeResumo(){
    cout << nome << "   |    " << getTipoEscrito() << endl;
}

void Item::imprimeDetalhe(){
    cout << "Nome: " << nome << endl;
    cout << "Tipo: " << getTipoEscrito() << endl;
    if(combate){
        if(tipo == 1){
            cout << "Desvantagem de ataque do inimigo: " << fa << endl;
            cout << "Bonus de defesa: " << dano << endl;
        }
        if(tipo == 2){
            cout << "Forca de ataque: " << fa << endl;
            cout << "Bonus de ataque: " << dano << endl;
        }
    }
}
