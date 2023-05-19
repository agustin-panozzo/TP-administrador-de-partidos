#include <iostream>
#include "../headers/claseEquipos.h"
#include "../headers/procesadoDeArchivos.h"
#include "../headers/claseMenu.h"

using namespace std;

int main() {
    Equipos equipos;
    Menu menu(&equipos);
    
    cargar_archivo_equipos(&equipos);
    
    menu.abrir();

    return 0;
}
