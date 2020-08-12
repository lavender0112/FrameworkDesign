#include "mainprocess.h"

#include <iostream>
using namespace std;

MainProcess::MainProcess()
{
    cout << "MainProcess..." <<endl;

    mp_i2c = new I2C(this);
    mp_usb = new USB(this);
}

void MainProcess::MainStartService()
{
    mp_i2c->StartService();
}

//开线程取数据转发
#if 0
get_queue();
#endif

void MainProcess::ProcessTaskI2C(char *data, int size)
{
    printf("I2C data[0]:%d size:%d\n",data[0], size);
    memcpy((char *)msg.payload,data,size);
    this->InformDataPushQueue(&msg);
    //in queue
}

void MainProcess::ProcessTaskUSB(char *data, int size)
{
    printf("USB data[0]:%d size:%d\n",data[0], size);
    //in queue
}

int MainProcess::HandleMessage(LinkMessage_t *msg)
{
    if(msg == nullptr)
    {
        printf("Fc003 HandleMessage return -1 \n");
        return -1;
    }
    else
    {
        mp_i2c->TransferDetection((char *)msg->payload,10);
        //printf("Fc003 HandleMessage...\n");
    }

    return 0;
}
