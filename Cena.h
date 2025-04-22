#pragma once

#include <string>
#include <iostream>

using namespace std;

class Cena{

    public:
        Cena();
        Cena(char* nomeArquivo, bool arquivo);
        Cena(char* novaDescricao);

        void setDescricao(char* novaDescricao);
        void setOpcoes(char* opcoes[]);
        void setOpcao(int index, char* novaOpcao);

        char* getDescricao();
        char* getOpcao(int index);
        char* getProximaCena(int index);

        void imprimeDescricao();
        void imprimeOpcoes();
        virtual void imprimeCena(){}

        Cena lerArquivo(char* nomeArquivo);

        void lerDescricao(char* nomeArquivo);
        void lerOpcoes(char* nomeArquivo);

        void separarOpcoes(char* entradas[3]);
        char* converteStringParaChar(string texto);

    protected:
        void copiarCena(Cena& outra);
        char* removeChar(char* texto, char* divisor);

    private:
        char* descricao;
        char* opcoes[3];
        char* proximaCena[3];

};
