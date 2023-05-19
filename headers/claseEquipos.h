#ifndef CLASE_EQUIPOS_H
#define CLASE_EQUIPOS_H

#include "ListaEnlazada.h"
#include "clasePais.h"

class Equipos : ListaEnlazada<Pais*>{
    private:
        std::vector<std::string> listaGrupos;

        bool fase_ya_existe(std::string nombreFase, std::vector<Fase*> fase);

        void actualizar_fases(std::string nombrePais, std::vector<Partido*> &partidos, std::string nombreFase);

        void asignar_titulos(Partido* partido, const int &fase);

        bool existe_grupo(std::string grupo);

        void agregar_grupo(std::string grupo);
        
    public:
        Equipos();

        /*
        Pre: - 
        Post: Inserta el puntero en la lista de paises ordenado por el nombre del pais.
        */
        void insertar_por_alfabeto(Pais* pais);

        /*
        Pre: El pais debe haber jugado en la fase indicada.
        Post: Inserta el puntero en la lista de paises ordenado por el puntaje obtenido en la fase.
        */
        void insertar_por_puntaje_fase(Pais* pais, const int &fase);

        /*
        Pre: -
        Post: Devuelve el puntero al pais que coincida con el nombre ingresado.
        */
        Pais* obtener_equipo(const std::string &nombre);

        /*
        Pre: -
        Post: A partir de la linea procesada, se actualiza la fase y partidos del pais
        */
        void actualizar_datos(std::vector<std::string> &lineaProcesada, const int &fase);

        /*
        Pre: -
        Post: Muestra los resultados de todos los partidos jugados.
        */
        void mostrar_partidos();

        /*
        Pre: -
        Post: Devuelve un vector con los nombres de los grupos (sin ordenar).
        */
        std::vector<std::string> obtener_grupos();

        /*
        Pre: El partido debe estar instanciado en el heap.
        Post: Libera la memoria asignada al partido y lo elimina de la lista de partidos.
        */
        void eliminar_partido(Partido* partido);

        int calcular_equipos_por_fase(std::string nombreFase);
        
        ~Equipos();
};

#endif // CLASE_EQUIPOS_H