//
//  Tree.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/18/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "TreeNode.hpp"

void TreeNode::add_after_prototype(WebProg& el) {
    WebProg* prot = el.get_prototype();
    if (prot == data) {
        TreeNode* new_el = new TreeNode;
        new_el->root = this;
        new_el->data = &el;
        children.push_back(new_el);
    }
    else if (prot != data) {
        for (int i = 0; i < children.size(); ++i) {
            children[i]->add_after_prototype(el);
        }
    }
    else {
        std::cout << "ERROR. An element can't be added, because this tree doesn't contain its prototype." << std::endl;
        return;
    }
}

void TreeNode::add(WebProg& el) {
    if(this->root == nullptr) {
        this->root = this;
        this->root->data = &el;
    } else {
        this->root->add_after_prototype(el);
    }
}

void TreeNode::print() {
    std::cout << data->get_name();
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

void TreeNode::print_with_addresses() {
    std::cout << data->get_name() << " " << this;
    if (!(children.empty())) {
        std::cout << "(";
        for (int i = 0; i < children.size() - 1; ++i) {
            children[i]->print_with_addresses();
            std::cout << ", ";
        }
        children.back()->print_with_addresses();
        std::cout << ")";
    }
}

TreeNode* TreeNode::find_node(int indx, int& count, bool& found) {
    count++;
    if(indx == count) { found = true; return this; }
    for (int i = 0; i < children.size(); ++i) {
        TreeNode* child = children[i]->find_node(indx, count, found);
        if (found) { return child; }
    }
    return nullptr;
}


TreeNode* TreeNode::get_node_by_preorder_index(int indx) {
    if (indx == 0) { return this; }
    else {
        int count = 0;
        bool found = false;
        for (int i = 0; i < children.size(); ++i) {
            TreeNode* child = children[i]->find_node(indx, count, found);
            if (found) { return child; }
        }
    }
    return nullptr;
}


int TreeNode::height() {
    std::vector<int> h;
    for (int i  = 0; i < children.size(); ++i) {
        h.push_back(children[i]->height());
    }
    return h.empty() ? 1 : *std::max_element(h.begin(), h.end()) + 1;
}

int TreeNode::children_size() {
    return children.size();
}

int TreeNode::subtree_size() {
    int count = 0;
    for (int i = 0; i < children.size(); ++i) {
        count += children[i]->subtree_size();
    }
    return count + 1;
}

double TreeNode::max_mark() {
    double children_max = 0;
    for (int i = 0; i < children.size(); ++i) {
        children_max = std::max(children_max, children[i]->max_mark());
    }
    return std::max(children_max, data->get_mark());
}

double TreeNode::min_mark() {
    double children_min = max_mark();
    for (int i = 0; i < children.size(); ++i) {
        children_min = std::min(children_min, children[i]->min_mark());
    }
    return std::min(children_min, data->get_mark());
}

double TreeNode::sum_of_marks() {
    double sum = 0;
    for (int i = 0; i < children.size(); ++i) {
        sum += children[i]->sum_of_marks();
    }
    return data->get_mark() + sum;
}

double TreeNode::average_mark() {
    return sum_of_marks() / subtree_size();
}

std::vector<TreeNode*> TreeNode::get_nodes_on_lvl(std::vector<TreeNode*>& nodes, int lvl) {
    static int count = 0;
    if (lvl == 0) { nodes.push_back(this); }
    else if (lvl == 1) {
        for (int i = 0; i < children.size(); ++i) {
            nodes.push_back(children[i]);
        }
    }
    else if (count == lvl - 2) {
        for (int i = 0; i < children.size(); ++i) {
            for(int j = 0; j < children[i]->children.size(); ++j) {
                nodes.push_back(children[i]->children[j]);
            }
        }
    }
   else {
       count++;
       for (int i = 0; i < children.size(); ++i) {
           children[i]->get_nodes_on_lvl(nodes, lvl);
       }
    }
    return nodes;
}



void TreeNode::move_subtree(int lvl) {
    if (lvl < 2) {
        std::cout << "ERROR, can't be moved." << std::endl;
        return;
    }
    std::vector<TreeNode*> nodes;
    get_nodes_on_lvl(nodes, lvl);
    TreeNode* node_max_within_min = nodes[0];
    int indx = 0;
    for (int i = 0; i < nodes.size(); ++i) {
        if(nodes[i]->min_mark() > node_max_within_min->min_mark()) {
            node_max_within_min = nodes[i];
            indx = i;
        }
    }
    
    std::vector<TreeNode*> nodes2;
    get_nodes_on_lvl(nodes2, lvl - 2);
    TreeNode* node_min_within_max = nodes2[0];
    
    for (int i = 0; i < nodes2.size(); ++i) {
        if(nodes2[i]->max_mark() < node_min_within_max->max_mark()) { node_min_within_max = nodes2[i]; }
    }
    node_min_within_max->children.push_back(node_max_within_min);
    node_max_within_min->root->children.erase(node_max_within_min->root->children.begin() + indx);
    node_max_within_min->root = node_min_within_max; 
    
}

double TreeNode::get_mark() {
    return data->get_mark();
}

void TreeNode::node_info() {
    std::cout << data->get_name() << " heigth(" << height() << ") num_of_children(" << children_size() << ") num_of_subtree_elements(" << subtree_size() << ") max_mark(" << max_mark() << ") min_mark(" << min_mark() << ") average_mark(" << average_mark() << ")" << std::endl;
    for (int i = 0; i < children.size(); ++i) {
        children[i]->node_info();
    }
}
