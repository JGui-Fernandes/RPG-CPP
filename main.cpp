#include <iostream>

#include "Personagem.h"
#include "CenaMonstro.h"
#include "Cena.h"

using namespace std;

int main()
{
    cout << "Teste" << endl;
    CenaMonstro* cena = new CenaMonstro();

    cena->imprimeDescricao();

    return 0;
}
