#include "../headers/procesadoDeArchivos.h"

using namespace std;

void cargar_archivo_equipos(Equipos* equipos) {
    string linea;

    ifstream archivo(ARCHIVO_EQUIPOS);

    if(archivo.is_open()) {
        while(getline(archivo, linea)){

            Pais* nuevoPais = procesar_linea_equipos(linea);
            equipos->insertar_por_alfabeto(nuevoPais);
        }

        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

Pais* procesar_linea_equipos(const string& linea){
    vector<string> datosEquipo;
    string dato;
    Pais* nuevoPais = nullptr;

    if(linea != ""){ // Para evitar lineas vacias

        for(char c : linea){

            if(c == ' '){
                datosEquipo.push_back(dato);
                dato = "";
            }

            else if(c == '_'){
                dato += ' ';
            }

            else{
                dato += c;
            }
        }
        datosEquipo.push_back(dato); //Agrego el último dato

        if(verificar_datos_equipo(datosEquipo)){ //Chequeo que los datos leídos sean válidos
            nuevoPais = new Pais(datosEquipo[NOMBRE], datosEquipo[GRUPO]);
            cout << "Se creó un nuevo país en la dirección: " << nuevoPais << endl;
        }
    }

    return nuevoPais;
}

void procesar_resultados(const string &linea, const string &fase, Equipos* equipos){
    vector<string> lineaProcesada;
    string palabra;

    for (char c : linea){

        if(linea != ""){ // Para evitar lineas vacias

            if (c == ','){
                lineaProcesada.push_back(palabra);
                palabra = "";
            }
            
            else{
                palabra += c;
            }
        }
    }
    lineaProcesada.push_back(palabra); //Agrego la ultima palabra

    if(verificar_datos_resultados(lineaProcesada, fase)){ // Chequeo que los datos leídos sean válidos  
        equipos->actualizar_fases(lineaProcesada, fase);
    }
}

void cargar_archivo_resultados(Equipos* equipos){
    string linea, fase;

    ifstream archivo(ARCHIVO_RESULTADOS);

    if(archivo.is_open()){

        while(getline(archivo, linea)){

            if(es_una_fase(linea)){
                fase = linea;
            }

            else{
                procesar_resultados(linea, fase, equipos);
            }
        }   

        archivo.close();
    }

    else{
        cout << "No se pudo abrir el archivo" << endl;
    }
}