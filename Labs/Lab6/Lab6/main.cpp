//
//  main.cpp
//  Lab6
//
//  Created by  Марина on 6/3/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "headers.h"
#include "LinkedList.hpp"
#include "ArrayBasedList.hpp"
#include "BSTree.hpp"

int main() {
//    OrderedLL l = OrderedLL::create_empty();
//    l.generate(20);
//    l.add({{20, 20}, {1, 1, 2001}});
//    l.add({{23, 20}, {1, 1, 2001}});
//    l.add({{18, 20}, {1, 1, 2001}});
//    l.add({{21, 10}, {2, 1, 2001}});
//    l.add({{20, 20}, {1, 1, 2002}});
//    l.print();
//    OrderedArrL<20> l = OrderedArrL<20>::create_empty();
//    l.add({{20, 20}, {1, 1, 2001}});
//    l.add({{20, 20}, {1, 1, 2002}});
//    l.add({{20, 20}, {1, 1, 2000}});
//    l.generate(6);
//    l.print();
//    l.remove(1);
//    l.print();
//
    BSTree t = BSTree::create_empty();
    t.add({{20, 20}, {1, 1, 2001}});
    t.add({{20, 20}, {1, 1, 2002}});
    t.add({{20, 20}, {1, 1, 2000}});
    t.add({{20, 20}, {12, 1, 2001}});
    t.add({{20, 20}, {12, 1, 2002}});
    t.add({{20, 20}, {1, 1, 1999}});
    t.tprint();
    std::cout << std::endl;
    //t.print();
    std::cout << std::endl;
    
    std::cout << std::endl;


    
    return 0;
}
