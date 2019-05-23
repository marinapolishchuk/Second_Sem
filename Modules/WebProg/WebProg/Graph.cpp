//
//  Graph.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/21/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(const std::vector<WebProg>& vortexes) {
    v = vortexes;
    adj_matr.reserve(v.size());
    for (int i = 0; i < v.size(); ++i) {
        adj_matr.push_back(std::vector<bool>(v.size(), false));
    }
}

void Graph::dfs(int start, std::vector<bool>& visited, std::vector<int>& comp) {
    comp.push_back(start);
    visited[start] = true;
    for (int i = 0; i < adj_matr.size(); ++i) {
        if (adj_matr[start][i] && !visited[i])
            dfs(i, visited, comp);
    }
}

void Graph::generate_links(double dist) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (WebProg::calculate_distance(v[i], v[j]) < dist) {
                adj_matr[i][j] = true;
                adj_matr[j][i] = true;
            }
        }
    }
}

void Graph::print() {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << i;
        bool hasAdj = false;
        for (int j = 0; j < v.size(); ++j) {
            if (adj_matr[i][j]) {
                if (!hasAdj) {
                    std::cout << " - ";
                    hasAdj = true;
                }
                std::cout << j << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int Graph::get_comps_number() {
    return get_comps().size();
}

std::vector<std::pair<int, int>> Graph::get_comps_diametrs() {
    std::vector<std::pair<int, int>> res;
    
    std::vector<std::vector<int>> d(adj_matr.size());
    
    constexpr int inf = 10000000;
    
    for (int i = 0; i < d.size(); ++i) {
        std::vector<int> d_i(adj_matr.size());
        for (int j = 0; j < d_i.size(); ++j) {
            if (adj_matr[i][j]) d_i[j] = 1;
            else if (i != j) d_i[j] = inf;
            else d_i[j] = 0;
        }
        d[i] = d_i;
    }
    
    for (int k = 0; k < d.size(); ++k)
        for (int i = 0; i < d.size(); ++i)
            for (int j = 0; j < d.size(); ++j)
                if (d[i][k] < inf && d[k][j] < inf)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    
    for (int i =0; i < d.size(); ++i) {
        std::replace(d[i].begin(), d[i].end(), inf, -1);
    }
    
    auto comps = get_comps();
    for (int i = 0; i < comps.size(); ++i) {
        int start = comps[i][0];
        int max_d = -1;
        for (int j = 0; j < comps[i].size(); ++j) {
            for (int k = 0; k < d[comps[i][j]].size(); ++k) {
                if (d[comps[i][j]][k] > max_d)
                    max_d = d[comps[i][j]][k];
            }
        }
        res.push_back(std::make_pair(start, max_d));
    }

    return res;
}

std::vector<std::vector<int>> Graph::get_comps() {
    std::vector<std::vector<int>> comps;
    std::vector<bool> visited(v.size(), false);
    for (int i = 0; i < v.size(); ++i) {
        std::vector<int> comp;
        if (!visited[i]) {
            dfs(i, visited, comp);
            comps.push_back(comp);
        }
    }
    return comps;
}

