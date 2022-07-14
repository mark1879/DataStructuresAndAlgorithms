//
//  skip_list.hpp
//  SkipList
//
//  Created by MarkWu on 2021/6/8.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef skip_list2_hpp
#define skip_list2_hpp

#include <iostream>
#include <vector>

using namespace std;

class Skiplist {
    
public:
    struct Node {
        int val_;
        vector<Node*> nexts_;
        Node(int val_ = -1, int level = MAX_LEVEL) : val_(val_), nexts_(level) {}
    };
    
private:
    static const int MAX_LEVEL = 16;
    Node* head_;
    int current_highest_level_ = 0;

public:
    
    Skiplist() {
        head_ = new Node();
    }
    
    bool search(int target) {
        Node* iter = head_;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            while (iter->nexts_[i] && target > iter->nexts_[i]->val_) {
                iter = iter->nexts_[i];
            }
            
            if (iter->nexts_[i] && target == iter->nexts_[i]->val_) {
                return true;
            }
        }
        
        return false;
    }
    
    void add(int value) {
        int random_level = RandomLevel();
        current_highest_level_ = max(current_highest_level_, random_level);
        
        Node* new_node = new Node(value, random_level);
        Node* iter = head_;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            while (iter->nexts_[i] && value > iter->nexts_[i]->val_) {
                iter = iter->nexts_[i];
            }
            
            if (i < random_level) {
                Node* next = iter->nexts_[i];
                iter->nexts_[i] = new_node;
                new_node->nexts_[i] = next;
            }
        }
    }
    
    bool erase(int target) {
        Node* iter = head_;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            while (iter->nexts_[i] && target > iter->nexts_[i]->val_) {
                iter = iter->nexts_[i];
            }
            
            if (iter->nexts_[i] && target == iter->nexts_[i]->val_) {
                Node* del = iter->nexts_[i];
                
                for(; i >= 0; --i){
                    while(iter->nexts_[i] != del)
                        iter = iter->nexts_[i];
                    
                    iter->nexts_[i] = iter->nexts_[i]->nexts_[i];
                    
                    if(!head_->nexts_[i])
                        current_highest_level_ = i;
                }
                
                delete del;
                
                return true;
            }
        }
        return false;
    }

private:
    int RandomLevel(){
        int random_level = 1;
        
        while (rand() % 2 == 1 && random_level <= MAX_LEVEL)
            ++random_level;
        
        return random_level;
    }
};


#endif /* skip_list_h */

