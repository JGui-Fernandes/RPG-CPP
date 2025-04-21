#include <iostream>

#include "Personagem.h"
#include "Cena.h"

using namespace std;

int main()
{
    Cena cena("#1.txt", true);

// Teste
    cena.imprimeOpcoes();
    return 0;
}
