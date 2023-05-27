#ifndef CLASE_FASE_H
#define CLASE_FASE_H

#include <iostream>
#include <vector>
#include "clasePartido.h"

class Fase {
    private:
        int puntajeFase;
        std::string nombreFase, nombrePais; //nombrePais lo uso para el calculo del puntaje en cada partido
        std::vector<Partido**> partidos;

    public:
        explicit Fase(const std::string nombreFase, const std::string nombrePais);

        /*
        Pre: -
        Post: Devuelve el nombre de la fase.
        */
        std::string obtener_nombre();

        /*
        Pre: -
        Post: Devuelve el puntaje de la fase.
        */
        int obtener_puntaje();

        /*
        Pre: -
        Post: Agrega un partido a la fase.
        */
        void agregar_partido(Partido* &partido);

        /*
        Pre: -
        Post: Devuelve un vector con los partidos de la fase.
        */
        std::vector<Partido**> obtener_partidos();

        void calcular_puntaje_fase();
        
        ~Fase() = default;
};

#endif // CLASE_FASE_H