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

void CenaMonstro::separaMonstroEDescricao(char* texto) {
    char* separador = strstr(texto, "N:");
    char* desc = nullptr;
    char* resto = nullptr;
    if (separador != nullptr) {
        int tamanhoDescricao = separador - texto;
        strncpy(desc, texto, tamanhoDescricao);
        desc[tamanhoDescricao] = '\0';
        setDescricao(desc);
    }

    resto = removeChar(texto, desc);


}

CenaMonstro CenaMonstro::lerArquivo(char* nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        CenaMonstro cm;
        Monstro m;
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo!" << endl;
            return CenaMonstro("", Monstro("", 0, 0, 0, 0, 0));
        }

        string linha, vitDer;
        char* linhas[12];

        for(int i = 0; i < 12; i++){
            getline(arquivo, linha);
            if(i == 8){
                vitDer = linha;
            }
            char* resultado = converteStringParaChar(linha);
            linhas[i] = removeChar(resultado, ": ");
        }

        cm.setDescricao(linhas[0]);
        m.setNome(linhas[1]);
        m.setHabilidade(converteCharParaInt(linhas[2]));
        m.setSorte(converteCharParaInt(linhas[3]));
        m.setEnergia(converteCharParaInt(linhas[4]));
        m.setTesouro(converteCharParaInt(linhas[5]));
        m.setProvisoes(converteCharParaInt(linhas[6]));

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

        char* charV = converteStringParaChar(v);
        char* charD = converteStringParaChar(d);

        m.setDerrota(charD);
        m.setVitoria(charV);

        cm.setMonstro(m);

        cm.lerOpcoes(nomeArquivo);

        return cm;
}

void CenaMonstro::copiarCenaMonstro(CenaMonstro& cm){

    copiarCena(cm);

    setMonstro(cm.getMonstro());
}

 int CenaMonstro::converteCharParaInt(char* texto){
    char* i = texto;
    int o = atoi(i);

    return o;
 }
