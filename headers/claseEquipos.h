#ifndef CLASE_EQUIPOS_H
#define CLASE_EQUIPOS_H

#include "ListaEnlazada.h"
#include "clasePais.h"

class Equipos : ListaEnlazada<Pais>{
    public:
        Equipos();

        /*
        Pre: - 
        Post: Inserta el puntero en la lista de paises ordenado por el nombre del pais.
        */
        void insertar_por_alfabeto(Pais pais);

        /*
        Pre: -
        Post: Muestra por pantalla los paises de la lista.
        */
        void mostrar_paises();
};

#endif // CLASE_EQUIPOS_H