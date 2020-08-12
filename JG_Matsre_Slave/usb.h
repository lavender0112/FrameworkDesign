#ifndef USB_H
#define USB_H

#include "base.h"

class USB
{
public:
    USB(Base *b_usb);
    void init();

public:
    Base *base2;
};

#endif // USB_H
