//
// Created by oreste on 11/11/22.
//

#include "Jeu.h"


void Jeu::bouger(Participant& p,Directions& direction){
    switch (direction) {
        case (SUD):
            // p.setPosition(plateau.jouable(p.getPosition());
            break;
        case(EST):
            break;
        case(OUEST):
            break;
        case (NORD):
            break;
        case(NORD_EST):
            break;
        case(NORD_OUEST):
            break;
        case (SUD_EST):
            break;
        case(SUD_OUEST):
            break;
        default:
            break;
    }
}
/*
void Jeu::jouer(){
    afficher();
}

Jeu::Jeu(const Joueur &joueur, const Plateau &plateau) : joueur(joueur), plateau(plateau) {}
void Jeu::afficher()const{
    for(int x=0;x<plateau.getGrille().size();x++){
        for(int y=0;y<plateau.getLargeur();y++){
            std::cout<<plateau.getGrille()[x][y].getType()<<"\t";
        }std::cout<<std::endl;
    }
}
void Jeu::MAJ(){
    //plateau.fixerCase(joueur.getPosition(),joueur.getChar());
}


char getChar(const unsigned int& val){
    switch (val) {
        case 0:
            //Joueur
            return 'J';
        case 1:
            //Jaguar
            return 'G';
        case 2:
            //piège
            return 'P';
        case 3:
            //Obstacle
            return '0';
        case 4:
            //vide
            return 'V';
        default:
            return 'V';
    }
}*/