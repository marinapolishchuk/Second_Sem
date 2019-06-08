//
//  BSTree.hpp
//  Lab6
//
//  Created by  Марина on 6/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp
#include "headers.h"

class BSTree {
private:
    TimeAndDate data;
    BSTree* root;
    BSTree* left;
    BSTree* right;
    void add(TimeAndDate data, BSTree* node);
    void tprint(BSTree* node);
    void print(BSTree* node);
    BSTree* min_node(BSTree* node);
public:
    BSTree() = default;
    ~BSTree() = default;
    static BSTree create_empty();
    void add(TimeAndDate data);
    void tprint();
    void print();
};

#endif /* BSTree_hpp */
