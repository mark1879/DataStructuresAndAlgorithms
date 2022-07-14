//
//  exercise.hpp
//  LinkedList
//
//  Created by MarkWu on 2022/1/13.
//  Copyright © 2022 Zego. All rights reserved.
//

#ifndef exercise_hpp
#define exercise_hpp

#include <iostream>
#include "linked_list.hpp"

ListNode<int> * reverseList(ListNode<int>* head) {
    if (!head)
        return head;

    ListNode<int>* curr = head;
    ListNode<int>* prev = nullptr;

    while (curr){
        ListNode<int>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode<int>* reverseBetween(ListNode<int>* head, int left, int right) {
       ListNode<int>* dummy_node = new ListNode<int>(-1);
       dummy_node->next = head;
       ListNode<int>* sub_head = dummy_node;

       for (int i = 1; i < left; i++){
           sub_head = sub_head->next;
       }

       ListNode<int>* current = sub_head->next;
       ListNode<int>* prev = nullptr;
       for (int i = left; i <= right; i++){
           ListNode<int>* next = current->next;
           current->next = prev;
           prev = current;
           current = next;
       }

       sub_head->next->next = current;
       sub_head->next = prev;

       return dummy_node->next;
}

ListNode<int>* mergeTwoLists(ListNode<int>* list1, ListNode<int>* list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    ListNode<int> head;
    ListNode<int> *it = &head;

    while (list1 && list2){
        if (list1->value < list2->value){
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



#endif /* exercise_h */
