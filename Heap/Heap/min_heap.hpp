//
//  min_heap.hpp
//  Heap
//
//  Created by MarkWu on 2022/5/21.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef min_heap_hpp
#define min_heap_hpp
#include "heap.hpp"

using namespace std;

template<class T>
class MinHeap : public Heap<T>
{
public:
    MinHeap();
    ~MinHeap();
    
private:
    unsigned int Compare(unsigned int adjust_position, unsigned int last_position) override;
    bool IsBigHeap() override { return false; }
};

template<class T>
MinHeap<T>::MinHeap()
{
}

template<class T>
MinHeap<T>::~MinHeap()
{
}



template<class T>
unsigned int MinHeap<T>::Compare(unsigned int adjust_position, unsigned int last_position)
{
    unsigned int left_child = adjust_position * 2;
    unsigned int right_child = adjust_position * 2 + 1;
    
    // 左、右两个字节点都合法
    if (right_child <= last_position)
    {
        unsigned int smaller = this->heap_[left_child] <= this->heap_[right_child] ? left_child : right_child;
        if (this->heap_[smaller] < this->heap_[adjust_position])
            return smaller;
        
    // 只有左节点合法
    }else if (left_child <= last_position)
    {
        if (this->heap_[left_child] < this->heap_[adjust_position])
            return left_child;
    }
    
    return adjust_position;
}

#endif /* min_heap_h */
