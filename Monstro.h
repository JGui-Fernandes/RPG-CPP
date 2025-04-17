#include <string>
#include <iostream>

#include "Personagem.h"

using namespace std;

class Monstro: public Personagem{
    public:
        Monstro();
        Monstro(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte, int novaVitoria, int novaDerrota);

        void setVitoria(int novaVitoria);
        void setDerrota(int novaDerrota);

        int getVitoria();
        int getDerrota();

    private:
        int vitoria;
        int derrota;
};
