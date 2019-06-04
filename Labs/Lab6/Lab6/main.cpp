//
//  main.cpp
//  Lab6
//
//  Created by  Марина on 6/3/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "headers.h"
#include "LinkedList.hpp"

int main() {
    OrderedLL l = OrderedLL::create_empty();
    l.generate(20);
//    l.add({{20, 20}, {1, 1, 2001}});
//    l.add({{23, 20}, {1, 1, 2001}});
//    l.add({{18, 20}, {1, 1, 2001}});
//    l.add({{21, 10}, {2, 1, 2001}});
//    l.add({{20, 20}, {1, 1, 2002}});
    l.print();
   
    
    return 0;
}
