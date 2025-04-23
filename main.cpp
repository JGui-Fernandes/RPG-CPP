#include <iostream>

#include "Personagem.h"
#include "CenaMonstro.h"
#include "CenaItem.h"
#include "Cena.h"

using namespace std;

int main()
{
    CenaMonstro cena("#2M.txt", true);

    cout << cena.getMonstro().getQtdeItens();

    cena.getMonstro().imprimeListaItens();

    return 0;
}
