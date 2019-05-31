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

void ExpTree::print(ExpTree* node) {
    if(node != nullptr) {
        std::cout << node->data;
        if(node->left != nullptr && node->right != nullptr) {
            std::cout << "(";
            print(node->left);
            std::cout << ", ";
            print(node->right);
            std::cout << ")";
        }
        else if(node->left == nullptr && node->right != nullptr) {
            std::cout << "(.., ";
            print(node->right);
            std::cout << ")";
        }
        else if(node->left != nullptr && node->right == nullptr) {
            std::cout << "(";
            print(node->left);
            std::cout << ", ..)";
        }
    }
}

void ExpTree::print() {
    print(root);
}

void ExpTree::calculate(const std::string &exp) {
    if(exp.empty()) { std::cout << "Expression is empty." << std::endl; return; }
    if(!is_correct(exp)) { std::cout << "An expression is incorrect. Can't be calculated." << std::endl; return; }
    std::cout << "Expression: " << exp << std::endl;
    std::string temp = exp;
    remove_spaces(temp);
    std::vector<std::string> parsed = get_parsed_exp(temp);
    std::cout << "Parsed expression: ";
    for (auto &a : parsed) {
        std::cout << "[" << a << "] ";
    }
    std::cout << std::endl;
    ExpTree* t = ExpTree::create_empty();
    t->build_tree(parsed);
    std::cout << "Tree:" << std::endl;
    t->print();
    std::cout << std::endl;
    //double res = get_res(t);
    //вывод выражения с результатом;
}

ExpTree* ExpTree::create_empty() {
    ExpTree* new_node = new ExpTree;
    new_node->root = new_node;
    new_node->left = new_node->right = nullptr;
    new_node->data = "";
    return new_node;
}

//Если считан токен ( - добавляем новый узел, как левого потомка текущего, и спускаемся к нему вниз
//Если считан один из операторов - устанавливаем корневое значение текущего узла равным оператору из этого токена. ДОбавляем новый узел на место правого потомка текущего и спускаемся вниз по правому поддереву.
//Если считанный токен - число, то устанавливаем корневое значение равным этой величине и возвращаемся к родителю.
//Если считан токен ), то перемещаемся к  родителю текущего узла.
//1. Создаем пустое дерево
void ExpTree::build_tree(std::vector<std::string> parsed) {
    ExpTree* current = this;
    for (auto &a : parsed) {
        if(a == "(") {
            current->left = new ExpTree;
            current->left->root = current;
            current->left->left = current->left->right = nullptr;
            current->left->data = "";
            current = current->left;
        }
        else if (a == "+" || a == "-" || a == "*" || a == "/" || a == "^" || a == "%") {
            current->right = new ExpTree;
            current->right->root = current;
            current->right->left = current->right->right = nullptr;
            current->data = a;
            current = current->right;
        }
        else if (a == ")") {
            current = current->root;
        }
        else {
            if(current == this) {
                current->left = new ExpTree;
                current->left->root = current;
                current->left->left = current->left->right = nullptr;
                current->left->data = a;
            } else {
                current->data = a;
                current = current->root;
            }
        }
    }
}







void remove_spaces(std::string &str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if(str.substr(i, 1) == " ") {
            str.erase(str.begin() + i);
        }
    }
}

//check if there is an error in expression, if number of "(" != number of ")" (done)
bool is_correct(const std::string &str) {
    unsigned op_brackets = 0;
    unsigned cl_brackets = 0;
    for (size_t i  = 0; i < str.size(); ++i) {
        if(str.substr(i, 1) == "(") { op_brackets++; }
        if(str.substr(i, 1) == ")") { cl_brackets++; }
    }
    if (op_brackets != cl_brackets) { return false; }
    return true;
}

std::vector<std::string> get_parsed_exp(const std::string &exp) {
    std::vector<std::string> parsed;
    parsed.reserve(exp.size());
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






