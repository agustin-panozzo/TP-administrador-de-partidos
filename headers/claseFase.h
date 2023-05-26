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
        Fase(const std::string &nombreFase);

        std::string obtener_nombre();

        int obtener_puntaje();

        void agregar_partido(Partido* &partido);

        std::vector<Partido**> obtener_partidos();

        void nombre_pais1();
        
        ~Fase() = default;
};

#endif // CLASE_FASE_H