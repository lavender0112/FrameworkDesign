#include "i2c.h"

I2C::I2C(Base *b_i2c)
{
    base1 = b_i2c;
    init();
}

void I2C::init()
{
    char data[1024] = {1,2,3,4,5,6,7,8,9,10};
    base1->ProcessTaskI2C(data, 10);
}

int I2C::RecvData(char *data, int size)
{
    static unsigned int count = 0;
    char data_i2c[1024] = {1,2,3,4,5,6,7,8,9,10};
    size = 10;
    memcpy(data, data_i2c, size);
    printf("===========I2C RecvData %d+++++++++++++++++++++++++++\n",count++);
    return 0;
}

//int I2C::SendData(char *data, int size)
//{
//    printf("I2C SendData data[0]:%d size:%d=========\n",data[0], size);
//    return 0;
//}

void I2C::TransferDetection(char *data, int size)
{
    printf("I2C TransferDetection data[0]:%d size:%d\n",data[0], size);

    //RC下发给各个模块
}

int I2C::HandleMessage(LinkMessage_t *msg)
{
    if(msg == nullptr)
    {
        printf("Fc003 HandleMessage return -1 \n");
        return -1;
    }
    else
    {
        TransferDetection((char *)msg->payload,10);
        //printf("Fc003 HandleMessage...\n");
    }

    return 0;
}
