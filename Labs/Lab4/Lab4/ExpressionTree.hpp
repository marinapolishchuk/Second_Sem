//
//  ExpressionTree.hpp
//  Lab4
//
//  Created by  Марина on 5/31/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef ExpressionTree_hpp
#define ExpressionTree_hpp
#include "helpers.h"

class ExpTree {
private:
    std::string data;
    ExpTree* root;
    ExpTree* left;
    ExpTree* right;
    void print(ExpTree* node);
    void build_tree(std::vector<std::string> parsed);
    std::pair<int, std::string> eval(ExpTree* node);
public:
    ExpTree() = default;
    ~ExpTree() = default;
    void print();
    static void calculate(const std::string &exp);
    static ExpTree* create_empty();
    
};

void remove_spaces(std::string &str); //+
bool is_correct(const std::string &str); //+
std::vector<std::string> get_parsed_exp(const std::string &exp); //+

#endif /* ExpressionTree_hpp */
