//
//  Web_prog.hpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/18/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Web_prog_hpp
#define Web_prog_hpp

#include <iostream>
#include <string>
#include <vector>

class Function {
private:
    static int count;
    int id;
    std::string name;
    int support_lvl;
public:
    Function();
    ~Function() = default;
    int get_support_lvl();
    void generate();
    void generate_empty();
    void print();
};

class WebProg {
private:
    std::string name;
    WebProg* prototype;
    std::vector<Function> functionality;
    double rate_wa;
    double mark;
    static int count;
    int id;
public:
    WebProg();
    ~WebProg() = default;
    void set_prototype(WebProg* prot);
    void set_functionality();
    void calculate_mark();
    void sort_functionality();
    static double calculate_distance(WebProg a, WebProg b);
    void generate(WebProg* prototype);
    double get_mark();
    WebProg* get_prototype();
    std::string get_name();
    void print();
    static void sort_by_mark(std::vector<WebProg> &vec);
};

#endif /* Web_prog_hpp */
