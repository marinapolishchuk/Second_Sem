//
//  Array.hpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp
#include <iostream>

template <typename T, size_t N>
class Array {
private:
    T array[N];
    int len;
public:
    Array() = default; //+
    ~Array() = default; //+
    constexpr size_t size(); //+
    T& operator[](size_t);
};


template <typename T, size_t N>
constexpr size_t Array<T, N>::size() {
    return N;
}

template <typename T, size_t N>
T& Array<T, N>::operator[](size_t indx) {
    if (indx >= N) { std::cout << "Error in get function. Wrong index." << std::endl; exit(0); }
    return array[indx];
}

#endif /* List_array_hpp */
