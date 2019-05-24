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

class TreeNode {
private:
    WebProg* data;
    TreeNode* root;
    std::vector<TreeNode*> children;
    void add_after_prototype(WebProg& el);
    double sum_of_marks();
    TreeNode* find_node(int indx, int& count, bool& found);
public:
    TreeNode() = default;
    ~TreeNode() = default;
    void add(WebProg& el); //+
    void print(); //+
    void print_with_addresses(); //+
    TreeNode* get_node_by_preorder_index(int indx); //!+
    int height(); //+
    int children_size(); //+
    int subtree_size(); //including the root of subtree; //+
    double max_mark(); //+
    double min_mark();//+
    double average_mark(); //+
    std::vector<TreeNode*> get_nodes_on_lvl(std::vector<TreeNode*>& nodes, int lvl); //+
    void move_subtree(int lvl); //+
    double get_mark(); //+
    void node_info(); //+
};
#endif /* Tree_hpp */
