//
// Created by barro on 2022-12-08.
//

#ifndef ASSIGNMENT4_ECOSIM_CITY_H
#define ASSIGNMENT4_ECOSIM_CITY_H


#include <iostream>
#include "GameSpecs.h"

using namespace std;



class City
{
    friend class Organism;
    friend class Zombie;
    friend class Human;

protected:


public:
    City();
    virtual ~City();
    void Display();
    Organism *grid[GRIDSIZE][GRIDSIZE];
    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );

    void move();



};


#endif //ASSIGNMENT4_ECOSIM_CITY_H
