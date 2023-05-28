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

    cout << "Seleccione una opción: ";
    cin >> opcion;
    
    return opcion;
}

void Menu::ejecutarAccion(const int &opcionElegida){
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
            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
            
        default:
            cout << "Opción inválida" << endl;
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