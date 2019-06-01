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
            std::cout << "Demonstration mode was chosen." << std::endl;
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
            ExpTree::calculate("(8+6)/(6+1)");
            break;
        }
        case 2: {
            std::cout << "Interactive mode was chosen." << std::endl;
            std::cout << "What tree would you like to create? \n\t1.Simple tree \n\t2.Binary tree \n\t3.Arithmetical expression tree" << std::endl;
            int chose = 0;
            std::cin >> chose;
            switch (chose) {
                case 1: {
                    std::cout << "Simple tree." << std::endl;
                    int size;
                    std::cout << "Enter size of tree: ";
                    std::cin >> size;
                    int data;
                    TreeNode t;
                    std::cout << "Enter data: ";
                    for (int i = 0; i < size; ++i) {
                        std::cin >> data;
                        t.add(data);
                    }
                    t.print();
                    std::cout << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Binary tree." << std::endl;
                    int size;
                    std::cout << "Enter size of tree: ";
                    std::cin >> size;
                    int data;
                    BTNode t;
                    std::cout << "Enter data: ";
                    for (int i = 0; i < size; ++i) {
                        std::cin >> data;
                        t.add(data);
                    }
                    t.print();
                    std::cout << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Arithmetical expression tree." << std::endl;
                    std::string exp;
                    std::cout << "Enter the expression: ";
                    std::cin >> exp;
                    ExpTree::calculate(exp);
                    break;
                }
                default: {
                    std::cout << "Error. An option was chosen incorrectly." << std::endl;
                    break;
                }
            }
            break;
        }
            
        default: {
            std::cout << "Error. Mode was chosen incorrectly." << std::endl;
            break;
        }
    }
    return 0;
}
