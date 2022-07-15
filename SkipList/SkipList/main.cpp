//
//  main.cpp
//  SkipList
//
//  Created by MarkWu on 2019/12/16.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <vector>
#include "skip_list.hpp"

int main(int argc, const char * argv[]) {
    
    SkipList<int> skip_list;
    
    for (int i = 1; i <= 20; i++) {
        skip_list.Add(i, i);
    }
    
    Node<int>* find = skip_list.Find(1);
    assert(find != nullptr);
    
    skip_list.Print();
        
    cout << endl << "<<<<<<<<<<<<<<<" << endl;

    skip_list.Delete(17);
    skip_list.Print();
    
    
    return 0;
}
