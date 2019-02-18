//
//  Point.hpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/14/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <string>
#include <cmath>

struct Point {
    double x;
    double y;
    double z;
    std::string toString() {
        std::string s =  "(" + std::to_string(static_cast<int>(x)) + ", " + std::to_string(static_cast<int>(y)) + ", " + std::to_string(static_cast<int>(z)) + ")";
        return s;
    }
};

#endif /* Point_hpp */
