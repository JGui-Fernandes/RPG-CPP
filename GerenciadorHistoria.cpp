#include "GerenciadorHistoria.h"

GerenciadorHistoria::GerenciadorHistoria(){

}

void GerenciadorHistoria::iniciador(){
    int resposta;
    cout << "Bem vindo ao jogo." << endl;
    cout << "O que deseja fazer? (1-Novo Jogo | 2-Carregar Jogo)" << endl;
    cin >> resposta;

    switch (resposta) {
        case 1:
            iniciarJogo();
            break;
        case 2:
            carregarJogo();
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            iniciador();
            break;
    }
}

void GerenciadorHistoria::iniciarJogo(){

    cout << "Iniciando novo jogo... \n" << endl;

    cout << "Vamos montar um heroi lendario para voce!\n" << endl;

    p = p.constroiHeroi();
}

void GerenciadorHistoria::carregarJogo(){
    cout << "Ainda nao implementado" << endl;
}
