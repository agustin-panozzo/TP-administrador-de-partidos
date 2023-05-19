#ifndef CLASE_PAIS_H
#define CLASE_PAIS_H

#include <iostream>
#include <vector>
#include "claseFase.h"

class Pais {
    private:
        std::string nombre;
        std::string grupo;
        std::vector<Fase*> fases;
        std::string titulo;
        int puntajeTotal;

    public:
        Pais(std::string &nombre, std::string &grupo);

        /*
        Pre: -
        Post: Devuelve el nombre del pais.
        */
        std::string obtener_nombre();

        /*
        Pre: -
        Post: Devuelve el grupo del pais.
        */
        std::string obtener_grupo();

        /*
        Pre: -
        Post: Devuelve un vector de punteros a fases en las que participó el pais.
        */
        std::vector<Fase*> obtener_fases();

        /*
        Pre: -
        Post: Devuelve el titulo del pais.
        */
        std::string obtener_titulo();

        /*
        Pre: titulo debe ser un valor entre 0 y 3.
        Post: Modifica el titulo del país.
        */
        void otorgar_titulo(const int &titulo);

        /*
        Pre: -
        Post: Devuelve un puntero a la fase con el nombre pasado por parametro. Si no lo encuentra, devuelve nullptr.
        */
        Fase* obtener_fase(const std::string &nombreFase);

        /*
        Pre: -
        Post: Agrega una fase al vector de fases del pais.
        Nota*: La fase se instancia en el heap, por lo que debe ser eliminado en el destructor de pais.
        */
        void agregar_fase(std::string &nombreFase);

        void eliminar_titulo();

        /*
        Pre: -
        Post: Actualiza el puntaje total del pais.
        */
        void actualizar_puntaje();

        /*
        Pre: -
        Post: Devuelve el puntaje total del pais.
        */
        int obtener_puntaje();

        /*
        Pre: -
        Post: Devuelve el nombre de la ultima fase en la que participó el pais.
        */
        std::string obtener_ultima_fase();
        
        /*
        Pre: -
        Post: Elimina las fases que no contiene partidos.
        */
        void limpiar_fases();

        ~Pais();
};

#endif // CLASE_PAIS_H