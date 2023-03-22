//
// Created by barro on 2022-12-08.
//

#ifndef ASSIGNMENT4_ECOSIM_ORGANISM_H
#define ASSIGNMENT4_ECOSIM_ORGANISM_H


#include <iostream>
#include "GameSpecs.h"
#include "City.h"

using namespace std;



class Organism
{
    friend class City;
protected:

    int width;
    int height;
    City *city;
    int breedTicks;



public:
    Organism();
    Organism( City *city, int width, int height );
    virtual ~Organism();
    virtual bool validMove(int xPos, int yPos);
    bool moved;
    int x;
    int y;
    virtual void move();
    virtual bool starve() = 0;
    virtual void breed() = 0;
    string type;
};


#endif //ASSIGNMENT4_ECOSIM_ORGANISM_H
