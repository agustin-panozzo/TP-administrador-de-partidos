#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>

const std::string ARCHIVO_EQUIPOS = "../equipos.txt"; 
const std::string ARCHIVO_RESULTADOS = "../resultados.csv";

const int CANTIDAD_FASES = 6;
const int CANTIDAD_OPCIONES_MENU = 6;
const int CANTIDAD_OPCIONES_SUBMENU = 4;
const int CANTIDAD_OPCIONES_MODIFICAR_PARTIDO = 3;

enum DATOS_EQUIPO {NOMBRE, GRUPO};
enum DATOS_RESULTADOS {NOMBRE_PAIS_1, GOLES_1, PENALES_1, NOMBRE_PAIS_2, GOLES_2, PENALES_2};

const std::string FASES[CANTIDAD_FASES] = {"Grupos", "Octavos", "Cuartos", "Semifinal", "Final", "Tercer Puesto"};

const std::string MENU[CANTIDAD_OPCIONES_MENU] = {
    "Listar equipos.",
    "Mostrar los equipos en primer, segundo y tercer lugar.",
    "Buscar equipo por nombre.",
    "Mostrar por fase los paises ordenados por puntaje",
    "Actualizar partidos.",
    "Salir."
};

const std::string SUBMENU[CANTIDAD_OPCIONES_SUBMENU] = {
    "Agregar un partido.",
    "Modificar un partido.",
    "Eliminar un partido.",
    "Volver al menu principal."
};

const std::string MODIFICAR_PARTIDO[CANTIDAD_OPCIONES_MODIFICAR_PARTIDO] = {
    "Modificar goles.",
    "Modificar equipos",
    "Volver al menu anterior."
};

#endif // CONSTANTES_H