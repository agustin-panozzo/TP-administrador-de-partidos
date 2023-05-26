#include "../headers/clasePartido.h"

using namespace std;

Partido::Partido(string pais1, int goles1, string pais2, int goles2){
    this->pais1 = pais1;
    this->goles1 = goles1;
    this->pais2 = pais2;
    this->goles2 = goles2;
};

string Partido::obtener_datos(){
    string datos = "";

    datos += pais1 + " " + to_string(goles1) + " - " + to_string(goles2) + " " + pais2;

    return datos;
};