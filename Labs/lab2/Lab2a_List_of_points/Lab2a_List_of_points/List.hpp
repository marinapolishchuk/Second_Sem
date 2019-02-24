//
//  List.hpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/11/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <iostream>
#include "Point.hpp"

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
    static List create_empty(); //+
    bool empty(); //+
    void append(T); //+
    void insert(int, T); //+
    void remove(int); //+
    Node* find_by_indx(int); //+
    T get(int); //+
    void set(int, T); //+
    int length(); //+
    void print(); //+
    void print_with_address(); //+
    
    /*List& operator +=(const Point& p){
        this->append(p);
        return *this;
    }*/
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
List<T> List<T>::create_empty() {
    return List();
}

template <typename T>
bool List<T>::empty() {
    return last == nullptr;
}

template <typename T>
void List<T>::append(T dat) {
    len++;
    if (empty()) {
        first = last = new Node{dat, nullptr};
        return;
    }
    last->next = new Node{dat, nullptr};
    last = last->next;
}

template <typename T>
void List<T>::insert(int indx, T dat) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    Node* head = first;
    Node* inserted_el = nullptr;
    int count = 0;
    while(head) {
        if(indx == 0) { inserted_el = new Node{dat, head}; first = inserted_el; return; }
        else if (indx == len) { inserted_el = new Node{dat, nullptr}; last->next = inserted_el; return; }
        else if(count == indx - 1) {
            inserted_el = new Node{dat, head->next};
            head->next = inserted_el;
            len++;
            return;
        }
        head = head->next;
        count++;
    }
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
    len--;
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

template <typename T>
T List<T>::get(int indx) {
    if(indx > len - 1) { std::cout << "Error. Entered index is not valid" << std::endl; exit(0); }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    return find_by_indx(indx)->data;
}

template <typename T>
void List<T>::set(int indx, T dat) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    indx >= 0 ? indx = indx : indx = len - abs(indx);
    Node* temp = find_by_indx(indx);
    temp->data = dat;
}

template <typename T>
int List<T>::length() {
    return len;
}

template <typename T>
void List<T>::print() {
    Node* head = first;
    while(head->next) {
        std::cout << head->data.toString() << ' ';
        head = head->next;
    }
    std::cout << head->data.toString() << std::endl;
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
