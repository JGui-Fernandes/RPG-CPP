#include "Personagem.h"
#include <string.h>
#include <iostream>

Personagem::Personagem(){
    qtdeItens = 0;
    provisoes = 0;
    tesouro = 0;
}

Personagem::Personagem(bool* heroi){
    Personagem p = constroiHeroi(heroi);
    copiaPersonagem(p);
}

Personagem::Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte){
    nome = novoNome;
    habilidade = novaHabilidade;
    energia = novaEnergia;
    sorte = novaSorte;
    qtdeItens = 0;
    tesouro = 0;
    provisoes = 0;
}

Personagem::Personagem(char* novoNome, int novaHabilidade, int novaEnergia, int novaSorte, int novaProvisao, int novaQtdeItens, int novoTesouro){
    nome = novoNome;
    habilidade = novaHabilidade;
    energia = novaEnergia;
    sorte = novaSorte;
    qtdeItens = novaQtdeItens;
    tesouro = novoTesouro;
    provisoes = novaProvisao;
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

Item* Personagem::getItem(int index) {
    return itens[index];
}

int Personagem::getTesouro() {
    return tesouro;
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

void Personagem::setItens(Item* novosItens[10]) {
    for (int i = 0; i < 10; i++) {
        itens[i] = novosItens[i];
    }
}

void Personagem::setTesouro(int novoTesouro) {
    tesouro = novoTesouro;
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

void Personagem::descartarItem(int index) {
    delete itens[index];

    for (int j = index; j < qtdeItens - 1; j++) {
        itens[j] = itens[j + 1];
    }
    itens[qtdeItens- 1] = nullptr;

    qtdeItens--;

}

void Personagem::imprimeListaItens(){
    if(qtdeItens == 0){
        cout << "Nenhum item registrado no iventario." << endl;
    } else{
        cout << "\n Seus itens: \n" << endl;
        for(int i = 0; i < qtdeItens; i++){
            cout << i+1 << " - " ;
            itens[i]->imprimeResumo();
            cout << "\n" << endl;
        }
    }
}

void Personagem::consumirProvisao(){
    if(provisoes > 0){
        energia += 4;
        cout << "Energia atual: " << energia << endl;
        provisoes--;
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

Personagem Personagem::constroiHeroi(bool* resposta){
    int valor;
    char n[50];
    int h = 6, e = 12, s = 6;

    cout << "Digite o nome do seu heroi: " << endl;
    cin.ignore();
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
            *resposta = true;
            return temp;
        }
        else if(valor == 2){
            cout << "Construcao de heroi cancelada.\n" << endl;
            passou = true;
            *resposta = false;
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
    provisoes = outro.getProvisao();
    tesouro = outro.getTesouro();
}

void Personagem::perderEnergia(int perda){
    energia -= perda;
}
