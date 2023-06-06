#include "../headers/actualizarPartidos.h"

using namespace std;

void eliminar_partidos(Equipos* equipos){
    string nombreFase, nombrePais1, nombrePais2;
    Pais* pais1 = nullptr;
    Pais* pais2 = nullptr;
    do{
        cout << "Ingrese la fase en la que se jugó el partido: " << endl;
        getline(cin >> ws, nombreFase);

        cout << "Ingrese el nombre del primer pais: " << endl;
        getline(cin >> ws, nombrePais1);

        cout << "Ingrese el nombre del segundo pais: " << endl;
        getline(cin >> ws, nombrePais2);
    }while(!es_una_fase(nombreFase) || equipos->obtener_pais(nombrePais1) == nullptr || equipos->obtener_pais(nombrePais2) == nullptr);

    pais1 = equipos->obtener_pais(nombrePais1);
    pais2 = equipos->obtener_pais(nombrePais2);

    if(equipos->existe_partido(nombreFase, pais1, pais2)){
        equipos->eliminar_partido(nombreFase, pais1, pais2);
    }

    else{
        cout << "El partido no existe" << endl;
    }
    

}