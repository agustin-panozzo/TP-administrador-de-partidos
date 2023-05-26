#ifndef MANEJO_DE_STRINGS_H
#define MANEJO_DE_STRINGS_H

#include <iostream>

/*
Pre: -
Post: Devuelve la cantidad de caracteres que contiene la cadena.
*/
int calcular_largo_string(const std::string& cadena);

/*
Pre: -
Post: Devuelve true si las dos cadenas son iguales y false en caso contrario.
*/
bool comparar_strings(const std::string& cadena1, const std::string& cadena2);

#endif // MANEJO_DE_STRINGS_H