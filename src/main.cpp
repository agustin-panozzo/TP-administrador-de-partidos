#include <iostream>
#include "../headers/procesadoDeArchivos.h"
#include "../headers/claseMenu.h"

using namespace std;

int main() {
    Equipos equipos;
    Menu menu(&equipos);

    cargar_archivo_equipos(&equipos);
    cargar_archivo_resultados(&equipos);

    menu.abrir();

    return 0;
}
