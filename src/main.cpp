#include <iostream>
#include "../headers/procesadoDeArchivos.h"
#include "../headers/claseMenuMundial.h"

using namespace std;

int main() {
    Equipos equipos;
    MenuMundial menuMundial(&equipos, CANTIDAD_OPCIONES_MENU, MENU);

    cargar_archivo_equipos(&equipos);
    cargar_archivo_resultados(&equipos);

    menuMundial.abrir();

    return 0;
}
