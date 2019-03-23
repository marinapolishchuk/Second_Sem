//
//  Stack.cpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "Parallelepiped.hpp"

class Stack {
    Parallelepiped* arr;
    int cap;
    int len;
    
    void resize(int);
public:
    Stack();
    void add(Parallelepiped);
    Parallelepiped top();
    void pop();
    int size();
    bool empty();
    void print();
    
};

Stack::Stack() : len(0), cap(1) {
    arr = new Parallelepiped[cap];
}

void Stack::resize(int new_size) {
    cap = new_size;
    Parallelepiped* temp = new Parallelepiped[cap];
    for (int i = 0; i < len; ++i) {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}

void Stack::add(Parallelepiped dat) {
    if (len == cap) { resize(cap * 2); }
    arr[len++] = dat;
}

Parallelepiped Stack::top() {return arr[len - 1];}
void Stack::pop() {
    --len;
}

int Stack::size() {return len;}

bool Stack::empty() {return len == 0;}

void Stack::print() {
    if (empty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    for (int i = 0; i < len; ++i)
        std::cout << arr[i].toString() << std::endl;
}

#endif /* Stack_hp */
