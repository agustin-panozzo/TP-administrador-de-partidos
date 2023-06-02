#include "../headers/mostrarEnConsola.h"

using namespace std;

void mostrar_grupo(Equipos* equipos, const string &grupo){
    Pais* paisActual = nullptr;
    Equipos* equiposPorGrupo = new Equipos();

    insertar_grupo(equipos, equiposPorGrupo, grupo);

    cout << "=  =  GRUPO " << grupo << "  =  =\n" << endl;

    for(int i = 1; i <= equiposPorGrupo->obtener_tamanio(); i++){
        paisActual = equiposPorGrupo->obtener_dato(i);
        cout << "Nombre: " << paisActual->obtener_nombre() << " Puntaje: " << paisActual->obtener_puntaje_fase("GRUPOS") << endl;
    }
    cout << endl;

    equiposPorGrupo->limpiar();
    delete equiposPorGrupo;
}

void mostrar_grupos_por_puntaje(Equipos* equipos){
    vector<string> grupos = equipos->obtener_grupos();

    cout << "= =  =  GRUPOS  =  =  =  \n" << endl;

    for(size_t i = 0; i < grupos.size(); i++){
        mostrar_grupo(equipos, grupos[i]);
    }
}

void mostrar_fase_por_puntaje(Equipos* equipos, const string &nombreFase){
    Pais* paisActual = nullptr;
    Equipos* equiposPorPuntaje = new Equipos();

    insertar_fase(equipos, equiposPorPuntaje, nombreFase);

    cout << "=  =  =  " << nombreFase << "  =  =  =  \n" << endl;

    for(int i = 1; i <= equiposPorPuntaje->obtener_tamanio(); i++){
        paisActual = equiposPorPuntaje->obtener_dato(i);
        cout << "Nombre: " << paisActual->obtener_nombre() << " Puntaje: " << paisActual->obtener_puntaje_fase(nombreFase) << endl;
    }
    cout << endl;

    equiposPorPuntaje->limpiar();
    delete equiposPorPuntaje;
}

void mostrar_eliminatorias_por_puntaje(Equipos* equipos){
    for(int i = 1; i < CANTIDAD_FASES; i++){
        mostrar_fase_por_puntaje(equipos, FASES[i]);
    }
}