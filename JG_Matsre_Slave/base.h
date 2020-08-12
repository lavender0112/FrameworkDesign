#ifndef BASE_PROCESS_H
#define BASE_PROCESS_H

class Base
{
public:
    virtual void ProcessTaskI2C(char *data, int size) = 0;
    virtual void ProcessTaskUSB(char *data, int size) = 0;
};

#endif // BASE_PROCESS_H
