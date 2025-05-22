#include "CenaMonstro.h"
#include <fstream>
#include <string.h>
#include <cstdlib>


CenaMonstro::CenaMonstro(){

}

CenaMonstro::CenaMonstro(char* nomeArquivo, bool arquivo){
    CenaMonstro cm = lerArquivo(nomeArquivo);

    copiarCenaMonstro(cm);

    char* temp[3];
    for (int i = 0; i < 3; i++) {
        temp[i] = cm.getOpcao(i);
    }

    separarOpcoes(temp);
}

CenaMonstro::CenaMonstro(char* novaDescricao, Monstro* novoMonstro):Cena(novaDescricao){
    monstro = novoMonstro;
}

void CenaMonstro::setMonstro(Monstro* novoMonstro){
    monstro = novoMonstro;
}

Monstro* CenaMonstro::getMonstro(){
    return monstro;
}

void CenaMonstro::imprimeCena(){
    imprimeDescricao();

    cout << "\n" << endl;

    monstro->imprimeInfo();

    cout << "\n" << endl;

    imprimeOpcoes();
}

CenaMonstro CenaMonstro::lerArquivo(char* nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        CenaMonstro cm;
        Monstro* m = new Monstro();
        Item* i = new Item();
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo!" << endl;
            return CenaMonstro("", new Monstro("", 0, 0, 0, 0, 0));
        }

        string linha, vitDer, it;
        char* linhas[12];

        for(int i = 0; i < 12; i++){
            getline(arquivo, linha);
            if(i == 7){
                it = linha;
            }
            if(i == 8){
                vitDer = linha;
            }
            char* resultado = util.converteStringParaChar(linha);
            linhas[i] = util.removeChar(resultado, ": ");
        }

        cm.setDescricao(linhas[0]);
        m->setNome(linhas[1]);
        m->setHabilidade(util.converteCharParaInt(linhas[2]));
        m->setSorte(util.converteCharParaInt(linhas[3]));
        m->setEnergia(util.converteCharParaInt(linhas[4]));
        m->setTesouro(util.converteCharParaInt(linhas[5]));
        m->setProvisoes(util.converteCharParaInt(linhas[6]));

        string v = "#";
        string d = "#";
        int c = 0;
        bool passou = false;

        for(int i = 0; i < vitDer.length(); i++){
            if(vitDer[i]==';'){
                    passou = true;
            }
            else if(!passou){
                v += vitDer[i];

            } else{
                d += vitDer[i];
            }

        }

        i->constroiItem(it);

        char* charV = util.converteStringParaChar(v);
        char* charD = util.converteStringParaChar(d);

        m->setDerrota(charD);
        m->setVitoria(charV);

        m->adicionaItem(i);

        cm.setMonstro(m);

        cm.lerOpcoes(nomeArquivo);

        return cm;
}

void CenaMonstro::copiarCenaMonstro(CenaMonstro& cm){

    copiarCena(cm);

    setMonstro(cm.getMonstro());
}
