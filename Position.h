//
// Created by oreste on 09/11/22.
//

#ifndef CHASSE_PAR_FAUVES_POSITION_H
#define CHASSE_PAR_FAUVES_POSITION_H


class Position {
private:
    unsigned int d_x;
    unsigned int d_y;

public:
    Position(unsigned int x,unsigned int y);
    Position(unsigned int xy);
    Position();

    unsigned int x()const;
    unsigned int y()const;
    void x(unsigned int x);
    void y(unsigned int y);


};


#endif //CHASSE_PAR_FAUVES_POSITION_H
