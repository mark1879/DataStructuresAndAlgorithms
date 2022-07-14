//
//  test_sorting_algorithms.hpp
//  Review
//
//  Created by MarkWu on 2022/4/27.
//

#ifndef test_sorting_algorithms_hpp
#define test_sorting_algorithms_hpp

#include <cassert>
#include <iostream>
#include <chrono>

using namespace std;

class TestSortingAlgorithms
{
private:    
    static bool VerifyOrderOfData(int sorted_data[], unsigned int data_size, bool from_small_to_large)
    {
        bool passed = true;
        
         for (unsigned int i = 0; i < (data_size - 1); i++)
         {
            if (from_small_to_large)
            {
                if (sorted_data[i] > sorted_data[i+1])
                {
                    passed = false;
                    break;
                }
            }
            else
            {
                if (sorted_data[i] < sorted_data[i+1])
                {
                    passed = false;
                    break;
                }
            }
         }
        
        sprintf(buf_of_log_, "[TestSortingAlgorithm::VerifyOrderOfData] passed: %d\n", passed);
        cout << buf_of_log_;
    
        return passed;
    }
    
public:
      static int* GenerateTestData(unsigned int data_size)
      {
          cout << "[TestSortingAlgorithm::GenerateTestData], size:" << data_size << endl;
          
          if (data_size == 0)
          {
              cout << "[TestSortingAlgorithm::GenerateTestData] Error, size must be larger than 0" << endl;
              return nullptr;
          }
          
          int *data = (int *)malloc(data_size * sizeof(int));
          if (data == nullptr)
          {
              cout << "[TestSortingAlgorithm::GenerateTestData] Error, malloc failed" << endl;
              return nullptr;
          }
          
          memset(data, 0, data_size * sizeof(int));
          
          srand((unsigned) time(nullptr));
          for (unsigned i = 0; i < data_size; i++)
          {
              data[i] = rand() % data_size;
          }
          
          return data;
      }
    
    static void Test(bool(*sort_func)(int *, int), string func_name, int data[], unsigned int data_size)
    {
        cout << "[TestSortingAlgorithm::Test], func_name: " << func_name << endl;
        
        if (sort_func == nullptr || data == nullptr || data_size == 0)
        {
            cout << "[TestSortingAlgorithm::Test], Arguments Error!" << endl;
            return;
        }
        
         std::chrono::milliseconds start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
               std::chrono::system_clock::now().time_since_epoch()
           );
        
        assert(sort_func(data, data_size) == true);
        
        std::chrono::milliseconds end_time = std::chrono::duration_cast< std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
        );
        
        cout << "[TestSortingAlgorithm::Test], time consumed: " << (end_time.count() - start_time.count()) << "ms" << endl;
        
        assert(VerifyOrderOfData(data, data_size, true) == true);
    }
    
private:
    static char buf_of_log_[1024];
};

char TestSortingAlgorithms::buf_of_log_[1024] = {0};




#endif /* test_sorting_algorithms_h */
