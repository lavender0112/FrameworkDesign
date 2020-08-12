#include <iostream>
#include <unistd.h>

using namespace std;

#include "mainprocess.h"

int main()
{
    cout << "JG Master Slave..." << endl;
    MainProcess *mainP = new MainProcess();
    mainP->MainStartService();

    while(1)
    {
        sleep(1);
    }

    return 0;
}
