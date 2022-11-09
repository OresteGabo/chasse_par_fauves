//
// Created by oreste on 09/11/22.
//

#include "Plateau.h"

Plateau::Plateau(unsigned int longeur,unsigned int largeur ):
d_longeur{longeur},
d_largeur{largeur}
{}
Plateau::Plateau(unsigned int l): Plateau(l,l){}

Plateau::Plateau():Plateau{6}{}
