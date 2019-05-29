//
//  TreeNode.cpp
//  Lab4
//
//  Created by  Марина on 5/29/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "TreeNode.hpp"

void TreeNode::add(const int &dat) {
    if (this->root == nullptr) {
        this->root = this;
        this->root->data = dat;
        count++;
    } else {
        TreeNode* new_el = new TreeNode;
        new_el->data = dat;
        new_el->root = this;
        this->children.push_back(new_el);
        count++;
    }
}

void TreeNode::print() {
    std::cout << data << ' ' << this;
    if (!(children.empty())) {
        std::cout << "(";
        for (int i = 0; i < children.size() - 1; ++i) {
            children[i]->print();
            std::cout << ", ";
        }
        children.back()->print();
        std::cout << ")";
    }
}

int TreeNode::size() {
    return count;
}

int TreeNode::get_data() {
    return data;
}

TreeNode* TreeNode::get_element_by_path(const std::vector<int> &path) {
    TreeNode* res = nullptr;
    if(path.empty()) { res = this; }
    else {
        std::vector<TreeNode*> temp_ch = children;
        for (size_t i = 0; i < path.size(); ++i) {
            res = temp_ch[path[i]];
            temp_ch = temp_ch[path[i]]->children;
        }
    }
    return res;
}

TreeNode* TreeNode::find_node(const int &dat, bool &found) {
    if (this->data == dat) { found = true; return this; }
    for (size_t i = 0; i < children.size(); ++i) {
        TreeNode* child = children[i]->find_node(dat, found);
        if (found) { return child; }
    }
    return nullptr;
}

TreeNode* TreeNode::get_node_by_data(const int &dat) {
    if (this->data == dat) { return this; }
    else {
        bool found = false;
        for (size_t i = 0; i < children.size(); ++i) {
            TreeNode* child = children[i]->find_node(dat, found);
            if (found) { return child; }
        }
    }
    return nullptr;
}

std::vector<int> TreeNode::get_path(const int &dat) {
    std::vector<int> path(0);
    if (this->data == dat) {
        return path;
    } else {
        TreeNode* node = get_node_by_data(dat);
        if (node != nullptr) {
            for (size_t i = 0; i < node->root->children.size(); ++i)    {
                if(node->root->children[i] == node) {
                    path.insert(path.begin(), i);
                    i = 0;
                    if (node->root != nullptr) {
                        node = node->root;
                        
                    } else { break; }
                }
            }
        }
    }
    return path;
}

void TreeNode::add_by_path(const int &dat, const std::vector<int> &path) {
    

}

