#ifndef CLASE_PARTIDO_SIN_PENALES_H
#define CLASE_PARTIDO_SIN_PENALES_H

#include "clasePartido.h"

class PartidoSinPenales : public Partido {
    public:
        PartidoSinPenales(std::string pais1, int goles1, std::string pais2, int goles2);

        std::string determinar_ganador() override;

        std::string determinar_perdedor() override;
        
        void mostrar_resultados() override;

        int calcular_puntaje(std::string &pais) override;

        std::string exportar_partido() override;

        ~PartidoSinPenales() = default;
};

#endif // CLASE_PARTIDO_SIN_PENALES_H