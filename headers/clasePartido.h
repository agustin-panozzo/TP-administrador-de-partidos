#ifndef CLASE_PARTIDO_H
#define CLASE_PARTIDO_H

#include <iostream>
#include "manejoDeStrings.h"

class Partido {
    protected:
        std::string pais1, pais2;
        int goles1, goles2;
        
    public:
        explicit Partido(std::string pais1, int goles1, std::string pais2, int goles2);

        /*
        Pre: -
        Post: Devuelve el nombre del pais ganador.
        */
        virtual std::string obtener_ganador();
        
        /*
        Pre: -
        Post: Devuelve los puntos que obtuvo el pais en el partido
        */
        virtual int obtener_puntaje(const std::string &nombrePais);

        virtual ~Partido() = default;
};

#endif // CLASE_PARTIDO_H