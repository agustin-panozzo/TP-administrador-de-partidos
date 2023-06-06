#ifndef ACTUALIZAR_PARTIDOS_H
#define ACTUALIZAR_PARTIDOS_H

#include "claseEquipos.h"

/*
Pre: -
Post: Elimina los punteros a los partidos de la fase indicada por el usuario.
*/
void eliminar_partidos(Equipos* equipos);

/*
Pre: -
Post: Modifica los datos de los partidos con los inputs del usuario.
*/
void modificar_partidos(Equipos* equipos);

#endif // ACTUALIZAR_PARTIDOS_H