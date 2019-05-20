//
//  Tree.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/18/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "Tree.hpp"

void Tree::add_after_prototype(WebProg& el) {
    WebProg* prot = el.get_prototype();
    if (prot == data) {
        Tree* new_el = new Tree;
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

void Tree::add(WebProg& el) {
    if(this->root == nullptr) {
        this->root = this;
        this->root->data = &el;
    } else {
        this->root->add_after_prototype(el);
    }
}

void Tree::print() {
    std::cout << data->get_name() << " " << this;
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

Tree* Tree::get_node_by_preorder_index(int indx) {
     Tree* res;
    static int count = 0;
    if(count == indx) { res = this; }
    else {
        count++;
        for(int i = 0; i < children.size(); ++i) {
            children[i]->get_node_by_preorder_index(indx--);
        }
    }
    return res;
}

int Tree::height() {
    std::vector<int> h;
    for (int i  = 0; i < children.size(); ++i) {
        h.push_back(children[i]->height());
    }
    return h.empty() ? 1 : *std::max_element(h.begin(), h.end()) + 1;
}

int Tree::children_size() {
    return children.size();
}

int Tree::subtree_size() {
    int count = 0;
    for (int i = 0; i < children.size(); ++i) {
        count += children[i]->subtree_size();
    }
    return count + 1;
}

double Tree::max_mark() {
    double children_max = 0;
    for (int i = 0; i < children.size(); ++i) {
        children_max = std::max(children_max, children[i]->max_mark());
    }
    return std::max(children_max, data->get_mark());
}

double Tree::min_mark() {
    double children_min = max_mark();
    for (int i = 0; i < children.size(); ++i) {
        children_min = std::min(children_min, children[i]->min_mark());
    }
    return std::min(children_min, data->get_mark());
}

double Tree::sum_of_marks() {
    double sum = 0;
    for (int i = 0; i < children.size(); ++i) {
        sum += children[i]->sum_of_marks();
    }
    return data->get_mark() + sum;
}

double Tree::average_mark() {
    return sum_of_marks() / subtree_size();
}

std::vector<Tree*> Tree::get_nodes_on_lvl(std::vector<Tree*>& nodes, int lvl) {
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

void Tree::move_subtree(int lvl) {
    std::vector<Tree*> nodes;
    get_nodes_on_lvl(nodes, lvl);
    std::vector<double> nodes_min;
    for (int i = 0; i < nodes.size(); ++i) {
        nodes_min.push_back(nodes[i]->min_mark());
    }
    
    
   
}

double Tree::get_mark() {
    return this->data->get_mark();
}
