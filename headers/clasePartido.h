#ifndef CLASE_PARTIDO_H
#define CLASE_PARTIDO_H

#include <iostream>

class Partido {
    protected:
        std::string pais1, pais2;
        int goles1, goles2;
        
    public:
        explicit Partido(std::string pais1, int goles1, std::string pais2, int goles2);

        std::string obtener_datos();

        ~Partido() = default;
};

#endif // CLASE_PARTIDO_H