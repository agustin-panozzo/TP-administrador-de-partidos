#include "../headers/generarObjetos.h"

using namespace std;

Partido* generar_partido(vector<string> &lineaProcesada, const string &nombreFase){
    Partido* nuevoPartido = nullptr;

    if(hubo_penales(lineaProcesada, nombreFase)){
        nuevoPartido = new PartidoConPenales(

        lineaProcesada[NOMBRE_PAIS_1], 
        stoi(lineaProcesada[GOLES_1]), 
        stoi(lineaProcesada[PENALES_1]), 

        lineaProcesada[NOMBRE_PAIS_2], 
        stoi(lineaProcesada[GOLES_2]),
        stoi(lineaProcesada[PENALES_2])
    
    ); 
    cout << "Se creó un partido con penales en: " << nuevoPartido << endl;
    }

    else{
        nuevoPartido = new Partido(

        lineaProcesada[NOMBRE_PAIS_1], 
        stoi(lineaProcesada[GOLES_1]), 

        lineaProcesada[NOMBRE_PAIS_2], 
        stoi(lineaProcesada[GOLES_2])

        ); 
        cout << "Se creó un partido sin penales en: " << nuevoPartido << endl;
    }

    return nuevoPartido;
}