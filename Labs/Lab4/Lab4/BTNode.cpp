//
//  BTNode.cpp
//  Lab4
//
//  Created by  Марина on 5/30/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "BTNode.hpp"
#include <iostream>

void BTNode::add(const int &dat, BTNode* leaf){
    if(dat < leaf->data){
        if(leaf->left != nullptr) {
            add(dat, leaf->left);
        } else {
            leaf->left = new BTNode;
            leaf->left->data = dat;
            leaf->left->root = leaf;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    } else if (dat >= leaf->data) {
        if (leaf->right != nullptr) {
            add(dat, leaf->right);
        } else {
            leaf->right = new BTNode;
            leaf->right->data = dat;
            leaf->right->root = leaf;
            leaf->right->right = nullptr;
            leaf->right->left = nullptr;
        }
    }
}

void BTNode::add(const int &dat) {
    if(root != nullptr){
        add(dat, root);
    } else {
        root = new BTNode;
        root->data = dat;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BTNode::print(BTNode* node) {
    if(node != nullptr) {
        std::cout << node->data;
        if(node->left != nullptr && node->right != nullptr) {
            std::cout << "(";
            print(node->left);
            std::cout << ", ";
            print(node->right);
            std::cout << ")";
        }
        else if(node->left == nullptr && node->right != nullptr) {
            std::cout << "(.., ";
            print(node->right);
            std::cout << ")";
        }
        else if(node->left != nullptr && node->right == nullptr) {
            std::cout << "(";
            print(node->left);
            std::cout << ", ..)";
        }
    }
}

void BTNode::print() {
    print(root);
}

