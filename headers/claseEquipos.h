#ifndef CLASE_EQUIPOS_H
#define CLASE_EQUIPOS_H

#include "ListaEnlazada.h"
#include "clasePais.h"
#include "constantes.h"
#include "manejoDeStrings.h"
#include "ordenamiento.h"
class Equipos : public ListaEnlazada<Pais*>{
    public:
        std::vector<Partido*> partidos; // Acá almaceno todos los partidos jugados durante el mundial. 
        std::vector<std::string> grupos; // Los grupos se insertan en orden alfabético.

        /*
        Pre: -
        Post: Devuelve true si el grupo ya existe en el vector de grupos. False en caso contrario.
        */
        bool existe_grupo(const std::string &grupo);

    public:
        Equipos();

        /*
        Pre: - 
        Post: Inserta el pais ordenado por el nombre del pais.
        */
        void insertar_por_alfabeto(Pais* pais);

        /*
        Pre: El pais debe de haber jugado en la fase indicada.
        Post: Inserta el pais ordenado por el puntaje obtenido en la fase, en orden descendiente.
        */
        void insertar_por_puntaje_fase(Pais* pais, const std::string &fase);

        /*
        Pre: -
        Post: Devuelve un puntero al país indicado. Si no existe, devuelve nullptr.
        */
        Pais* obtener_pais(const std::string &nombrePais);

        /*
        Pre: -
        Post: Actualiza los datos de las fases de los paises que participaron del partido.
        */
        void actualizar_fases(std::vector<std::string> &lineaProcesada, const std::string &fase);

        /*
        Pre: -
        Post: Agrega el grupo al vector de grupos. Si el grupo ya existe, no lo agrega.
        */
        void agregar_grupo(const std::string &grupo);

        /*
        Pre: -
        Post: Devuelve un vector con los nombres de los grupos.
        */
        std::vector<std::string> obtener_grupos();

        /*
        Pre: -
        Post: Devuelve true si el partido existe. False en caso contrario.
        */
        bool existe_partido(const std::string &nombreFase, Pais* pais1, Pais* pais2);

        /*
        Pre: El partido debe de existir.
        Post: Elimina el partido de la lista de partidos y actualiza las fases de los paises que participaron del partido.
        */
        void eliminar_partido(const std::string &nombreFase, Pais* pais1, Pais* pais2);

        /*
        Pre: -
        Post: Elimina los punteros que apuntan a nullptr dentro de la lista de partidos.
        */
        void actualizar_lista_partidos();

        /*
        Pre: La fase debe existir.
        Post: Si la fase no tiene partidos, la elimina de la lista de fases del pais.
        */
        void actualizar_fase(Pais* pais, Fase* fase);

        ~Equipos();
};

#endif // CLASE_EQUIPOS_H