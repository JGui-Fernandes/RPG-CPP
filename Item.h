#pragma once

#include <string>
#include <iostream>

#include "TipoItem.h"
#include "Util.h"

using namespace std;

class Item{

    public:
        Item();
        Item(char* novoNome, TipoItem novoTipo, bool novoCombate, int novoFa, int novoDano);

        void setNome(char*);
        void setTipo(TipoItem);
        void setTipo(char*);
        void setCombate(bool);
        void setFA(int);
        void setDano(int);

        char* getNome();
        TipoItem getTipo();
        bool getCombate();
        int getFA();
        int getDano();

        char* getTipoEscrito();

        void imprimeResumo();

        void imprimeDetalhe();

        void constroiItem(string texto);

    private:

        char* nome;
        TipoItem tipo;
        bool combate;
        int fa;
        int dano;
        Util util;
};
