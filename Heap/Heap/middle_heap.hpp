//
//  middle_heap.hpp
//  Heap
//
//  Created by MarkWu on 2022/6/1.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef middle_heap_hpp
#define middle_heap_hpp

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include "min_heap.hpp"
#include "max_heap.hpp"

using namespace std;

/**
    对顶堆，维护中位数
 */
class MiddleHeap {
public:
    MiddleHeap() {}
    
    void Insert(int val) {
        if (max_heap_.Size() > 0) {
            int max_top;
            max_heap_.Top(max_top);
            
            if (val <= max_top) {
                max_heap_.Push(val);
            } else {
                min_heap_.Push(val);
            }
        } else {
            max_heap_.Push(val);
        }
        
        if (max_heap_.Size() + 2 == min_heap_.Size()) {
            int min_top;
            min_heap_.Pop(min_top);
            max_heap_.Push(min_top);
        }
        
        if (min_heap_.Size() + 2 == max_heap_.Size()) {
            int max_top;
            max_heap_.Pop(max_top);
            min_heap_.Push(max_top);
        }
    }
    
    bool SeekMiddleValue(double& middle_value) {
        
        if (min_heap_.Size() == 0 && max_heap_.Size() == 0)
            return false;
        
        int min_top;
        int max_top;
        
        min_heap_.Top(min_top);
        max_heap_.Top(max_top);
        
        if (max_heap_.Size() == min_heap_.Size()) {
            middle_value = (min_top + max_top) / 2.0;
        } else {
            middle_value = max_heap_.Size() > min_heap_.Size() ? max_top : min_top;
        }
        
        return true;
    }
    
    void OutPut() {
        cout << "max_heap: " << endl;
        max_heap_.Sort();
        max_heap_.Traverse();
        
        cout << "min_heap: " << endl;
        min_heap_.Sort();
        min_heap_.Traverse();
    }
    
private:
    MaxHeap<int> max_heap_;
    MinHeap<int> min_heap_;
};




#endif /* middle_heap_h */
