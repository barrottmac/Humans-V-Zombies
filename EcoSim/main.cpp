#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include "City.h"
#include "Human.h"
#include "Zombie.h"
#include "GameSpecs.h"



void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void wait (int seconds);
int main() {
    string s;
    srand(time(NULL));
    City w;
    City *cityPtr;

    cityPtr = &w;

    int humanCount = 0;
    while (humanCount < HUMAN_STARTCOUNT)
    {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if (w.getOrganism(x,y)==NULL)
        {
            humanCount++;
            Human *a1 = new Human(&w,x,y);
        }
    }

    int zombieCount = 0;
    while (zombieCount < ZOMBIE_STARTCOUNT)
    {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if (w.getOrganism(x,y)==NULL)
        {
            zombieCount++;
             Zombie *d1 = new Zombie(&w,x,y);
        }
    }
    chrono::milliseconds interval(1);

    while (s.length() == 0)
    {
        w.Display();
        w.move();
        wait(1);
        cout << endl;
        this_thread::sleep_for(interval);
    }


    w.Display();
    cout << "\nHit any key to exit...";
    getline(cin,s);
    return 0;
}


void wait (int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}//end main
