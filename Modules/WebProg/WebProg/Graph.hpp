//
//  Graph.hpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/21/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <algorithm>
#include "Web_prog.hpp"

class Graph {
    using Matrix = std::vector<std::vector<bool>>;
    std::vector<WebProg> v;
    Matrix adj_matr;
    void dfs(int start, std::vector<bool>& visited, std::vector<int>& comp);
    std::vector<std::vector<int>> get_comps();
public:
    Graph() = delete;
    Graph(const std::vector<WebProg>& vortexes);
    void generate_links(double dist);
    void print();
    int get_comps_number();
    std::vector<std::pair<int, int>> get_comps_diametrs(); //first - start of component, second - diametr;
};

#endif /* Graph_hpp */
