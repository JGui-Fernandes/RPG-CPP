#include "Item.h"
#include <string.h>

Item::Item(){

}

Item::Item(char* novoNome, TipoItem novoTipo, bool novoCombate, int novoFa, int novoDano){
    nome = novoNome;
    tipo = novoTipo;
    combate = novoCombate;
    fa = novoFa;
    dano = novoDano;
}

bool Item::getCombate(){
    return combate;
}

int Item::getDano(){
   return dano;
}

char* Item::getNome(){
    return nome;
}

TipoItem Item::getTipo(){
    return tipo;
}

int Item::getFA(){
    return fa;
}

void Item::setCombate(bool novoCombate){
    combate = novoCombate;
}

void Item::setDano(int novoDano){
    dano = novoDano;
}

void Item::setFA(int novoFa){
    fa = novoFa;
}

void Item::setNome(char* novoNome){
    nome = novoNome;
}

void Item::setTipo(TipoItem novoTipo){
    tipo = novoTipo;
}

void Item::setTipo(char* novoTipo){
    if(novoTipo[0] == 'c'){
        setTipo(C);
    }
    else if(novoTipo[0] == 'r'){
        setTipo(R);
    }
    else if(novoTipo[0] == 'w'){
        setTipo(W);
    }
}

char* Item::getTipoEscrito(){
    if(tipo == 0){
        return "Item Comum";
    }
    if(tipo == 1){
        return "Armadura";
    }
    if(tipo == 2){
        return "Arma";
    }
}

void Item::imprimeResumo(){
    cout << nome << "   |    " << getTipoEscrito() << endl;
}

void Item::imprimeDetalhe(){
    cout << "Nome: " << nome << "  |  Tipo: " << getTipoEscrito();
    if(combate){
        if(tipo == 1){
            cout << "  |  Bonus de defesa: " << dano << endl;
        }
        if(tipo == 2){
            cout << "  |  Bonus de ataque: " << dano << endl;
        }
    }
}

void Item::constroiItem(string texto){
    int cont = 1;

    string nome = "", tipo = "", combate = "", fa = "", dano = "";
    for(int i = 0; i < texto.length(); i++){
        if(texto[i] == ';'){
            cont++;
        } else{
            if(cont == 1){
                nome += texto[i];
            }
            if(cont == 2){
                tipo += texto[i];
            }
            if(cont == 3){
                combate += texto[i];
            }
            if(cont == 4){
                fa += texto[i];
            }
            if(cont == 5){
                dano += texto[i];
            }
        }
    }


    char* nomeFinal = util.removeChar(util.converteStringParaChar(nome), "I: ");
    char* tipoFinal = util.converteStringParaChar(tipo);
    int combateFinal = util.converteStringParaInt(combate), faFinal = util.converteStringParaInt(fa), danoFinal = util.converteStringParaInt(dano);

    setNome(nomeFinal);
    setCombate(combateFinal);
    setDano(danoFinal);
    setFA(faFinal);
    setTipo(tipoFinal);
}
