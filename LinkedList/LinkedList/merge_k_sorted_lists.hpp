//
//  merge_k_sorted_lists.hpp
//  LinkedList
//
//  Created by MarkWu on 2022/1/16.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef merge_k_sorted_lists_h
#define merge_k_sorted_lists_h

#include <iostream>
#include <vector>

struct Node
{
public:
    int val;
    Node *next;
    
public:
    Node() : val(0), next(nullptr) {}
};

class MergeKSortedList {
public:
    static Node* MergeTwoList(Node* list1, Node* list2){
        if (!list1 || !list2)
            return list1 ? list1 : list2;
        
        Node head;
        Node* it = &head;
        
        while (list1 && list2){
            if (list1->val < list2->val){
                it->next = list1;
                list1 = list1->next;
            } else {
                it->next = list2;
                list2 = list2->next;
            }
            
            it = it->next;
        }
        
        it->next = list1 ? list1 : list2;
        
        return head.next;
    }
    
    static Node* Solution1(vector<Node*>& lists){
        Node* ans = nullptr;
        
        for (size_t i = 0, size = lists.size(); i < size; i++)
            ans = MergeTwoList(ans, lists[i]);
        
        return ans;
    }
    
    static void Test(){
        
    }
};


#endif /* merge_k_sorted_lists_h */
