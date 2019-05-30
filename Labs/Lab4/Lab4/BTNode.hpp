//
//  BTNode.hpp
//  Lab4
//
//  Created by  Марина on 5/30/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef BTNode_hpp
#define BTNode_hpp

class BTNode {
private:
    int data;
    BTNode* root;
    BTNode* left;
    BTNode* right;
    void add(const int &dat, BTNode* leaf); //+
    void print(BTNode* node); //+
public:
    BTNode() = default;
    ~BTNode() = default;
    void add(const int &dat); //+
    void print(); //+
};

#endif /* BTNode_hpp */
