//
//  main.cpp
//  BSTree
//
//  Created by MarkWu on 2020/4/29.
//  Copyright © 2020 Zego. All rights reserved.
//

#include <iostream>
#include <vector>
#include "binary_search_tree.hpp"

int main(int argc, const char * argv[]) {
    
    BSTree<int> tree;
    tree.Insert(100);
    
    tree.Insert(120);
    tree.Insert(110);
    tree.Insert(130);
    tree.Insert(140);
    tree.Insert(125);
    tree.Insert(123);
    tree.Insert(124);
    tree.Insert(128);
    
    tree.Insert(60);
    tree.Insert(50);
    tree.Insert(45);
    tree.Insert(55);
    tree.Insert(80);
    
//    tree.Order(BSTOrder::PreOder);
    tree.Order(BSTOrder::InOrder);
//    tree.Order(BSTOrder::PostOrder);
    
    cout << "Maximum: " << tree.Maximum() << endl;
    cout << "Minimum: " << tree.Minimum() << endl;
    
    tree.Remove(45);
    tree.Remove(50);
    tree.Remove(80);
    tree.Remove(60);
    tree.Order(BSTOrder::InOrder);
    cout << "Maximum: " << tree.Maximum() << endl;
    cout << "Minimum: " << tree.Minimum() << endl;

    tree.Insert(70);
    tree.Insert(30);
    tree.Order(BSTOrder::InOrder);
    cout << "Maximum: " << tree.Maximum() << endl;
    cout << "Minimum: " << tree.Minimum() << endl;
    
    tree.Remove(120);
    tree.Remove(123);
    tree.Remove(100);
    tree.Order(BSTOrder::InOrder);
    cout << "Maximum: " << tree.Maximum() << endl;
    cout << "Minimum: " << tree.Minimum() << endl;

    BSTNode<int> node;
    assert(tree.Search(node, 130) == true);
    assert(tree.Search(node, 200) == false);
    return 0;
}
