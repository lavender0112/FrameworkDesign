#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <initializer_list>

typedef struct
{
    uint8_t sop1;
    uint8_t sop2;
    uint8_t type;
    uint8_t flag;
    uint8_t srcSysId;
    uint8_t srcCompId;
    uint8_t dstSysId;
    uint8_t dstCompId;
    uint16_t msgId;
    uint8_t seq;
    uint16_t len;
    char payload[256];
    uint16_t checksum;
}LinkMessage_t;//与GlinkMessageMax_t*到GlinkMessage_t*可强制类型转换

class RingBuffer
{
public:
    RingBuffer();
    ~RingBuffer();

    void StartThread();
    static void RunRecvMainLoop(RingBuffer *self);

    void InformDataPushQueue(LinkMessage_t *msg);
    LinkMessage_t *FetchNextMessage();
    bool empty();
    void setMaxSize(unsigned int size);
    unsigned int getMaxSize();
    int freesize();
    virtual int HandleMessage(LinkMessage_t *msg);

private:
    std::queue<LinkMessage_t*> DataQueue;
    std::thread *_recv_th;
    mutable std::mutex _mtx;
    mutable std::condition_variable _cond;
    unsigned int _maxSize;
};


#endif // RINGBUFFER_H
