//
//  Web_prog.cpp
//  WebProg
//
//  Created by Marina Polishchuk on 5/18/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "Web_prog.hpp"
#include <cmath>

int Function::count = 0;

Function::Function() {
    count++;
    id = count;
}

int Function::get_support_lvl() {
    return support_lvl;
}

void Function::generate() {
    this->name = "Func_" + std::to_string(this->id);
    this->support_lvl = rand() % 101;
}

void Function::generate_empty() {
    this->name = "Func_0000";
    this-> support_lvl = 0;
}

void Function::print() {
    std::cout << "Function: " << this->name << "; Support level: " << this->support_lvl << std::endl;
}

int WebProg::count = 0;

WebProg::WebProg() {
    ++count;
    id = count;
}

void WebProg::set_prototype(WebProg* prot) {
    this->prototype = prot;
}

void WebProg::set_functionality() {
    int size = 13;
    int num = rand() % 13 + 1;
    for (int i = 0; i < num; ++i) {
        Function func;
        func.generate();
        this->functionality.push_back(func);
    }
    
    for (int i = 0; i < size - num; ++i) {
        Function func;
        func.generate_empty();
        this->functionality.push_back(func);
    }
    //    for(auto a : this->functionality) {
    //        a.print();
    //    }
}

void WebProg::calculate_mark() {
    double res = 0;
    for (int i = 0; i < this->functionality.size(); ++i) {
        int temp = pow(functionality[i].get_support_lvl(), 2);
        res += temp;
    }
    this->mark = pow(res, (2 + this->rate_wa/4));
}

void WebProg::sort_functionality() {
    std::sort(this->functionality.begin(), this->functionality.end(), [](Function a, Function b) { return a.get_support_lvl() < b.get_support_lvl();});
    
    //    for (auto a : this->functionality) {
    //        a.print();
    //    }
    
}

double WebProg::calculate_distance(WebProg a, WebProg b) {
    double res = 0;
    a.sort_functionality();
    b.sort_functionality();
    int temp = 0;
    for (int i = 0; i < a.functionality.size(); ++i) {
        int diff = 0;
        int af = a.functionality[i].get_support_lvl();
        int bf = b.functionality[i].get_support_lvl();
        diff = af - bf;
        temp += diff * diff;
    }
    res = temp + 1;
    double temp_pow = ((a.rate_wa + b.rate_wa) / 2)/9 - 6;
    res = pow(res, temp_pow);
    res = -log(res);
    
    return res;
}

void WebProg::generate(WebProg* prototype) {
    this->name = "Prog_" + std::to_string(this->id);
    this->set_prototype(prototype);
    this->set_functionality();
    this->rate_wa = rand() % 9 + 1;
    this->calculate_mark();
}

double WebProg::get_mark() {
    return mark;
}

WebProg* WebProg::get_prototype() {
    return this->prototype;
}

std::string WebProg::get_name() {
    return name;
}

void WebProg::print() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "NAME: " << this->name << std::endl;
    std::cout << "RATE: " << this->rate_wa << std::endl;
    std::cout << "MARK: " << this->mark << std::endl;
    std::cout << "THE LIST OF FUNCTIONS: " << std::endl;
    for (auto a : this->functionality) {
        a.print();
    }
    std::cout << "-------------------------------------" << std::endl;
}

void WebProg::sort_by_mark(std::vector<WebProg> &vec) {
    std::sort(vec.begin(), vec.end(), [](WebProg a, WebProg b){ return a.mark > b.mark; });
}

