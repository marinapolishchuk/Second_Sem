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


class List {
private:
    struct Node {
        Parallelepiped data;
        int key;
        Node* next;
    };
    Node* first;
    Node* last;
    int len;
public:
    List(); //+
    ~List(); //+
    bool empty(); //+
    void push_back(Parallelepiped); //+
    void remove(size_t);
    Parallelepiped get(size_t);
    void remove(size_t, size_t);
    void transform();
    void insert(size_t, Parallelepiped);
    int length(); //+
    void print(); //+
    void print_with_address(); //+
    void print_keys();
};

List::List() : len(0) {
    first = last = nullptr;
}

List::~List() {
    Node* head = first;
    while(head != last) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    first = last = nullptr;
}

bool List::empty() {
    return first == nullptr;
}

void List::push_back(Parallelepiped dat) {
    len++;
    if (empty()) {
        first = last = new Node{dat, dat.Get_Value() % 17, first};
        return;
    }
    last->next = new Node{dat, dat.Get_Value() % 17, first};
    last = last->next;
}

int List::length() {
    return len;
}

void List::print() {
    Node* head = first;
    while(head != last) {
        std::cout << head->data.toString() << std::endl;
        head = head->next;
    }
    std::cout << head->data.toString() << std::endl;
}

void List::print_with_address() {
    Node* head = first;
    while(head != last) {
        std::cout << "Element's data: " << head->data.toString() << ", Address: " << head << std::endl;
        head = head->next;
    }
    std::cout << "Element's data: " << head->data.toString() << ", Address: " << head << std::endl;
}

void List::print_keys() {
    Node* head = first;
    while(head->next != first) {
        std::cout << head->key << ' ';
        head = head->next;
    }
    std::cout << head->key << std::endl;
}

void List::remove(size_t indx) {
    if(indx >= len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    Node* head = first;
    int count = 0;
    while (count != indx - 1) {
        head = head->next;
        ++count;
    }
    Node* t = head->next;
    if (head->next == last){
        head->next = first;
        last = head;
    }
    else head->next = head->next->next;
    delete t;
    len--;
}

void List::remove(size_t start, size_t end) {
    while (start != end)
        remove(end--);
    remove(start);
}

void List::transform() {
    int del_count = 0;
    while (del_count < 1181) {
        int start = 0, end = 0;
        bool removed = false;
        for (Node* head = first; head != last; head = head->next) {
            if (head->next->key <= head->key) ++end;
            else {
                if (end - start >= 3) {
                    removed = true;
                    remove(start, end);
                    for (int i = 0; i <= (end - start) / 2; ++ i) {
                        Parallelepiped p;
                        p.GenerateVectors();
                        insert(start, p);
                    }
                    break;
                }
                else {
                    start = ++end;
                }
//                ++start;
            }
//            if (end == len - 1 && end - start >= 3) {
//                removed = true;
//                remove(start, end);
//                for (int i = 0; i <= (end - start) / 2; ++ i) {
//                    Parallelepiped p;
//                    p.GenerateVectors();
//                    insert(start, p);
//                }
//                print_keys();
//            }
        }
        if (end == len - 1 && end - start >= 2) {
            removed = true;
            remove(start, end);
            for (int i = 0; i <= (end - start) / 2; ++ i) {
                Parallelepiped p;
                p.GenerateVectors();
                insert(start, p);
            }
        }
        if (!removed) break;
    }
}


void List::insert(size_t indx, Parallelepiped dat) {
    if(indx > len) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    Node* head = first;
    int index = 0;
    while (index != indx - 1) {
        head = head->next;
        ++index;
    }
    Node* t = head->next;
    head->next = new Node{dat, dat.Get_Value() % 17, t};
    if (t == first) {
        last = head->next;
    }
    ++len;
    
    
//    int count = 0;
//    while(head) {
//        if(indx == 0) { inserted_el = new Node{dat, dat.Get_Value() % 17, head}; first = inserted_el; return; }
//        else if (indx == len) { inserted_el = new Node{dat, dat.Get_Value() % 17, first}; last->next = inserted_el; return; }
//        else if(count == indx - 1) {
//            inserted_el = new Node{dat, dat.Get_Value() % 17, head->next};
//            head->next = inserted_el;
//            len++;
//            return;
//        }
//        head = head->next;
//        count++;
//    }
}

Parallelepiped List::get(size_t indx) {
    if(indx >= len) { std::cout << "Error. Entered index is not valid" << std::endl; return Parallelepiped(); }
    Node* head = first;
    int count = 0;
    while (count != indx - 1) {
        head = head->next;
        ++count;
    }
    return head->next->data;
}

#endif /* List_hpp */
