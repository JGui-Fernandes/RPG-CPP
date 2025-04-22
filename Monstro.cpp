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

void Monstro::copiaMonstro(Monstro& outro){
    setNome(outro.getNome());
    setHabilidade(outro.getHabilidade());
    setEnergia(outro.getEnergia());
    setSorte(outro.getSorte());
    setQtdeItens(outro.getQtdeItens());
    setProvisoes(outro.getProvisao());
    setTesouro(outro.getTesouro());
    vitoria = outro.getVitoria();
    derrota = outro.getDerrota();
}
