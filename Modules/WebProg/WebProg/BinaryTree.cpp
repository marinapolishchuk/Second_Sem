//
//  BinaryTree.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "BinaryTree.hpp"

void BTNode::add(WebProg dat, BTNode* node) {
    if (dat.get_mark() < node->data->get_mark()) {
        if (node->left != nullptr) {
            add(dat, node->left);
        } else {
            node->left = new BTNode;
            node->left->data = std::make_unique<WebProg>(dat);
            node->left->left = nullptr;
            node->left->right = nullptr;
        }
    }
    else if (dat.get_mark() >= node->data->get_mark()) {
        if (node->right != nullptr) {
            add(dat, node->right);
        } else {
            node->right = new BTNode;
            node->right->data = std::make_unique<WebProg>(dat);
            node->right->right = nullptr;
            node->right->left = nullptr;
        }
    }
}

void BTNode::add(WebProg dat) {
    if (root != nullptr) {
        add(dat, root);
    } else {
        root = new BTNode;
        root->data = std::make_unique<WebProg>(dat);
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BTNode::print(BTNode* node) {
    if(node != nullptr) {
        std::cout << node->data->get_name();// << "[" << node->data->get_mark() << "]";
        if(node->left != 0 && node->right != 0) {
            std::cout << "(";
            print(node->left);
            std::cout << ", ";
            print(node->right);
            std::cout << ")";
        }
        else if(node->left == 0 && node->right != 0) {
            std::cout << "(.., ";
            print(node->right);
            std::cout << ")";
        }
        else if(node->left != 0 && node->right == 0) {
            std::cout << "(";
            print(node->left);
            std::cout << ", ..)";
        }
        
    }
}

void BTNode::print() {
    print(root);
}

void BTNode::postorder_print(BTNode* node) {
    if (node == nullptr) { return; }
    postorder_print(node->left);
    postorder_print(node->right);
    std::cout << node->data->get_name() << "[" << node->data->get_mark() << "] ";
}

void BTNode::postorder_print() {
    postorder_print(root);
}

BTNode* BTNode::search(double mark, double prec) {
    return search(mark, prec, root);
}

BTNode* BTNode::search(double mark, double prec, BTNode* root) {
    if(root != nullptr){
        if(std::abs(mark - root->data->get_mark()) <= prec){
            return root;
        }
        if(mark - root->data->get_mark() < 0){
            return search(mark, prec, root->left);
        }
        else { return search(mark, prec, root->right); }
    }
    else { return nullptr; }
}

WebProg& BTNode::get_data() {
    return *data;
}
