#include <iostream>
#include <unordered_map>
#include "Plateau.h"
#include "Position.h"
#include "Jeu.h"

using namespace std;



int main() {

    Plateau p=Plateau(5);
    p.afficher();



    //p.moveDown();p.moveDown();
    cout<<endl;
    p.afficher();
    //p(2,4)=JAGUAR;
    //cout<<endl<<p;
    /*Position ps=Position (5);
    Joueur joueur=Joueur();
    Jeu jeu=Jeu(joueur,p);
    jeu.jouer();

   p.fixerCase(ps,joueur);*/
    //p.afficher();
    std::cout<<"Hello jam"<<std::endl;



    return 0;
}

