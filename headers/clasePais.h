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

        /*
        Pre: -
        Post: Devuelve true si la fase se encuentra en el vector fases, false en caso contrario.
        */
        bool tiene_fase(const std::string &fase);

        /*
        Pre: El partido no debe estar empatado.
        Post: Asigna un titulo al pais.
        */
        void asignar_titulo(Partido* partido, const std::string &nombreFase);

        /*
        Pre: -
        Post: Devuelve la fase en su equivalencia numérica. Si la fase no es válida, devuelve -1.
        */
        size_t fase_a_entero(Fase* fase);

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

        /*
        Pre: -
        Post: Devuelve el titulo del pais.
        */
        const std::string obtener_titulo();

        /*
        Pre: -
        Post: Actualiza las fases con los datos proporcionados por el archivo.
        */
        void actualizar_fase(const std::string &fase, Partido* &partido);

        /*
        Pre: -
        Post: Devuelve un puntero a la fase indica, si no existe, devuelve nullptr.
        */
        Fase* obtener_fase(const std::string &fase);

        /*
        Pre: -
        Post: Verifica si el pais tiene la fase, si no la tiene la agrega.
        */
        void verificar_fase(const std::string &fase);

        /*
        Pre: -
        Post: Agrega la fase al pais.
        */
        void agregar_fase(Fase* fase);

        /*
        Pre: -
        Post: Devuelve el puntaje total del pais en el torneo.
        */
        int obtener_puntaje_total();

        /*
        Pre: -
        Post: Devuelve un puntero a la ultima fase que jugó el pais. Si no jugó ninguna, devuelve nullptr.
        */
        Fase* obtener_ultima_fase();

        /*
        Pre: El país debe de haber jugado la fase.
        Post: Devuelve el puntaje obtenido en la fase indicada.
        */
        int obtener_puntaje_fase(const std::string &nombreFase);

        /*
        Pre: -
        Post: Devuelve true si el pais jugó en la fase indicada. En caso contrario, devuelve false.
        */
        bool jugo_en_fase(const std::string &fase);

        ~Pais();
};

#endif // CLASE_PAIS_H