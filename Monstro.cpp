#include "Monstro.h"

Monstro::Monstro(){

}

Monstro::Monstro(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte, char* novaVitoria, char* novaDerrota):Personagem(novoNome, novaHabilidade, novaEnergia, novaSorte){
    vitoria = novaVitoria;
    derrota = novaDerrota;
}

void Monstro::setDerrota(char* novaDerrota){
    derrota = novaDerrota;
}

void Monstro::setVitoria(char* novaVitoria){
    vitoria = novaVitoria;
}

char* Monstro::getDerrota(){
    return derrota;
}

char* Monstro::getVitoria(){
    return vitoria;
}
