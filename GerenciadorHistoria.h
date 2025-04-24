#include <string>
#include <iostream>

#include "Personagem.h"
#include "Monstro.h"
#include "Cena.h"
#include "CenaItem.h"
#include "CenaMonstro.h"

using namespace std;

class GerenciadorHistoria{

    public:
        GerenciadorHistoria();
        void iniciador();
        void iniciarJogo();
        void carregarJogo();

        void abrirCena(char* arquivo);
        char* lerRespostaERetornaCena(Cena* cena);
        char* lerRespostaERetornaCenaMonstro(CenaMonstro* ce);
        char* lerRespostaERetornaCenaItem(CenaItem* ce);

        void encerrador();

        int sortearValor();

        void batalha(Personagem* p, Monstro* m);

        int getDanoReduzido(Item* armaduras[10], int qtde);

        Item* escolherAcaoBatalha(Personagem* p, Item* armas[10], Item* armaduras[10], int* qtdeArmas, int *qtdeArmaduras);

        void separaArmas(Item* armas[10], Personagem* p, int* qtde);
        void separaArmaduras(Item* armas[10], Personagem* p, int* qtde);

        void imprimeAtaque(Item* armas[10], int qtde);

        void atacar(Item* arma, int faDefesa, Personagem* ataque, Personagem* defesa);
        void sofrerAtaque(int faDefesa, Personagem* ataque, Personagem* defesa, Item* armaduras[10], int qtdeArmadura);

        void pegarObjeto(Item* item);

        int abrirInventario();

    private:
        Personagem p;
        Cena* c;
        CenaMonstro* cm;
        CenaItem* ci;
        Monstro m;
};
