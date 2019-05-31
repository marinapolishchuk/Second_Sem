//
//  ExpressionTree.hpp
//  Lab4
//
//  Created by  Марина on 5/31/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef ExpressionTree_hpp
#define ExpressionTree_hpp
#include <string>

class ExpTree {
private:
    char data;
    ExpTree* root;
    ExpTree* left;
    ExpTree* right;
    
public:
    ExpTree() = default;
    ~ExpTree() = default;
    static void calculate(std::string exp);
    
};

std::vector<std::string> parse_exp(std::string exp);

#endif /* ExpressionTree_hpp */
