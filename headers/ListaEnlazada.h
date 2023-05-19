#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
#include "nodo.h"

template <typename Tipo>
    class ListaEnlazada {
        protected:
            Nodo<Tipo>* primero;
            int tamanio;

            Nodo<Tipo>* obtener_nodo(int posicion);

        public:
            ListaEnlazada();
            
            /*
            Pre: Posicion debe ser mayor a cero y menor o igual al tamaño de la lista. Si la lista está vacía,
            se debe insertar el primer elemento en la posición 1.
            Post: Inserta el elemento en la posicion indicada.
            */
            void insertar(Tipo elemento, int posicion);

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
            Tipo obtener_dato(int posicion);

            /*
            Pre: -
            Post: Devuelve el tamaño de la lista.
            */
            int obtener_tamanio();

            ~ListaEnlazada();
    };

template <typename Tipo>
Nodo<Tipo>* ListaEnlazada<Tipo>::obtener_nodo(int posicion){
    Nodo<Tipo>* aux = primero;
    for(int i = 1; i < posicion; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
};

template <typename Tipo>
ListaEnlazada<Tipo>::ListaEnlazada(){
    this->primero = nullptr;
    this->tamanio = 0;
};

template <typename Tipo>
void ListaEnlazada<Tipo>::insertar(Tipo elemento, int posicion){
    Nodo<Tipo>* aux = new Nodo<Tipo>(elemento);

    if(posicion == 1) {
        aux->modificar_siguiente(primero);
        primero = aux;
    }
    else {
        Nodo<Tipo>* anterior = obtener_nodo(posicion - 1);
        aux->modificar_siguiente(anterior->obtener_siguiente());
        anterior->modificar_siguiente(aux);
    }
    tamanio++;
};

template <typename Tipo>
void ListaEnlazada<Tipo>::eliminar(int posicion){
    Nodo<Tipo>* aux = primero;

    if(posicion == 1) {
        primero = aux->obtener_siguiente();
    }
    else{
        Nodo<Tipo>* anterior = obtener_nodo(posicion - 1);
        aux = anterior->obtener_siguiente();
        anterior->modificar_siguiente(aux->obtener_siguiente());
    }
    delete aux;
    tamanio--;
    };

template <typename Tipo>
bool ListaEnlazada<Tipo>::estaVacia(){
    return (tamanio == 0);
};

template <typename Tipo>
Tipo ListaEnlazada<Tipo>::obtener_dato(int posicion){
    Nodo<Tipo>* aux = obtener_nodo(posicion);
    return (aux->obtener_elemento());
};

template <typename Tipo>
int ListaEnlazada<Tipo>::obtener_tamanio(){
    return tamanio;
};

template <typename Tipo>
void ListaEnlazada<Tipo>::mostrar_elementos(){
    for(int i = 1; i <= this->tamanio; i++){
        std::cout << this->obtener_dato(i) << std::endl;
    }
}

template <typename Tipo>
ListaEnlazada<Tipo>::~ListaEnlazada(){
    while(!estaVacia()){
        eliminar(1);
    }
};

#endif // LISTA_ENLAZADA_H