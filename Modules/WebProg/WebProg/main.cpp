//
//  main.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/17/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//  VARIANT 2-2

#include <array>
#include "TreeNode.hpp"
#include "BinaryTree.hpp"
#include "Graph.hpp"
//#define TASK1 //+
//#define TASK2 //+
//#define TASK3 //+
//#define TASK4 //+



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
    TreeNode t2;
    std::array<WebProg, 37> arr;
    for (auto a : arr) {
        WebProg temp;
        a = temp;
    }
    arr[0].generate(nullptr);
    arr[1].generate(&arr[0]);
    arr[2].generate(&arr[0]);
    arr[3].generate(&arr[1]);
    arr[4].generate(&arr[1]);
    arr[5].generate(&arr[1]);
    arr[6].generate(&arr[2]);
    arr[7].generate(&arr[4]);
    arr[8].generate(&arr[6]);
    
    for (int i = 9; i < arr.size(); ++i) {
        arr[i].generate(&arr[i % 5]);
    }
    
    for (auto &a : arr) {
        t2.add(a);
    }

    std::cout << "TREE:" << std::endl;
    t2.print();
    std::cout << std::endl;
    std::cout << "\nNODES INFO:" << std::endl;
    t2.node_info();
    
    int lvl = 1;
    std::cout << "\nMOVE SUBTREE FROM LVL " << lvl << ": " << std::endl;
    std::cout << "\nbefore moving:" << std::endl;
    t2.print();
    std::cout << std::endl;
    t2.move_subtree(lvl);
    std::cout << "\nafter moving:" << std::endl;
    t2.print();
    std::cout << std::endl;
#endif
    
#ifdef TASK3
    
    WebProg prot;
    prot.generate(nullptr);
    std::vector<WebProg> vs(37);
    vs[0].generate(&prot);
    for (int i = 1; i < vs.size(); ++i) {
        vs[i].generate(&vs[i - 1]);
    }
    Graph g(vs);
    g.generate_links(WebProg::calculate_distance(prot, vs[0]));
    std::cout << "GRAPH:" << std::endl;
    g.print();
    std::cout << "COMPS NUMBER: " << g.get_comps_number() << std::endl;
    auto ds = g.get_comps_diametrs();
    std::cout << "COMPS DIAMETRS: " << std::endl;
    for (auto a : ds) {
        std::cout << "{" << a.first << ' ' << a.second << "} ";
    }
    std::cout << std::endl;
    
#endif
    
#ifdef TASK4
    BTNode t;
    WebProg prot;
    prot.generate(nullptr);
    t.add(prot);
    
    for (int i = 0; i < 37; ++i) {
        WebProg w;
        w.generate(&prot);
        t.add(w);
    }
    
    std::cout << "TREE:" << std::endl;
    t.print();
    std::cout << std::endl;
    
    std::cout << "\nPOSTORDER PRINT:" << std::endl;
    t.postorder_print();
    std::cout << std::endl;
    
    
    std::cout << "\nSEARCH:" << std::endl;
    auto n = t.search(5.85059e+11, 1e+6);
    std::cout << n->get_data().get_name() << std::endl;
    
    
#endif
    
    return 0;
}

