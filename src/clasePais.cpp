#include "../headers/clasePais.h"

using namespace std;

Pais::Pais(){
    this->nombre = "";
    this->grupo = "";
    this->titulo = "";
    this->puntajeTotal = 0;
}

Pais::Pais(const string &nombrePais, const string &grupo){
    this->nombre = nombrePais;
    this->grupo = grupo;
    this->titulo = "Sin titulo";
    this->puntajeTotal = 0;
}

const string Pais::obtener_nombre(){
    return nombre;
}

const string Pais::obtener_grupo(){
    return grupo;
}