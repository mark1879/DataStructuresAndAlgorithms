//
//  circular_linked_list.cpp
//  CircularLinkedList
//
//  Created by MarkWu on 2019/5/29.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef circular_linked_list_hpp
#define circular_linked_list_hpp

#include <iostream>
#include <boost/format.hpp>
#include "zego_log.hpp"

using namespace std;

template<class T>
struct Node
{
public:
    T val;
    Node *prev;
    Node *next;
    
public:
    Node() {}
    Node(T t, Node *prev, Node *next)
    {
        this->val = t;
        this->prev = prev;
        this->next = next;
    }
};

template<class T>
class CircularLinkedList
{
public:
    CircularLinkedList();
    ~CircularLinkedList();
    
    unsigned int Size() const;
    bool IsEmpty();
    
    bool GetNode(unsigned int index, T& value);
    bool InsertNode(unsigned int index, T t);
    bool PushBack(T t);
    bool DeleteNode(unsigned int index);
    
    void Traverse(bool reverse);
    
private:
    unsigned int count_of_list_;
    Node<T> *head_of_list_;
};

template<class T>
CircularLinkedList<T>::CircularLinkedList() : count_of_list_(0)
{
    head_of_list_ = new Node<T>();
    head_of_list_->prev = head_of_list_->next = head_of_list_;
    
    log_v_print(boost::format("[CircularLinkedList] create"));
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    Node<T> *node = head_of_list_->next;
    while (node != head_of_list_)
    {
        Node<T> *temp = node;
        node = node->next;
        delete temp;
    }
    
    delete head_of_list_;
    head_of_list_ = nullptr;
    
    log_v_print(boost::format("[~CircularLinkedList] done"));
}

template<class T>
unsigned int CircularLinkedList<T>::Size() const
{
    return count_of_list_;
}

template<class T>
bool CircularLinkedList<T>::IsEmpty()
{
    return count_of_list_ == 0;
}

template<class T>
bool CircularLinkedList<T>::InsertNode(unsigned int index, T t)
{
    log_v_print(boost::format("[InsertNode] enter, index: %u") % index);
    
    if (index > count_of_list_)
    {
        log_v_print(boost::format("[Insert Node] Error, length of list: %u, index: %u Overflowed") % count_of_list_ % index);
        return false;
    }
    
    Node<T> *node = head_of_list_;
    for(unsigned int i = 0; i < index; i++)
    {
        node = node->next;
    }
    
    Node<T> *new_node = new Node<T>(t, node, node->next);
    node->next->prev = new_node;
    node->next= new_node;
    
    count_of_list_++;
    
    log_v_print(boost::format("[InserNode] insert done, count_of_list_: %u") % count_of_list_);
    
    return true;
}

template<class T>
bool CircularLinkedList<T>::PushBack(T t)
{
    
    Node<T> *new_node = new Node<T>(t, head_of_list_->prev, head_of_list_);
    
    if (count_of_list_ == 0){
        head_of_list_->next = new_node;
    } else{
        head_of_list_->prev->next = new_node;
    }
    
    head_of_list_->prev = new_node;

    count_of_list_++;
    
    log_v_print(boost::format("[PushBack] done, count_of_list_: %u") % count_of_list_);
    
    return true;
}

template<class T>
bool CircularLinkedList<T>::GetNode(unsigned int index, T& value)
{
    log_v_print(boost::format("[GetNode] enter, index: %u") % index);
    
    if (index >= count_of_list_)
    {
        log_v_print(boost::format("[GetNode] Error, length of list: %u, index: %u Overflowed") % count_of_list_ % index);
        return false;
    }
    
    Node<T> *node = head_of_list_;
    for (unsigned int i = 0; i <= index; i++)
    {
        node = node->next;
    }
    
    value = node->val;
    
    return true;
}

template<class T>
bool CircularLinkedList<T>::DeleteNode(unsigned int index)
{
    log_v_print(boost::format("[DeleteNode] enter, index: %u") % index);
    
    if (index >= count_of_list_)
    {
        log_v_print(boost::format("[DeleteNode] Error, length of list: %u, index: %u, Overflowed") % index % count_of_list_);
        return false;
    }
    
    Node<T> *node_deleted = head_of_list_;
    for (unsigned int i = 0; i <= index; i++)
    {
        node_deleted = node_deleted->next;
    }
    
    node_deleted->prev->next = node_deleted->next;
    node_deleted->next->prev = node_deleted->prev;
    
    delete node_deleted;
    count_of_list_--;
    
    log_v_print(boost::format("[DeleteNode] delete done, count_of_list_: %u") % count_of_list_);
    
    return true;
}

template<class T>
void CircularLinkedList<T>::Traverse(bool reverse)
{
    if (count_of_list_ == 0)
    {
        log_v_print(boost::format("[Traverse] Waring, the list is empty!"));
        return;
    }
    
    log_v_print(boost::format("[Traverse] traversing the list(reverse: %d):") % reverse);
    
    if (!reverse)
    {
        Node<T> *node = head_of_list_->next;
        while (node != head_of_list_)
        {
            cout << node->val << endl;
            node = node->next;
        }
    }
    else
    {
        Node<T> *node = head_of_list_->prev;
        while (node != head_of_list_)
        {
            cout << node->val << endl;
            node = node->prev;
        }
    }
}

#endif
