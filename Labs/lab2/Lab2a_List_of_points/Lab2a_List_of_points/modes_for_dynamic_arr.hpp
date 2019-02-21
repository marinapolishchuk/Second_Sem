//
//  modes_for_dynamic_arr.hpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/19/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef modes_for_dynamic_arr_hpp
#define modes_for_dynamic_arr_hpp

#include "List_dynamic_arr.hpp"

void demo_mode(Vector<Point> p) {
    
    std::cout << "\nWelcome to a demo mode." << std::endl;
    std::cout << "Start capacity of the vector is 1. Length = 5. " << std::endl;
    int size = 5;
    for (double i = 0; i < size; ++i) {
        Point temp{i, i, i};
        p.append(temp);
    }
    std::cout << "The list of 5: " << std::endl;
    p.print();
    std::cout << "\nThe list with addresses: " << std::endl;
    p.print_with_address();
    
    std::cout << "\nset() method demonstration.";
    int indx_set = 3;
    Point data_set{999, 999, 999};
    std::cout << "\nset(" << indx_set << ", " << data_set.toString() << "):" << std::endl;
    p.set(indx_set, data_set);
    p.print();
    
    std::cout << "\nget() method demonstration.";
    int indx_get = 3;
    std::cout << "\nget(" << indx_get << "): " << p.get(indx_get).toString() << std::endl;
    
    std::cout << "\ninsert() method demonstration.";
    int indx_insert = 2;
    Point data_insert{777, 777, 777};
    std::cout << "\ninsert(" << indx_insert << ", " << data_insert.toString() << "):" << std::endl;
    p.insert(indx_insert, data_insert);
    p.print();
    
    std::cout << "\nremove() method demonstration.";
    int indx_remove = 4;
    std::cout << "\nremove(" << indx_remove << "):" << std::endl;
    p.remove(indx_remove);
    p.print();
    std::cout << std::endl;
    return;
}


void interactive_mode(Vector<Point> p) {
    
    std::cout << "\nWelcome to an interactive mode." << std::endl;
    std::cout << "Press 'a' to fill the list automatically or press 'b' to fill the list by yourself." << std::endl;
    char how_to_fill;
    std::cin >> how_to_fill;
    
    switch (how_to_fill) {
        case 'a':
        { std::cout << "\nEnter size of the list: ";
            int size = 0;
            std::cin >> size;
            for(double i = 0; i < size; ++i) {
                Point temp{i, i, i};
                p.append(temp);
            }
            break;
        }
        case 'b':
        {
            std::cout << "\nEnter size of the list: ";
            int size = 0;
            std::cin >> size;
            std::cout << "Fill the list (append() method): " << std::endl;
            for(int i = 0; i < size; ++i) {
                Point point;
                std::cin >> point.x >> point.y >> point.z;
                p.append(point);
            }
            break;
        }
        default:
        {
            std::cout << "Error. The way of filling the list was selected incorrectly" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
    
    std::cout << "How to print the list?\n" <<
    "\t1. print() method\n" <<
    "\t2. print_with_address() method\n" <<
    "\t3. both" << std::endl;
    std::cout << std::endl;
    
    int how_to_print = 0;
    std::cin >> how_to_print;
    switch (how_to_print) {
        case 1: { p.print(); break; }
        case 2: { p.print_with_address(); break; }
        case 3: { p.print(); std::cout << std::endl; p.print_with_address(); break; }
        default: {
            std::cout << "Error. The way of printing the list was selected incorrectly" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
    
    std::cout << "\nset() method demonstration.\nEnter index and data:" << std::endl;
    int indx_set;
    Point data_set;
    std::cin >> indx_set;
    std::cin >> data_set.x >> data_set.y >> data_set.z;
    std::cout << "\nset():" << std::endl;
    p.set(indx_set, data_set);
    p.print();
    
    std::cout << "\n\nget() method demonstration.\nEnter index:" << std::endl;
    int indx_get;
    std::cin >> indx_get;
    std::cout << "\nget(): " << p.get(indx_get).toString() << std::endl;
    
    std::cout << "\ninsert() method demonstration.\nEnter index and data:" << std::endl;
    int indx_insert;
    Point data_insert;
    std::cin >> indx_insert;
    std::cin >> data_insert.x >> data_insert.y >> data_insert.z;
    std::cout << "\ninsert():" << std::endl;
    p.insert(indx_insert, data_insert);
    p.print();
    
    std::cout << "\n\nremove() method demonstration.\nEnter index:" << std::endl;
    int indx_remove;
    std::cin >> indx_remove;
    std::cout << "\nremove():" << std::endl;
    p.remove(indx_remove);
    p.print();
    std::cout << std::endl;
    return;
}

#endif /* modes_for_dynamic_arr_hpp */
