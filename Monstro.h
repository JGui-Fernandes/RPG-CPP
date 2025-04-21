#include <string>
#include <iostream>

#include "Personagem.h"

using namespace std;

class Monstro: public Personagem{
    public:
        Monstro();
        Monstro(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte, char* novaVitoria, char* novaDerrota);

        void setVitoria(char* novaVitoria);
        void setDerrota(char* novaDerrota);

        char* getVitoria();
        char* getDerrota();

    private:
        char* vitoria;
        char* derrota;
};
