#include "../headers/claseSubMenuMundial.h"

using namespace std;

SubmenuMundial::SubmenuMundial() : Menu() {
    this->equipos = nullptr;
}

SubmenuMundial::SubmenuMundial(Equipos* equipos, const int cantidadOpciones, const string opciones[]) : Menu(cantidadOpciones, opciones) {
    this->equipos = equipos;
    this->menuModificarPartidos = MenuModificarPartidos(equipos, CANTIDAD_OPCIONES_MODIFICAR_PARTIDO, MODIFICAR_PARTIDO);
}

void SubmenuMundial::ejecutar_accion(const int &opcionElegida){
    //limpiar_pantalla();

    switch(opcionElegida) {
        case 1:
            break;

        case 2:
            menuModificarPartidos.abrir();
            break;

        case 3:
            eliminar_partidos(equipos);
            break;
            
        case 4:
            cout << "Volviendo al menu principal..." << endl;
            break;
            
        default:
            cout << "Opción inválida" << endl;
            break;
    }
}
