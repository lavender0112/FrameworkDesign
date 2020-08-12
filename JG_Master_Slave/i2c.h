#ifndef I2C_H
#define I2C_H

#include "base.h"
#include "ringbuffer.h"
#include "base_rxtx.h"

class I2C:public RingBuffer,public RecvSend
{
public:
    I2C(Base *b_i2c);

    void init();

    // void StartService();

     int RecvData(char *data, int size);
     //int SendData(char *data, int size);

     void TransferDetection(char *data, int size);

     int HandleMessage(LinkMessage_t *msg);

 public:
     //static void RecvThread(I2C *self);
     //static void DealThread();

     //int RecvData2(char *data, int size);
     //int SendData(char *data, int size);

 private:
     bool _recvFlag;
     bool _dealFlag;
     bool _doExit;

     std::thread _recvTh;
     std::thread _dealTh;

 private:
     Base *base1;
     //RecvSend *mp_RecvSend;
};

#endif // I2C_H
