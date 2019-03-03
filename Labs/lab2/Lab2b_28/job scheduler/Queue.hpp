//
//  Queue.hpp
//  job scheduler
//
//  Created by Marina Polishchuk on 2/24/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* first;
    Node* last;
    int len;
public:
    Queue(); //+
    ~Queue() = default; //+
    bool empty(); //+
    void push_back(T); //+
    Node* get_first(); //+
    void remove_first_in_the_end(); //+
    void remove_first_element(); //+
    void print(); //+
    void print_with_address(); //+
    int length(); //+
};

template <typename T>
Queue<T>::Queue() : len(0) {
    first = last = nullptr;
}

template <typename T>
bool Queue<T>::empty() {
    return last == nullptr;
}

template <typename T>
void Queue<T>::push_back(T dat) {
    len++;
    if (empty()) {
        first = last = new Node{dat, nullptr};
        return;
    }
    last->next = new Node{dat, nullptr};
    last = last->next;
}

template <typename T>
typename Queue<T>::Node* Queue<T>::get_first() {
    return first;
}

template <typename T>
void Queue<T>::remove_first_in_the_end() {
    Node* temp = first;
    first = first->next;
    last->next = temp;
    last = last->next;
    last->next = nullptr;
}

template <typename T>
void Queue<T>::remove_first_element() {
    len--;
    Node* temp = first;
    if(len == 0) { first = last = first->next; }
    else { first = first->next; }
    delete temp;
}

template <typename T>
void Queue<T>::print() {
    Node* head = first;
    while(head) {
        std::cout << head->data.text << ". Execute time: " << head->data.execute_time << std::endl;
        head = head->next;
    }
}

template <typename T>
void Queue<T>::print_with_address() {
    Node* head = first;
    while(head) {
        std::cout << "Element's data: " << head->data.text << ", Address: " << head << std::endl;
        head = head->next;
    }
}

template <typename T>
int Queue<T>::length() {
    return len;
}


#endif /* Queue_hpp */
