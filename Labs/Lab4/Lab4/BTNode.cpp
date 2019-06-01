//
//  BTNode.cpp
//  Lab4
//
//  Created by  Марина on 5/30/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "BTNode.hpp"

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
    if(count > 0){
        add(dat, root);
        count++;
    } else {
        root = this;
        data = dat;
        left = nullptr;
        right = nullptr;
        count++;
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

unsigned BTNode::size() {
    return count;
}

void BTNode::NLR(BTNode *start, BTNode* dest, int &count, bool& found) {
    ++count;
    if (start == dest || found) {
        found = true;
        return;
    }
    if (start->left != nullptr) NLR(start->left, dest, count, found);
    if (start->right != nullptr) NLR(start->right, dest, count, found);
}

unsigned BTNode::node_count(BTNode* node, BTNode* root) {
    int count = 0;
    bool found = false;
    if (node != nullptr) NLR(root, node->right, count, found);
    return count;
}


void BTNode::make_table(std::vector<table_element> &table, BTNode* root) {
    table.push_back(table_element{this->data, node_count(this->right, root), this->left != nullptr});
    if (this->left != nullptr) {
        this->left->make_table(table, root);
    }
    if (this->right != nullptr) {
        this->right->make_table(table, root);
    }
}

void BTNode::print_table() {
    std::vector<table_element> vec;
    make_table(vec, this);
    std::cout << "Data: ";
    for (auto &a : vec) {
        std::cout << std::setw(3) << a.dat << ' ';
    }
    std::cout << std::endl << std::setw(6);
    std::cout << "R: ";
    for (auto &a : vec) {
        std::cout << std::setw(3) << a.r << ' ';
    }
    std::cout << std::endl << std::setw(6);
    std::cout << "IsL: ";
    for (auto &a : vec) {
        std::cout << std::setw(3) << a.isl << ' ';
    }
    std::cout << std::endl;
}



