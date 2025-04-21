#include "CenaMonstro.h"
#include <fstream>
#include <string.h>

CenaMonstro::CenaMonstro(){
    cout << "Construtor" << endl;
    lerArquivo("#2M.txt");
    lerMonstro("#2M.txt");
}

CenaMonstro::CenaMonstro(char* novaDescricao, Monstro novoMonstro):Cena(novaDescricao){
    monstro = novoMonstro;
}

void CenaMonstro::setMonstro(Monstro novoMonstro){
    monstro = novoMonstro;
}

Monstro CenaMonstro::getMonstro(){
    return monstro;
}

void CenaMonstro::imprimeCena(){
    imprimeDescricao();

    cout << "\n" << endl;

    monstro.imprimeInfo();

    cout << "\n" << endl;

    imprimeOpcoes();
}

void CenaMonstro::lerMonstro(char* nomeArquivo) {
    ifstream entrada(nomeArquivo);

    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo do monstro!" << endl;
        return;
    }

    char nome[100];
    int habilidade = 0, sorte = 0, energia = 0;
    int cenaSucesso = -1, cenaFracasso = -1;

    string linha;
    while (getline(entrada, linha)) {
        if (linha.empty()) continue;

        char identificador = linha[0];

        if (identificador == 'N') {
            strncpy(nome, linha.substr(3).c_str(), sizeof(nome));
            nome[sizeof(nome) - 1] = '\0';  // segurança
        } else if (identificador == 'H') {
            habilidade = stoi(linha.substr(3));
        } else if (identificador == 'S') {
            sorte = stoi(linha.substr(3));
        } else if (identificador == 'E') {
            energia = stoi(linha.substr(3));
        } else if (linha.find(';') != string::npos) {
            sscanf(linha.c_str(), "%d;%d", &cenaSucesso, &cenaFracasso);
        }
    }

    entrada.close();

    // Monta strings tipo "#1", "#2" para vitória e derrota
    char vitoria[10];
    char derrota[10];
    sprintf(vitoria, "#%d", cenaSucesso);
    sprintf(derrota, "#%d", cenaFracasso);

    // Cria o monstro com os dados corretos
    Monstro m(nome, habilidade, energia, sorte, vitoria, derrota);
    setMonstro(m);
}
