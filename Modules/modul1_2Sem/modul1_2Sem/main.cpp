//
//  main.cpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include "List.hpp"

int main() {
    Parallelepiped p, m;
    m.GenerateVectors();
    p.GenerateVectors();
    
    List<Parallelepiped> l;
    l.push_back(p);
    l.push_back(m);
    l.print();
    l.print_with_address();
    
    
//    m.print_parallelepiped();
//    std::cout << std::endl;
//    p.print_parallelepiped();
//    std::cout << std::endl;


    return 0;
}
