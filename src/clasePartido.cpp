#include "../headers/clasePartido.h"

using namespace std;

Partido::Partido(string pais1, int goles1, string pais2, int goles2){
    this->pais1 = pais1;
    this->goles1 = goles1;
    this->pais2 = pais2;
    this->goles2 = goles2;
};

string Partido::obtener_ganador(){
    string ganador;

    if (goles1 > goles2){
        ganador = pais1;
    }

    else if (goles2 > goles1){
        ganador = pais2;
    }

    else{
        ganador = "Empate";
    }

    return ganador;
};

int Partido::obtener_puntaje(const string &nombrePais){
    string ganador = obtener_ganador();
    int puntaje;

    if(ganador == "Empate"){
        puntaje = 1;
    }

    else if (comparar_strings(ganador, nombrePais)){ // Ganó por goles
        puntaje = 3;
    }

    else {
        puntaje = 0;
    }

    return puntaje;
}

vector<string> Partido::exportar_partido(){
    vector<string> partido;

    partido.push_back(pais1);
    partido.push_back(to_string(goles1));
    partido.push_back("-1");
    partido.push_back(pais2);
    partido.push_back(to_string(goles2));
    partido.push_back("-1");

    return partido;
}