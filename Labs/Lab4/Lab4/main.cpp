//
//  main.cpp
//  Lab4
//
//  Created by Марина on 5/29/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

//ВАРІАНТ: БЛОК 1 - ЗАВДАННЯ 2, 3
///////////БЛОК 2 - ЗАВДАННЯ  7
///////////БЛОК 3 - ЗАВДАННЯ  13
///////////БЛОК 4 - ЗАВДАННЯ  18
///////////БЛОК 5 - ЗАВДАННЯ  21
///////////БЛОК 6 - ЗАВДАННЯ  22


#include "TreeNode.hpp"
#include "BTNode.hpp"
#include "ExpressionTree.hpp"

int main() {
    
    std::cout << "Choose mode: \n\t1.Demonstration mode. \n\t2.Interactive mode." << std::endl;
    int chose = 0;
    std::cin >> chose;
    switch (chose) {
        case 1: {
            std::cout << "Demo mode was chosen." << std::endl;
            std::cout << "\nTREE IMPLEMENTATION: " << std::endl;
            std::cout << "====================" << std::endl;
            std::cout << "get_path()\nget_element_by_path()\nadd_element_by_path\nprint_with_brackets()\nget_deleted_subtree()" << std::endl;
            std::cout << "====================" << std::endl;
            
            TreeNode t;
            t.add(1); t.add(2); t.add(3);
            std::cout << "TREE: ";
            t.print();
            std::cout << std::endl;
            t.add_by_path(4, {});
            t.add_by_path(5, {0});
            t.add_by_path(6, {0});
            t.add_by_path(7, {1});
            t.add_by_path(8, {1});
            t.add_by_path(9, {0, 0});
            t.add_by_path(10, {1, 0});

            std::cout << "t.add_by_path(4, {}); \nt.add_by_path(5, {0}); \nt.add_by_path(6, {0}); \nt.add_by_path(7, {1}); \nt.add_by_path(8, {1}); \nt.add_by_path(9, {0, 0}); \nt.add_by_path(10, {1, 0});" << std::endl;
            std::cout << "TREE: ";
            t.print();
            std::cout << std::endl;
            std::cout << "get_path(10): { ";
            for (auto a : t.get_path(10)) {
                std::cout << a << ' ';
            }
            std::cout << "}" << std::endl;
            std::cout << "t.get_element_by_path({1, 0})->get_data(): " << t.get_element_by_path({1, 0})->get_data() << std::endl;
            std::cout << "t.get_element_by_path({0, 0, 0})->get_data(): " << t.get_element_by_path({0, 0, 0})->get_data() << std::endl;
            TreeNode* subtree = t.get_deleted_subtree({0});
            std::cout << "Deleted subtree by path {0}:" << std::endl;
            subtree->print();
            std::cout << std::endl;
            std::cout << "Tree after subtree extraction:" << std::endl;
            t.print();
            std::cout << std::endl;
            
            
            std::cout << "\nBINARY TREE IMPLEMENTATION: " << std::endl;
            std::cout << "====================" << std::endl;
            BTNode bt;
            std::cout << "bt.add(10); bt.add(11); bt.add(9); bt.add(7); bt.add(6); bt.add(12);" << std::endl;
            std::cout << "TREE:" << std::endl;
            bt.add(10);
            bt.add(11);
            bt.add(9);
            bt.add(7);
            bt.add(6);
            bt.add(12);
            bt.print();
            std::cout << std::endl;
            std::cout << "TABLE:" << std::endl;
            bt.print_table();
            std::cout << std::endl;
            
            std::cout << "\nARITHMETICAL EXPRESSION TREE IMPLEMENTATION: " << std::endl;
            std::cout << "====================" << std::endl;
            ExpTree::calculate("(5+(3^2))-15");

            break;
        }
        case 2: {
            break;
        }
            
        default: {
            std::cout << "Error. Mode was chosen incorrectly." << std::endl;
            break;
        }
    }
    
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
//    ExpTree::calculate("(2 + 3)/0");
   
    return 0;
}
