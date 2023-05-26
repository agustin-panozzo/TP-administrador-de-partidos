#ifndef GENERAR_OBJETOS_H
#define GENERAR_OBJETOS_H

#include <vector>
#include "clasePartidoConPenales.h"
#include "clasePartidoSinPenales.h"
#include "validaciones.h"
#include "constantes.h"

Partido* generar_partido(std::vector<std::string> &lineaProcesada, const std::string &nombreFase);

#endif // GENERAR_OBJETOS_H