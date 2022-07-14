//
//  heap.hpp
//  Heap
//
//  Created by MarkWu on 2022/5/21.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp

#include "priority_queue.h"
#include <boost/format.hpp>
#include <memory>
#include "zego_log.hpp"

using namespace std;

template<class T>
class Heap : public PriorityQueue<T>
{
public:
    Heap();
    ~Heap();
    bool Empty() const override;
    unsigned int Size() const override;
    bool Push(const T& elem) override;
    bool Push2(const T& elem) override;
    bool Pop(T&) override;
    void Traverse() const;
    void Sort();
    bool Top(T& top_value) const;
    
protected:
    void ShiftDown(unsigned int last_position);
    void ShiftUp(unsigned int adjust_position);
    virtual bool IsBigHeap(){ return true; };
    virtual unsigned int Compare(unsigned int adjust_position, unsigned int last_position){ return adjust_position; };
    
protected:
    unsigned int heap_size_;
    vector<T> heap_;
    
    const unsigned int kTop = 1;
};

template<class T>
Heap<T>::Heap()
{
    heap_size_ = 0;
    // 在索引0的位置增加一个元素，便于调整堆
    heap_.push_back(0);
}

template<class T>
Heap<T>::~Heap()
{
}

template<class T>
bool Heap<T>::Empty() const
{
    return heap_size_ == 0;
}

template<class T>
unsigned int Heap<T>::Size() const
{
    return heap_size_;
}

template<class T>
bool Heap<T>::Top(T& top_value) const
{
    if (Empty())
    {
        log_v_print(boost::format("[Heap<T>::Top] Warning, heap is empty"));
        return false;
    }
    
    top_value = heap_[kTop];
    
    return true;
}

template<class T>
bool Heap<T>::Push(const T& elem)
{
    heap_size_ += 1;
    heap_.push_back(elem);
    
    ShiftUp(heap_size_);
    
    return true;
}

template<class T>
bool Heap<T>::Push2(const T& elem)
{
    heap_size_ += 1;
    heap_.insert(heap_.begin() + 1, elem);
    
    ShiftDown(heap_size_);
    
    return true;
}

template<class T>
void Heap<T>::Traverse() const
{
    if (Empty())
    {
        log_v_print(boost::format("[Heap<T>::Traverse] Warning, heap is empty"));
        return;
    }
    
    log_v_print(boost::format("[Heap<T>::Traverse], heap_size:  %u") % heap_size_);
    
    for (unsigned int i = 1; i <= heap_size_; i++)
    {
        cout << heap_[i] << "\t";
    }
    
    cout << endl;
}


template<class T>
void Heap<T>::Sort()
{
    if (Empty())
    {
        log_v_print(boost::format("[Heap<T>::Sort] Warning, heap is empty"));
        return;
    }
    
    for (unsigned int i = 1; i <= heap_size_; i++)
    {
        swap_value(heap_[kTop], heap_[heap_size_ - (i - 1)]);
        
        ShiftDown(heap_size_ - i);
    }
    
    // 将排序结果逆序
    for (unsigned int i = 1; i <= heap_size_ / 2; i++)
        swap_value(heap_[i], heap_[heap_size_ - (i - 1)]);
}

template<class T>
bool Heap<T>::Pop(T& value)
{
    if (Empty())
    {
        log_v_print(boost::format("[Heap<T>::Pop] Warning, heap is empty"));
        return false;
    }
    
    // 第一个元素
    value = heap_[kTop];
    
    // 将最后一个元素放置堆顶
    heap_[kTop] = heap_[heap_size_];
    heap_size_ -= 1;
    
    ShiftDown(heap_size_);
    
    return true;
}

template<class T>
void Heap<T>::ShiftUp(unsigned int adjust_position)
{
    while (adjust_position > this->kTop)
    {
        unsigned int parent = adjust_position / 2;

        if ((this->heap_[adjust_position] > this->heap_[parent] && IsBigHeap()) ||
            (this->heap_[adjust_position] < this->heap_[parent] && !IsBigHeap()))
        {
            swap_value(this->heap_[adjust_position], this->heap_[parent]);
        }

        adjust_position = parent;
    }
}

template<class T>
void Heap<T>::ShiftDown(unsigned int last_position)
{
    unsigned int adjust_position = this->kTop;
    
    while (adjust_position < last_position)
    {
        unsigned int need_to_exchange = Compare(adjust_position, last_position);

        if (adjust_position != need_to_exchange)
        {
            swap_value(this->heap_[adjust_position], this->heap_[need_to_exchange]);
            adjust_position = need_to_exchange;
        }
        else
        {
            // 不需要调整
            break;
        }
    }
}


#endif /* heap_h */
