//
//  heap_queue.hpp
//  ThreadPool
//
//  Created by MarkWu on 2022/5/31.
//

#ifndef heap_queue_hpp
#define heap_queue_hpp

template<typename T, typename Array_T=vector<T>, typename Compare_T=less<T>>
class HeapQueue {
public :
    HeapQueue() {
        elements_.clear();
    }
    
    bool empty() {
        return elements_.size() == 0;
    }
    
    T front() {
        return elements_[0];
    }
    
    void push(const T &val) {
        elements_.push_back(val);
        ShiftUp();
    }
    
    void pop() {
        if (empty())
            return;
        
        swap(elements_[elements_.size() - 1], elements_[0]);
        elements_.pop_back();
        
        ShiftDown();
    }
    
private:
    void ShiftUp() {
        int index = elements_.size();
        
        while (index > 1 && compare_(elements_[index / 2 - 1], elements_[index - 1])) {
            swap(elements_[index / 2 - 1], elements_[index - 1]);
            index /= 2;
        }
    }
    
    void ShiftDown() {
        int current_index = 0;
        int size = elements_.size();
        
        while (current_index * 2 + 1 < size) {
            int target_index = current_index;
            
            if (compare_(elements_[target_index], elements_[current_index * 2 + 1])) {
                target_index = current_index * 2 + 1;
            }
            
            if (current_index * 2 + 2 < size &&
                compare_(elements_[target_index], elements_[current_index * 2 + 2])) {
                target_index = current_index * 2 + 2;
            }
            
            if (current_index == target_index)
                break;
            
            swap(elements_[current_index], elements_[target_index]);
            current_index = target_index;
        }
    }
private:
    Array_T elements_;
    Compare_T compare_;
};


#endif /* heap_queue_h */
