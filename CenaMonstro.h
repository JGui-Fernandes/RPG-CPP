#include <string>
#include <iostream>

#include "Cena.h"
#include "Monstro.h"

using namespace std;

class CenaMonstro: public Cena{

    public:
        CenaMonstro();
        CenaMonstro(char* nomeArquivo, bool arquivo);
        CenaMonstro(char* novaDescricao, Monstro* novoMonstro);

        void setMonstro(Monstro* novoMonstro);

        Monstro* getMonstro();

        void imprimeCena();

        CenaMonstro lerArquivo(char* nomeArquivo);

        void copiarCenaMonstro(CenaMonstro& cm);

    private:
        Monstro* monstro;
};
