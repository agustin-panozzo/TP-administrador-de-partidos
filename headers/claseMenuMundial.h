#ifndef CLASE_MENU_MUNDIAL_H
#define CLASE_MENU_MUNDIAL_H

#include <iostream>
#include "claseMenu.h"
#include "claseSubmenuMundial.h"
#include "procesadoDeArchivos.h"

class MenuMundial : public Menu {
    private:
        Equipos* equipos;
        SubmenuMundial submenu;

        void ejecutar_accion(const int &opcionElegida) override;

    public:
        explicit MenuMundial(Equipos* equipos, const int cantidadOpciones, const std::string opcionesMenu[]);

        ~MenuMundial() = default;
};

#endif // CLASE_MENU_MUNDIAL_H