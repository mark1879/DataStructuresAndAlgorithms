//
//  main.cpp
//  Heap
//
//  Created by MarkWu on 2019/6/18.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "max_heap.hpp"
#include "min_heap.hpp"
#include "middle_heap.hpp"

using namespace std;

void TestMaxHeap()
{
    unsigned int capacity = 100;
    
    MaxHeap<unsigned int> max_heap;
    
    for (unsigned int i = 1; i <= capacity; i++)
    {
        max_heap.Push2(i);
    }

    max_heap.Traverse();
    
    max_heap.Sort();
    max_heap.Traverse();

    unsigned int value;
    max_heap.Pop(value);
    cout << "Pop: " << value << endl;
    max_heap.Sort();
    max_heap.Traverse();
    
}

void TestMinHeap()
{
    unsigned int capacity = 100;
    
    MinHeap<unsigned int> min_heap;
    
    for (unsigned int i = capacity; i >= 1; i--)
    {
        min_heap.Push2(i);
    }

    min_heap.Traverse();

    min_heap.Sort();
    min_heap.Traverse();

    unsigned int value;
    min_heap.Pop(value);
    cout << "Pop: " << value << endl;
    min_heap.Sort();
    min_heap.Traverse();
    
}

void TopKBiggerNums(int k)
{
    MinHeap<int> minHeap;
    
    for (int i = 1; i <= 100*100; i++){
        if (minHeap.Size() == k) {
            int top_value;
            if (minHeap.Top(top_value) && i > top_value) {
                minHeap.Pop(top_value);
                minHeap.Push2(i);
            }
        } else {
            minHeap.Push2(i);
        }
    }
    
    cout << "Top " << k << " NUM: " << endl;
    minHeap.Sort();
    minHeap.Traverse();
}

void TestMiddleHeap()
{
    MiddleHeap middle_heap;
    srand((int)time(0));
    for (int i = 0; i < 21; i++)
    {
        middle_heap.Insert(rand() % 100);
    }
    
    double value;
    if (middle_heap.SeekMiddleValue(value)) {
        cout << "middle value: " << value << endl;
    }
    
    middle_heap.OutPut();
}

int main(int argc, const char * argv[])
{
//    TestMaxHeap();
//    TestMinHeap();
    
//    TopKBiggerNums(10);
    
    TestMiddleHeap();
   
    return 0;
}
