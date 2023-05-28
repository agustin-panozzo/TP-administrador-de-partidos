#ifndef FUNCIONES_MENU_H
#define FUNCIONES_MENU_H

#include <iostream>
#include "claseEquipos.h"

/*
Pre: -
Post: Muestra por pantalla la lista de paises y el grupo al que pertenecen.
*/
void mostrar_paises(Equipos* equipos);

/*
Pre: -
Post: Asigna a los punteros los paises que obtuvieron el 1er, 2do y 3er puesto.
*/
void obtener_top3(Pais* &campeon, Pais* &subcampeon, Pais* &tercerpuesto, Equipos* equipos);

/*
Pre: -
Post: Muestra por pantalla los tres finalistas del mundial y los puntos totales.
*/
void mostrar_top3(Equipos* equipos);

/*
Pre: -
Post: Solicita al usuario un pais y muestra por pantalla sus datos.
*/
void buscar_pais(Equipos* equipos);

#endif // FUNCIONES_MENU_H