//
//  max_priority_queue.h
//  Heap
//
//  Created by MarkWu on 2019/6/20.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef max_priority_queue_h
#define max_priority_queue_h

#include <vector>

using namespace std;

template<class T>
class PriorityQueue
{
public:
    virtual ~PriorityQueue() {}
    virtual bool Empty() const = 0;
    virtual unsigned int Size() const = 0;
    virtual bool Pop(T&) = 0;
    virtual bool Push(const T& t) = 0;  //从顶向下调整
    virtual bool Push2(const T& t) = 0; //线性建堆
};
#endif /* max_priority_queue_h */
