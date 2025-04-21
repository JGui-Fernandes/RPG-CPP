#include <string>
#include <iostream>

#include "Cena.h"
#include "Monstro.h"

using namespace std;

class CenaMonstro: public Cena{

    public:
        CenaMonstro();
        CenaMonstro(char* nomeArquivo, bool arquivo);
        CenaMonstro(char* novaDescricao, Monstro novoMonstro);

        void setMonstro(Monstro novoMonstro);

        Monstro getMonstro();

        void imprimeCena();

        void lerMonstro(char* nomeArquivo);

        CenaMonstro lerArquivoMonstro(char* nomeArquivo);

    protected:
        void copiarCena(Cena& outra);

    private:
        Monstro monstro;
};
