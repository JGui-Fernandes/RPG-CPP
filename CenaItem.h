#include <string>
#include <iostream>

#include "Cena.h"
#include "Item.h"

using namespace std;

class CenaItem: public Cena{

    public:
        CenaItem();
        CenaItem(char* nomeArquivo, bool arquivo);
        CenaItem(char* novaDescricao, Item novoItem);

        void setItem(Item item);

        Item getItem();

        void imprimeCena();

        CenaItem lerArquivo(char* nomeArquivo);

        void copiarCenaItem(CenaItem& cm);

    private:
        Item item;
};
