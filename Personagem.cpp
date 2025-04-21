#include "Personagem.h"
#include <string.h>
#include <iostream>

Personagem::Personagem(){
    qtdeItens = 0;
    qtdeTesouros = 0;
    provisoes = 0;
}

Personagem::Personagem(bool heroi){
    Personagem p = constroiHeroi();
    copiaPersonagem(p);
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

void Personagem::descartarItem(Item novoItem) {
    for (int i = 0; i < qtdeItens; i++) {
        if (strcmp(itens[i]->getNome(), novoItem.getNome()) == 0) {
            delete itens[i];

            for (int j = i; j < qtdeItens - 1; j++) {
                itens[j] = itens[j + 1];
            }
            itens[qtdeItens- 1] = nullptr;

            qtdeItens--;

            break;
        }
    }
}

void Personagem::descartarTesouro(Tesouro novoTesouro) {
    for (int i = 0; i < qtdeTesouros; i++) {
        if (strcmp(tesouros[i]->getNome(), novoTesouro.getNome()) == 0) {
            delete tesouros[i];

            for (int j = i; j < qtdeTesouros - 1; j++) {
                tesouros[j] = tesouros[j + 1];
            }
            tesouros[qtdeTesouros- 1] = nullptr;

            qtdeTesouros--;

            break;
        }
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

void Personagem::imprimeInfo(){
    cout << "Nome: " << nome << endl;
    cout << "Habilidade: " << habilidade << endl;
    cout << "Energia: " << energia << endl;
    cout << "Sorte: " << sorte << endl;
}

Personagem Personagem::constroiHeroi(){
    int valor;
    char n[50];
    int h = 6, e = 12, s = 6;

    cout << "Digite o nome do seu heroi: " << endl;
    cin.getline(n, 50);

    cout << "Voce possui 12 pontos de melhoria para distribuir entre seus atributos." << endl;
    int pontosRestantes = 12;

    bool passou = false;

    passou = false;
    while(!passou){
        cout << "Voce possui 6 pontos no atributo HABILIDADE. Quantos mais deseja adicionar?" << endl;
        cin >> valor;
        if(valor > pontosRestantes){
            cout << "Nao possui pontos suficientes. Digite outro valor. " << endl;
        }
        else if(valor > 6){
            cout << "O limite de HABILIDADE possivel eh 12. Digite outro valor." << endl;
        }
        else if(valor < 0){
            cout << "Digite um valor valido." << endl;
        }
        else{
            h += valor;
            pontosRestantes -= valor;
            passou = true;
        }
    }

    passou = false;
    while(!passou){
        cout << "Voce possui 12 pontos no atributo ENERGIA. Quantos mais deseja adicionar?" << endl;
        cin >> valor;
        if(valor > pontosRestantes){
            cout << "Nao possui pontos suficientes. Digite outro valor. " << endl;
        }
        else if(valor > 12){
            cout << "O limite de ENERGIA possivel eh 24. Digite outro valor." << endl;
        }
        else if(valor < 0){
            cout << "Digite um valor valido." << endl;
        }
        else{
            e += valor;
            pontosRestantes -= valor;
            passou = true;
        }
    }

    passou = false;
    while(!passou){
        cout << "Voce possui 6 pontos no atributo SORTE. Quantos mais deseja adicionar?" << endl;
        cin >> valor;
        if(valor > pontosRestantes){
            cout << "Nao possui pontos suficientes. Digite outro valor. " << endl;
        }
        else if(valor > 6){
            cout << "O limite de SORTE possivel eh 12. Digite outro valor." << endl;
        }
        else if(valor < 0){
            cout << "Digite um valor valido." << endl;
        }
        else{
            s += valor;
            pontosRestantes -= valor;
            passou = true;
        }
    }

    Personagem temp(n, h, e, s);

    passou = false;
    while(!passou){
        temp.imprimeInfo();

        cout << "\nConfirma seus valores? (1 - SIM | 2 - NAO): " << endl;
        cin >> valor;

        if(valor == 1){
            cout << "Heroi construido com sucesso!\n" << endl;
            passou = true;
            return temp;
        }
        else if(valor == 2){
            cout << "Construcao de heroi cancelada.\n" << endl;
            passou = true;
            return Personagem();
        }
        else{
            cout << "Digite um valor valido." << endl;
        }
    }

    return Personagem();
}

void Personagem::copiaPersonagem(Personagem& outro){
    nome = outro.getNome();
    habilidade = outro.getHabilidade();
    energia = outro.getEnergia();
    sorte = outro.getSorte();
    qtdeItens = outro.getQtdeItens();
    qtdeTesouros = outro.getQtdeTesouros();
    provisoes = outro.getProvisao();
}
