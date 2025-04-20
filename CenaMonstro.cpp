#include "CenaMonstro.h"

CenaMonstro::CenaMonstro(){

}

CenaMonstro::CenaMonstro(char* novaDescricao, Monstro novoMonstro):Cena(novaDescricao){
    monstro = novoMonstro;
}

void CenaMonstro::setMonstro(Monstro novoMonstro){
    monstro = novoMonstro;
}

Monstro CenaMonstro::getMonstro(){
    return monstro;
}

void CenaMonstro::imprimeCena(){
    imprimeDescricao();

    cout << "\n" << endl;

    monstro.imprimeInfo();

    cout << "\n" << endl;

    imprimeOpcoes();
}
