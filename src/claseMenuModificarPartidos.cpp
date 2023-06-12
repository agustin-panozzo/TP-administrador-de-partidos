#include "../headers/claseMenuModificarPartidos.h"

using namespace std;

MenuModificarPartidos::MenuModificarPartidos() : Menu() {
    this->equipos = nullptr;
}

MenuModificarPartidos::MenuModificarPartidos(Equipos* equipos, const int cantidadOpciones, const string opciones[]) : Menu(cantidadOpciones, opciones) {
    this->equipos = equipos;
}

void MenuModificarPartidos::ejecutar_accion(const int &opcionElegida){
    //limpiar_pantalla();
    string nombreFase, nombrePais1, nombrePais2;

    switch(opcionElegida) {
        case 1:
            solicitar_datos_partido(equipos, nombreFase, nombrePais1, nombrePais2);
            modificar_goles(equipos, nombreFase, nombrePais1, nombrePais2);
            break;

        case 2:
            solicitar_datos_partido(equipos, nombreFase, nombrePais1, nombrePais2);
            modificar_equipos(equipos, nombreFase, nombrePais1, nombrePais2);
            break;
            
        case 3:
            cout << "Volviendo al menu anterior..." << endl;
            break;
            
        default:
            cout << "Opción inválida" << endl;
            break;
    }
}