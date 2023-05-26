#include "../headers/clasePartidoConPenales.h"

using namespace std;

PartidoConPenales::PartidoConPenales(string pais1, int goles1, int penales1, string pais2, int goles2, int penales2) : Partido(pais1, goles1, pais2, goles2){
    this->penales1 = penales1;
    this->penales2 = penales2;
};

