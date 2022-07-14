//
//  quick_sort.hpp
//  Review
//
//  Created by MarkWu on 2022/4/26.
//

#ifndef quick_sort_hpp
#define quick_sort_hpp
#include "common_header.hpp"
#include "test_sorting_algorithms.hpp"

long count_quick_sort_ = 0;

void quick_sort_(int data[], int left, int right){
    
    if (left >= right)
        return;
    
    int i = left;
    int j = right;
    int middle = data[left];
    
    while (i != j){
        count_quick_sort_++;
        while (i < j && data[j] >= middle){
            j--;
            count_quick_sort_++;
        }
        
        while (i < j && data[i] <= middle){
            i++;
            count_quick_sort_++;
        }
        
        if (i < j){
            count_quick_sort_++;
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    data[left] = data[i];
    data[i] = middle;
    
    quick_sort_(data, left, i - 1);
    quick_sort_(data, i + 1, right);
}

bool quick_sort(int data[], int data_len){
    
    if (data == nullptr || data_len <= 0)
        return false;
    
    cout << "quick_sort, data_len: " << data_len << endl;
    
    
    quick_sort_(data, 0, data_len - 1);
    
    cout << "count_quick_sort_: " << count_quick_sort_ << endl;
    
    return true;
}

#endif /* quick_sort_h */
