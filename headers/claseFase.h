#ifndef CLASE_FASE_H
#define CLASE_FASE_H

#include <iostream>
#include <vector>
#include "clasePartido.h"
#include "constantes.h"

class Fase {
    private:
        int puntajeFase;
        std::string nombreFase, nombrePais; //nombrePais lo uso para el calculo del puntaje en cada partido
        std::vector<Partido**> partidos;

    public:
        explicit Fase(const std::string nombreFase, const std::string nombrePais);

        /*
        Pre: -
        Post: Devuelve el nombre de la fase.
        */
        std::string obtener_nombre();

        /*
        Pre: -
        Post: Devuelve el puntaje de la fase.
        */
        int obtener_puntaje();

        /*
        Pre: -
        Post: Agrega un partido a la fase.
        */
        void agregar_partido(Partido* &partido);

        /*
        Pre: -
        Post: Devuelve un vector con los partidos de la fase.
        */
        std::vector<Partido**> obtener_partidos();

        /*
        Pre: -
        Post: Calcula el puntaje de la fase y lo actualiza.
        */
        void calcular_puntaje_fase();

        /*
        Pre: -
        Post: Devuelve un puntero al partido buscado. Si no existe, devuelve nullptr.
        */
        Partido* obtener_partido(const std::string &nombrePais1, const std::string &nombrePais2);

        /*
        Pre: - 
        Post: Elimina el partido de la fase.
        */
        void eliminar_partido(const std::string &nombrePais1, const std::string &nombrePais2);

        /*
        Pre: -
        Post: Elimina de la lista los punteros que apuntan a partidos ya eliminados (nullptr).
        */
        void limpiar_partidos();
        
        /*
        Pre: -
        Post: Devuelve true si la fase no contiene partidos. False en caso contrario.
        */
        bool esta_vacia();

        ~Fase() = default;
};

#endif // CLASE_FASE_H