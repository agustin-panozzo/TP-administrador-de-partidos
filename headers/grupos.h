#ifndef GRUPOS_H
#define GRUPOS_H

#include <iostream>
#include "claseEquipos.h"

/*
Pre: -
Post: Inserta los paises de la primer lista dentro de la segunda, ordenados por puntaje obtenido en la fase de grupos y
que pertenezcan al grupo indicado.
*/
void insertar_grupo(Equipos* equipos, Equipos* equiposPorGrupo, const std::string &grupo);

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

/*
Pre: -
Post: Inserta los paises de la primer lista dentro de la segunda que hayan jugado en la fase indicada 
y ordenados por puntaje obtenido en dicha fase.
*/
void insertar_fase(Equipos* equipos, Equipos* equiposPorPuntaje, const std::string &nombreFase);

#endif // GRUPOS_H