#include "Util.h"
#include <string.h>

Util::Util(){

}

char* Util::converteStringParaChar(string texto){
    char* resultado = (char*)malloc(texto.length() + 1);
    strcpy(resultado, texto.c_str());
}


int Util::converteCharParaInt(char* texto){
    char* i = texto;
    int o = atoi(i);

    return o;
}

int Util::converteStringParaInt(string texto){
    char* i = converteStringParaChar(texto);
    int o = converteCharParaInt(i);

    return o;
}

char* Util::removeChar(char* texto, char* divisor) {
    char* pos = strstr(texto, divisor);

    if (pos != nullptr) {
        char* resultado = pos + strlen(divisor);
        return resultado;
    }
    return texto;
}
