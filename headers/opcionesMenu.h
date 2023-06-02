#ifndef FUNCIONES_MENU_H
#define FUNCIONES_MENU_H

#include <iostream>
#include "claseEquipos.h"
#include "grupos.h"

/*
Pre: -
Post: Limpia la pantalla.
*/
void limpiar_pantalla();

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
Post: Devuelve el nombre de la ultima fase en la que participo el pais.
*/
std::string obtener_nombre_ultima_fase(Pais* pais);

/*
Pre: -
Post: Solicita al usuario un pais y muestra por pantalla sus datos.
*/
void buscar_pais(Equipos* equipos);

/*
Pre: -
Post: Muestra por pantalla los paises ordenados por puntaje en cada fase.
*/
void mostrar_por_fase(Equipos* equipos);

#endif // FUNCIONES_MENU_H