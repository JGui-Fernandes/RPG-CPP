#pragma once

#include <string>
#include <iostream>

#include "Cena.h"
#include "Personagem.h"
#include "Util.h"

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

        void lerArquivo();

        char converteTipo(int antigo);

    private:
        Personagem* personagem;
        char* cenas[20];
        int qtdeCenas;
        char* arquivo;
        Util util;
};
