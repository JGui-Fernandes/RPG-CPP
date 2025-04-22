#include <iostream>

#include "Personagem.h"
#include "CenaMonstro.h"
#include "Cena.h"

using namespace std;

int main()
{
    CenaMonstro cena("#2M.txt", true);

    cout << "D: " << cena.getMonstro().getDerrota();
    return 0;
}
