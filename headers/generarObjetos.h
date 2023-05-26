#ifndef GENERAR_OBJETOS_H
#define GENERAR_OBJETOS_H

#include <vector>
#include "clasePartidoConPenales.h"
#include "clasePartidoSinPenales.h"
#include "validaciones.h"
#include "constantes.h"

/*
Pre: -
Post: Genera un partido a partir de los datos proporcionados por el archivo y devuelve el puntero.
*/
Partido* generar_partido(std::vector<std::string> &lineaProcesada, const std::string &nombreFase);

#endif // GENERAR_OBJETOS_H