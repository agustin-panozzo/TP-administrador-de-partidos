#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "claseEquipos.h"
#include "opcionesMenu.h"
#include "actualizarPartidos.h"
class Menu {
    private:
        int cantidadOpciones;
        std::vector<std::string> opciones;
        
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
        virtual void ejecutar_accion(const int &opcionElegida) = 0;
                
    public:
        // Pre: La ultima opción del vector opciones debe indicar la salida del programa.
        explicit Menu(const int cantidadOpciones, const std::string opciones[]);
        Menu();

        /*
        Pre: -
        Post: Abre el menu y ejecuta las opciones que elige el usuario.
        */
        void abrir();

        ~Menu() = default;
    };

#endif // MENU_H