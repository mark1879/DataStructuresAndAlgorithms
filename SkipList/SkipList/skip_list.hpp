//
//  skip_list.hpp
//  SkipList
//
//  Created by MarkWu on 2021/6/8.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef skip_list_hpp
#define skip_list_hpp

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *right_, *down_;
    int val_;
    Node(Node *right, Node *down, int val){
        right_ = right;
        down_ = down;
        val_ = val;
    }
};

class SKipList{

private:
    Node *head_;
    const int MIN_INT = std::numeric_limits<int>::min();
    
public:
    SKipList(){
        head_ = new Node(NULL, NULL, MIN_INT);
    }
    
    void Insert(int value){
        vector<Node *> path;
        Node *iter = head_;
        
        while(iter){
            while(iter->right_ && iter->right_->val_ < value){
                iter = iter->right_;
            }
            path.push_back(iter);
            iter = iter->down_;
        }
        
        bool insert_up = true;
        Node *down_node = nullptr;
        
        while(insert_up && path.size() > 0){
            Node *insert_node = path.back();
            path.pop_back();
            insert_node->right_ = new Node(insert_node->right_, down_node, value);
            down_node = insert_node->right_;
            insert_up = (rand() & 1) == 0;
        }
        
        // 新加一层
        if (insert_up){
            head_ = new Node(new Node(NULL, down_node, value), head_, MIN_INT);
        }
    }
    
    bool Search(int target){
        Node *iter = head_;
        while (iter){
            while (iter->right_ && iter->right_->val_ < target){
                iter = iter->right_;
            }
            
            if (iter->right_ && iter->right_->val_ == target)
                return true;
            
            iter = iter->down_;
        }
        
        return false;
    }
    
    bool Delete(int target){
        Node *iter = head_;
        bool deleted = false;
        
        while(iter){
            while (iter->right_ && iter->right_->val_ < target){
                iter = iter->right_;
            }
            
            if (iter->right_ && iter->right_->val_ == target){
                deleted = true;
                iter->right_ = iter->right_->right_;
            }
            
            iter = iter->down_;
        }
        
        return deleted;
    }
};


#endif /* skip_list_h */
