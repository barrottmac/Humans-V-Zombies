//
// Created by barro on 2022-12-08.
//

#include "windows.h"
#include "GameSpecs.h"
#include "City.h"
#include "Organism.h"





City::City() {
    int i,j;
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            grid[i][j]=NULL;
        }
    }
}

City::~City()
{
    int i,j;
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if (grid[i][j]!=NULL) delete (grid[i][j]);
        }
    }
}

void City::setOrganism(Organism *organism, int x, int y) {
    if ((x>=0) && (x<GRIDSIZE) && (y>=0) && (y<GRIDSIZE))

    {
        grid[x][y] = organism;
    }
}

Organism* City::getOrganism(int x, int y) {
    if ((x>=0) && (x<GRIDSIZE) && (y>=0) && (y<GRIDSIZE))
        return grid[x][y];
    return NULL;
}

void City::Display()
{

    HANDLE jconsole =GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j;
    int countA=0, countB=0;
    cout << endl << endl;
    for (j=0; j<GRIDSIZE; j++)
    {
        for (i=0; i<GRIDSIZE; i++)
        {
            if (grid[i][j]==NULL){

                cout << SPACE_CH;
            }

            else if (grid[i][j]->type =="H" )
            {

                countA++;
                cout << HUMAN_CH;
            }
            else
            {

                countB++;
                cout << ZOMBIE_CH;
            }
            cout<<"  ";
        }
        cout << endl;
    }
    cout << endl << HUMAN_CH << " = " << countA << "\t  " << ZOMBIE_CH<< " = " << countB;
}

void City::move() {
    int i,j;
    //reset organisms to not moved
    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE;j++)
        {
            if (grid[i][j]!=NULL)
            {
                grid[i][j]->moved = false;
            }
        }
    }

    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->type=="Z"))
            {
                if (grid[i][j]->moved == false)
                {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->type=="H"))
            {
                if (grid[i][j]->moved == false)
                {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->type=="Z"))
            {
                //Setting zombie to a human if they starve
                if (grid[i][j]->starve())
                {
                    (grid[i][j])->type="H";

                }
            }
        }
    }

    for (i=0; i<GRIDSIZE; i++)
    {
        for (j=0; j<GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->moved==true))
            {
                grid[i][j]->breed();
            }
        }
    }
}