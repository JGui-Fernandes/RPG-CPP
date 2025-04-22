#include "Cena.h"
#include <cstring>
#include <fstream>

Cena::Cena(){
    descricao = nullptr;
    for(int i = 0; i < 3; i++){
        opcoes[i] = nullptr;
    }
}

Cena::Cena(char* nomeArquivo, bool arquivo){
    Cena c = lerArquivo(nomeArquivo);
    copiarCena(c);

    char* temp[3];
    for (int i = 0; i < 3; i++) {
        temp[i] = c.getOpcao(i);
    }

    separarOpcoes(temp);
}

Cena::Cena(char* novaDescricao){
    descricao = novaDescricao;
    strcpy(descricao, novaDescricao);
    for(int i = 0; i < 3; i++){
        opcoes[i] = nullptr;
    }
}

void Cena::setDescricao(char* novaDescricao){
    descricao = novaDescricao;
}

void Cena::setOpcoes(char* novasOpcoes[]){
    for(int i = 0; i < 3; i++){
        opcoes[i] = novasOpcoes[i];
    }
}

char* Cena::getDescricao(){
    return descricao;
}

void Cena::imprimeDescricao(){
    cout << descricao << "\n" << endl;
}

void Cena::imprimeOpcoes(){
    for(int i = 0; i < 3; i++){
        if(strcmp(opcoes[i], "") == 0 || strcmp(opcoes[i], " ") == 0){
            break;
        }
        cout << i+1 << ") " << opcoes[i] << endl;
    }
}

Cena Cena::lerArquivo(char* nomeArquivo) {
    Cena novaCena;

    novaCena.lerDescricao(nomeArquivo);
    novaCena.lerOpcoes(nomeArquivo);

    return novaCena;
}


void Cena::copiarCena(Cena& outra){
    descricao = outra.getDescricao();
    for(int i = 0; i < 3; i++){
        opcoes[i] = outra.getOpcao(i);
        proximaCena[i] = outra.getProximaCena(i);
    }
}

char* Cena::getOpcao(int index){
    return opcoes[index];
}

char* Cena::getProximaCena(int index){
    return proximaCena[index];
}

void Cena::separarOpcoes(char* entradas[3]) {
    for (int i = 0; i < 3; i++) {
        if (entradas[i] == nullptr) {
            opcoes[i] = nullptr;
            proximaCena[i] = nullptr;
            continue;
        }

        char* separador = strchr(entradas[i], ':');

        if (separador != nullptr) {
            int tamanhoEsquerda = separador - entradas[i];

            proximaCena[i] = new char[tamanhoEsquerda + 1];
            strncpy(proximaCena[i], entradas[i], tamanhoEsquerda);
            proximaCena[i][tamanhoEsquerda] = '\0';

            char* direita = separador + 1;
            while (*direita == ' '){
                direita++;
            }

            opcoes[i] = direita;
        } else {
            opcoes[i] = nullptr;
            proximaCena[i] = nullptr;
        }
    }
}

void Cena::lerDescricao(char* nomeArquivo) {
    ifstream entrada(nomeArquivo);

    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo para ler descricao!" << endl;
        descricao = nullptr;
        return;
    }

    string linha = "";

    getline(entrada, linha);

    char* resultado = converteStringParaChar(linha);

    descricao = resultado;


    entrada.close();
}

void Cena::lerOpcoes(char* nomeArquivo) {
    ifstream entrada(nomeArquivo);

    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo para ler opcoes!" << endl;
        return;
    }

    string linha;
    int countOpcoes = 0;

    while (getline(entrada, linha)) {
        if (!linha.empty() && linha[0] == '#') {
            if (countOpcoes < 3) {
                char* opcao = new char[linha.length() + 1];
                strcpy(opcao, linha.c_str());
                opcoes[countOpcoes] = opcao;
                countOpcoes++;
            }
        }
    }

    for (int i = countOpcoes; i < 3; i++) {
       opcoes[i] = nullptr;
    }

    entrada.close();
}

char* Cena::removeChar(char* texto, char* divisor) {
    char* pos = strstr(texto, divisor);

    if (pos != nullptr) {
        char* resultado = pos + strlen(divisor);
        return resultado;
    }
    return texto;
}

char* Cena::converteStringParaChar(string texto){
        char* resultado = (char*)malloc(texto.length() + 1);
        strcpy(resultado, texto.c_str());
}
