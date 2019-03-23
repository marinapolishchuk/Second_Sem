//
//  Vector.hpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef List_dynamic_arr_hpp
#define List_dynamic_arr_hpp

#include <iostream>
#include <algorithm> // std::swap

template <typename T>
class Vector {
private:
    T* array;
    size_t len;
    size_t cap;
    void resize(size_t); //+
public:
    Vector(); //+
    ~Vector() = default; //+
    bool empty(); //+
    void push_back(T); //+
    void insert(int, T); //+
    void remove(int); //+
    size_t length(); //+
    size_t capacity(); //+
    
    T& operator[](size_t);
};

template <typename T>
Vector<T>::Vector() : len(0), cap(1) {
    array = new T[cap];
}

template <typename T>
void Vector<T>::resize(size_t new_size) {
    cap = new_size;
    T* temp = new T[cap];
    for (int i = 0; i < len; ++i) {
        temp[i] = array[i];
    }
    delete [] array;
    array = temp;
}

template <typename T>
bool Vector<T>::empty() {
    return len == 0;
}

template <typename T>
void Vector<T>::push_back(T dat) {
    if (len == cap) { resize(cap * 2); }
    array[len++] = dat;
}

template <typename T>
void Vector<T>::insert(int indx, T dat) {
    if (indx >= len) { std::cout << "Error. Can't be inserted by this index." << std::endl; return; }
    len++;
    if (len == cap) { resize(cap * 2); }
    size_t temp = len - 1;
    for (int i = 0; i < len - 1 - indx; i++) {
        std::swap(array[temp - 1], array[temp]);
        temp--;
    }
    array[indx] = dat;
}

template <typename T>
void Vector<T>::remove(int indx) {
    if (indx >= len) { std::cout << "Error. Can't be removed by this index." << std::endl; return; }
    len--;
    for (int i = 0; i < len - 1; ++i) {
        std::swap(array[indx], array[indx + 1]);
        indx++;
    }
    array[indx].x = 0;
    array[indx].y = 0;
    array[indx].z = 0;
    
}

template <typename T>
T& Vector<T>::operator[](size_t indx) {
    if (indx >= len) { std::cout << "Error in get function. Wrong index." << std::endl; exit(0); }
    return array[indx];
}

template <typename T>
size_t Vector<T>::length() {
    return len;
}

template <typename T>
size_t Vector<T>::capacity() {
    return cap;
}

#endif /* List_dynamic_arr_hpp */
