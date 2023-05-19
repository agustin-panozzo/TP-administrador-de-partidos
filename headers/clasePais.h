#ifndef CLASE_PAIS_H
#define CLASE_PAIS_H

#include <iostream>
#include <vector>
#include "claseFase.h"

class Pais {
    private:
        std::string nombre;
        std::string grupo;
        std::string titulo;
        int puntajeTotal;

    public:
        Pais();
        explicit Pais(const std::string &nombre, const std::string &grupo);

        /*
        Pre: -
        Post: Devuelve el nombre del pais.
        */
        const std::string obtener_nombre();

        /*
        Pre: -
        Post: Devuelve el grupo al que pertenece el pais.
        */
        const std::string obtener_grupo();
};

#endif // CLASE_PAIS_H