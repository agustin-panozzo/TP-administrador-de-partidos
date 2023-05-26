#include "../headers/claseFase.h"

using namespace std;

Fase::Fase(const string &nombreFase) {
    this->nombreFase = nombreFase;
    this->puntajeFase = 0;
}

string Fase::obtener_nombre() {
    return this->nombreFase;
}

int Fase::obtener_puntaje() {
    return this->puntajeFase;
}

void Fase::agregar_partido(Partido* &partido) {
    partidos.push_back(&partido);
}

vector<Partido**> Fase::obtener_partidos(){
    return partidos;
}