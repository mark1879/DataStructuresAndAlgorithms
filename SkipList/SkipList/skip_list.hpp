//
//  skip_list.hpp
//  SkipList
//
//

#ifndef skip_list_hpp
#define skip_list_hpp

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node {
    int key_;
    T value_;
    vector<Node*> nexts_;
    
    Node(int k, T v, int level) : key_(k), value_(v) {
        for (int i = 0; i < level; i++)
            nexts_.push_back(nullptr);
    }
};

template<class T>
class SkipList {
private:
    Node<T>* head_;
    int current_highest_level_;
    int kMAX_LEVEL = 16;
public:
    SkipList() : current_highest_level_(0) {
        head_ = new Node<T>(INT_MIN, INT_MIN, kMAX_LEVEL);
    }
    
    ~SkipList() {
        delete head_;
    };
    
    Node<T>* Find(int key) {
        Node<T>* iter = head_;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            while (iter->nexts_[i] && iter->nexts_[i]->key_ < key) {
                iter = iter->nexts_[i];
            }
            
            if (iter->nexts_[i] && iter->nexts_[i]->key_ == key)
                return iter->nexts_[i];
        }
        
        return nullptr;
    }
    
    bool Add(int key, T value) {
        Node<T>* new_node = Find(key);
        if (new_node) {
            new_node->value_ = value;
            cout << "The key: " << key << " has been existed, upate it's value: " << value << endl;
            return true;
        }
        
        int random_level = RandomLevel();
        
        current_highest_level_ = max(current_highest_level_, random_level);
        new_node = new Node<T>(key, value, random_level);
        Node<T>* iter = head_;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            while (iter->nexts_[i] && iter->nexts_[i]->key_ < key) {
                iter = iter->nexts_[i];
            }
            
            if (i < random_level) {
                new_node->nexts_[i] = iter->nexts_[i];
                iter->nexts_[i] = new_node;
            }
        }
        
        return true;
    }
    
    bool Delete(int key) {
        if (!Find(key)) {
            cout << "The key: " << key << " doesn't exist!" << endl;
            return false;
        }
        
        Node<T>* iter = head_;
        Node<T>* del = nullptr;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            while (iter->nexts_[i] && iter->nexts_[i]->key_ < key) {
                iter = iter->nexts_[i];
            }
            
            del = iter->nexts_[i];
            iter->nexts_[i] = del->nexts_[i];
            
            if(!head_->nexts_[i])
                current_highest_level_ = i;
        }
        
        if (del)
            delete(del);
        
        return true;
    }
    
    void Print() {
        cout << "Print the skip list: " << endl;
        
        for (int i = current_highest_level_ - 1; i >= 0; --i) {
            cout << "Level: " << i << endl;
            
            Node<T> *iter = head_;
            
            cout << "{ ";
            
            while (iter->nexts_[i] != nullptr) {
                cout << "(key: " << iter->nexts_[i]->key_ << ", value: " << iter->nexts_[i]->value_ << "), ";
                iter = iter->nexts_[i];
            }
            
            cout << " }" << endl;
        }
    }
    
private:
    int RandomLevel() {
        int random_level = 1;
        
        while (rand() % 2 == 1 && random_level <= kMAX_LEVEL)
            ++random_level;
        
        return random_level;
    }
};

#endif /* skip_list_hpp */
