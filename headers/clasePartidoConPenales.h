#ifndef CLASE_PARTIDO_CON_PENALES_H
#define CLASE_PARTIDO_CON_PENALES_H

#include "clasePartido.h"

class PartidoConPenales : public Partido {
    private:
        int penales1, penales2;

    public:
        PartidoConPenales(std::string pais1, int goles1, int penales1, std::string pais2, int goles2, int penales2);
        
        /*
        Pre: -
        Post: Modifica los penales de uno de los paises que conforman el partido.
        */
        void modificar_penales(std::string &pais, int &penales);
        
        std::string determinar_ganador() override;

        std::string determinar_perdedor() override;
        
        void mostrar_resultados() override;

        int calcular_puntaje(std::string &pais) override;

        std::string exportar_partido() override;

        ~PartidoConPenales() = default;

};

#endif // CLASE_PARTIDO_CON_PENALES_H