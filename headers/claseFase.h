#ifndef CLASE_FASE_H
#define CLASE_FASE_H

#include <iostream>
#include <vector>
#include "clasePartido.h"

class Fase {
    protected:
        int puntajeFase;
        std::string nombreFase;
        std::vector<Partido*> partidos;

    public:
        Fase(std::string nombreFase);
        
        /*
        Pre: -
        Post: Devuelve el nombre de la fase.
        */
        std::string obtener_nombre();

        void eliminar_partido(std::string &nombrePais1, std::string &nombrePais2);

        /*
        Pre: -
        Post: Actualiza el puntaje total obtenido en la fase.
        */
        void calcular_puntaje(std::string &pais);

        /*
        Pre: -
        Post: Agrega un puntero a partido a la fase.
        */
        void agregar_partido(Partido* partido);

        /*
        Pre: -
        Post: Devuelve el puntaje total obtenido en la fase.
        */
        int obtener_puntaje();

        /*
        Pre: -
        Post: Devuelve un puntero a partido que coincida con los nombres de los paises ingresados.
        */
        Partido* obtener_partido(std::string &nombrePais1, std::string &nombrePais2);
        
        /*
        Pre: -
        Post: Devuelve un vector con los punteros a partidos de la fase.
        */
        std::vector<Partido*> obtener_partidos();

        ~Fase();
};

#endif // CLASE_FASE_H