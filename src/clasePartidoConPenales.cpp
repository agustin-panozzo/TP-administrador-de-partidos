#include "../headers/clasePartidoConPenales.h"

using namespace std;

PartidoConPenales::PartidoConPenales(string pais1, int goles1, int penales1, string pais2, int goles2, int penales2) : Partido(pais1, goles1, pais2, goles2){
    this->penales1 = penales1;
    this->penales2 = penales2;
};

string PartidoConPenales::obtener_ganador(){ // No necesito chequear los goles porque si hubo penales, los goles no importan
    string ganador;

    if(penales1 > penales2){
        ganador = pais1;
    }

    else if(penales2 > penales1){
        ganador = pais2;
    }

    else{
        ganador = "Empate";
    }

    return ganador;
}

int PartidoConPenales::obtener_puntaje(const string &nombrePais){
    string ganador = obtener_ganador();
    int puntaje;

    if(ganador == "Empate"){
        puntaje = 1;
    }

    else if (comparar_strings(ganador, nombrePais)){ // Ganó por penales
        puntaje = 2;
    }

    else { // Perdió por penales
        puntaje = 1;
    }

    return puntaje;
}

vector<string> PartidoConPenales::exportar_partido(){
    vector<string> datosPartido;

    cout << pais1 << " " << goles1 << " " << penales1 <<" "<< pais2 << " " << goles2 << " " << penales2 << " " << endl;

    datosPartido.push_back(pais1);
    datosPartido.push_back(to_string(goles1));
    datosPartido.push_back(to_string(penales1));
    datosPartido.push_back(pais2);
    datosPartido.push_back(to_string(goles2));
    datosPartido.push_back(to_string(penales2));
    
    return datosPartido;
}