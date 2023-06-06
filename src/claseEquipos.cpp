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

Pais* Equipos::obtener_pais(const string &nombrePais){
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

bool Equipos::existe_partido(const string &nombreFase, const string &nombrePais1, const string &nombrePais2){
    bool partidoEncontrado = false;

    Fase* fasePais1 = obtener_pais(nombrePais1)->obtener_fase(nombreFase);
    Fase* fasePais2 = obtener_pais(nombrePais2)->obtener_fase(nombreFase);
    if(fasePais1 != nullptr && fasePais2 != nullptr){

        if(fasePais1->obtener_partido(nombrePais1, nombrePais2) != nullptr && fasePais2->obtener_partido(nombrePais1, nombrePais2) != nullptr){
            partidoEncontrado = true;
        }
    }

    return partidoEncontrado;
}

void Equipos::actualizar_lista_partidos(){
    for(size_t i = 0; i < partidos.size(); i++){
        if(partidos[i] == nullptr){
            partidos.erase(partidos.begin() + i);
        }
    }
}

void Equipos::actualizar_fase(Pais* pais, Fase* fase){
    fase->limpiar_partidos();

    if(fase->esta_vacia()){
        if(comparar_strings(fase->obtener_nombre(), "SEMIFINAL") || comparar_strings(fase->obtener_nombre(), "TERCER PUESTO") || comparar_strings(fase->obtener_nombre(), "FINAL")){
            pais->eliminar_titulo();
        }

        pais->eliminar_fase(fase);
    }
}

void Equipos::eliminar_partido(const string &nombreFase, Pais* pais1, Pais* pais2){
    Fase* fasePais1 = pais1->obtener_fase(nombreFase);
    Fase* fasePais2 = pais2->obtener_fase(nombreFase);

    fasePais1->eliminar_partido(pais1->obtener_nombre(), pais2->obtener_nombre());
    fasePais2->eliminar_partido(pais1->obtener_nombre(), pais2->obtener_nombre());

    actualizar_lista_partidos();
    actualizar_fase(pais1, fasePais1);
    actualizar_fase(pais2, fasePais2);
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