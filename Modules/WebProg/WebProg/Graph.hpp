//
//  Graph.hpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/21/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Web_prog.hpp"

class Graph {
    
    using Matrix = std::vector<std::vector<bool>>;
    
    std::vector<WebProg> v;
    Matrix adj_matr;
    
    void dfs(int v, std::vector<bool>& visited);
    void dfsr(int v);
    
public:
    Graph() = delete;
    Graph(int n);
    void fill();
    void generate_links();
    
    int getCompsNumber();
    
    
};

#endif /* Graph_hpp */
