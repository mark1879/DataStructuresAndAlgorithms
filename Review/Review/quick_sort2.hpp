//
//  quick_sort2.hpp
//  Review
//
//  Created by MarkWu on 2022/4/27.
//

#ifndef quick_sort2_hpp
#define quick_sort2_hpp
#include "common_header.hpp"

long count_quick_sort2_ = 0;

int partition(int data[], int left, int right){
    
    int i = left;
    int j = right;
//    int middle = min(max(data[left], data[right]), data[(left + right)/2]);
    int middle = data[left];
    
    while (i != j){
        count_quick_sort2_++;
        
        while (i < j && data[j] >= middle){
            j--;
            count_quick_sort2_++;
        }
        
        while (i < j && data[i] <= middle){
            i++;
            count_quick_sort2_++;
        }
        
        if (i < j){
            count_quick_sort2_++;
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    data[left] = data[i];
    data[i] = middle;
    
    return i;
}

void quick_sort2_(int data[], int l, int r) {
    while (l < r) {
        count_quick_sort2_++;
        // 进行一轮 partition 操作
        // 获得基准值的位置
        int ind = partition(data, l, r);
        // 右侧正常调用递归函数
        quick_sort2_(data, ind + 1, r);
        // 用本层处理左侧的排序
        r = ind - 1;
    }
}

bool quick_sort2(int data[], int data_len){
    
    if (data == nullptr || data_len <= 0)
        return false;
    
    cout << "quick_sort2, data_len: " << data_len << endl;
    
    
    quick_sort2_(data, 0, data_len - 1);
    
    cout << "count_quick_sort2_: " << count_quick_sort2_ << endl;
    
    return true;
}

#endif /* quick_sort2_h */
