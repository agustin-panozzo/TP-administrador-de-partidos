#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "claseEquipos.h"
#include "funcionesMenu.h"
class Menu {
    private:
        Equipos* equipos;
        
        /*
        Pre: -
        Post: Muestra el menu por pantalla.
        */
        void mostrar();
        
        /*
        Pre: -
        Post: Devuelve la opcion elegida por el usuario.
        */
        int elegir_opcion();
        
        /*
        Pre: -
        Post: Ejecuta la accion elegida por el usuario.
        */
        void ejecutarAccion(const int &opcionElegida);
                
    public:
        explicit Menu(Equipos* equipos);

        /*
        Pre: -
        Post: Abre el menu y ejecuta las opciones que elige el usuario.
        */
        void abrir();

        ~Menu() = default;
    };

#endif // MENU_H