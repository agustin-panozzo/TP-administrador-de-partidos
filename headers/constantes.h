#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>

const std::string ARCHIVO_EQUIPOS = "../equipos.txt"; 
const std::string ARCHIVO_RESULTADOS = "../resultados.csv";

const int CANTIDAD_FASES = 6;
const int CANTIDAD_TITULOS = 4;

enum DATOS_EQUIPO {NOMBRE, GRUPO};
enum DATOS_RESULTADOS {NOMBRE_PAIS_1, GOLES_1, PENALES_1, NOMBRE_PAIS_2, GOLES_2, PENALES_2};

const std::string FASES[CANTIDAD_FASES] = {"Grupos", "Octavos", "Cuartos", "Semifinal", "Final", "Tercer Puesto"};
const std::string TITULOS[CANTIDAD_TITULOS] = {"Campeon", "Subcampeon", "Tercer Puesto", "Cuarto Puesto"};

#endif // CONSTANTES_H