#include "Personagem.h"

Personagem::Personagem(){

}

Personagem::Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte){
    nome = novoNome;
    habilidade = novaHabilidade;
    energia = novaEnergia;
    sorte = novaSorte;
}

char* Personagem::getNome() {
    return nome;
}

int Personagem::getHabilidade() {
    return habilidade;
}

int Personagem::getEnergia() {
    return energia;
}

int Personagem::getSorte() {
    return sorte;
}

int Personagem::getQtdeItens() {
    return qtdeItens;
}

int Personagem::getQtdeTesouros() {
    return qtdeTesouros;
}

int Personagem::getQtdeProvisoes() {
    return qtdeProvisoes;
}

Item* Personagem::getItem(int index) {
    return itens[index];
}

Tesouro* Personagem::getTesouro(int index) {
    return tesouros[index];
}

Provisao* Personagem::getProvisao(int index) {
    return provisoes[index];
}

void Personagem::setNome(char* novoNome) {
    nome = novoNome;
}

void Personagem::setHabilidade(int novaHabilidade) {
    habilidade = novaHabilidade;
}

void Personagem::setEnergia(int novaEnergia) {
    energia = novaEnergia;
}

void Personagem::setSorte(int novaSorte) {
    sorte = novaSorte;
}

void Personagem::setQtdeItens(int qtde) {
    qtdeItens = qtde;
}

void Personagem::setQtdeTesouros(int qtde) {
    qtdeTesouros = qtde;
}

void Personagem::setQtdeProvisoes(int qtde) {
    qtdeProvisoes = qtde;
}

void Personagem::setItens(Item* novosItens[10]) {
    for (int i = 0; i < 10; i++) {
        itens[i] = novosItens[i];
    }
}

void Personagem::setTesouros(Tesouro* novosTesouros[10]) {
    for (int i = 0; i < 10; i++) {
        tesouros[i] = novosTesouros[i];
    }
}

void Personagem::setProvisoes(Provisao* novasProvisoes[5]) {
    for (int i = 0; i < 5; i++) {
        provisoes[i] = novasProvisoes[i];
    }
}

void Personagem::adicionaItem(Item* novoItem){
    if(qtdeItens < 10){
        itens[qtdeItens] = novoItem;
        qtdeItens++;
    }
}

void Personagem::adicionaTesouro(Tesouro* novoTesouro){
    if(qtdeTesouros < 10){
        tesouros[qtdeTesouros] = novoTesouro;
        qtdeTesouros++;
    }
}

void Personagem::adicionaProvisao(Provisao* novaProvisao){
    if(qtdeProvisoes < 5){
        provisoes[qtdeProvisoes] = novaProvisao;
        qtdeProvisoes++;
    }
}

void Personagem::imprimeListaItens(){
    if(qtdeItens == 0){
        cout << "Nenhum item registrado no iventario." << endl;
    } else{
        cout << "\n Seus itens: \n" << endl;
        for(int i = 0; i < qtdeItens; i++){
            cout << i << " - " ;
            itens[i]->imprimeResumo();
            cout << "\n" << endl;
        }
    }
}

void Personagem::imprimeListaTesouros(){
    if(qtdeTesouros == 0){
        cout << "Nenhum tesouro registrado no iventario." << endl;
    } else{
        cout << "\n Seus tesouros: \n" << endl;
        for(int i = 0; i < qtdeTesouros; i++){
            cout << i << " - " ;
            tesouros[i]->imprimeResumo();
            cout << "\n" << endl;
        }
    }
}

void Personagem::imprimeListaProvisoes(){
    if(qtdeProvisoes == 0){
        cout << "Nenhuma provisao registrada no iventario." << endl;
    } else{
        cout << "\n Suas provisoes: \n" << endl;
        for(int i = 0; i < qtdeProvisoes; i++){
            cout << i << " - " ;
            provisoes[i]->imprimeResumo();
            cout << "\n" << endl;
        }
    }
}
