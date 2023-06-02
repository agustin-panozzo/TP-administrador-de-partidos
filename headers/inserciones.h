#ifndef INSERCIONES_H
#define INSERCIONES_H

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
Post: Inserta los paises de la primer lista dentro de la segunda que hayan jugado en la fase indicada 
y ordenados por puntaje obtenido en dicha fase.
*/
void insertar_fase(Equipos* equipos, Equipos* equiposPorPuntaje, const std::string &nombreFase);

#endif // INSERCIONES_H