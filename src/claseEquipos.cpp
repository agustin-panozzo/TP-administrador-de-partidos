#include "../headers/claseEquipos.h"

using namespace std;

Equipos::Equipos() : ListaEnlazada<Pais>() {
    this->primero = nullptr;
    this->tamanio = 0;
};

void Equipos::insertar_por_alfabeto(Pais pais){
    int indice = 1;
    bool posicionEncontrada = false;
    Nodo<Pais>* nodoActual = primero;
    string nombrePais = pais.obtener_nombre();

    if(nodoActual != nullptr){
        string nombrePaisActual = nodoActual->obtener_elemento().obtener_nombre();

        if(nombrePais > nombrePaisActual){
            indice = 2; // Comienzo a comparar desde el segundo elemento

            while(nodoActual->obtener_siguiente() != nullptr && posicionEncontrada == false){
                string nombrePaisSiguiente = nodoActual->obtener_siguiente()->obtener_elemento().obtener_nombre();

                if(nombrePaisSiguiente < nombrePais){
                    nodoActual = nodoActual->obtener_siguiente();
                    indice++;
                }

                else{
                    posicionEncontrada = true;
                }
            }
        }
    }

    insertar(pais, indice);
}


void Equipos::mostrar_paises(){
    Pais paisActual;
    cout << "\n  =  =  =  LISTA DE PAISES  =  =  =  " << endl;

    for(int i = 1; i <= tamanio; i++){
        
        paisActual = obtener_dato(i);
        cout << "Nombre: " << paisActual.obtener_nombre() << " Grupo: " << paisActual.obtener_grupo() << endl;
    }

    cout << endl;
}