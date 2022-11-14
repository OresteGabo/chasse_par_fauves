//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_JEU_H
#define CHASSE_PAR_FAUVES_JEU_H


#include "Joueur.h"
#include "Plateau.h"
//#include "constants.cpp"


class Jeu {
private:
Joueur joueur;
Plateau plateau;
public:
    Jeu(const Joueur &joueur, const Plateau &plateau);

    void bouger(Participant& p,Directions& direction);
    void afficher()const;
    void MAJ();
    void jouer();



};


#endif //CHASSE_PAR_FAUVES_JEU_H
