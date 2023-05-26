#ifndef CLASE_PAIS_H
#define CLASE_PAIS_H

#include <iostream>
#include <vector>
#include "claseFase.h"
#include "validaciones.h"
#include "clasePartido.h"
#include "generarObjetos.h"
class Pais {
    private:
        std::string nombre;
        std::string grupo;
        std::string titulo;
        std::vector<Fase*> fases;
        int puntajeTotal;

        bool tiene_fase(const std::string &fase);

    public:
        Pais();
        explicit Pais(const std::string nombre, const std::string grupo);

        /*
        Pre: -
        Post: Devuelve el nombre del pais.
        */
        const std::string obtener_nombre();

        /*
        Pre: -
        Post: Devuelve el grupo al que pertenece el pais.
        */
        const std::string obtener_grupo();

        void actualizar_fase(std::vector<std::string> &lineaProcesada, const std::string &fase, Partido* &partido); //Paso el puntero por referencia

        Fase* obtener_fase(const std::string &fase);

        std::vector<Fase*> obtener_fases();

        void verificar_fase(const std::string &fase);

        void agregar_fase(Fase* fase);

        ~Pais();
};

#endif // CLASE_PAIS_H