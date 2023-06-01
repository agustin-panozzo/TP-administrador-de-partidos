#include "../headers/claseEquipos.h"

using namespace std;

Equipos::Equipos() : ListaEnlazada<Pais*>() {
    this->primero = nullptr;
    this->tamanio = 0;
};

void Equipos::insertar_por_alfabeto(Pais* pais) {
    int indice = 1;
    string nombrePaisActual;
    string nombrePais = pais->obtener_nombre();
    Nodo<Pais*>* nodoActual = primero;
    bool posicionEncontrada = false;

    while (nodoActual != nullptr && !posicionEncontrada) {
        nombrePaisActual = nodoActual->obtener_elemento()->obtener_nombre();

        if (nombrePais > nombrePaisActual) {
            indice++;
        }

        else{
            posicionEncontrada = true;
        }

        nodoActual = nodoActual->obtener_siguiente();
    }

    insertar(pais, indice);
}


void Equipos::insertar_por_puntaje_fase(Pais* pais, const string &fase) {
    int indice = 1;
    int puntajePaisActual;
    int puntajePais = pais->obtener_puntaje_fase(fase);
    Nodo<Pais*>* nodoActual = primero;
    bool posicionEncontrada = false;

    while (nodoActual != nullptr && !posicionEncontrada) {
        puntajePaisActual = nodoActual->obtener_elemento()->obtener_puntaje_fase(fase);

        if (puntajePais < puntajePaisActual) {
            indice++;
        }
        
        else{
            posicionEncontrada = true;
        }

        nodoActual = nodoActual->obtener_siguiente();
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

bool Equipos::existe_grupo(const string &grupo){
    bool grupoEncontrado = false;
    size_t indice = 0;

    while(indice < grupos.size() && !grupoEncontrado){
        if(comparar_strings(grupos[indice], grupo)){
            grupoEncontrado = true;
        }

        indice++;
    }

    return grupoEncontrado;
}

void Equipos::agregar_grupo(const string &grupo){
    if(!existe_grupo(grupo)){
        insertar_en_vector_ordenado(grupos, grupo);
    }
}

vector<string> Equipos::obtener_grupos(){
    return grupos;
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