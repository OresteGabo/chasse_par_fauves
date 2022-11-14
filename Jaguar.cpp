//
// Created by oreste on 11/11/22.
//

#include "Jaguar.h"

Jaguar::Jaguar(unsigned int vie, int puissanceAttaque) : Enemie(vie, puissanceAttaque) {}

void Jaguar::bouger(const Position &position) {

}

unsigned int Jaguar::getType() const {
    return JAGUAR;
}
