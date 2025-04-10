#include <string>
#include <iostream>

using namespace std;

class Tesouro{

    public:
        Tesouro();
        Tesouro(char* novoNome, char* novaDescricao, int novoValor);

        void setNome(char*);
        void setDescricao(char*);
        void setValor(int);

        char* getNome();
        char* getDescricao();
        int getValor();

        void imprimeResumo();

        void imprimeDetalhe();

    private:
        char* nome;
        char* descricao;
        int valor;
};
