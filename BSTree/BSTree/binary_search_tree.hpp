//
//  binary_search_tree.hpp
//  BSTree
//
//  Created by MarkWu on 2020/4/29.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef binary_search_tree_hpp
#define binary_search_tree_hpp
#include <iostream>
#include <boost/format.hpp>

using namespace std;

template <class T>
class BSTNode{
public:
    T key_;
    BSTNode *left_;
    BSTNode *right_;
    BSTNode *parent_;
    
    BSTNode() : parent_(nullptr), left_(nullptr), right_(nullptr){ }

    BSTNode(T key, BSTNode *parent, BSTNode *left, BSTNode *right):
        key_(key),parent_(parent),left_(left),right_(right) {}
};

enum class BSTOrder {
    PreOder = 1,
    InOrder = 2,
    PostOrder = 3
};

template <class T>
class BSTree {
private:
    BSTNode<T> *root_;

public:
    BSTree();
    ~BSTree();

    void Order(BSTOrder order);
    
    bool Search(BSTNode<T> &node, T key);

    T Minimum();
    T Maximum();

    void Insert(T key);
    void Remove(T key);
    void Destroy();
    
private:
    void Delete(BSTNode<T>* &node);
    void Order(BSTNode<T>* node, BSTOrder order);
};

template<class T>
BSTree<T>::BSTree() : root_(nullptr) {}

template<class T>
BSTree<T>::~BSTree() {
    Destroy();
}

template<class T>
void BSTree<T>::Destroy() {
    cout << "[BSTree<T>::Destroy]" << endl;
    Delete(root_);
}

template<class T>
void BSTree<T>::Delete(BSTNode<T>* &node) {
    if (node == nullptr)
        return;
    
    if (node->left_ != nullptr)
        Delete(node->left_);
    if (node->right_ != nullptr)
        Delete(node->right_);
    
    delete node;
    node = nullptr;
}

template <class T>
void BSTree<T>::Insert(T key) {
    cout << "[BSTree<T>::Insert], heap_size: " << key << endl;
    
    BSTNode<T> *new_node = new BSTNode<T>(key, nullptr, nullptr, nullptr);
    if (root_ == nullptr) {
        root_ = new_node;
        return;
    }
       
    BSTNode<T> *cur = root_;
    BSTNode<T> *parent = nullptr;
    
    // 查找插入位置
    while (cur != nullptr) {
        parent = cur;
        if (key < cur->key_)
            cur = cur->left_;
        else
            cur = cur->right_;
    }
    
    if (key < parent->key_)
        parent->left_ = new_node;
    else
        parent->right_ = new_node;
    
    new_node->parent_ = parent;
}

template<class T>
void BSTree<T>::Order(BSTOrder order) {
    cout << "[BSTree<T>::Order], order: " << (int)order << endl;
    
    Order(root_, order);
    
    cout << endl;
}

template<class T>
void BSTree<T>::Order(BSTNode<T>* node, BSTOrder order) {
    if (node != nullptr) {
        if (order == BSTOrder::PreOder)
            cout << node->key_ << "\t";
        
        Order(node->left_, order);
        
        if (order == BSTOrder::InOrder)
            cout << node->key_ << "\t";
        
        Order(node->right_, order);
        
        if (order == BSTOrder::PostOrder)
            cout << node->key_ << "\t";
    }
}

template<class T>
T BSTree<T>::Minimum() {
    if (root_ == nullptr)
        throw "[BSTree<T>::Minimum], Error: tree is null";
    
    BSTNode<T> *curr = root_;
    
    while (curr->left_ != nullptr)
        curr = curr->left_;
    
    return curr->key_;
}

template<class T>
T BSTree<T>::Maximum() {
    if (root_ == nullptr)
        throw "[BSTree<T>::Maximum], Error: tree is null";
    
    BSTNode<T> *curr = root_;
    
    while (curr->right_ != nullptr)
        curr = curr->right_;
    
    return curr->key_;
}

template<class T>
void BSTree<T>::Remove(T key) {
    cout << "[BSTree<T>::Remove], key: " << key << endl;
    
    BSTNode<T> *target = root_;

    while (target != nullptr && target->key_ != key) {
        if (key < target->key_)
            target = target->left_;
        else
            target = target->right_;
    }
    
    if (target == nullptr) {
        cout << "[BSTree<T>::Remove] Warning: didn't find the key: " << key << endl;
        return;
    }
    
    if (target->left_ != nullptr && target->right_ != nullptr) {
        BSTNode<T> *iter = target->right_;
        
        while (iter->left_ != nullptr) {
            iter = iter->left_;
        }
        
        iter->parent_->left_ = iter->right_;
        if (iter->right_ != nullptr)
            iter->right_->parent_ = iter->parent_;
        
        target->key_ = iter->key_;
        delete iter;
        
    } else if (target->left_ != nullptr || target->right_ != nullptr) {
        BSTNode<T> *child = target->left_ != nullptr ? target->left_ : target->right_;
        
        if (target->key_ > target->parent_->key_)
            target->parent_->right_ = child;
        else
            target->parent_->left_ = child;
        
        child->parent_ = target->parent_;
        delete target;
    
    }else {
        if (key > target->parent_->key_)
            target->parent_->right_ = nullptr;
        else
            target->parent_->left_ = nullptr;
        
        delete target;
    }
}

template<class T>
bool BSTree<T>::Search(BSTNode<T> &node, T key) {
    BSTNode<T>* cur = root_;
    
    while (cur != nullptr && cur->key_ != key){
        if (key < cur->key_)
            cur = cur->left_;
        else
            cur = cur->right_;
    }
    
    if (cur != nullptr) {
        node.key_ = cur->key_;
        return true;
    }
    
    return false;
}

#endif /* binary_search_tree_hpp */
