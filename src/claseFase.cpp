#include "../headers/claseFase.h"

using namespace std;

Fase::Fase(const string nombreFase, const string nombrePais) {
    this->nombreFase = nombreFase;
    this->nombrePais = nombrePais;
    this->puntajeFase = 0;
}

string Fase::obtener_nombre() {
    return this->nombreFase;
}

int Fase::obtener_puntaje() {
    return this->puntajeFase;
}

void Fase::agregar_partido(Partido* &partido) { //Paso el puntero por referencia debido a que necesito guardar la dirección del puntero original y no una copia
    partidos.push_back(&partido);
}

vector<Partido**> Fase::obtener_partidos(){
    return partidos;
}

void Fase::calcular_puntaje_fase() {
    puntajeFase = 0; // lo seteo en 0 para que no se acumule el puntaje al calcularlo varias veces

    for(size_t i = 0; i < partidos.size(); i++){
            puntajeFase += (*partidos[i])->obtener_puntaje(nombrePais);
        }
    }


Partido* Fase::obtener_partido(const string &nombrePais1, const string &nombrePais2){
    Partido* partidoBuscado = nullptr;
    vector<string> datosPartido;

    for(size_t i = 0; i < partidos.size(); i++){
        if(*partidos[i] != nullptr){
            datosPartido = (*partidos[i])->exportar_partido();

            if(comparar_strings(datosPartido[NOMBRE_PAIS_1], nombrePais1) && comparar_strings(datosPartido[NOMBRE_PAIS_2], nombrePais2)){
                partidoBuscado = *partidos[i];
            }
        }
    }

    return partidoBuscado;
}

void Fase::limpiar_partidos(){
    for(size_t i = 0; i < partidos.size(); i++){

        if((*partidos[i]) == nullptr){
            partidos.erase(partidos.begin() + i);
        }
    }
}

void Fase::eliminar_partido(const string &nombrePais1, const string &nombrePais2){
    Partido* partidoBuscado = obtener_partido(nombrePais1, nombrePais2); //Puntero al partido de la lista de partidos

    if(partidoBuscado != nullptr){
        for(size_t i = 0; i < partidos.size(); i++){

            if(partidoBuscado == *partidos[i]){
                *partidos[i] = nullptr;
                partidos.erase(partidos.begin() + i);
            }
        }
        delete partidoBuscado;
    }

    else{
        limpiar_partidos(); // Verifico si tengo un puntero a null en la lista de partidos y lo elimino
    }

    calcular_puntaje_fase();
}

bool Fase::esta_vacia(){
    return partidos.empty();
}