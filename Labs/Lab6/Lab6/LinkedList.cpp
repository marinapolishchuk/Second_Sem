//
//  LinkedList.cpp
//  Lab6
//
//  Created by  Марина on 6/3/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "LinkedList.hpp"

OrderedLL::OrderedLL() : len(0) {
    first = last = nullptr;
}

OrderedLL::~OrderedLL() {
    Node* head = first;
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    first = last = nullptr;
}

OrderedLL OrderedLL::create_empty() {
    return OrderedLL();
}

int OrderedLL::size() {
    return len;
}

void OrderedLL::add(TimeAndDate dat) {
    Node* head = first;
    bool added = true;
    if (head == nullptr) {
        Node* new_node = new Node{dat, nullptr, nullptr};
        first = last = new_node;
        ++len;
    } else {
        while (head) {
            if(dat > head->data) {
                Node* new_node = new Node;
                new_node->data = dat;
                new_node->next = head;
                new_node->prev = head->prev;
                if(head->prev != nullptr) {
                    head->prev->next = new_node;
                } else {
                    first = new_node;
                }
                head->prev = new_node;
                ++len;
                break;
            } else {
                added = false;
                head = head->next;
            }
            
        }
        if(!added) {
            Node* new_node = new Node{dat, last, nullptr};
            last->next = new_node;
            last = new_node;
            ++len;
        }
    }
}

void OrderedLL::remove(int indx) {
    if(indx > len - 1) { std::cout << "Error. Entered index is not valid" << std::endl; return; }
    Node* head = first;
    if(indx == 0) {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        first = head;
        delete temp;
        --len;
    }
    else if(indx == len - 1) {
        Node* temp = last;
        temp->prev->next = nullptr;
        last = temp->prev;
        delete temp;
    } else {
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
        --len;
    }
}

OrderedLL::Node* OrderedLL::search(TimeAndDate dat) {
    Node* res = nullptr;
    Node* head = first;
    while (head) {
        if(head->data == dat) {
            res = head;
            break;
        } else {
            head = head->next;
        }
    }
    return res;
}

std::vector<OrderedLL::Node*> OrderedLL::search(TimeAndDate begin, TimeAndDate end) {
    std::vector<Node*> res;
    Node* head = first;
    while (head) {
        if(head->data > begin && head->data < end) {
            res.push_back(head);
        }
        head = head->next;
    }
    return res;
}


void OrderedLL::print() {
    Node* head = first;
    while(head->next) {
        std::cout << head->data.to_string() << ", ";
        head = head->next;
    }
    std::cout << head->data.to_string() << "." << std::endl;
}

void OrderedLL::generate(int size) {
    for (int i = 0; i < size; ++i) {
        TimeAndDate temp;
        temp.generate_random();
        this->add(temp);
    }
}
