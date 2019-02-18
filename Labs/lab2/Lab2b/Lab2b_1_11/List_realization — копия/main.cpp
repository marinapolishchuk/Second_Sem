#include <iostream>
#include "List.hpp"

void interactive_mode(List<int>);
void demo_mode(List<int>);

int main() {
    List<int> p;
    std::cout << "Select mode.\nEnter '1' to choose an interactive mode.\nEnter '2' to choose a demo mode." << std::endl;
    int mode = 0;
    std::cin >> mode;
    
    switch (mode) {
        case 1:
        { interactive_mode(p); break; }
            
        case 2:
        { demo_mode(p); break; }

        default:
        {
            std::cout << "Error. Mode was selected incorrectly" << std::endl;
            break;
        }
    }
    
    return 0;
}



void demo_mode(List<int> p) {
    
    std::cout << "\nWelcome to a demo mode." << std::endl;
    std::cout << "The size of the list is 10." << std::endl;
    int size = 10;
    for (int i = 0; i < size; ++i) {
        p.push_back(i);
    }
    std::cout << "The list: " << std::endl;
    p.print();
    std::cout << "\nThe list with addresses: " << std::endl;
    p.print_with_address();
    
    std::cout << "\nrotate() method demonstration." ;
    int begin = 2, new_begin = 4, end = 5;
    std::cout << "\nRotated list (" << begin << ", " << new_begin << ", " << end << "):" << std::endl;
    p.rotate(begin, new_begin, end);
    p.print();
    
    std::cout << "\nset() method demonstration.";
    int indx_set = 3, data_set = 333;
    std::cout << "\nset(" << indx_set << ", " << data_set << "):" << std::endl;
    p.set(indx_set, data_set);
    p.print();
    
    std::cout << "\nget() method demonstration.";
    int indx_get = 3;
    std::cout << "\nget(" << indx_get << "): " << p.get(indx_get) << std::endl;
    
    std::cout << "\ninsert() method demonstration.";
    int indx_insert = 2, data_insert = 222;
    std::cout << "\ninsert(" << indx_insert << ", " << data_insert << "):" << std::endl;
    p.insert(indx_insert, data_insert);
    p.print();
    
    std::cout << "\nremove() method demonstration.";
    int indx_remove = 10;
    std::cout << "\nremove(" << indx_remove << "):" << std::endl;
    p.remove(indx_remove);
    p.print();
    std::cout << std::endl;
    return;
}

void interactive_mode(List<int> p) {
    
    std::cout << "\nWelcome to an interactive mode." << std::endl;
    std::cout << "Press 'a' to fill the list automatically or press 'b' to fill the list by yourself." << std::endl;
    char how_to_fill;
    std::cin >> how_to_fill;

    switch (how_to_fill) {
        case 'a':
        { std::cout << "\nEnter size of the list: ";
            int size = 0;
            std::cin >> size;
            for(int i = 0; i < size; ++i) {
                p.push_back(i);
            }
            break;
        }
        case 'b':
        {
            std::cout << "\nEnter size of the list: ";
            int size = 0;
            std::cin >> size;
            std::cout << "Fill the list (push_back() method): " << std::endl;
            for(int i = 0; i < size; ++i) {
                int dat = 0;
                std::cin >> dat;
                p.push_back(dat);
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

    std::cout << "rotate() method demonstration.\nEnter begin, new_begin, end:" << std::endl;
    int begin, new_begin, end;
    std::cin >> begin >> new_begin >> end;
    std::cout << "\nRotated list:" << std::endl;
    p.rotate(begin, new_begin, end);
    p.print();

    std::cout << "\nset() method demonstration.\nEnter index and data:" << std::endl;
    int indx_set, data_set;
    std::cin >> indx_set >> data_set;
    std::cout << "\nset():" << std::endl;
    p.set(indx_set, data_set);
    p.print();

    std::cout << "\nget() method demonstration.\nEnter index:" << std::endl;
    int indx_get;
    std::cin >> indx_get;
    std::cout << "\nget(): " << p.get(indx_get) << std::endl;

    std::cout << "\ninsert() method demonstration.\nEnter index and data:" << std::endl;
    int indx_insert, data_insert;
    std::cin >> indx_insert >> data_insert;
    std::cout << "\ninsert():" << std::endl;
    p.insert(indx_insert, data_insert);
    p.print();

    std::cout << "\nremove() method demonstration.\nEnter index:" << std::endl;
    int indx_remove;
    std::cin >> indx_remove;
    std::cout << "\nremove():" << std::endl;
    p.remove(indx_remove);
    p.print();
    std::cout << std::endl;
    return;
}
