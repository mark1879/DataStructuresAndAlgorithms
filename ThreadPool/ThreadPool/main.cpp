//
//  main.cpp
//  ThreadPool
//
//  Created by MarkWu on 2022/5/31.
//

#include <iostream>
#include "task.hpp"
#include "thread_pool.hpp"
#include "heap_queue.hpp"

void func(int a, int b) {
    cout << a << " + " << b << " = " << (a + b) << endl;
}

int main() {
    ThreadPool<HeapQueue<Task *>> thread_pool(5);
    
    this_thread::sleep_for(chrono::seconds(2));
    thread_pool.AddOneTask(new Task(func, 3, 4));
    thread_pool.AddOneTask(new Task(func, 5, 10));
    thread_pool.AddOneTask(new Task(func, 14, 60));
    
    this_thread::sleep_for(chrono::seconds(2));
    
    return 0;
}
