#include "../headers/validaciones.h"

using namespace std;

bool vector_esta_vacio(vector<string> &vector){
    bool estaVacio = false;

    if(vector.size() == 0){
        estaVacio = true;
    }
    
    else{
        for(size_t i = 0; i < vector.size(); i++){
            if(vector[i] == ""){
                estaVacio = true;
            }
        }
    }

    return estaVacio;
}

bool verificar_datos_equipo(vector<string> &datosEquipo){
    bool datosValidos = true;

    if(datosEquipo.size() != 2 || vector_esta_vacio(datosEquipo)){
        datosValidos = false;
    }

    return datosValidos;
}

bool verificar_datos_resultados(std::vector<std::string> &datosResultados, const std::string &fase){
    bool datosValidos = true;

    if(vector_esta_vacio(datosResultados) || datosResultados.size() != 6){
        datosValidos = false;
    }

    return datosValidos;
}

bool es_una_fase(const string &fase){
    bool faseValida = false;

    for(size_t i = 0; i < CANTIDAD_FASES; i++){
        if(comparar_strings(fase, FASES[i])){
            faseValida = true;
        }
    }

    return faseValida;
}

bool hubo_penales(vector<string> &datosResultados, const string &fase){
    bool huboPenales = false;

    if(!comparar_strings(fase, "GRUPOS")){
        if(datosResultados[PENALES_1] != "-1" && datosResultados[PENALES_2] != "-1"){
            huboPenales = true;
        }
    }

    return huboPenales;
}