#include <string>
#include <iostream>

#include "Cena.h"
#include "Monstro.h"

using namespace std;

class CenaMonstro: public Cena{

    public:
        CenaMonstro();
        CenaMonstro(char* novaDescricao, Monstro novoMonstro);

        void setMonstro(Monstro novoMonstro);

        Monstro getMonstro();

        void imprimeCena();

        void lerMonstro(char* nomeArquivo);
    private:
        Monstro monstro;
};
