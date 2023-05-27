#ifndef NODO_H
#define NODO_H

template <typename Tipo>
    class Nodo {
        public:
        Tipo elemento;
        Nodo<Tipo>* siguiente;

        explicit Nodo(Tipo elemento);

        /*
        Pre: -
        Post: Devuelve el elemento del nodo.
        */
        Tipo obtener_elemento();
        
        /*
        Pre: -
        Post: Devuelve el nodo siguiente.
        */
        Nodo<Tipo>* obtener_siguiente();

        /*
        Pre: -
        Post: Modifica el nodo siguiente.
        */
        void modificar_siguiente(Nodo<Tipo>* nuevoNodo);

        ~Nodo() = default;

    };

template <typename Tipo>
Nodo<Tipo>::Nodo(Tipo elemento) {
    this->elemento = elemento;
    this->siguiente = nullptr;
};

template <typename Tipo>
Tipo Nodo<Tipo>::obtener_elemento(){
    return elemento;
};

template <typename Tipo>
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente(){
    return siguiente;
};

template <typename Tipo>
void Nodo<Tipo>::modificar_siguiente(Nodo<Tipo>* nuevoNodo){
    siguiente = nuevoNodo;
};

#endif // NODO_H