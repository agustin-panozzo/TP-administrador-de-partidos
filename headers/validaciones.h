#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <vector>
#include "constantes.h"
#include "manejoDeStrings.h"

/*
Pre: -
Post: Si el vector está vacío o contiene strings vacíos, devuelve true. En caso contrario, devuelve false.
*/
bool vector_esta_vacio(std::vector<std::string> &vector);

/*
Pre: -
Post: Si el vector no contiene caracteres vacíos y tiene dos elementos, devuelve true. En caso contrario, devuelve false.
*/
bool verificar_datos_equipo(std::vector<std::string> &datosEquipo);

/*
Pre: -
Post: Si el vector no contiene caracteres vacíos y tiene una cantidad de elementos acorde a su fase, devuelve true. En caso contrario, devuelve false.
*/
bool verificar_datos_resultados(std::vector<std::string> &datosResultados, const std::string &fase);

/*
Pre: -
Post: Si el string es igual a alguna fase, devuelve true. En caso contrario, devuelve false.
*/
bool es_una_fase(const std::string &fase);

/*
Pre: -
Post: Devuelve true si hubo penales en el partido. En caso contrario, devuelve false.
*/
bool hubo_penales(std::vector<std::string> &datosResultados, const std::string &fase);

/*
Pre: -
Post: Devuelve true si el vector contiene los nombres indicados. En caso contrario, devuelve false.
*/
bool comparar_datos_partido(std::vector<std::string> &datosPartido, const std::string &nombrePais1, const std::string &nombrePais2);

#endif // VALIDACIONES_H