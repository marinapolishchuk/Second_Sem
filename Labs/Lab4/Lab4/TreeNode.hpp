//
//  TreeNode.hpp
//  Lab4
//
//  Created by  Марина on 5/29/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp
#include <iostream>
#include <vector>

class TreeNode {
private:
    int data;
    TreeNode* root;
    std::vector<TreeNode*> children;
    int count = 0;
    TreeNode* find_node(const int &dat, bool &found); //+
public:
    TreeNode() = default;
    ~TreeNode() = default;
    void add(const int &dat); //+
    void print(); //+
    int size(); //+
    int get_data(); //+
    TreeNode* get_element_by_path(const std::vector<int> &path); //+
    TreeNode* get_node_by_data(const int &dat); //+
    std::vector<int> get_path(const int &el); //+
    void add_by_path(const int &dat, const std::vector<int> &path);//+
    TreeNode* get_deleted_subtree(const std::vector<int> &path); 
};


#endif /* TreeNode_hpp */
