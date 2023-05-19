#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
#include "nodo.h"

template <typename Dato>
    class ListaEnlazada {
        protected:
            Nodo<Dato>* primero;
            int tamanio;

            Nodo<Dato>* obtener_nodo(int posicion);

        public:
            ListaEnlazada();
            
            /*
            Pre: Posicion debe ser mayor a cero y menor o igual al tamaño de la lista.
            Post: Inserta el elemento en la posicion indicada.
            */
            void insertar(Dato elemento, int posicion);

            /*
            Pre: Posicion debe ser mayor a cero y menor o igual al tamaño de la lista.
            Post: Elimina el elemento en la posicion indicada.
            */
            void eliminar(int posicion);

            /*
            Pre: -
            Post: Muestra por pantalla los elementos de la lista.
            */
            void mostrar_elementos();

            /*
            Pre: -
            Post: Devuelve true si la lista esta vacia, false en caso contrario.
            */
            bool estaVacia();

            /*
            Pre: posicion debe ser mayor a cero y menor o igual al tamaño de la lista.
            Post: Devuelve el elemento en la posicion indicada.
            */
            Dato obtener_dato(int posicion);

            /*
            Pre: -
            Post: Devuelve el tamaño de la lista.
            */
            int obtener_tamanio();

            ~ListaEnlazada();
    };

template <typename Dato>
Nodo<Dato>* ListaEnlazada<Dato>::obtener_nodo(int posicion){
    Nodo<Dato>* aux = primero;
    for(int i = 1; i < posicion; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
};

template <typename Dato>
ListaEnlazada<Dato>::ListaEnlazada(){
    this->primero = nullptr;
    this->tamanio = 0;
};

template <typename Dato>
void ListaEnlazada<Dato>::insertar(Dato elemento, int posicion){
    Nodo<Dato>* aux = new Nodo<Dato>(elemento);

    if(posicion == 1) {
        aux->modificar_siguiente(primero);
        primero = aux;
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(posicion - 1);
        aux->modificar_siguiente(anterior->obtener_siguiente());
        anterior->modificar_siguiente(aux);
    }
    tamanio++;
};

template <typename Dato>
void ListaEnlazada<Dato>::eliminar(int posicion){
    Nodo<Dato>* aux = primero;

    if(posicion == 1) {
        primero = aux->obtener_siguiente();
    }
    else{
        Nodo<Dato>* anterior = obtener_nodo(posicion - 1);
        aux = anterior->obtener_siguiente();
        anterior->modificar_siguiente(aux->obtener_siguiente());
    }
    delete aux;
    tamanio--;
    };

template <typename Dato>
bool ListaEnlazada<Dato>::estaVacia(){
    return (tamanio == 0);
};

template <typename Dato>
Dato ListaEnlazada<Dato>::obtener_dato(int posicion){
    Nodo<Dato>* aux = obtener_nodo(posicion);
    return (aux->obtener_elemento());
};

template <typename Dato>
int ListaEnlazada<Dato>::obtener_tamanio(){
    return tamanio;
};

template <typename Dato>
void ListaEnlazada<Dato>::mostrar_elementos(){
    for(int i = 1; i <= this->tamanio; i++){
        std::cout << *this->obtener_dato(i) << std::endl;
    }
}

template <typename Dato>
ListaEnlazada<Dato>::~ListaEnlazada(){
    while(!estaVacia()){
        eliminar(1);
    }
};

#endif // LISTA_ENLAZADA_H