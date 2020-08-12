#include "usb.h"

USB::USB(Base *b_usb)
{
    base2 =  b_usb;
    init();
}

void USB::init()
{
    char data[1024] = {100,2,3,4,5,6,7,8,9,10};
    base2->ProcessTaskUSB(data, 10);
}
