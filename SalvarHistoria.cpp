#include "SalvarHistoria.h"
#include <fstream>
#include "string.h"

SalvarHistoria::SalvarHistoria(){
    arquivo = "salvamento.txt";
    qtdeCenas = 0;
}

SalvarHistoria::SalvarHistoria(Personagem* novoPersonagem){
    personagem = novoPersonagem;
    qtdeCenas = 0;
    arquivo = "salvamento.txt";
}

void SalvarHistoria::setPersonagem(Personagem* novoPersonagem){
    personagem = novoPersonagem;
}

void SalvarHistoria::setQtdeCenas(int qtde){
    qtdeCenas = qtde;
}

Personagem* SalvarHistoria::getPersonagem(){
    return personagem;
}

char* SalvarHistoria::getCena(int index){
    return cenas[index];
}

int SalvarHistoria::getQtdeCenas(){
    return qtdeCenas;
}

char* SalvarHistoria::getArquivo(){
    return arquivo;
}

void SalvarHistoria::escreverSalvamento(){
    ofstream arq(arquivo);

    arq << "P: " << personagem->getNome() << ";"
    << personagem->getHabilidade()<< ";"
    << personagem->getEnergia() << ";"
    << personagem->getSorte() << ";"
    << personagem->getProvisao() << ";"
    << personagem->getQtdeItens() << ";"
    << personagem->getTesouro() << endl;

    for(int i = 0; i < personagem->getQtdeItens(); i++){
        Item* it = personagem->getItem(i);
        arq << "I: " << it->getNome() << ";"
        << converteTipo(it->getTipo()) << ";"
        << it->getCombate() << ";"
        << it->getFA() << ";"
        << it->getDano() << endl;
    }

    for(int i = 0; i < qtdeCenas; i++){
        arq << cenas[i] << endl;
    }
}

void SalvarHistoria::adicionaCena(char* nomeCena){
    for(int i = 0; i < qtdeCenas; i++){
        if(strcmp(cenas[i], nomeCena) == 0){
            return;
        }
    }
    cenas[qtdeCenas] = nomeCena;
    qtdeCenas++;
}

void SalvarHistoria::lerArquivo(){
    ifstream arq(arquivo);

    string linha;

    getline(arq, linha);

    int cont = 1;

    string nome = "", habilidade = "", energia = "", sorte = "", provisao = "", qtdeItem = "", tesouro = "";

    for(int i = 0; i < linha.length(); i++){
        if(linha[i] == ';'){
            cont++;
        } else{
            if(cont == 1){
                nome += linha[i];
            }
            if(cont == 2){
                habilidade += linha[i];
            }
            if(cont == 3){
                energia += linha[i];
            }
            if(cont == 4){
                sorte += linha[i];
            }
            if(cont == 5){
                provisao += linha[i];
            }
            if(cont == 6){
                qtdeItem += linha[i];
            }
            if(cont == 7){
                tesouro += linha[i];
            }
        }
    }


    char* nomeFinal = util.removeChar(util.converteStringParaChar(nome), "P: ");
    int habilidadeFinal = util.converteStringParaInt(habilidade), energiaFinal = util.converteStringParaInt(energia),
        sorteFinal = util.converteStringParaInt(sorte), provisaoFinal = util.converteStringParaInt(provisao),
        qtdeFinal = util.converteStringParaInt(qtdeItem), tesouroFinal = util.converteStringParaInt(tesouro);

    personagem = new Personagem(nomeFinal, habilidadeFinal, energiaFinal, sorteFinal, provisaoFinal, qtdeFinal, tesouroFinal);

    Item* itens[10];

    for(int i = 0; i < qtdeFinal; i++){
        Item* item = new Item();
        getline(arq, linha);
        item->constroiItem(linha);

        itens[i] = item;
    }

    personagem->setItens(itens);

    while(getline(arq, linha)){
        adicionaCena(util.converteStringParaChar(linha));
    }
}

char SalvarHistoria::converteTipo(int antigo){
    if(antigo == 0){
        return 'c';
    } else if(antigo == 1){
        return 'r';
    } else{
        return 'w';
    }
}
