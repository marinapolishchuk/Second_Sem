//
//  List.hpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include "Parallelepiped.hpp"


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
    List(); //+
    ~List(); //+
    bool empty(); //+
    void push_back(T); //+
    int length(); //+
    void print(); //+
    void print_with_address(); //+
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
bool List<T>::empty() {
    return last == nullptr;
}

template <typename T>
void List<T>::push_back(T dat) {
    len++;
    if (empty()) {
        first = last = new Node{dat, nullptr};
        return;
    }
    last->next = new Node{dat, nullptr};
    last = last->next;
}

template <typename T>
int List<T>::length() {
    return len;
}

template <typename T>
void List<T>::print() {
    Node* head = first;
    while(head) {
        std::cout << head->data.toString() << std::endl;
        head = head->next;
    }
   
}

template <typename T>
void List<T>::print_with_address() {
    Node* head = first;
    while(head) {
        std::cout << "Element's data: " << head->data.toString() << ", Address: " << head << std::endl;
        head = head->next;
    }
}

#endif /* List_hpp */
