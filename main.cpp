#include <iostream>
#include <unordered_map>
#include "Plateau.h"
#include "Position.h"
#include "Jeu.h"
#include "Lion.h"
#include "Jaguar.h"
#include "Obstacle.h"
#include "Vide.h"
#include "Piege.h"
#include <time.h>
using namespace std;





Occupant** getRandomOccupants(unsigned int nl,unsigned int nc){
    OccupantPtr *grille=new OccupantPtr [nl*nc];
    srand (time(NULL));
    for(int x=0;x<nl*nc;x++){
        //random number between 1 and 5
        int rd = rand() % 50 + 1;
        if(rd==1 ){
            grille[x]=new Lion();
        }else if(rd==2){
            grille[x]=new Obstacle();
        }else if(rd==3){
            grille[x]=new Piege();
        }else{
            grille[x]=new Vide();
        }
    }
    return grille;
}




int main() {
    Joueur joueur=Joueur();
    //Lion* lion=new Lion(Position(2,2));

    Plateau plateau= Plateau(25,getRandomOccupants(25,25));
    Jeu *jeu=new Jeu(joueur,plateau);
    jeu->lancer();

    //p(2,4)=JAGUAR;
    //cout<<endl<<p;
    /*Position ps=Position (5);
    Joueur joueur=Joueur();
    Jeu jeu=Jeu(joueur,p);
    jeu.jouer();

   p.fixerCase(ps,joueur);*/
    //p.afficher();
    //jeu->lancer();
    std::cout<<"Hello jam"<<std::endl;
//
  //  delete jeu;

    return 0;
}