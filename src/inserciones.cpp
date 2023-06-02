#include "../headers/inserciones.h"

using namespace std;

void insertar_fase(Equipos* equipos, Equipos* equiposPorPuntaje, const string &nombreFase){
    Pais* paisActual = nullptr;

    for(int i = 1; i <= equipos->obtener_tamanio(); i++){
        paisActual = equipos->obtener_dato(i);

        if(paisActual->jugo_en_fase(nombreFase)){
            equiposPorPuntaje->insertar_por_puntaje_fase(paisActual, nombreFase);
        }
    }
}

void insertar_grupo(Equipos* equipos, Equipos* equiposPorGrupo, const string &grupo){
    Pais* paisActual = nullptr;

    for(int i = 1; i <= equipos->obtener_tamanio(); i++){
        paisActual = equipos->obtener_dato(i);
        
        if(comparar_strings(paisActual->obtener_grupo(), grupo) && paisActual->jugo_en_fase("GRUPOS")){
            equiposPorGrupo->insertar_por_puntaje_fase(paisActual, "GRUPOS");
        }
    }
}