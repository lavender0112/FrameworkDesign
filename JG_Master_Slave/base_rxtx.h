#ifndef BASE_RXTX_H
#define BASE_RXTX_H

#include <thread>
#define MAX_MSG_SIZE 1024

class BaseRxTxIml
{
public:
    virtual int RecvData(char *data, int size) = 0;
};

class RecvSend
{
public:
    RecvSend();

    void StartService();

public:
    static void RecvThread(RecvSend *self);
    //static void DealThread();

    virtual int RecvData(char *data, int size);
    //virtual int SendData(char *data, int size);


private:
    bool _recvFlag;
    bool _dealFlag;
    bool _doExit;

    std::thread _recvTh;
    std::thread _dealTh;
};

#endif // BASE_RXTX_H
