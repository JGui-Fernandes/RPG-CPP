
#include <string>
#include <iostream>

using namespace std;

class Provisao{

    public:
        Provisao();
        Provisao(char* novoNome, char* novaDescricao, int novoPv);

        void setNome(char*);
        void setDescricao(char*);
        void setPV(int);

        char* getNome();
        char* getDescricao();
        int getPV();

        void imprimeResumo();

        void imprimeDetalhe();

    private:
        char* nome;
        char* descricao;
        int pv;
};
