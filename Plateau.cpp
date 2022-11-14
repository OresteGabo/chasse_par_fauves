//
// Created by oreste on 09/11/22.
//


#include <cassert>
#include "Plateau.h"
#include "Vide.h"
/*
Plateau::Plateau(const unsigned int longeur,const unsigned int largeur ):
d_longeur{longeur<TAILLE_MIN?TAILLE_MIN:longeur},
d_largeur{largeur<TAILLE_MIN?TAILLE_MIN:largeur}
{
    initialiser();
}
Plateau::Plateau(unsigned int l): Plateau(l<6?6:l,l<6?6:l){}

Plateau::Plateau():Plateau{6}{}*/
/*

/**
 * Le pla
 *
void Plateau::initialiser() {
     grille= reinterpret_cast< Occupant **>(new int[d_largeur][d_longeur]);
    for(int x=0;x<d_largeur;x++){
        //grille[x]=new Occupant[d_longeur];
        for(int y=0;y<d_longeur;y++){
            //TODO on doit ajouter des occupants vide initialement
            //grille[x].push_back(Occupant&);
            //grille[x][y]=Occnew Vide();
        }
    }
}


/**
    Accesseur d'une case du plateau
    @param[in] p - un plateau
    @return la valeaur en p de gr
*
const Occupant& Plateau::evalCase(const Position & p)const{
    assert(p.x() > TAILLE_MIN and TAILLE_MIN <= p.y());
    return grille[p.x()][p.y()];
}

/**
    Modifieur d'une case du plateau
    @param[in,out] p - la position
    @param[in] valeur - nouvel occupant

*
void Plateau::fixerCase( const Position & p,  const Occupant& valeur){
    if(p.valide() && jouable(p))
   grille[p.x()][p.y()] = valeur;
}



bool Plateau::jouable(const Position& position)const{
    return true;
    //TODO
    //return valide(position) && evalCase(position).getType() != OBSTACLE ;
}
*/

Plateau::Plateau():
Plateau(0,0)
{}
Plateau::Plateau(unsigned int nl, unsigned int nc):
d_nl{nl},
d_nc{nc},
position_joueur{Position(0,0)},

d_tab{new unsigned int*[d_nl]},
grille{new unsigned int[d_nl*d_nc]}
{
    for(int i = 0; i < d_nl; i++) {
        d_tab[i] = (unsigned int *) VIDE;
    }
    int k = 0;
    for(int l = 0; l < d_nl; l++) {
        for(int c = 0; c < d_nc; c++){
            if(position_joueur.l()==l && position_joueur.c()==c)
                grille[k++]=JOUEUR;
            else
                grille[k++]=CHIEN;
        }
    }
}
Plateau::Plateau(const Plateau &t) :
    d_nl(t.d_nl),
    d_nc(t.d_nc),
    grille(new unsigned int[d_nl*d_nc]),
    d_tab(new unsigned int*[d_nl])
{
    for(unsigned int l = 0; l < d_nl; l++) {
        d_tab[l] = grille+l*d_nc;
    }
    for(unsigned int i = 0; i < d_nl*d_nc; i++){
        grille[i] = t.grille[i];
    }
}


Plateau::Plateau(unsigned int lc):
Plateau(lc,lc)
{

}
Plateau::~Plateau() { delete[] d_tab; delete[] grille; }
// Pour dupliquer un autre tableau
Plateau& Plateau::operator=(const Plateau& t) {

    if (this != &t) {
        if (t.d_nl == d_nl && t.d_nc == d_nc) {
            for(int i = 0; i < d_nl*d_nc; i++){
                grille[i] = t.grille[i];
            }
        } else if (t.d_nl*t.d_nc == d_nl*d_nc) {
            d_nl = t.d_nl; d_nc = t.d_nc;
            for(int i = 0; i < d_nl*d_nc; i++){
                grille[i] = t.grille[i];
            }
            delete[] d_tab; d_tab = new unsigned int*[d_nl];
            for(int l = 0; l < d_nl; l++){
                d_tab[l] = grille+l*d_nc;
            }

        } else {
            delete[] grille; // Libération de la mémoire
            delete[] d_tab;
            d_nc = t.d_nc; // Les dimensions sont
            d_nl = t.d_nl; // les mêmes
            grille = new unsigned int[d_nl*d_nc]; // Nouvelles allocations
            d_tab = new unsigned int*[d_nl];
            for(int i = 0; i < d_nl; i++) {
                d_tab[i] = grille+i*d_nc; // Les départs de lignes
            }// Enfin, la recopie du tableau contigu
            for(int i = 0; i < d_nl*d_nc; i++)
                grille[i] = t.grille[i];
        }
    }
    return *this;
}
// Pour connaître ses dimensions
unsigned int Plateau::get_nl() const{
    return d_nl;
}
unsigned int Plateau::get_nc() const{
    return d_nc;
}
// Pour afficher son contenu
ostream& operator<<(ostream& os,const Plateau& t);


