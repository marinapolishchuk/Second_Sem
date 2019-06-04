//
//  ArrayBasedList.hpp
//  Lab6
//
//  Created by  Марина on 6/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef ArrayBasedList_hpp
#define ArrayBasedList_hpp

#include "headers.h"

template <size_t N>
class OrderedArrL {
private:
    TimeAndDate array[N];
    size_t len;
public:
    OrderedArrL();
    ~OrderedArrL() = default;
    static OrderedArrL create_empty();
    void add(TimeAndDate dat);
    void remove(unsigned indx);
    TimeAndDate* search(TimeAndDate data);
    std::vector<TimeAndDate*> search(TimeAndDate begin, TimeAndDate end);
    void print();
    void generate(size_t size);
    
    TimeAndDate& operator[](unsigned indx){
        return array[indx];
    }
    constexpr size_t size() const{
        return N;
    }
    size_t length() {
        return len;
    }
};

template <size_t N>
OrderedArrL<N>::OrderedArrL() : len(0) {
    for (size_t i = 0; i < size(); ++i) {
        array[i].date.day = 0;
        array[i].date.month = 0;
        array[i].date.year = 0;
        
        array[i].time.hours = 0;
        array[i].time.minutes = 0;
    }
}

template <size_t N>
OrderedArrL<N> OrderedArrL<N>::create_empty() {
    return OrderedArrL();
}

template <size_t N>
void OrderedArrL<N>::add(TimeAndDate dat) {
    if (N == 0) { return; }
    if (len == 0) { array[len++] = dat; return; }
    int i = 0;
    for (; i < len && array[i] > dat; ++i);
    for (size_t j = len; j > i; --j) {
        std::swap(array[j], array[j-1]);
    }
    array[i] = dat;
    len++;
    return;
}

template <size_t N>
void OrderedArrL<N>::remove(unsigned indx) {
    for (int i = indx; i < len; ++i) {
        std::swap(array[i], array[i + 1]);
    }
    len--;
}

template <size_t N>
TimeAndDate* OrderedArrL<N>::search(TimeAndDate data) {
    for (size_t i = 0; i < len; ++i) {
        if(array[i] == data) {
            return &array[i];
        }
    }
    return nullptr;
}

template <size_t N>
std::vector<TimeAndDate*> OrderedArrL<N>::search(TimeAndDate begin, TimeAndDate end) {
    std::vector<TimeAndDate*> res;
    for (size_t i = 0; i < len; ++i) {
        if(array[i] > begin && array[i] < end) {
            res.push_back(&array[i]);
        }
    }
    return res;
}

template <size_t N>
void OrderedArrL<N>::print() {
    if (len == 0 || N == 0) { return; }
    for (size_t i = 0; i < len - 1; ++i) {
        std::cout << array[i].to_string() << ", ";
    }
    std::cout << array[len - 1].to_string() << "." << std::endl;
}

template <size_t N>
void OrderedArrL<N>::generate(size_t size) {
    if(size <= N) {
        for (int i = 0; i < size; ++i) {
            TimeAndDate temp;
            temp.generate_random();
            add(temp);
        }
    } else { std::cout << "Error." << std::endl; }
}


#endif /* ArrayBasedList_hpp */
