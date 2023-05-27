#ifndef CLASE_PARTIDO_CON_PENALES_H
#define CLASE_PARTIDO_CON_PENALES_H

#include "clasePartido.h"

class PartidoConPenales : public Partido {
    private:
        int penales1, penales2;

    public:
        explicit PartidoConPenales(std::string pais1, int goles1, int penales1, std::string pais2, int goles2, int penales2);

        std::string obtener_ganador() override;

        int obtener_puntaje(const std::string &nombrePais) override;

        ~PartidoConPenales() = default;
};

#endif // CLASE_PARTIDO_CON_PENALES_H