#include "../headers/procesadoDeArchivos.h"

using namespace std;

void cargar_archivo_equipos(Equipos* equipos) {
    string linea;

    ifstream archivo(ARCHIVO_EQUIPOS);

    if(archivo.is_open()) {
        while(getline(archivo, linea)){

            Pais* nuevoPais = procesar_linea_equipos(linea);
            equipos->insertar_por_alfabeto(nuevoPais);
            equipos->agregar_grupo(nuevoPais->obtener_grupo());
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
            cout << "Se creo un nuevo pais en la direccion: " << nuevoPais << endl;
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

// Si es la fase de grupos, agrego los penales como -1. Esto es para dar consistencia a la estructura del vector y no se tiene en cuenta a la hora de guardar los datos.    
    if(comparar_strings(fase, "GRUPOS")){ 
        lineaProcesada.insert(lineaProcesada.begin() + PENALES_1, "-1");
        lineaProcesada.insert(lineaProcesada.begin() + PENALES_2, "-1");
    }

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

string formatear_partido(vector<string> &datosPartido, const string &nombreFase){
    string partidoFormateado;

    for(size_t i = 0; i < datosPartido.size(); i++){

        if( !(comparar_strings("GRUPOS", nombreFase) && datosPartido[i] == "-1") ){
            partidoFormateado += datosPartido[i];

            if( (i != datosPartido.size() - 1 && !(comparar_strings("GRUPOS", nombreFase) && i == datosPartido.size() - 2)) ){
                partidoFormateado += ',';
            }
        }
    }

    return partidoFormateado;
}

void exportar_partidos(Equipos* equipos){
    string linea, fase;
    vector<string> datosPartido;
    vector<Partido*> partidosExportados;
    ofstream archivo("../PRUEBAS.csv", ios::trunc);

    if(archivo.is_open()){
        for(int i = 0; i < CANTIDAD_FASES; i++){
            partidosExportados.clear();
            fase = FASES[i];
            archivo << fase << endl;

            for(int i = 1; i <= equipos->obtener_tamanio(); i++){

                Fase* faseActual = equipos->obtener_dato(i)->obtener_fase(fase);

                if(faseActual != nullptr){
                    vector<Partido*> partidos = equipos->obtener_dato(i)->obtener_fase(fase)->obtener_partidos();
                    cout << i << endl;
                    for(size_t i = 0; i < partidos.size(); i++){

                        if(!partido_esta_en_vector(partidos[i], partidosExportados)){
                            partidosExportados.push_back(partidos[i]);
                            datosPartido = partidos[i]->exportar_partido();

                            archivo << formatear_partido(datosPartido, fase) << endl;
                        }
                    }
                }
            }
        }
    }

    else{
        cout << "No se pudo abrir el archivo" << endl;
    }
}