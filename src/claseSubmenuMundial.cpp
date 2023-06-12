#include "../headers/claseSubMenuMundial.h"

using namespace std;

SubmenuMundial::SubmenuMundial() : Menu() {
    this->equipos = nullptr;
    this->menuModificarPartidos = MenuModificarPartidos();
}

SubmenuMundial::SubmenuMundial(Equipos* equipos, const int cantidadOpciones, const string opciones[]) : Menu(cantidadOpciones, opciones) {
    this->equipos = equipos;
    this->menuModificarPartidos = MenuModificarPartidos(equipos, CANTIDAD_OPCIONES_MODIFICAR_PARTIDO, MODIFICAR_PARTIDO);
}

void SubmenuMundial::abrir(){
    int opcionElegida;

    do{
        mostrar();
        cout << ADVERTENCIA_AGREGAR_PARTIDOS << endl;
        opcionElegida = elegir_opcion();
        ejecutar_accion(opcionElegida);

    }while(opcionElegida != cantidadOpciones); // La ultima opción siempre es la de salir
}

void SubmenuMundial::ejecutar_accion(const int &opcionElegida){
    //limpiar_pantalla();

    switch(opcionElegida) {
        case 1:
            agregar_partido(equipos);
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
