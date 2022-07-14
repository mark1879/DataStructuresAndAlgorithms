//
//  task.hpp
//  ThreadPool
//
//  Created by MarkWu on 2022/5/31.
//

#ifndef task_hpp
#define task_hpp
#include <iostream>

using namespace std;

class Task {
public:
    template<typename Func_T, typename ...ARGS>
    Task(Func_T func, ARGS ...args) {
        this->func_ = bind(func, forward<ARGS>(args)...);
    }
    
    void run() {
        this->func_();
        return;
    }
    
public:
    function<void()> func_;
};


#endif /* task_h */
