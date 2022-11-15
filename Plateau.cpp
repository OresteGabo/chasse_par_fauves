//
// Created by oreste on 09/11/22.
//


#include <cassert>
#include "Plateau.h"
#include "Vide.h"
#include "Joueur.h"
#include "Lion.h"
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
Plateau::Plateau(unsigned int lc,OccupantPtr *occupants):
    Plateau(lc,lc,occupants){}
Plateau::Plateau( OccupantPtr* occupants):
    Plateau(TAILLE_MIN,TAILLE_MIN,occupants)
{}
Plateau::Plateau(unsigned int nl, unsigned int nc,OccupantPtr *occupants):
    d_nl{nl},d_nc{nc},
    position_joueur{Position(0,0)},
    //occupants(occupants),
    d_tab{new OccupantPtr *[d_nl]},
    grille{new OccupantPtr [d_nl*d_nc]},joueur{new Joueur()}
{
    for(int i = 0; i < d_nl; i++) {
        ///TODO CORRECTION NEEDED
        d_tab[i] = (OccupantPtr *) new Vide();
    }

    for(int x = 0; x < d_nl*d_nc; x++) {
        if (x == 0) {
            grille[x] = new Joueur();
            position_joueur = Position(0, 0);
        } else {
            grille[x] = occupants[x];
        }
    }

    //for(int x=0;x<occupants.size();x++){
        //Position pos=occupants[x]->position();
        //grilleOc[d_nc*pos.l()+pos.c()]=occupants[x]->getType();
    //}
}
Plateau::Plateau(const Plateau &t) :
    d_nl(t.d_nl),
    d_nc(t.d_nc),
    //grille(new unsigned int[d_nl*d_nc]),
    //d_tab(new unsigned int*[d_nl]),
    d_tab(new OccupantPtr * [d_nl]),
    grille(new OccupantPtr[d_nl*d_nc])
{
    for(unsigned int l = 0; l < d_nl; l++) {
        //d_tab[l] = grille+l*d_nc;
        d_tab[l] = grille+l*d_nc;
    }
    for(unsigned int i = 0; i < d_nl*d_nc; i++){
        //grille[i] = t.grille[i];
        grille[i]=t.grille[i];
    }
    //grilleOc.resize(t.occupants.size());
   // for(int x=0;x<t.occupants.size();x++){
       // occupants[x]=new Participant(t.occupants[x].position());
    ///}
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
            delete[] d_tab; d_tab = new OccupantPtr*[d_nl];
            for(int l = 0; l < d_nl; l++){
                d_tab[l] = grille+l*d_nc;
            }

        } else {
            delete[] grille; // Libération de la mémoire
            delete[] d_tab;
            d_nc = t.d_nc; // Les dimensions sont
            d_nl = t.d_nl; // les mêmes
            grille = new OccupantPtr[d_nl*d_nc]; // Nouvelles allocations
            d_tab = new OccupantPtr*[d_nl];
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


OccupantPtr* Plateau::operator[](unsigned int l) {
    return d_tab[l];
}
const OccupantPtr* Plateau::operator[](unsigned int l) const {
    return d_tab[l];
}
OccupantPtr& Plateau::operator()(unsigned int l, unsigned int c) {
    return grille[l*d_nc+c];
}
OccupantPtr Plateau::operator()(unsigned int l, unsigned int c) const {
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
            return 'G';
        case 4:
            //PIEGE
            return 'P';
        case 5:
            //OBSTACLE
            return 'J';
        case 6:
            //JOUEUR
            return 'O';
        default:
            return 'V';
    }
}
ostream& operator<<(ostream& os, const Plateau& t) {
    int k = 0;
    for(int i = 0; i < t.d_nl; i++) {
        for(int j = 0; j < t.d_nc; j++)
            // L’accès se fait par un simple indice
            os << Plateau::getChar(t.grille[k++]->getType() )<< "\t";
        os << std::endl;
    }
    return os;
}
void Plateau::afficher()const{
    int k = 0;
    for(int i = 0; i < d_nl; i++) {
        for(int j = 0; j < d_nc; j++)
            // L’accès se fait par un simple indice
            std::cout << getChar(grille[k++]->getType()) << "\t";
        std::cout << std::endl;
    }
}
void Plateau::MAJ(){
    //grilleOc[position_joueur.c()*position_joueur.l()+position_joueur.c()]=JOUEUR;
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
        //Position nextPos=Position(position_joueur.l()-1,position_joueur.c());
        //Occupant* p=fight();
        //Occupant *oc=grilleOc[position_joueur];
        grille[(position_joueur.l()-1)*d_nc+position_joueur.c()]=joueur;
        grille[inter.l()*d_nc+ inter.c()]=new Vide();
        position_joueur.l(position_joueur.l()-1);
    }
}

///DONE
void Plateau::moveDown(){
    if(position_joueur.l()<d_nl-1){
        Position inter=position_joueur;
        Position nextPos=Position(position_joueur.l()+1,position_joueur.c());
        grille[(position_joueur.l()+1)*d_nc+position_joueur.c()]=joueur;
        grille[inter.l()*d_nc+ inter.c()]=new Vide();
        position_joueur.l(position_joueur.l()+1);

    }
}
///DONE
void Plateau::moveLeft(){
    if(position_joueur.c()>0){
        Position inter=position_joueur;
        Position nextPos=Position(position_joueur.l(),position_joueur.c()-1);
        grille[position_joueur.l()*d_nc+position_joueur.c()-1]=joueur;
        grille[inter.l()*d_nc+ inter.c()]=new Vide();
        position_joueur.c(position_joueur.c()-1);
    }
}

///DONE
void Plateau::moveRight(){
    if(position_joueur.c()<d_nc-1){
        Position inter=position_joueur;
        Position nextPos=Position(position_joueur.l(),position_joueur.c()+1);
        grille[position_joueur.l()*d_nc+position_joueur.c()+1]=joueur;
        grille[inter.l()*d_nc+ inter.c()]=new Vide();
        position_joueur.c(position_joueur.c()+1);
    }
}


Occupant& Plateau::fight(Participant& p1,Participant& p2){

    if(p1.getVie()>p2.getVie()){
        p1.setVie(p1.getVie()-p2.getVie());
        return p1;
    }else if(p1.getVie()>p2.getVie()){
        p2.setVie(p2.getVie()-p1.getVie());
        return p2;
    }
    p1.setVie(0);p2.setVie(0);
    return p1;
}

