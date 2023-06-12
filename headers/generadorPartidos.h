#ifndef GENERARADOR_PARTIDOS_H
#define GENERADOR_PARTIDOS_H

#include <vector>
#include "clasePartidoConPenales.h"
#include "validaciones.h"
#include "constantes.h"

/*
Pre: -
Post: Genera un partido a partir de los datos proporcionados por el archivo y devuelve el puntero.
*/
Partido* generar_partido(std::vector<std::string> &lineaProcesada, const std::string &nombreFase);

#endif // GENERAR_OBJETOS_H