//
//  LinkedList.hpp
//  Lab6
//
//  Created by  Марина on 6/3/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "headers.h"

class OrderedLL {
private:
    struct Node {
        TimeAndDate data;
        Node* prev;
        Node* next;
    };
    Node* first;
    Node* last;
    int len;
public:
    OrderedLL();
    ~OrderedLL();
    static OrderedLL create_empty();
    int size();
    void add(TimeAndDate dat);
    void remove(int indx);
    Node* search(TimeAndDate data);
    std::vector<Node*> search(TimeAndDate begin, TimeAndDate end);
    void print();
    void generate(int size);
};

#endif /* LinkedList_hpp */
