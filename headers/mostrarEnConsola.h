#ifndef MOSTRAR_EN_CONSOLA_H
#define MOSTRAR_EN_CONSOLA_H

#include <iostream>
#include "claseEquipos.h"
#include "inserciones.h"

/*
Pre: -
Post: Muestra los paises de un grupo ordenados por puntaje obtenido en la fase.
*/
void mostrar_grupo(Equipos* equipos, const std::string &grupo);

/*
Pre: -
Post: Muestra los paises de todos los grupos ordenados por puntaje obtenido en la fase.
*/
void mostrar_grupos_por_puntaje(Equipos* equipos);

/*
Pre: -
Post: Muestra los paises que participaron de la fase indicada ordenados por puntaje obtenido en dicha fase.
*/
void mostrar_fase_por_puntaje(Equipos* equipos, const std::string &nombreFase);

/*
Pre: -
Post: Muestra el puntaje de todos los paises que participaron en fases eliminatorias.
*/
void mostrar_eliminatorias_por_puntaje(Equipos* equipos);

#endif // MOSTRAR_EN_CONSOLA_H