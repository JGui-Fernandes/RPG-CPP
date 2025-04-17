#include "Monstro.h"

Monstro::Monstro(){

}

Monstro::Monstro(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte, int novaVitoria, int novaDerrota):Personagem(novoNome, novaHabilidade, novaEnergia, novaSorte){
    vitoria = novaVitoria;
    derrota = novaDerrota;
}

void Monstro::setDerrota(int novaDerrota){
    derrota = novaDerrota;
}

void Monstro::setVitoria(int novaVitoria){
    vitoria = novaVitoria;
}

int Monstro::getDerrota(){
    return derrota;
}

int Monstro::getVitoria(){
    return vitoria;
}
