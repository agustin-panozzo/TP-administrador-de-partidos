#include "../headers/actualizarPartidos.h"

using namespace std;

void solicitar_datos_partido(Equipos* equipos, string &nombreFase, string &nombrePais1, string &nombrePais2){
    do{
        cout << "Ingrese la fase en la que se jugó el partido: " << endl;
        getline(cin >> ws, nombreFase);

        cout << "Ingrese el nombre del primer pais: " << endl;
        getline(cin >> ws, nombrePais1);

        cout << "Ingrese el nombre del segundo pais: " << endl;
        getline(cin >> ws, nombrePais2);

    }while(!es_una_fase(nombreFase) || equipos->obtener_pais(nombrePais1) == nullptr || equipos->obtener_pais(nombrePais2) == nullptr);
}

void solicitar_goles(vector<string> &datosPartido, const string &nombreFase){
    int goles1, goles2;

    do{
        cout << "Ingrese la cantidad de goles de " << datosPartido[NOMBRE_PAIS_1] << ":" << endl;
        cin >> goles1;

        cout << "Ingrese la cantidad de goles de " << datosPartido[NOMBRE_PAIS_2] << ":" << endl;
        cin >> goles2;

    }while(goles1 > 20 || goles2 > 20 || goles1 < 0 || goles2 < 0);

    datosPartido[GOLES_1] = to_string(goles1);
    datosPartido[GOLES_2] = to_string(goles2);

    if(goles1 == goles2 && !comparar_strings(nombreFase, "Grupos")){
        int penales1, penales2;
        cout << "Los equipos están empatados." << endl;

        do{
            cout << "Ingrese la cantidad de penales de " << datosPartido[NOMBRE_PAIS_1] << ":" << endl;
            cin >> penales1;

            cout << "Ingrese la cantidad de penales de " << datosPartido[NOMBRE_PAIS_2] << ":" << endl;
            cin >> penales2;

        }while(penales1 > 20 || penales2 > 20 || penales1 < 0 || penales2 < 0);

        datosPartido[PENALES_1] = to_string(penales1);
        datosPartido[PENALES_2] = to_string(penales2);
    }

    else{
        datosPartido[PENALES_1] = "-1";
        datosPartido[PENALES_2] = "-1";
    }
}

void modificar_goles(Equipos* equipos, string nombreFase, string nombrePais1, string nombrePais2){
    vector<string> datosPartido;
    Pais* pais1 = equipos->obtener_pais(nombrePais1);
    Pais* pais2 = equipos->obtener_pais(nombrePais2);

    if(equipos->existe_partido(nombreFase, pais1, pais2)){
        Partido* partido = pais1->obtener_fase(nombreFase)->obtener_partido(nombrePais1, nombrePais2);
        datosPartido = partido->exportar_partido();
        solicitar_goles(datosPartido, nombreFase);

        equipos->eliminar_partido(nombreFase, pais1, pais2);
        equipos->actualizar_fases(datosPartido, nombreFase);
    }

    else{
        cout << "El partido no existe" << endl;
    }
}

void solicitar_equipos(Equipos* equipos, vector<string> &datosPartido, const string &nombreFase){
    string nombrePais1, nombrePais2;

    do{
        //limpiar_pantalla();
        cout << "=  =  =  NUEVOS DATOS  =  =  =" << endl;
        cout << "Ingrese el nombre del primer pais: " << endl;
        getline(cin >> ws, nombrePais1);

        cout << "Ingrese el nombre del segundo pais: " << endl;
        getline(cin >> ws, nombrePais2);

    }while(equipos->obtener_pais(nombrePais1) == nullptr || equipos->obtener_pais(nombrePais2) == nullptr);

    datosPartido[NOMBRE_PAIS_1] = nombrePais1;
    datosPartido[NOMBRE_PAIS_2] = nombrePais2;
}

void modificar_equipos(Equipos* equipos, string nombreFase, string nombrePais1, string nombrePais2){
    vector<string> datosPartido;
    Pais* pais1 = equipos->obtener_pais(nombrePais1);
    Pais* pais2 = equipos->obtener_pais(nombrePais2);

    if(equipos->existe_partido(nombreFase, pais1, pais2)){
        Partido* partido = pais1->obtener_fase(nombreFase)->obtener_partido(nombrePais1, nombrePais2);
        datosPartido = partido->exportar_partido();
        solicitar_equipos(equipos, datosPartido, nombreFase);

        equipos->eliminar_partido(nombreFase, pais1, pais2);
        equipos->actualizar_fases(datosPartido, nombreFase);
    }

    else{
        cout << "El partido no existe" << endl;
    }
}

void eliminar_partidos(Equipos* equipos){
    string nombreFase, nombrePais1, nombrePais2;

    solicitar_datos_partido(equipos, nombreFase, nombrePais1, nombrePais2);

    Pais* pais1 = equipos->obtener_pais(nombrePais1);
    Pais* pais2 = equipos->obtener_pais(nombrePais2);

    if(equipos->existe_partido(nombreFase, pais1, pais2)){
        equipos->eliminar_partido(nombreFase, pais1, pais2);
    }

    else{
        cout << "El partido no existe" << endl;
    }
    
}

string solicitar_fase(){
    string nombreFase;

    do{
        cout << "Ingrese la fase en la que se jugo el partido: " << endl;
        getline(cin >> ws, nombreFase);

    }while(!es_una_fase(nombreFase));

    return nombreFase;
}

void solicitar_datos_nuevo_partido(Equipos* equipos, vector<string> &datosNuevoPartido){
    string nombreFase = solicitar_fase();

    solicitar_equipos(equipos, datosNuevoPartido, nombreFase);
    solicitar_goles(datosNuevoPartido, nombreFase);

    equipos->actualizar_fases(datosNuevoPartido, nombreFase);
}

void agregar_partido(Equipos* equipos){
    string nombreFase, nombrePais1, nombrePais2;
    vector<string> datosNuevoPartido(6);

    solicitar_datos_nuevo_partido(equipos, datosNuevoPartido);

}