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