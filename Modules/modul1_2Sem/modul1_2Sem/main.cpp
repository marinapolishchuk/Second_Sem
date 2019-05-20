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
#include "Array.hpp"
#include "Vector.hpp"

void task3(List& l, Stack& s);
//void task4();


void addToArr(Array<Vector<Parallelepiped>, 103> arr, Parallelepiped p);
Vector<Parallelepiped> getByValue(Array<Vector<Parallelepiped>, 103> arr, int value);

int main() {
    List l;
    Stack s;
    for (size_t i = 0; i < 101; ++i) {
        Parallelepiped p;
        p.GenerateVectors();
        l.push_back(p);
        s.add(p);
    }
    task3(l, s);
   // task4();
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
        if (step == 1) {
            std::cout << "List: ";
            l.print();
            std::cout << "Stack: ";
            s.print();
        } else if (step % 10 == 0) {
            std::cout << "Step " << step << ":" << std::endl;
            std::cout << "Processed: \n1: ";
            std::cout << _1.toString() << std::endl;
            std::cout << "2: " << _2.toString() << std::endl;
            std::cout << "3: " << _3.toString() << std::endl;
            std::cout << "Added to stack: ";
            std:: cout << s.top().toString() << std::endl;
        }
    }
    
    std::cout << "After processing:\nList: ";
    l.print();
    std::cout << "Stack: ";
    s.print();
    
}

void addToArr(Array<Vector<Parallelepiped>, 103> arr, Parallelepiped p) {
    arr[p.Get_Value() % 103].push_back(p);
}


Vector<Parallelepiped> getByValue(Array<Vector<Parallelepiped>, 103> arr, int value) {
    Vector<Parallelepiped> res;
    
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].length(); ++j) {
            if (arr[i][j].Get_Value() == value) res.push_back(arr[i][j]);
        }
    }
    
    return res;
}
