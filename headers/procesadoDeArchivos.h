#ifndef PROCESADO_DE_ARCHIVOS_H
#define PROCESADO_DE_ARCHIVOS_H

#include <iostream>
#include <fstream>
#include "validaciones.h"
#include "clasePartidoConPenales.h"
#include "claseEquipos.h"
/*
Pre: -
Post: Carga los datos de los equipos en la clase Equipos a partir del archivo equipos.txt
*/
void cargar_archivo_equipos(Equipos* equipos);

/*
Pre: -
Post: Devuelve una clase pais con los datos cargados.
*/
Pais* procesar_linea_equipos(const std::string& linea);

/*
Pre: -
Post: Carga los datos de los resultados en la clase Equipos a partir del archivo resultados.csv
*/
void cargar_archivo_resultados(Equipos* equipos);

/*
Pre: -
Post: Procesa la línea leída y carga los datos de los resultados en la clase Equipos
*/
void procesar_resultados(const std::string &linea, const std::string &fase, Equipos* equipos);

#endif // PROCESADO_DE_ARCHIVOS_H