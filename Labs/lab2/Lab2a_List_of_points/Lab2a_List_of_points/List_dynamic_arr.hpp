//
//  List_dynamic_arr.hpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/19/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef List_dynamic_arr_hpp
#define List_dynamic_arr_hpp

#include <iostream>
#include "Point.hpp"

template <typename T>
class List_dynamic_array {
private:
    T* data;
    int len;
    int capacity;
public:
    List_dynamic_array(int);
    List_dynamic_array();
    ~List_dynamic_array();
    static List_dynamic_array create_empty();
    void append(T);
    void insert(int, T);
    void remove(int);
    T get(int);
    void set(int, T);
    int length();
    void print();
    void print_with_address();
};

template <typename T>
List_dynamic_array<T>::List_dynamic_array(int capacity) : capacity(capacity) {
    data = new T[capacity];
}

template <typename T>
List_dynamic_array<T>::List_dynamic_array() : capacity(1) {
    data = new T[capacity];
}

#endif /* List_dynamic_arr_hpp */
