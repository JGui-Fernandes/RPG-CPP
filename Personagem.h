#include <string>
#include <iostream>

#include "Item.h"
#include "Tesouro.h"

using namespace std;

class Personagem{

    public:
        Personagem();
        Personagem(bool);
        Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte);

        char* getNome();
        int getHabilidade();
        int getEnergia();
        int getSorte();
        int getQtdeItens();
        int getQtdeTesouros();
        int getQtdeProvisoes();
        Item* getItem(int index);
        Tesouro* getTesouro(int index);
        int getProvisao();

        void setNome(char* novoNome);
        void setHabilidade(int novaHabilidade);
        void setEnergia(int novaEnergia);
        void setSorte(int novaSorte);
        void setQtdeItens(int qtde);
        void setQtdeTesouros(int qtde);
        void setQtdeProvisoes(int qtde);
        void setItens(Item* novosItens[10]);
        void setTesouros(Tesouro* novosTesouros[10]);
        void setProvisoes(int novaProvisao);

        void adicionaItem(Item* novoItem);
        void adicionaTesouro(Tesouro* novoTesouro);

        void descartarItem(Item novoItem);
        void descartarTesouro(Tesouro novoTesouro);

        void imprimeListaItens();
        void imprimeListaTesouros();

        void consumirProvisao();

        void imprimeInfo();

   private:
        char* nome;
        int habilidade;
        int energia;
        int sorte;
        Item* itens[10];
        Tesouro* tesouros[10];
        int provisoes;
        int qtdeItens, qtdeTesouros;

        Personagem constroiHeroi();
};
