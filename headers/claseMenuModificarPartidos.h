#ifndef MENU_MODIFICAR_PARTIDOS_H
#define MENU_MODIFICAR_PARTIDOS_H

#include "claseMenu.h"

class MenuModificarPartidos : public Menu {
    private:
        Equipos* equipos;

        void ejecutar_accion(const int &opcionElegida) override;

    public:
        MenuModificarPartidos();
        explicit MenuModificarPartidos(Equipos* equipos, const int cantidadOpciones, const std::string opciones[]);

        ~MenuModificarPartidos() = default;
};

#endif // MENU_MODIFICAR_PARTIDOS_H