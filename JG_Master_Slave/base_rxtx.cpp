#include "base_rxtx.h"

#include <unistd.h>
#include <string.h>

RecvSend::RecvSend()
{
    _recvFlag = true;
    _dealFlag = true;
}

void RecvSend::StartService()
{
    _doExit = false;

    if(_recvFlag)
    {
        _recvTh = std::thread(&RecvSend::RecvThread, this);
    }

//    if(_dealFlag)
//    {
//        _dealTh = std::thread(&RecvSend::DealThread, this);
//    }
}

void RecvSend::RecvThread(RecvSend *self)
{
    int ret = -1;
    char buffer[MAX_MSG_SIZE];
    printf("RecvThread...\n");

    while(1)
    {
        printf("RecvData...\n");
        ret = self->RecvData(buffer, MAX_MSG_SIZE);
        if(ret < 0)
        {
            usleep(1000000);
            continue;
        }

       // self->SendData(buffer, ret);
        usleep(10*1000);
        printf("***********************************************\n");
    }
}

//void RecvSend::DealThread()
//{

//}

int RecvSend::RecvData(char *data, int size)
{
    static unsigned int count = 0;
    char data_i2c[1024] = {1,2,3,4,5,6,7,8,9,10};
    size = 10;
    memcpy(data, data_i2c, size);
    printf("RecvSend::RecvData data[0]:%d size:%d %d===================\n",data[0], size,count++);
    //sleep(1);
    return 0;
}

//int RecvSend::SendData(char *data, int size)
//{
//    static unsigned int count = 0;
//    printf("RecvSend::SendData data[0]:%d size:%d %dSSSSSSSSSSSSSSSSSS\n",data[0], size, count++);
//    //sleep(1);
//    return 0;
//}

