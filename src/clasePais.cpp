#include "../headers/clasePais.h"

using namespace std;

Pais::Pais(){
    this->nombre = "";
    this->grupo = "";
    this->titulo = "";
}

Pais::Pais(const string nombrePais, const string grupo){
    this->nombre = nombrePais;
    this->grupo = grupo;
    this->titulo = "Sin titulo";
}

const string Pais::obtener_nombre(){
    return nombre;
}

const string Pais::obtener_grupo(){
    return grupo;
}

const string Pais::obtener_titulo(){
    return titulo;
}

bool Pais::tiene_fase(const string &fase){
    bool tieneFase = false;
    size_t i = 0;

    while(i < fases.size() && tieneFase == false){
        if(comparar_strings(fases[i]->obtener_nombre(), fase)){
            tieneFase = true;
        }

        i++;
    }

    return tieneFase;
}

void Pais::agregar_fase(Fase* fase){
    fases.push_back(fase);
}

void Pais::verificar_fase(const std::string &fase){
    if(!tiene_fase(fase)){
        Fase* nuevaFase = new Fase(fase, nombre);
        cout << "Se creó una fase con el nombre " << fase << " en: " << nuevaFase << endl;
        agregar_fase(nuevaFase);
    }
}

Fase* Pais::obtener_fase(const std::string &nombreFase){
    Fase* fase = nullptr;

    for(size_t i = 0; i < fases.size(); i++){
        if(comparar_strings(fases[i]->obtener_nombre(), nombreFase)){
            fase = fases[i];
        }
    }

    return fase;
}

void Pais::asignar_titulo(Partido* partido, const string &nombreFase){
    if(comparar_strings(nombreFase, "FINAL")){

        if(comparar_strings(nombre, partido->obtener_ganador())){
            titulo = "CAMPEON";
        }

        else{
            titulo = "SUBCAMPEON";
        }
    }

    else{

        if(comparar_strings(nombre, partido->obtener_ganador())){
            titulo = "TERCER PUESTO";
        }

        else{
            titulo = "CUARTO PUESTO";
        }
    }
}

void Pais::actualizar_fase(const string &nombreFase, Partido* &partido){
    if(comparar_strings(nombreFase, "FINAL") || comparar_strings(nombreFase, "TERCER PUESTO")){
        asignar_titulo(partido, nombreFase);
    };

    verificar_fase(nombreFase); // Verifico si el pais tiene la fase, si no la tiene la agrega. 
    Fase* fase = obtener_fase(nombreFase);
    fase->agregar_partido(partido);
    fase->calcular_puntaje_fase(); // Cada vez que se agrega un partido, debo recalcular el puntaje.
}

int Pais::obtener_puntaje_total(){
    int puntajeTotal = 0;

    for(size_t i = 0; i < fases.size(); i++){
        puntajeTotal += fases[i]->obtener_puntaje();
    }

    return puntajeTotal;
}

Pais::~Pais(){
    for(size_t i = 0; i < fases.size(); i++){
        cout << "Se borrará una fase en: " << fases[i] << endl;
        delete fases[i];
        cout << "La fase se eliminó correctamente" << endl;
    }
}