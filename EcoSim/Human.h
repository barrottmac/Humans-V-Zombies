//
// Created by barro on 2022-12-08.
//

#ifndef ASSIGNMENT4_ECOSIM_HUMAN_H
#define ASSIGNMENT4_ECOSIM_HUMAN_H


#include "Organism.h"
#include "City.h"

class Human : public Organism
{
public:
    Human();
    Human(City *city, int x, int y );
    virtual ~Human();
    virtual void breed();
    virtual bool starve();



};


#endif //ASSIGNMENT4_ECOSIM_HUMAN_H
