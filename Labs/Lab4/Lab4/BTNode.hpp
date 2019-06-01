//
//  BTNode.hpp
//  Lab4
//
//  Created by  Марина on 5/30/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef BTNode_hpp
#define BTNode_hpp

#include "helpers.h"

struct table_element {
    int dat;
    unsigned int r;
    bool isl;
};

class BTNode {
private:
    int data;
    BTNode* root;
    BTNode* left;
    BTNode* right;
    unsigned count;
    void add(const int &dat, BTNode* leaf); //+
    void print(BTNode* node); //+
    void make_table(std::vector<table_element> &table, BTNode* root); //+
    unsigned node_count(BTNode* node, BTNode* root); //+
    void NLR(BTNode* start, BTNode* dest, int& count, bool& found); //+
public:
    BTNode() : count(0) {};
    ~BTNode() = default;
    void add(const int &dat); //+
    void print(); //+
    unsigned size(); //+
    void print_table(); //+

};

#endif /* BTNode_hpp */
