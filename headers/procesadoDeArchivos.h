#ifndef PROCESADO_DE_ARCHIVOS_H
#define PROCESADO_DE_ARCHIVOS_H

#include <iostream>
#include <fstream>
#include "clasePais.h"
#include "claseEquipos.h"
#include "constantes.h"

/*
Pre: -
Post: Carga los datos de los equipos en la clase Equipos a partir del archivo equipos.txt
*/
void cargar_archivo_equipos(Equipos* equipos);

/*
Pre: -
Post: Si el vector no contiene caracteres vacíos y tiene dos elementos, devuelve true. En caso contrario, devuelve false.
*/
bool verificar_datos_equipo(std::vector<std::string> &datosEquipo);

/*
Pre: -
Post: Devuelve un puntero a un pais con los datos cargados
*/
Pais procesar_linea_equipos(const std::string& linea);

/*
Pre: -
Post: Carga los datos de los resultados en la clase Equipos a partir del archivo resultados.csv
*/
void cargar_archivo_resultados(Equipos &equipos);

/*
Pre: -
Post: Procesa la línea leída y carga los datos de los resultados en la clase Equipos
*/
void procesar_resultados(const std::string &linea, const int &fase, Equipos &equipos);

#endif // PROCESADO_DE_ARCHIVOS_H