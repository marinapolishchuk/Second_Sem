//
//  List_array.hpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/14/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef List_array_hpp
#define List_array_hpp
#include <iostream>
#include "Point.hpp"
#include <algorithm> //swap

template <typename T, size_t N>
class List_array {
private:
    T array[N];
    int len;
    T* first;
    T* last;
public:
    List_array(); //+
    ~List_array() = default; //+
    static List_array create_empty(); //+
    int length(); //+
    bool empty(); //+
    void append(T); //+
    void insert(int, T); //+
    void remove(int); //+
    T get(int); //+
    void set(int, T); //+
    void print(); //+
    void print_with_address(); //+
    
    //////////////////////////////
    constexpr size_t size() const{
        return N;
    }
    
    T& operator[](size_t indx){
        return array[indx];
    }
};

template <typename T, size_t N>
List_array<T, N>::List_array() : len(0) {
    for (int i = 0; i < size(); ++i) {
        array[i].x = 0;
        array[i].y = 0;
        array[i].z = 0;
        
    }
    first = last = &array[0];
};

template <typename T, size_t N>
List_array<T, N> List_array<T, N>::create_empty() {
    return List_array();
}

template <typename T, size_t N>
int List_array<T, N>::length() {
    return len;
}

template <typename T, size_t N>
bool List_array<T, N>::empty() {
    return len == 0;
}

template <typename T, size_t N>
void List_array<T, N>::append(T dat) {
    if (len < N) {
        if(empty()) {
            *first = *last = dat;
            last = first + 1;
        } else {
            *last = dat;
            last = last + 1;
        }
        len++;
    } else { std::cout << "Error. Can't be appended." << std::endl; return; }
}

template <typename T, size_t N>
void List_array<T, N>::insert(int indx, T dat) {
    if (indx >= len) { std::cout << "Error. Can't be inserted by this index." << std::endl; return; }
    else {
    T* temp = last;
    T* before_temp = last - 1;
    for(int i = 0; i < len - indx; ++i) {
        std::swap(*before_temp, *temp);
        temp = before_temp;
        before_temp -= 1;
    }
    array[indx] = dat;
    len++;
    }
}

template <typename T, size_t N>
void List_array<T, N>::remove(int indx) {
    if (indx >= len) { std::cout << "Error. Can't be removed by this index." << std::endl; return; }
    else {
    array[indx].x = 0;
    array[indx].y = 0;
    array[indx].z = 0;
    T* temp = &array[indx];
    for(int i = 0; i < len - 1 - indx; ++i) {
        std::swap(*temp, *(temp+1));
        temp += 1;
    }
    len--;
    }
}

template <typename T, size_t N>
T List_array<T, N>::get(int indx) {
    if (indx >= len) { std::cout << "Error in get function. Wrong index." << std::endl; exit(0); }
    return array[indx];
}

template <typename T, size_t N>
void List_array<T, N>::set(int indx, T dat) {
    if (indx >= len) { std::cout << "Error in set function. Wrong index." << std::endl; return; }
    else { array[indx] = dat; }
}

template <typename T, size_t N>
void List_array<T, N>::print() {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i].toString() << ' ';
    }
}

template <typename T, size_t N>
void List_array<T, N>::print_with_address() {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i].toString() << ' ' << &array[i] << std::endl;
    }
}

#endif /* List_array_hpp */
