#include "Personagem.h"

Personagem::Personagem(){
    qtdeItens = 0;
    qtdeTesouros = 0;
    provisoes = 0;
}

Personagem::Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte){
    nome = novoNome;
    habilidade = novaHabilidade;
    energia = novaEnergia;
    sorte = novaSorte;
    qtdeItens = 0;
    qtdeTesouros = 0;
    provisoes = 0;
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

Item* Personagem::getItem(int index) {
    return itens[index];
}

Tesouro* Personagem::getTesouro(int index) {
    return tesouros[index];
}

int Personagem::getProvisao() {
    return provisoes;
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

void Personagem::setProvisoes(int novasProvisoes) {
    provisoes = novasProvisoes;
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

void Personagem::consumirProvisao(){
    if(provisoes > 0){
        energia += 4;
        cout << "Energia atual: " << energia << endl;
    }
    else{
        cout << "Sem provisoes para consumo" << endl;
    }
}
