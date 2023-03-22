//
// Created by barro on 2022-12-08.
//

#ifndef ASSIGNMENT4_ECOSIM_ZOMBIE_H
#define ASSIGNMENT4_ECOSIM_ZOMBIE_H

#include "Organism.h"
class Zombie : public Organism
{
public:
    Zombie();

    Zombie( City *city, int width, int height );

    virtual ~Zombie();

    virtual void breed();

    virtual bool starve();

    virtual void move();

private:
    int starvation;
};


#endif //ASSIGNMENT4_ECOSIM_ZOMBIE_H
