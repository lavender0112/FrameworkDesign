#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include "i2c.h"
#include "usb.h"

class MainProcess:public Base,public RingBuffer
{
public:
    MainProcess();

    void MainStartService();

    void ProcessTaskI2C(char *data, int size);
    void ProcessTaskUSB(char *data, int size);

    int HandleMessage(LinkMessage_t *msg);

public:
    I2C *mp_i2c;
    USB *mp_usb;
    LinkMessage_t msg;
};
#endif // MAINPROCESS_H