unsigned int* Plateau::operator[](unsigned int l) {
    return d_tab[l];
}
const unsigned int* Plateau::operator[](unsigned int l) const {
    return d_tab[l];
}
unsigned int& Plateau::operator()(unsigned int l, unsigned int c) {
    return grille[l*d_nc+c];
}
unsigned int Plateau::operator()(unsigned int l, unsigned int c) const {
    return grille[l*d_nc+c];
}


char Plateau::getChar(unsigned int val) {

    switch (val) {
        case 0:
            //VIDE
            return '.';
        case 1:
            //LION
            return 'L';
        case 2:
            //piège
            return 'C';
        case 3:
            //JAGUAR
            return 'J';
        case 4:
            //PIEGE
            return 'P';
        case 5:
            //OBSTACLE
            return 'O';
        case 6:
            //JOUEUR
            return 'J';
        default:
            return 'V';
    }
}
ostream& operator<<(ostream& os, const Plateau& t) {
    int k = 0;
    for(int i = 0; i < t.d_nl; i++) {
        for(int j = 0; j < t.d_nc; j++)
            // L’accès se fait par un simple indice
            os << Plateau::getChar(t.grille[k++] )<< "\t";
        os << std::endl;
    }
    return os;
}
void Plateau::afficher()const{
    int k = 0;
    for(int i = 0; i < d_nl; i++) {
        for(int j = 0; j < d_nc; j++)
            // L’accès se fait par un simple indice
            std::cout << getChar(grille[k++]) << "\t";
        std::cout << std::endl;
    }
}
void Plateau::MAJ(){
    grille[position_joueur.c()*position_joueur.l()+position_joueur.c()]=JOUEUR;
}

void Plateau::bouger(const Directions& direction){
    switch (direction) {
        case (SUD):
            moveDown();
            break;
        case(EST):
            moveRight();
            break;
        case(OUEST):
            moveLeft();
            break;
        case (NORD):
            moveUp();
            break;
        case(NORD_EST):
            moveRight();
            moveUp();
            break;
        case(NORD_OUEST):
            moveLeft();
            moveUp();
            break;
        case (SUD_EST):
            moveDown();
            moveRight();
            break;
        case(SUD_OUEST):
            moveLeft();
            moveDown();
            break;
        default:
            break;
    }
}


///DONE
void Plateau::moveUp(){
    if(position_joueur.l()>0){
        Position inter=position_joueur;
        grille[(position_joueur.l()-1)*d_nc+position_joueur.c()]=JOUEUR;
        grille[inter.l()*d_nc+ inter.c()]=VIDE;
        position_joueur.l(position_joueur.l()-1);
    }
}

///DONE
void Plateau::moveDown(){
    if(position_joueur.l()<d_nl-1){
        Position inter=position_joueur;
        grille[(position_joueur.l()+1)*d_nc+position_joueur.c()]=JOUEUR;
        grille[inter.l()*d_nc+ inter.c()]=VIDE;
        position_joueur.l(position_joueur.l()+1);

    }
}
///DONE
void Plateau::moveLeft(){
    if(position_joueur.c()>0){
        Position inter=position_joueur;
        grille[position_joueur.l()*d_nc+position_joueur.c()-1]=JOUEUR;
        grille[inter.l()*d_nc+ inter.c()]=VIDE;
        position_joueur.c(position_joueur.c()-1);
    }
}

///DONE
void Plateau::moveRight(){
    if(position_joueur.c()<d_nc-1){
        Position inter=position_joueur;
        grille[position_joueur.l()*d_nc+position_joueur.c()+1]=JOUEUR;
        grille[inter.l()*d_nc+ inter.c()]=VIDE;
        position_joueur.c(position_joueur.c()+1);
    }
}




