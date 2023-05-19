#ifndef NODO_H
#define NODO_H

template <typename Dato>
    class Nodo {
        public:
        Dato elemento;
        Nodo<Dato>* siguiente;

        Nodo(Dato elemento);

        /*
        Pre: -
        Post: Devuelve el elemento del nodo.
        */
        Dato obtener_elemento();
        
        /*
        Pre: -
        Post: Devuelve el nodo siguiente.
        */
        Nodo<Dato>* obtener_siguiente();

        /*
        Pre: -
        Post: Modifica el nodo siguiente.
        */
        void modificar_siguiente(Nodo<Dato>* nuevoNodo);

        ~Nodo(); //Suponiendo que nodo almacene punteros en el heap

    };

template <typename Dato>
Nodo<Dato>::Nodo(Dato elemento) {
    this->elemento = elemento;
    this->siguiente = nullptr;
};

template <typename Dato>
Dato Nodo<Dato>::obtener_elemento(){
    return elemento;
};

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
};

template <typename Dato>
void Nodo<Dato>::modificar_siguiente(Nodo<Dato>* nuevoNodo){
    siguiente = nuevoNodo;
};

template <typename Dato>
Nodo<Dato>::~Nodo(){ 
    delete elemento; //Asumiendo que elemento es un puntero a un objeto instanciado en memoria dinamica
};

#endif // NODO_H