//
//  main.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/17/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

//#include "Web_prog.hpp"
#include "Tree.hpp"
//#define TASK1 
//#define TASK2
//#define TASK3
//#define TASK4



int main() {
#ifdef TASK1
    std::cout << "TASK 1 DEMONSTRARION" << std::endl;
    WebProg prototype;
    prototype.generate(nullptr);
    WebProg* ptr_prototype = &prototype;
    std::vector<WebProg> vec;
    vec.push_back(prototype);
    for (int i = 0; i < 10; ++i) {
        WebProg temp;
        temp.generate(ptr_prototype);
        vec.push_back(temp);
    }
    WebProg::sort_by_mark(vec);
    for (auto a : vec) {
        a.print();
    }
    
    std::vector<std::pair<WebProg, WebProg>> pairs;
    std::vector<double> dist;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            std::pair<WebProg, WebProg> p = {vec[i], vec[j]};
            pairs.push_back(p);
        }
    }
    
    std::sort(pairs.begin(), pairs.end(), [](std::pair<WebProg, WebProg> p1, std::pair<WebProg, WebProg> p2)  {
        double dist1 = WebProg::calculate_distance(p1.first, p1.second);
        double dist2 = WebProg::calculate_distance(p2.first, p2.second);
        return dist1 > dist2;
    });
    
    std::cout << "\n\n11 pairs with the greatest distance: " << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << "PAIR ********************************" << std::endl;
        pairs[i].first.print();
        pairs[i].second.print();
        double dist = WebProg::calculate_distance(pairs[i].first, pairs[i].second);
        std::cout << "DISTANCE: " << dist;
        std::cout << "\n\n\n";
    }
    
    std::cout << "\n\n11 pairs with the smallest distance: " << std::endl;
    for (size_t i = pairs.size() - 1; i > pairs.size() - 12; --i) {
        std::cout << "PAIR ********************************" << std::endl;
        pairs[i].first.print();
        pairs[i].second.print();
        double dist = WebProg::calculate_distance(pairs[i].first, pairs[i].second);
        std::cout << "DISTANCE: " << dist;
        std::cout << "\n\n\n";
    }
#endif
    
#ifdef TASK2
//    Tree t;
//    
//    WebProg first; //level 0
//    first.generate(nullptr);
//    t.add(first);
//    WebProg w1, w2, w3; //level 1
//    w1.generate(&first); w2.generate(&first); w3.generate(&first); t.add(w1); t.add(w2); t.add(w3);
//    
//    //level 2
//    WebProg  w4, w5; //w1
//    w4.generate(&w1); w5.generate(&w1); t.add(w4); t.add(w5);
//    WebProg w6, w7, w8; //w2
//    w6.generate(&w2); w7.generate(&w2); w8.generate(&w2); t.add(w6); t.add(w7); t.add(w8);
//    WebProg w9; //w3
//    w9.generate(&w3); t.add(w9);
//    
//    //level 3
//    WebProg w10, w11; //w4
//    w10.generate(&w4); w11.generate(&w4); t.add(w10); t.add(w11);
//    WebProg w12; // w6
//    w12.generate(&w6); t.add(w12);
//    WebProg w13, w14, w15; //w7
//    w13.generate(&w7); w14.generate(&w7); w15.generate(&w7); t.add(w13); t.add(w14); t.add(w15);
//    
    //level 4
    //level 5
    
    
    //add elements
    
//    t.print();
//    std::cout << std::endl;
//    std::vector<Tree*> vec;
//    t.get_nodes_on_lvl(vec, 3);
//    for (auto a : vec) {
//        std::cout << a << ' ';
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
    
    Tree t2;
    WebProg p1, p2, p3, p4, p5, p6, p7, p8, p9;
    p1.generate(nullptr);
    p2.generate(&p1);
    p3.generate(&p1);
    p4.generate(&p2);
    p5.generate(&p2);
    p6.generate(&p2);
    p7.generate(&p3);
    p8.generate(&p5);
    p9.generate(&p7);
    t2.add(p1), t2.add(p2); t2.add(p3); t2.add(p4); t2.add(p5); t2.add(p6); t2.add(p7); t2.add(p8); t2.add(p9);
    std::cout << t2.get_node_by_preorder_index(1) << std::endl;
    std::cout << t2.get_node_by_preorder_index(2) << std::endl;
    std::cout << t2.get_node_by_preorder_index(3) << std::endl;
    std::cout << t2.get_node_by_preorder_index(4) << std::endl;
    std::cout << t2.get_node_by_preorder_index(5) << std::endl;
    std::cout << t2.get_node_by_preorder_index(6) << std::endl;
    std::cout << t2.get_node_by_preorder_index(7) << std::endl;
    std::cout << t2.get_node_by_preorder_index(8) << std::endl;
    std::cout << t2.get_node_by_preorder_index(9) << std::endl;

//    std::cout << t2.get_node_by_preorder_index(8)->max_mark() << std::endl;
//    std::cout << t2.get_node_by_preorder_index(7)->get_mark() << std::endl;
//
//    std::cout << t2.get_node_by_preorder_index(8)->get_mark() << std::endl;
//
//    
    t2.print();
    std::cout << std::endl;
    
#endif
    
    
    return 0;
}

