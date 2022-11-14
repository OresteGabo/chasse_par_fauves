//
// Created by oreste on 09/11/22.
//

#ifndef CHASSE_PAR_FAUVES_PLATEAU_H
#define CHASSE_PAR_FAUVES_PLATEAU_H

#include <vector>
#include <iostream>
#include <ostream>
#include "Position.h"
#include "Participant.h"

using std::vector;
using std::ostream;
class Plateau {
//private:
    /*const unsigned int d_largeur;
    const unsigned int d_longeur;
    Occupant** grille;
    void initialiser();*/
//public:
    //Plateau(unsigned int dLargeur, unsigned int dLongeur, const Grille &grille);
    //Plateau(const Position&, const Grille &grille);
    /*Plateau(unsigned int dLargeur, unsigned int dLongeur, Occupant **grille);*/

    const Occupant& evalCase(const Position & p)const;
    void fixerCase( const Position & p, const Occupant &valeur);
    bool valide(const Position&)const;
    bool jouable(const Position&)const;
    Position position_joueur;
    void MAJ();

private:
    //nombre ligne
    unsigned int d_nl;

    //nombre colonne
    unsigned int d_nc;

    // Le tableau contigu
    unsigned int *grille;
// Le tableau de pointeurs sur les « lignes »
    unsigned int **d_tab;
    unsigned int& operator()(unsigned int l, unsigned int c);
public:
    //movements
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    Plateau(unsigned int nl,unsigned int nc);
public:
    // Constructeurs et destructeur
    Plateau();
    Plateau(unsigned int);

    ~Plateau();
    Plateau(const Plateau& t);
// Pour modifier ses éléments avec l’opérateur []
    unsigned int* operator[](unsigned int l);
// Pour accéder à ses éléments avec l’opérateur []
    const unsigned int* operator[](unsigned int l) const;
// Une autre façon de modifier et lire ses éléments.

    unsigned int operator()(unsigned int l, unsigned int c) const;

// Pour dupliquer un autre tableau
    Plateau& operator=(const Plateau& t) ;
// Pour connaître ses dimensions
    unsigned int get_nl() const; unsigned int get_nc() const;
// Pour afficher son contenu
    friend ostream& operator<<(ostream& os,const Plateau& t);
    void afficher()const;

    static char getChar( unsigned int);

    void bouger(const Directions& direction);
};


#endif //CHASSE_PAR_FAUVES_PLATEAU_H
