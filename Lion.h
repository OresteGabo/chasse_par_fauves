//
// Created by oreste on 12/11/22.
//

#ifndef CHASSE_PAR_FAUVES_LION_H
#define CHASSE_PAR_FAUVES_LION_H


#include "Enemie.h"

class Lion: public Enemie {

public:
    Lion(unsigned int vie, int puissanceAttaque);

    void bouger(const Position &position) override;

    unsigned int getType() const override;

};

void Lion::bouger(const Position &position) {

}

unsigned int Lion::getType() const {
    return LION;
}


#endif //CHASSE_PAR_FAUVES_LION_H
