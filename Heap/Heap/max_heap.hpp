//
//  max_heap.cpp
//  Heap
//
//  Created by MarkWu on 2019/6/20.
//  Copyright © 2019 Zego. All rights reserved.
//
#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP
#include "priority_queue.h"
#include <boost/format.hpp>
#include <memory>
#include "zego_log.hpp"
#include "heap.hpp"

using namespace std;

template<class T>
class MaxHeap : public Heap<T>
{
public:
    MaxHeap();
    ~MaxHeap();
    
private:
    unsigned int Compare(unsigned int adjust_position, unsigned int last_position) override;
};

template<class T>
MaxHeap<T>::MaxHeap()
{
}

template<class T>
MaxHeap<T>::~MaxHeap()
{
}

template<class T>
unsigned int MaxHeap<T>::Compare(unsigned int adjust_position, unsigned int last_position)
{
    unsigned int left_child = adjust_position * 2;
    unsigned int right_child = adjust_position * 2 + 1;
    
    // 左、右两个字节点都合法
    if (right_child <= last_position)
    {
        unsigned int bigger = this->heap_[left_child] >= this->heap_[right_child] ? left_child : right_child;
        if (this->heap_[bigger] > this->heap_[adjust_position])
            return bigger;
        
    // 只有左节点合法
    }else if (left_child <= last_position)
    {
        if (this->heap_[left_child] > this->heap_[adjust_position])
            return left_child;
    }
    
    return adjust_position;
}

#endif
