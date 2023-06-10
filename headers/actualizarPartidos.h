#ifndef ACTUALIZAR_PARTIDOS_H
#define ACTUALIZAR_PARTIDOS_H

#include "claseEquipos.h"
#include "constantes.h"
#include <iostream>

/*
Pre: -
Post: Solicita al usuario los datos del partido a eliminar.
*/
void solicitar_datos_partido(Equipos* equipos, std::string &nombreFase, std::string &nombrePais1, std::string &nombrePais2);

/*
Pre: -
Post: Elimina los punteros a los partidos de la fase indicada por el usuario.
*/
void eliminar_partidos(Equipos* equipos);

/*
Pre: Los datos ingresados deben ser números.
Post: Solicita al usuario los resultados del partido a modificar.
*/
void solicitar_goles(std::vector<std::string> &datosPartido, const std::string &nombreFase);

/*
Pre: -
Post: Modifica los goles de un partido.
*/
void modificar_goles(Equipos* equipos, std::string nombreFase, std::string nombrePais1, std::string nombrePais2);

/*
Pre: Los equipos deben existir.
Post: Solicita al usuario los equipos del partido a modificar.
*/
void solicitar_equipos(Equipos* equipos, std::vector<std::string> &datosPartido, const std::string &nombreFase);

/*
Pre: -
Post: Modifica los equipos de un partido.
*/
void modificar_equipos(Equipos* equipos, std::string nombreFase, std::string nombrePais1, std::string nombrePais2);

/*
Pre: -
Post: Solicita al usuario los datos del nuevo partido a agregar.
*/
void solicitar_datos_nuevo_partido(Equipos* equipos, std::vector<std::string> &datosNuevoPartido);

/*
Pre: -
Post: Solicita al usuario una fase y la devuelve.
*/
std::string solicitar_fase();

/*
Pre: -
Post: Agrega un partido con los datos ingresados por el usuario.
*/
void agregar_partido(Equipos* equipos);

#endif // ACTUALIZAR_PARTIDOS_H