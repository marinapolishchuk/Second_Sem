//
//  main.cpp
//  Lab4
//
//  Created by Марина on 5/29/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "TreeNode.hpp"
#include "BTNode.hpp"
#include "ExpressionTree.hpp"

int main() {
//    TreeNode t;
//    t.add(1); t.add(2); t.add(3);
//    t.get_element_by_path({1})->add(4);
//    t.print();
//    std::cout << std::endl;
//    std::cout << t.get_element_by_path({1, 0})->get_data() << std::endl;
//    std::cout << t.get_node_by_data(3) << std::endl;
//    for (auto a : t.get_path(5)) {
//        std::cout << a << ' ';
//    }
//    t.add_by_path(7, {});
//    t.print();
//    std::cout << std::endl;
//
    
    /////
//    BTNode t;
//    t.add(10);
//    t.add(11);
//    t.add(9);
//    t.add(7);
//    t.print();
//    std::cout << std::endl;
//    t.print_table();
    ExpTree::calculate("(2 + 3)/0");
   
    return 0;
}
