#include "../headers/procesadoDeArchivos.h"

using namespace std;

void cargar_archivo_equipos(Equipos* equipos) {
    string linea;

    ifstream archivo(ARCHIVO_EQUIPOS);

    if(archivo.is_open()) {
        while(getline(archivo, linea)){

            Pais nuevoPais = procesar_linea_equipos(linea);
            equipos->insertar_por_alfabeto(nuevoPais);
        }
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }

    archivo.close();
}

bool verificar_datos_equipo(vector<string> &datosEquipo){
    bool datosValidos = true;

    if(datosEquipo.size() != 2 || datosEquipo[NOMBRE] == "" || datosEquipo[GRUPO] == ""){
        datosValidos = false;
    }

    return datosValidos;
}

Pais procesar_linea_equipos(const string& linea){
    vector<string> datosEquipo;
    string dato;
    Pais nuevoPais;

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
            nuevoPais = Pais(datosEquipo[NOMBRE], datosEquipo[GRUPO]);
        }
    }

    return nuevoPais;
}

/*void procesar_resultados(const string &linea, const int &fase, Equipos &equipos){
    vector<string> lineaProcesada; //equipo1,goles1,penales1,equipo2,goles2,penales2
    string palabra;

    for (char c : linea){
        if (c != ','){
            palabra += c;
        }

        else if(palabra == "-1"){
            palabra = "";
        }
        
        else {
            lineaProcesada.push_back(palabra);
            palabra = "";
        }
    }

    if(palabra != "-1"){
        lineaProcesada.push_back(palabra); //Agrego la ultima palabra
    }

    equipos.actualizar_datos(lineaProcesada, fase);
}

void cargar_archivo_resultados(Equipos &equipos){
    string linea;
    int fase;
    ifstream archivo(ARCHIVO_RESULTADOS);
    while(getline(archivo, linea)){

        if(verificar_fase(linea)){
            fase = linea_a_fase(linea);
        }
        else{
            procesar_resultados(linea, fase, equipos);
        }   
    }

    archivo.close();
}*/