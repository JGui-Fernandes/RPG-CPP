#pragma once

#include <string>
#include <iostream>

#include "TipoItem.h"

using namespace std;

class Item{

    public:
        Item();
        Item(char* novoNome, TipoItem novoTipo, bool novoCombate, int novoFa, int novoDano);

        void setNome(char*);
        void setTipo(TipoItem);
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

    private:

        char* nome;
        TipoItem tipo;
        bool combate;
        int fa;
        int dano;
};
