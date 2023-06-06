#ifndef CLASE_SUBMENU_H
#define CLASE_SUBMENU_H

#include "claseMenu.h"
#include "actualizarPartidos.h"

class SubmenuMundial : public Menu {
    private:
        Equipos* equipos;

        void ejecutar_accion(const int &opcionElegida) override;

    public:
        SubmenuMundial();
        explicit SubmenuMundial(Equipos* equipos, const int cantidadOpciones, const std::string opciones[]);

        ~SubmenuMundial() = default;
};

#endif // CLASE_SUBMENU_H