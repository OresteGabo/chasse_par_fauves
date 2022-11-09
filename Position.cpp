//
// Created by oreste on 09/11/22.
//

#include "Position.h"
#include <iostream>

/**
 *  Le constructeur par défaut (0,0)
 */
Position::Position():Position{0,0}{}

/**
 * Constructeur d'affectation pour d_x,et d_y avec tous la meme valeur
 * @param[in] xy la valeur
 */
Position::Position(unsigned int xy):Position{xy,xy}{}

/**
 * Constructeur d'affectation pour d_x,et d_y
 * @param[in] x la valeur de d_x
 * @param[in] y la valeur de d_y
 */
Position::Position(unsigned int x, unsigned int y):
        d_x{x},
        d_y{y}
{

}
/**
 * @return la valeur de d_x
 */
unsigned int Position::x()const
{
    return d_x;
}
/**
 * @return la valeur de d_y
 */
unsigned int Position::y()const
{
    return d_y;
}

/**
 * Modifieur de d_x
 * @param[in] x La valeur
 */
void Position::x(unsigned int x)
{
    d_x=x;
}

/**
 * Modifieur de d_y
 * @param[in] y La valeur
 */
void Position::y(unsigned int y)
{
    d_y=y;
}

/**
 * Operateur d'affectation
 * @param[in] p la nouvelle position
 * @return le référance du nouvelle position
 */
Position& Position::operator=(const Position& p){
    if (this != &p) {
        d_x=p.d_x;
        d_y=p.d_y;
    }
    return *this;
}

/**
 * Operateur d'égalité
 * @param[in] p la position pour effectuer la comparaison
 * @return vrai si les valeurs des 2 positions sont égaux, ou identiques
 */
bool Position::operator==(const Position& p)const{
    if(this != &p){
        return p.d_x==this->d_x && p.d_y== this->d_y;
    }
    return true;
}

