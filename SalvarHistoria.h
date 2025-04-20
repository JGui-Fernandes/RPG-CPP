#include <string>
#include <iostream>

#include "Cena.h"
#include "Personagem.h"

using namespace std;

class SalvarHistoria{

    public:
        SalvarHistoria();
        SalvarHistoria(Personagem novoPersonagem);

        void setPersonagem(Personagem novoPersonagem);
        void setCenas(Cena* cenas[]);

        Personagem getPersonagem();
        Cena* getCena(int index);




    private:
        Personagem personagem;
        Cena* cenas[10];
};
