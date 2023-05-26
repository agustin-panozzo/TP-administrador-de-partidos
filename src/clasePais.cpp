#include "../headers/clasePais.h"

using namespace std;

Pais::Pais(){
    this->nombre = "";
    this->grupo = "";
    this->titulo = "";
    this->puntajeTotal = 0;
}

Pais::Pais(const string nombrePais, const string grupo){
    this->nombre = nombrePais;
    this->grupo = grupo;
    this->titulo = "Sin titulo";
    this->puntajeTotal = 0;
}

const string Pais::obtener_nombre(){
    return nombre;
}

const string Pais::obtener_grupo(){
    return grupo;
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
        Fase* nuevaFase = new Fase(fase);
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

void Pais::actualizar_fase(vector<string> &lineaProcesada, const string &nombreFase, Partido* &partido){
    verificar_fase(nombreFase); // Verifico si el pais tiene la fase, si no la tiene la agrega. 
    Fase* fase = obtener_fase(nombreFase);
    fase->agregar_partido(partido);
}

Pais::~Pais(){
    for(size_t i = 0; i < fases.size(); i++){
        cout << "Se borrará una fase en: " << fases[i] << endl;
        delete fases[i];
        cout << "La fase se eliminó correctamente" << endl;
    }
}