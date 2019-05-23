//
//  BinaryTree.hpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

//- [+] Реалізувати бінарне дерево пошуку для зберігання елементу за його оцінкою
//- [+] Реалізувати вставку в дерево

//- [+] Вивід у зворотньому порядку
//- [+] Вивід у вигляді дерева
//- [ ] Пошук за оцінкою (із заданою точністю)

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "Web_prog.hpp"
#include <memory>
#include <cmath>

class BTNode {
private:
    std::unique_ptr<WebProg> data;
    BTNode* root;
    BTNode* right;
    BTNode* left;
    void add(WebProg data, BTNode* node); //+
    void print(BTNode* node); //+
    void postorder_print(BTNode* node); //+
    BTNode* search(double mark, double prec, BTNode* root);
public:
    BTNode() = default;
    ~BTNode() = default;
    void add(WebProg data); //+
    void print(); //+
    void postorder_print(); //+
    BTNode* search(double mark, double prec);
    WebProg& get_data();
    
};


#endif /* BinaryTree_hpp */
