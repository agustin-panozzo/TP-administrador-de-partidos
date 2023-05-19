#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu {
public:
    Menu();

    void mostrar();
    
    int elegir_opcion();
    
    void ejecutarAccion(const int &opcionSeleccionada);
};

#endif // MENU_H