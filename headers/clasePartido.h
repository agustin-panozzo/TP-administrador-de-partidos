#ifndef CLASE_PARTIDO_H
#define CLASE_PARTIDO_H

#include <iostream>

class Partido {
    protected:
        std::string pais1, pais2;
        int goles1, goles2;
        
    public:
        explicit Partido(std::string &pais1, int goles1, std::string &pais2, int goles2);

        /*
        Pre: -
        Post: Modifica el nombre de uno de los paises que conforman el partido.
        */
        void modificar_pais(std::string paisNuevo, std::string paisViejo);

        /*
        Pre: -
        Post: Modifica los goles de uno de los paises que conforman el partido.
        */
        void modificar_goles(std::string pais, int goles);

        bool pais_existe(std::string &nombrePais);

        /*
        Pre: -
        Post: Devuelve el nombre del pais que ganó el partido.
        */
        virtual std::string determinar_ganador() = 0;

        /*
        Pre: -
        Post: Devuelve el nombre del pais que perdió el partido.
        */
        virtual std::string determinar_perdedor() = 0;

        /*
        Pre: -
        Post: Muestra los resultados del partido.
        */
        virtual void mostrar_resultados() = 0;

        /*
        Pre: -
        Post: Devuelve el puntaje que obtuvo el país en el partido.
        */
        virtual int calcular_puntaje(std::string &pais) = 0;

        /*
        Pre: -
        Post: Devuelve un vector con los datos del partido.
        */
        virtual std::string exportar_partido() = 0;

        virtual ~Partido() = default;
};

#endif // CLASE_PARTIDO_H