#include "../headers/claseMenu.h"

using namespace std;

Menu::Menu(){
    this->cantidadOpciones = 0;
}

Menu::Menu(const int cantidadOpciones, const string opciones[]) {
    this->cantidadOpciones = cantidadOpciones;
    
    for(int i = 0; i < cantidadOpciones; i++) {
        this->opciones.push_back(opciones[i]);
    }
}

void Menu::mostrar() {
    cout << "=  =  =  =  =  M E N U  =  =  =  =  =" << endl;
    for(int i = 0; i < cantidadOpciones; i++) {
        cout << (i + 1) << "." << opciones[i] << endl;
    }
}

int Menu::elegir_opcion() {
    int opcion;

    cout << "Seleccione una opcion: ";
    cin >> opcion;
    
    return opcion;
}

void Menu::abrir(){
    int opcionElegida;

    do{
        mostrar();
        opcionElegida = elegir_opcion();
        ejecutar_accion(opcionElegida);

    }while(opcionElegida != cantidadOpciones); // La ultima opción siempre es la de salir
}