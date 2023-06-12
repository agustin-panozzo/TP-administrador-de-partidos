#include "../headers/claseMenuMundial.h"

using namespace std;

MenuMundial::MenuMundial(Equipos* equipos, const int cantidadOpciones, const std::string opcionesMenu[]) : Menu(cantidadOpciones, opcionesMenu) {
    this->equipos = equipos;
    this->submenu = SubmenuMundial(equipos, CANTIDAD_OPCIONES_SUBMENU, SUBMENU);
}

void MenuMundial::ejecutar_accion(const int &opcionElegida){
    //limpiar_pantalla();

    switch(opcionElegida) {
        case 1:
            mostrar_paises(equipos);
            break;

        case 2:
            mostrar_top3(equipos);
            break;

        case 3:
            buscar_pais(equipos);
            break;

        case 4:
            mostrar_por_fase(equipos);
            break;

        case 5:
            submenu.abrir();
            break;
            
        case 6:
            cout << "Saliendo del programa..." << endl;
            exportar_partidos(equipos);
            break;
            
        default:
            cout << "Opción inválida" << endl;
            break;
    }
}