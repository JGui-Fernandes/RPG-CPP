#include <string>
#include <iostream>

#include "Personagem.h"
#include "Monstro.h"
#include "Cena.h"
#include "CenaItem.h"
#include "CenaMonstro.h"

using namespace std;

class GerenciadorHistoria{

    public:
        GerenciadorHistoria();
        void iniciador();
        void iniciarJogo();
        void carregarJogo();

    private:
        Personagem p;
        Cena c;
        CenaMonstro cm;
        CenaItem ci;
        Monstro m;
};
