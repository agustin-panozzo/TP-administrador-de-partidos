#ifndef CLASE_EQUIPOS_H
#define CLASE_EQUIPOS_H

#include "ListaEnlazada.h"
#include "clasePais.h"
#include "constantes.h"
#include "manejoDeStrings.h"
class Equipos : public ListaEnlazada<Pais*>{
    private:
        std::vector<Partido*> partidos; // Acá almaceno todos los partidos jugados durante el mundial. 

    public:
        Equipos();

        /*
        Pre: - 
        Post: Inserta el puntero en la lista de paises ordenado por el nombre del pais.
        */
        void insertar_por_alfabeto(Pais* pais);

        /*
        Pre: -
        Post: Devuelve un puntero al país indicado. Si no existe, devuelve nullptr.
        */
        Pais* obtener_pais(std::string &nombrePais);

        /*
        Pre: -
        Post: Actualiza los datos de las fases de los paises que participaron del partido.
        */
        void actualizar_fases(std::vector<std::string> &lineaProcesada, const std::string &fase);

        ~Equipos();
};

#endif // CLASE_EQUIPOS_H