//
//  main.cpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include "List.hpp"
#include "Stack.hpp"

void task3(List& l, Stack& s);

int main() {
    List l;
    Stack s;
    for (size_t i = 0; i < 15; ++i) {
        Parallelepiped p;
        p.GenerateVectors();
        l.push_back(p);
        s.add(p);
    }

    l.print_keys();
    return 0;
}


void task3(List& l, Stack& s) {
    int size = l.length() / 5;
    for (int i = 0; i < size; ++i) {
        s.add(l.get(i));
        l.remove(i);
    }
    
    int step = 0;
    while (!l.empty()) {
        Parallelepiped _1 = l.get(l.length() - 1);
        Parallelepiped _2 = s.top();
        Parallelepiped _3;
        
        l.remove(l.length() - 1);
        s.pop();
        _3.GenerateVectors();
        
        int val_1_2 = _1.Get_Value() + _2.Get_Value();
        int val_1_3 = _1.Get_Value() + _3.Get_Value();
        int val_2_3 = _2.Get_Value() + _3.Get_Value();
        
        if (_1.Get_Value() > val_2_3)
            s.add(_1);
        else if (_2.Get_Value() > val_1_3)
            s.add(_2);
        else if (_3.Get_Value() > val_1_2)
            s.add(_3);
        else {
            Parallelepiped p;
            p.GenerateVectors();
            s.add(p);
        }
        ++step;
        
        
        
    }
}
