#ifndef CLASE_EQUIPOS_H
#define CLASE_EQUIPOS_H

#include "ListaEnlazada.h"
#include "clasePais.h"
#include "constantes.h"
#include "manejoDeStrings.h"
class Equipos : ListaEnlazada<Pais*>{
    private:
        std::vector<Partido*> partidos;

    public:
        Equipos();

        /*
        Pre: - 
        Post: Inserta el puntero en la lista de paises ordenado por el nombre del pais.
        */
        void insertar_por_alfabeto(Pais* pais);

        /*
        Pre: -
        Post: Muestra por pantalla los paises de la lista.
        */
        void mostrar_paises();

        Pais* obtener_pais(std::string &nombrePais);

        void actualizar_fases(std::vector<std::string> &lineaProcesada, const std::string &fase);

        ~Equipos();
};

#endif // CLASE_EQUIPOS_H