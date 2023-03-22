//
// Created by barro on 2022-12-08.
//

#include "Human.h"
#include "Organism.h"
#include "City.h"


Human::Human() {
    this->type="H";
}

Human::Human(City *city, int x, int y): Organism(city, x, y) {

    this->type="H";

}
Human::~Human()
{

}

bool Human::starve()
{
    return false;
}

void Human::breed()
{
    if(((this->breedTicks) % 3 == 0 ) &&
       (validMove(x-1,y) || validMove(x+1,y)	||
        validMove(x,y-1) || validMove(x,y+1)))
    {
        bool successful = false;
        while (!successful)
        {
            int place = rand() % 4;
            switch(place)
            {
                case 0:
                {
                    if(validMove(x-1,y))
                    {
                        Human *h = new Human(city,x-1,y);
                    }
                    successful = true;
                    break;
                }
                case 1:
                {
                    if(validMove(x+1,y))
                    {
                        Human *a1 = new Human(city,x+1,y);
                    }
                    successful = true;
                    break;
                }
                case 2:
                {
                    if(validMove(x,y+1))
                    {
                        Human *a1 = new Human(city,x,y+1);
                    }
                    successful = true;
                    break;
                }
                case 3:
                {
                    if(validMove(x,y-1))
                    {
                        Human *a1 = new Human(city,x,y-1);
                    }
                    successful = true;
                    break;
                }
            }
        }
    }

    (this->breedTicks)++;
}






// MOVE. For every time step, the humans randomly try to move (aka run screaming) up,
//down, left, or right. If the neighboring cell in the selected direction is occupied or would
//        move the human out of the city (i.e. off the grid), then the human stays in the current cell.
