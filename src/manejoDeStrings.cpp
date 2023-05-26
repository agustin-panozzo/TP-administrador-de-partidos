#include "../headers/manejoDeStrings.h"

using namespace std;

int calcular_largo_string(const string& cadena){
    int indice = 0;
    while(cadena[indice] != '\0'){
        indice++;
    }

    return indice;
}

bool comparar_strings(const string& cadena1, const string& cadena2){
    bool sonIguales = true;
    int largoString1 = calcular_largo_string(cadena1);
    int largoString2 = calcular_largo_string(cadena2);

    if(largoString1 != largoString2){
        sonIguales = false;
    }

    for(int i = 0; i < min(largoString1, largoString2); i++){
        if(tolower(cadena1[i]) != tolower(cadena2[i])){
            sonIguales = false;
        }
    }

    return sonIguales;
}