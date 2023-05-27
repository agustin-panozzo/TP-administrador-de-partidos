#include "../headers/funcionesMenu.h"

using namespace std;

void mostrar_paises(Equipos* equipos){
    Pais* paisActual;
    cout << "\n  =  =  =  LISTA DE PAISES  =  =  =  " << endl;

    for(int i = 1; i <= equipos->obtener_tamanio(); i++){
        
        paisActual = equipos->obtener_dato(i);
        cout << "Nombre: " << paisActual->obtener_nombre() << " Grupo: " << paisActual->obtener_grupo() << endl;
    }

    cout << endl;
}

void obtener_top3(Pais* &campeon, Pais* &subcampeon, Pais* &tercerpuesto, Equipos* equipos){

    for(int i = 1; i <= equipos->obtener_tamanio(); i++){

        if(comparar_strings(equipos->obtener_dato(i)->obtener_titulo(), "Campeon")){
            campeon = equipos->obtener_dato(i);
        }

        else if(comparar_strings(equipos->obtener_dato(i)->obtener_titulo(), "Subcampeon")){
            subcampeon = equipos->obtener_dato(i);
        }

        else if(comparar_strings(equipos->obtener_dato(i)->obtener_titulo(), "Tercer puesto")){
            tercerpuesto = equipos->obtener_dato(i);
        }
    }
}

void mostrar_top3(Equipos* equipos){
    Pais* campeon = nullptr;
    Pais* subcampeon = nullptr;
    Pais* tercerpuesto = nullptr;

    obtener_top3(campeon, subcampeon, tercerpuesto, equipos);

    cout << "\n  =  =  =  TOP 3  =  =  =  " << endl;

    if(campeon != nullptr){
        cout << "1er puesto: " << campeon->obtener_nombre() << " Puntos total: " << campeon->obtener_puntaje_total() << endl;
    }

    if(subcampeon != nullptr){
        cout << "2do puesto: " << subcampeon->obtener_nombre() << " Puntos total: " << subcampeon->obtener_puntaje_total() << endl;
    }

    if(tercerpuesto != nullptr){
        cout << "3er puesto: " << tercerpuesto->obtener_nombre() << " Puntos total: " << tercerpuesto->obtener_puntaje_total() << endl;
    }

    cout << endl;
}