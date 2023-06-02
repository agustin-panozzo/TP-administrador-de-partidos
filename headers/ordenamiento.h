#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
#include <vector>

/*
Pre: El tipo de dato debe tener definido el operador "<" y además si el vector contiene elementos, éstos deben estar ordenados.
Post: Inserta el elemento dentro del vector ordenado en forma descendente.
*/
template<typename Tipo>
void insertar_en_vector_ordenado(std::vector<Tipo> &vector, const Tipo &elemento){
    size_t indice = 0;
    bool posicionEncontrada = false;

    while(indice < vector.size() && !posicionEncontrada){
        if(elemento < vector[indice]){
            posicionEncontrada = true;
        }

        else{
            indice++;
        }
    }

    vector.insert(vector.begin() + indice, elemento);
}
#endif // ORDENAMIENTO_H