#include "../headers/claseEquipos.h"

using namespace std;

Equipos::Equipos() : ListaEnlazada<Pais*>() {
    this->primero = nullptr;
    this->tamanio = 0;
};

void Equipos::insertar_por_alfabeto(Pais* pais){ //Este método se podría hacer con menos anidaciones pero intenté hacerlo lo más legible posible
    int indice = 1;
    bool posicionEncontrada = false;
    Nodo<Pais*>* nodoActual = primero;
    string nombrePais = pais->obtener_nombre();

    if(nodoActual != nullptr){
        string nombrePaisActual = nodoActual->obtener_elemento()->obtener_nombre();

        if(nombrePais > nombrePaisActual){
            indice = 2; // Comienzo a comparar desde el segundo elemento

            while(nodoActual->obtener_siguiente() != nullptr && !posicionEncontrada){
                string nombrePaisSiguiente = nodoActual->obtener_siguiente()->obtener_elemento()->obtener_nombre();

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

Pais* Equipos::obtener_pais(string &nombrePais){
    Nodo<Pais*>* nodoActual = primero;
    Pais* paisBuscado = nullptr;
    Pais* aux = nullptr;
    bool paisEncontrado = false;

    while(nodoActual != nullptr && paisEncontrado == false){
        aux = nodoActual->obtener_elemento();

        if(comparar_strings(aux->obtener_nombre(), nombrePais)){
            paisEncontrado = true;
            paisBuscado = nodoActual->obtener_elemento();
        }

        else{
            nodoActual = nodoActual->obtener_siguiente();
        }
    }

    return paisBuscado;
};

void Equipos::actualizar_fases(vector<string> &lineaProcesada, const string &fase){
    Pais* pais1 = obtener_pais(lineaProcesada[NOMBRE_PAIS_1]);
    Pais* pais2 = obtener_pais(lineaProcesada[NOMBRE_PAIS_2]);
    
    partidos.push_back(generar_partido(lineaProcesada, fase));

    pais1->actualizar_fase(fase, partidos[partidos.size() - 1]);
    pais2->actualizar_fase(fase, partidos[partidos.size() - 1]);
}

Equipos::~Equipos(){
    for(size_t i = 0; i < partidos.size(); i++){
        cout << "Se elimino un partido en: " << partidos[i] << endl;
        delete partidos[i];
        partidos[i] = nullptr;
    }

    for(int i = 1; i <= tamanio; i++){ // Elimino los paises
        delete obtener_dato(i);
        cout << "Se elimino un pais en: " << obtener_dato(i) << endl;
    }
}