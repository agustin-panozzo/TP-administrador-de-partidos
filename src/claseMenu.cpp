#include "../headers/claseMenu.h"

using namespace std;

Menu::Menu(Equipos* equipos) {
    this->equipos = equipos;
}

void Menu::mostrar() {
    cout << "  =  =  =  M E N U  =  =  =  " << endl;
    cout << "1.Listar equipos." << endl;
    cout << "2.Mostrar los equipos en primer, segundo y tercer lugar." << endl;
    cout << "3.Buscar equipo por nombre." << endl;
    cout << "4.Mostrar por fase los paises ordenados por puntaje" << endl;
    cout << "5.Salir." << endl;
}

int Menu::elegir_opcion() {
    int opcion;

    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    
    return opcion;
}

void Menu::ejecutarAccion(const int &opcionElegida){
    switch(opcionElegida) {
        case 1:
            equipos->mostrar_paises();
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
            
        default:
            std::cout << "Opción inválida" << std::endl;
            break;
    }
}

void Menu::abrir(){
    int opcionElegida;

    do{
        mostrar();
        opcionElegida = elegir_opcion();
        ejecutarAccion(opcionElegida);

    }while(opcionElegida != 5);
}