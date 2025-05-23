#pragma once

#include <string>
#include <iostream>

#include "Item.h"

using namespace std;

class Personagem{

    public:
        Personagem();
        Personagem(bool*);
        Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte);
        Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte, int novaProvisao, int novaQtdeItens, int novoTesouro);

        char* getNome();
        int getHabilidade();
        int getEnergia();
        int getSorte();
        int getTesouro();
        int getQtdeItens();
        int getQtdeProvisoes();
        Item* getItem(int index);
        int getProvisao();

        void setNome(char* novoNome);
        void setHabilidade(int novaHabilidade);
        void setEnergia(int novaEnergia);
        void setSorte(int novaSorte);
        void setQtdeItens(int qtde);
        void setQtdeProvisoes(int qtde);
        void setItens(Item* novosItens[10]);
        void setProvisoes(int novaProvisao);
        void setTesouro(int novoTesouro);

        void adicionaItem(Item* novoItem);

        void descartarItem(int index);

        void imprimeListaItens();

        void consumirProvisao();

        void perderEnergia(int perda);

        void imprimeInfo();

        Personagem constroiHeroi(bool*);
    protected:
        void copiaPersonagem(Personagem& outro);

   private:
        char* nome;
        int habilidade;
        int energia;
        int sorte;
        Item* itens[10];
        int tesouro;
        int provisoes;
        int qtdeItens;

};
