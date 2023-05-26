#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "claseEquipos.h"
#include <cstdlib> //Lo uso para limpiar la consola
class Menu {
    private:
        Equipos* equipos;
        
        void mostrar();
        
        int elegir_opcion();
        
        void ejecutarAccion(const int &opcionElegida);
                
    public:
        Menu(Equipos* equipos);

        void abrir();

        ~Menu() = default;
    };

#endif // MENU_H