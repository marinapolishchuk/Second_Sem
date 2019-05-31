//
//  ExpressionTree.cpp
//  Lab4
//
//  Created by  Марина on 5/31/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "ExpressionTree.hpp"
#include <vector>
#include <iostream>

void ExpTree::calculate(std::string exp) {
    std::string temp = exp;
    //std::vector<std::string> parsed = parse_e(temp);
    //ExpTree* t = build_tree(parsed);
    //double res = traverse(t);
    //вывод выражения с результатом;
}

std::vector<std::string> parse_exp(std::string exp) {
    std::vector<std::string> parsed;
    std::string symbol;
    for (size_t i = 0; i < exp.size(); ++i) {
        if (isdigit(exp.substr(i, 1)[0])) {
            symbol.push_back(exp.substr(i, 1)[0]);
            while (isdigit(exp.substr(i + 1, 1)[0])) {
                ++i;
                symbol.push_back(exp.substr(i, 1)[0]);
            }
        } else { symbol = exp.substr(i, 1); }
        parsed.push_back(symbol);
        symbol = "";
    }
    return parsed;
}
