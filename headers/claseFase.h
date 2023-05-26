#ifndef CLASE_FASE_H
#define CLASE_FASE_H

#include <iostream>
#include <vector>
#include "clasePartido.h"

class Fase {
    private:
        int puntajeFase;
        std::string nombreFase;
        std::vector<Partido**> partidos;

    public:
        Fase(const std::string nombreFase);

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
        
        ~Fase() = default;
};

#endif // CLASE_FASE_H