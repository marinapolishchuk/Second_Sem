//
//  List.hpp
//  List_realization
//
//  Created by Marina Polishchuk on 2/8/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include <iostream>
#include <algorithm> // std::swap

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* first;
    Node* last;
    int len;
public:
    List();
    ~List();
    void push_back(T);
    bool empty();
    void print();
    void print_with_address();
    int length();
    Node* find_by_indx(int); // return ptr
    void rotate(int, int, int);
    void set(int, T);
    T get(int); // return data
    void insert(int, T); // insert after an element by indx
    void remove(int); // delete by indx
};

template <typename T>
List<T>::List() : len(0) {
    first = last = nullptr;
}

template <typename T>
List<T>::~List() {
    Node* head = first;
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    first = last = nullptr;
}

template <typename T>
void List<T>::push_back(T data) {
    len++;
    if (empty()) {
        first = last = new Node{data, nullptr};
        return;
    }
    last->next = new Node{data, nullptr};
    last = last->next;
}

template <typename T>
bool List<T>::empty() {
    return last == nullptr;
}

template <typename T>
void List<T>::print() {
    Node* head = first;
    while(head->next) {
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << head->data << std::endl;
}

template <typename T>
void List<T>::print_with_address() {
    Node* head = first;
    while(head) {
        std::cout << "Element's data: " << head->data << ", Address: " << head << std::endl;
        head = head->next;
    }
}

template <typename T>
int List<T>::length() {
    return len;
}

template <typename T>
typename List<T>::Node* List<T>::find_by_indx(int indx) {
    Node* needed_el = nullptr;
    int count = 0;
    Node* head = first;
    while(head) {
        if(count == indx) { needed_el = head; break; }
        count++;
        head = head->next;
    }
    return needed_el;
}

// Лабораторна 2b. Задача 11. Реалізувати операцію rotate для списків. Ця операція приймає три індекси begin, new_begin, end і переставляє елементи між begin та end таким чином, щоб новим початком став елемент new_begin, при цьому відносний порядок елементів зберігається. Наприклад, якщо List = [0,1,2,3,4,5,6,7], то rotate(lst, 2, 4, 5) = [0,1,4,5,2,3,6,7]. (1, 3, 5)[0,1,2,3,4,5,6]->[0,3,4,5,1,2,6]
template <typename T>
void List<T>::rotate(int begin_indx, int new_begin_indx, int end_indx) {
    Node* pBegin = find_by_indx(begin_indx), *pNew_begin = find_by_indx(new_begin_indx), *pEnd = find_by_indx(end_indx);
    Node* head = first;
    
    Node* el_before_begin = nullptr;
    while(head) {
        if(head->next == pBegin) { el_before_begin = head; break; }
        head = head->next;
    }
    
    Node* el_before_new_begin = nullptr;
    while(head) {
        if(head->next == pNew_begin) { el_before_new_begin = head; break; }
        head = head->next;
    }
    
    el_before_begin->next = pNew_begin;
    el_before_new_begin->next = pEnd->next;
    pEnd->next = pBegin;
}

//Лабораторна 2b. Завдання 1. Реалізувати список з операціями get, set - доступу за індексом, insert - вставки за індексом, remove - вилучення за індексом. Індекс може бути як позитивним (тоді це звичайний штдекс від початку, починаючи з 0), так і негативним (тоді це індекс з кінця списку). Наприклад, якщо lst = [1,2,3,4,5], то lst[0] == 1, lst[2] == 3, lst[-1] == 5, lst[-3] == 3&
template <typename T>
void List<T>::set(int indx, T dat) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    Node* temp = find_by_indx(indx);
    temp->data = dat;
}

template <typename T>
T List<T>::get(int indx) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return 0; }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    return find_by_indx(indx)->data;
}

template <typename T>
void List<T>::insert(int indx, T dat) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    Node* head = first;
    int count = 0;
    while(head) {
        if(count == indx) { break; }
        head = head->next;
        count++;
    }
    Node* new_el = new Node{dat, head->next};
    head->next = new_el;
}

template <typename T>
void List<T>::remove(int indx) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    Node* head = first;
    int count = 0;
    while(head) {
        if(count == indx - 1) {
            Node* temp = head->next;
            head->next = head->next->next;
            delete temp;
            break;
        }
        head = head->next;
        count++;
    }
}

#endif /* List_hpp */
