//
// Created by barro on 2022-12-08.
//

#include "Organism.h"
#include "City.h"

Organism::Organism()
{
    city = NULL;
    moved = false;
    breedTicks = 0;
    x=0;
    y=0;
}

Organism::Organism(City *city, int x, int y)
{
    this->city = city;
    moved = false;
    breedTicks = 0;
    this->x=x;
    this->y=y;
    city->setOrganism(this,x,y);
}

Organism::~Organism()
{

}

bool Organism::validMove(int xPos, int yPos)
{
    if((xPos>=0 && xPos<GRIDSIZE && yPos>=0 && yPos<GRIDSIZE) && (city->grid[xPos][yPos] == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Organism::move()
{

    //	0 = up
    //	1 = down
    //	2 = left
    //	3 = right
    int direction = rand() % 4;

    switch(direction)
    {
        case 0:
        {
            if (validMove(this->x, (this->y)-1))
            {
                city->setOrganism(NULL,x, y );
                city->setOrganism(this, x, y-1 );
                this->y -= 1;
            }
            break;
        }
        case 1:
        {
            if (validMove(this->x, (this->y)+1))
            {
                city->setOrganism(NULL,x, y );
                city->setOrganism( this,x, y+1);
                this->y += 1;
            }
            break;
        }
        case 2:
        {
            if (validMove((this->x)-1, this->y))
            {
                city->setOrganism(NULL,x, y );
                city->setOrganism( this,x-1, y);
                this->x -= 1;
            }
            break;
        }
        case 3:
        {
            if (validMove((this->x)+1, this->y))
            {
                city->setOrganism(NULL,x, y );
                city->setOrganism(this,x+1, y );
                this->x += 1;
            }
            break;
        }

        default:
            break;
    }
}