#pragma once

#include <string>
#include <iostream>

#include "Cena.h"
#include "Personagem.h"

using namespace std;

class SalvarHistoria{

    public:
        SalvarHistoria();
        SalvarHistoria(Personagem* novoPersonagem);

        void setPersonagem(Personagem* novoPersonagem);
        void setQtdeCenas(int qtde);

        Personagem* getPersonagem();
        char* getCena(int index);
        int getQtdeCenas();
        char* getArquivo();

        void escreverSalvamento();

        void adicionaCena(char* nomeCena);

    private:
        Personagem* personagem;
        char* cenas[10];
        int qtdeCenas;
        char* arquivo;
};
