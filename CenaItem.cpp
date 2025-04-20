#include "CenaItem.h"

CenaItem::CenaItem(){

}

CenaItem::CenaItem(char* novaDescricao, Item novoItem): Cena(novaDescricao){
    item = novoItem;
}

void CenaItem::setItem(Item novoItem){
    item = novoItem;
}

Item CenaItem::getItem(){
    return item;
}

void CenaItem::imprimeCena(){
    Cena::imprimeCena();

    cout << "\n" << endl;

    item.imprimeDetalhe();

    cout << "\n" << endl;

    Cena::imprimeOpcoes();
}
