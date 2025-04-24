#include <iostream>

#include "GerenciadorHistoria.h"
#include "Personagem.h"
#include "Monstro.h"
#include "Item.h"
#include "SalvarHistoria.h"

using namespace std;

int main()
{
    Personagem p("joao", 10, 12, 10);
    Item* i = new Item("Espada", W, true, 3, 3);
    Item* i1 = new Item("Espada", C, true, 3, 3);
    Item* i2 = new Item("Arco", W, true, 3, 2);

    p.adicionaItem(i);
    p.adicionaItem(i1);
    p.adicionaItem(i2);

    SalvarHistoria s(&p);

    //s.escreverSalvamento();
    GerenciadorHistoria gerenciador;

    gerenciador.iniciador();




    Monstro* m = new Monstro("orc", 10, 6, 6, "#1", "#3");
    p.setProvisoes(3);


    //gerenciador.batalha(p, m);

    return 0;
}
