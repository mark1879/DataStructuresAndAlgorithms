//
//  main.cpp
//  CircularLinkedList
//
//  Created by MarkWu on 2019/5/29.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "circular_linked_list.hpp"
#include <cassert>
#include <vector>

using namespace std;

void TestInsertNode()
{
    log_v_print(">>> TestInsertNode");
    
    CircularLinkedList<int> circular_linked_list;
    
    unsigned int index;
    int value;
    int value_was_inserted;
    
    // insert the head
    index = 0;
    value = 100;
    assert(circular_linked_list.InsertNode(index, value) == true);
    assert(circular_linked_list.GetNode(index, value_was_inserted));
    assert(value_was_inserted == value);
    
    // insert the tail
    index = circular_linked_list.Size();
    value = 200;
    assert(circular_linked_list.InsertNode(index, value) == true);
    assert(circular_linked_list.GetNode(index, value_was_inserted));
    assert(value_was_inserted == value);
    
    // insert the intermediate
    index = circular_linked_list.Size() / 2;
    value = 150;
    assert(circular_linked_list.InsertNode(index, value) == true);
    assert(circular_linked_list.GetNode(index, value_was_inserted));
    assert(value_was_inserted == value);
    
    // index overflow
    index = circular_linked_list.Size() + 1;
    value = 0;
    assert(circular_linked_list.InsertNode(index, value) == false);
    
    index = circular_linked_list.Size();
    assert(circular_linked_list.GetNode(index, value_was_inserted) == false);
    
    circular_linked_list.Traverse(false);
    circular_linked_list.Traverse(true);
}

void TestDeleteNode()
{
    log_v_print(">>> TestDeleteNode");
    
    CircularLinkedList<int> circular_linked_list;
    
    for (unsigned int index = 0; index < 10; index++)
    {
        circular_linked_list.InsertNode(index, index);
    }
    
    // index overflow
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size()) == false);
    
    // delete the head
    assert(circular_linked_list.DeleteNode(0) == true);
    
    // delete the intermediate
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size() / 2) == true);
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size() / 2) == true);
    
    // delete the tail
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size() - 1) == true);
    
    
    
    circular_linked_list.Traverse(false);
    circular_linked_list.Traverse(true);
}


int Joseph(int num, const int tag){
   
    CircularLinkedList<int> linked_list;
    
    for (int i = 0; i < num; i++){
        linked_list.PushBack(i);
    }
    
    int count = 0;
    unsigned int index = 0;
    
    while (linked_list.Size() > 1){
        if (index >= linked_list.Size())
            index = 0;
        
        if (++count % tag == 0)
            linked_list.DeleteNode(index);
        else
            index++;
    }
    
    int value;
    linked_list.GetNode(0, value);
    
    return value;
}

int lastRemaining(int n, int m) {

      vector<int> vec;
      for (int i = 0; i < n; i++)
          vec.push_back(i);
          
      int index = 0;
      int count = 0;

      while (vec.size() > 1){
          index = index % vec.size();
          
          if (++count % m == 0){
              cout << vec[index] << endl;
              vec.erase(vec.begin() + index);
          }
          else
              index++;
      }
    
    return vec[0];
  }

int f(int n, int m) {
    if (n == 1) {
        return 0;
    }
    
    int x = f(n - 1, m);
    
    cout << x << endl;
    
    return (m + x) % n;
}

int main(int argc, const char * argv[])
{
    
//    TestInsertNode();
//    TestDeleteNode();
    
    assert(Joseph(5, 3) == 3);
    assert(Joseph(10, 17) == 2);
    
    assert(lastRemaining(5, 3) == 3);
//    assert(lastRemaining(10, 17) == 2);
    
    assert(f(5, 3) == 3);
//    assert(f(10, 17) == 2);
    
    return 0;
}
