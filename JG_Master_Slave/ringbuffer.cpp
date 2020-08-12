#include "ringbuffer.h"

#include <thread>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

RingBuffer::RingBuffer()
{
    _maxSize = 1024;
    StartThread();
}

RingBuffer::~RingBuffer()
{
    if (_recv_th->joinable())
    {
        _recv_th->join();
        delete _recv_th;
        _recv_th = nullptr;
    }
}

void RingBuffer::StartThread()
{
    //printf("debug 3...\n");
    _recv_th = new std::thread(&RingBuffer::RunRecvMainLoop, this);
    if (_recv_th == NULL) {
          printf("ERROR! new thrd_heart std::thread() failed!");
    }
    //printf("debug 3.1...\n");
}

void RingBuffer::RunRecvMainLoop(RingBuffer *self)
{
    //printf("debug 5...\n");
    LinkMessage_t *msg_get;
    while(1)
    {
       //dzlog_debug("recv....\n");
       msg_get = self->FetchNextMessage();
       self->HandleMessage(msg_get);
    }
}

void RingBuffer::InformDataPushQueue(LinkMessage_t *msg)
{
   std::lock_guard<std::mutex> lk(_mtx);
   //printf("Fc002 _dataQueue.size():%d _maxSize:%d\n",(int)DataQueue.size(),_maxSize);
   if(DataQueue.size() >= _maxSize)
   {
       DataQueue.pop();
       DataQueue.push(msg);
   }else{
       DataQueue.push(msg);
       _cond.notify_one();
   }
}

LinkMessage_t* RingBuffer::FetchNextMessage()
{
    std::unique_lock<std::mutex> lk(_mtx);
    _cond.wait(lk, [this]{return !this->DataQueue.empty();});

    LinkMessage_t *value = DataQueue.front();
    DataQueue.pop();
    return value;
}

bool RingBuffer::empty()
{
    std::lock_guard<std::mutex> lk(_mtx);
    return DataQueue.empty();
}

void RingBuffer::setMaxSize(unsigned int size)
{
    _maxSize = size;
}

unsigned int RingBuffer::getMaxSize()
{
    return _maxSize;
}

int RingBuffer::freesize()
{
    std::lock_guard<std::mutex> lk(_mtx);
    return (_maxSize - DataQueue.size());
}

int RingBuffer::HandleMessage(LinkMessage_t *msg)
{
    //printf("%d \n", msg->sop1);
    return 0;
}
