#pragma once

#include <string>
#include <iostream>

using namespace std;

class Util{

    public:
        Util();

        char* converteStringParaChar(string texto);
        int converteCharParaInt(char* texto);
        int converteStringParaInt(string texto);
        char* removeChar(char* texto, char* divisor);
};
