#include "CenaItem.h"
#include <fstream>
#include <string.h>
#include <cstdlib>

CenaItem::CenaItem(){

}

CenaItem::CenaItem(char* nomeArquivo, bool arquivo){
    CenaItem ci = lerArquivo(nomeArquivo);

    copiarCenaItem(ci);

    char* temp[3];
    for (int i = 0; i < 3; i++) {
        temp[i] = ci.getOpcao(i);
    }

    separarOpcoes(temp);
}

CenaItem::CenaItem(char* novaDescricao, Item* novoItem): Cena(novaDescricao){
    item = novoItem;
}

void CenaItem::setItem(Item* novoItem){
    item = novoItem;
}

Item* CenaItem::getItem(){
    return item;
}

void CenaItem::imprimeCena(){
    imprimeDescricao();

    cout << "\n" << endl;

    item->imprimeDetalhe();

    cout << "\n\n" << endl;

   imprimeOpcoes();
}

CenaItem CenaItem::lerArquivo(char* nomeArquivo){
    ifstream entrada(nomeArquivo);
    CenaItem ci;

    if (!entrada.is_open()) {
            cerr << "Erro ao abrir o arquivo!" << endl;
            return CenaItem("", new Item());
    }

    string linha1, linha2;

    getline(entrada, linha1);
    getline(entrada, linha2);

    char* linha1Final;
    linha1Final = converteStringParaChar(linha1);

    ci.setDescricao(linha1Final);

    Item* i = new Item();
    i->constroiItem(linha2);


    ci.setItem(i);

    ci.lerOpcoes(nomeArquivo);

    return ci;
}



void CenaItem::copiarCenaItem(CenaItem& cm){
    copiarCena(cm);

    setItem(cm.getItem());
}
