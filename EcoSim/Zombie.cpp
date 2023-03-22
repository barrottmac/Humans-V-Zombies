//
// Created by barro on 2022-12-08.
//

#include "Zombie.h"
#include "City.h"
#include "GameSpecs.h"

Zombie::Zombie() {
    type="Z";
    starvation = 0;
}

Zombie::Zombie(City *city, int x, int y) : Organism(city, x, y)
{
    type="Z";
    starvation = 0;
}

Zombie::~Zombie(){}



void Zombie::breed()
{
    if(((this->breedTicks) % ZOMBIE_BREED == 0 ) &&
       (validMove(x-1,y) || validMove(x+1,y) ||
        validMove(x,y-1) || validMove(x,y+1)))
    {
        bool successful = false;
        while (!successful)
        {
            int spot = rand() % 4;
            switch(spot)
            {
                case 0:
                {
                    if(validMove(x-1,y))
                    {
                        Zombie *z1 = new Zombie(city,x-1,y);
                    }
                    successful = true;
                    break;
                }
                case 1:
                {
                    if(validMove(x+1,y))
                    {
                        Zombie *z1 = new Zombie(city,x+1,y);
                    }
                    successful = true;
                    break;
                }
                case 2:
                {
                    if(validMove(x,y+1))
                    {
                        Zombie *z1 = new Zombie(city,x,y+1);
                    }
                    successful = true;
                    break;
                }
                case 3:
                {
                    if(validMove(x,y-1))
                    {
                        Zombie *z1 = new Zombie(city,x,y-1);
                    }
                    successful = true;
                    break;
                }
            }
        }
    }
}

bool Zombie::starve()
{
    if(this->starvation == 3)
        return true;
    else
        return false;
}

void Zombie::move()
{
    int randInt= rand()%8;
    //West Move
    if(city->getOrganism(x-1, y) != NULL && (city->getOrganism(x-1,y))->type == "H" && randInt==0)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x-1, y );
        this->x -= 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //East Move
    else if(city->getOrganism(x+1, y) != NULL && (city->getOrganism(x+1,y))->type == "H" && randInt==1)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x+1, y );
        this->x += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //South Move
    else if(city->getOrganism(x, y-1) != NULL && (city->getOrganism(x,y-1))->type == "H" && randInt==2)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x, y-1 );
        this->y -= 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //North Move
    else if(city->getOrganism(x, y+1) != NULL && (city->getOrganism(x,y+1))->type == "H" && randInt==3)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x, y+1 );
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //NorthEast Move
    else if(city->getOrganism(x+1, y+1) != NULL && (city->getOrganism(x+1,y+1))->type == "H" && randInt==4)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x+1, y+1 );
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //SouthEast Move
    else if(city->getOrganism(x+1, y-1) != NULL && (city->getOrganism(x+1,y-1))->type == "H" && randInt==5)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x+1, y-1 );
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //SouthWest Move
    else if(city->getOrganism(x-1, y-1) != NULL && (city->getOrganism(x-1,y-1))->type == "H" && randInt==6)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x-1, y-1 );
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    //NorthEast Move
    else if(city->getOrganism(x-1, y+1) != NULL && (city->getOrganism(x-1,y+1))->type == "H" && randInt==7)
    {
        city->setOrganism(NULL,x, y );
        city->setOrganism(this,x-1, y+1 );
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    else
    {

        this->starvation++;

    }
}
