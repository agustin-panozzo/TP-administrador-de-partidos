#ifndef CLASE_SUBMENU_H
#define CLASE_SUBMENU_H

#include "claseMenuModificarPartidos.h"

class SubmenuMundial : public Menu {
    private:
        Equipos* equipos;
        MenuModificarPartidos menuModificarPartidos;

        void ejecutar_accion(const int &opcionElegida) override;

    public:
        SubmenuMundial();
        explicit SubmenuMundial(Equipos* equipos, const int cantidadOpciones, const std::string opciones[]);

        void abrir() override;

        ~SubmenuMundial() = default;
};

#endif // CLASE_SUBMENU_H