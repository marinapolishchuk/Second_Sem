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
    static Vector create_empty(); //+
    bool empty(); //+
    void append(T); //+
    void insert(int, T); //+
    void remove(int); //+
    T get(int); //+
    void set(int, T); //+
    size_t length(); //+
    size_t capacity(); //+
    void print(); //+
    void print_with_address(); //+
};

template <typename T>
Vector<T>::Vector() : len(0), cap(1) {
    array = new T[cap];
}

template <typename T>
Vector<T> Vector<T>::create_empty() {
    return Vector();
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
void Vector<T>::append(T dat) {
    if (len == cap) { resize(cap * 2); }
    array[len++] = dat;
}

template <typename T>
void Vector<T>::insert(int indx, T dat) {
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
T Vector<T>::get(int indx) {
    return array[indx];
}

template <typename T>
void Vector<T>::set(int indx, T dat) {
    array[indx] = dat;
}

template <typename T>
size_t Vector<T>::length() {
    return len;
}

template <typename T>
size_t Vector<T>::capacity() {
    return cap;
}

template <typename T>
void Vector<T>::print() {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i].toString() << ' ';
    }
}

template <typename T>
void Vector<T>::print_with_address() {
    for (int i = 0; i < len; ++i) {
        std::cout << "Data: " << array[i].toString() << ", Address: " << &array[i] << std::endl;
    }
}

#endif /* List_dynamic_arr_hpp */
