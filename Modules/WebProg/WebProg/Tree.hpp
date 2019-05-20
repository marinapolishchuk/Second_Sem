//
//  Tree.hpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/18/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "Web_prog.hpp"

class Tree {
private:
    WebProg* data;
    Tree* root;
    std::vector<Tree*> children;
    void add_after_prototype(WebProg& el);
    double sum_of_marks();
public:
    Tree() = default;
    ~Tree() = default;
    void add(WebProg& el); //+
    void print(); //+
    Tree* get_node_by_preorder_index(int indx); //?
    int height(); //?
    int children_size(); //?
    int subtree_size(); //including the root of subtree; //?
    double max_mark(); //?
    double min_mark();//?
    double average_mark(); //?
    std::vector<Tree*> get_nodes_on_lvl(std::vector<Tree*>& nodes, int lvl); //+
    void move_subtree(int lvl); //-
    double get_mark(); //+
};
#endif /* Tree_hpp */
