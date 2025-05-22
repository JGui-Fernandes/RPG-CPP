#pragma once

#include <string>
#include <iostream>
#include "Util.h"

using namespace std;

class Cena{

    public:
        Cena();
        Cena(char* nomeArquivo, bool arquivo);
        Cena(char* novaDescricao);

        virtual ~Cena(){}

        void setDescricao(char* novaDescricao);
        void setOpcoes(char* opcoes[]);
        void setOpcao(int index, char* novaOpcao);
        void setQtdeOpcoes(int novaQtdeOpcoes);

        char* getDescricao();
        char* getOpcao(int index);
        char* getProximaCena(int index);
        int getQtdeOpcoes();

        void imprimeDescricao();
        void imprimeOpcoes();
        void imprimeCena();

        Cena lerArquivo(char* nomeArquivo);

        void lerDescricao(char* nomeArquivo);
        void lerOpcoes(char* nomeArquivo);

        void separarOpcoes(char* entradas[3]);

    protected:
        void copiarCena(Cena& outra);
        Util util;

    private:
        char* descricao;
        char* opcoes[3];
        char* proximaCena[3];
        int qtdeOpcoes;

};
