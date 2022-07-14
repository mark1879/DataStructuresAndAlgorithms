//
//  thread_pool.hpp
//  ThreadPool
//
//  Created by MarkWu on 2022/5/31.
//

#ifndef thread_pool_hpp
#define thread_pool_hpp

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <thread>
#include "task.hpp"

using namespace std;


template<typename QueueType = queue<Task *>>
class ThreadPool {
public :
    ThreadPool(size_t size) {
        is_running_ = true;
        
        for (int i = 0; i < size; i++) {
            threads_.push_back(
                new thread(
                    &ThreadPool::ThreadWorker, this
                )
            );
        }
    }
    
    void ThreadWorker() {
        cout << "ThreadWorker begin: " << endl;
        
        while (is_running_) {
            Task *t = this->GetOneTask();
            if (t == nullptr)
                break;
            t->run();
            delete t;
        }
        
        cout << "ThreadWorker end: " << endl;
    }
    
    Task *GetOneTask() {
        unique_lock<mutex> lock(mutex_);
        
        while (is_running_ && tasks_.empty()) cond_var_.wait(lock);
        
        Task *t = nullptr;
        if (is_running_) {
            t = tasks_.front();
            tasks_.pop();
        }
        
        return t;
    }
    
    void AddOneTask(Task *t) {
        unique_lock<mutex> lock(mutex_);
        
        tasks_.push(t);
        cond_var_.notify_one();
    }
    
    ~ThreadPool() {
        do {
            is_running_ = false;
            unique_lock<mutex> lock(mutex_);
            cond_var_.notify_all();
        } while (0);
        
        for (int i = 0; i < threads_.size(); i++) {
            threads_[i]->join();
            delete threads_[i];
        }
        return ;
    }
    
private:
    vector<thread *> threads_;
    QueueType tasks_;
    mutex mutex_;
    condition_variable cond_var_;
    bool is_running_;
};

#endif /* thread_pool_h */
