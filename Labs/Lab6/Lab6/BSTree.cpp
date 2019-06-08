//
//  BSTree.cpp
//  Lab6
//
//  Created by  Марина on 6/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "BSTree.hpp"

BSTree BSTree::create_empty() {
    return BSTree();
}

void BSTree::add(TimeAndDate dat, BSTree* node) {
    if (dat < node->data) {
        if (node->left != nullptr) {
            add(dat, node->left);
        } else {
            node->left = new BSTree;
            node->left->data = dat;
            node->left->left = nullptr;
            node->left->right = nullptr;
        }
    }
    else {
        if (node->right != nullptr) {
            add(dat, node->right);
        } else {
            node->right = new BSTree;
            node->right->data = dat;
            node->right->right = nullptr;
            node->right->left = nullptr;
        }
    }
}

void BSTree::add(TimeAndDate dat) {
    if (root != nullptr) {
        add(dat, root);
    } else {
        root = new BSTree;
        root->data = dat;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BSTree::tprint(BSTree* node) {
    if(node != nullptr) {
        std::cout << node->data.to_string();
        if(node->left != 0 && node->right != 0) {
            std::cout << "(";
            tprint(node->left);
            std::cout << ", ";
            tprint(node->right);
            std::cout << ")";
        }
        else if(node->left == 0 && node->right != 0) {
            std::cout << "(.., ";
            tprint(node->right);
            std::cout << ")";
        }
        else if(node->left != 0 && node->right == 0) {
            std::cout << "(";
            tprint(node->left);
            std::cout << ", ..)";
        }
        
    }
}

void BSTree::tprint() {
    tprint(root);
}

void BSTree::print(BSTree* node) {
    if (node == nullptr) { return; }
    print(node->right);
    std::cout << node->data.to_string() << ' ';
    print(node->left);
}

void BSTree::print() {
    print(root);
}


