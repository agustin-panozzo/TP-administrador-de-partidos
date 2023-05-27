#ifndef CLASE_PARTIDO_SIN_PENALES_H
#define CLASE_PARTIDO_SIN_PENALES_H

#include "clasePartido.h"

class PartidoSinPenales : public Partido {
    public:
        explicit PartidoSinPenales(std::string pais1, int goles1, std::string pais2, int goles2);

        ~PartidoSinPenales() = default;
};

#endif // CLASE_PARTIDO_SIN_PENALES_H