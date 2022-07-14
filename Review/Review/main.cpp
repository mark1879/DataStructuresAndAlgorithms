//
//  main.cpp
//  Review
//
//  Created by MarkWu on 2022/4/26.
//

#include <iostream>
#include "quick_sort.hpp"
#include "quick_sort2.hpp"
#include "test_sorting_algorithms.hpp"

int main(int argc, const char * argv[]) {
    
    int data_size = 100 * 100 * 100 * 10;
    int *data = TestSortingAlgorithms::GenerateTestData(data_size);
    
    int *copy_of_data1 = (int *)malloc(data_size * sizeof(int));
    memcpy(copy_of_data1, data, data_size * sizeof(int));
    TestSortingAlgorithms::Test((bool(*)(int *, int))quick_sort, "quick_sort", copy_of_data1, data_size);
    free(copy_of_data1);

    cout << endl;
    
    int *copy_of_data2 = (int *)malloc(data_size * sizeof(int));
    memcpy(copy_of_data2, data, data_size * sizeof(int));
    TestSortingAlgorithms::Test((bool(*)(int *, int))quick_sort2, "quick_sort2", copy_of_data2, data_size);
    free(copy_of_data2);
    
    free(data);
    
    return 0;
}
