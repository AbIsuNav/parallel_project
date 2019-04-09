//
// Created by sliberman on 4/5/19.
//

#ifndef PARALLELGENETIC_COLOUR_H
#define PARALLELGENETIC_COLOUR_H


class Colour {

public:
    Colour(unsigned char r, unsigned char g, unsigned char i, double a);

private:
    unsigned char r, g, b;
    double a;
};


#endif //PARALLELGENETIC_COLOUR_H