#include <string>
#include <iostream>

using namespace std;

class Cena{

    public:
        Cena();
        Cena(char* novaDescricao);

        void setDescricao(char* novaDescricao);
        void setOpcoes(char* opcoes[]);

        char* getDescricao();

        void imprimeDescricao();
        void imprimeOpcoes();
        virtual void imprimeCena();

    private:
        char* descricao;
        char* opcoes[5];
};
