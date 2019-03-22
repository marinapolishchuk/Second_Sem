//
//  Parallelepiped.hpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Parallelepiped_hpp
#define Parallelepiped_hpp
#include <iostream>
#include <string>
#include <cmath> // sqrt()
#include <cstdlib> // rand()
// координаты вершин по модулю <= 100
// value = floor(volume + (4*v + 5)*surface)
class Parallelepiped {
private:
    struct Point { double x; double y; double z; };
    struct Vector {
        Point beg;
        Point end;
        double vec_x;
        double vec_y;
        double vec_z;
    };
    Vector a1;
    Vector a2;
    Vector a3;
    int v; // номер варианта
    double value; // величина //+
    double volume; // объем //+
    double surface; // площадь //+
    
    void Calculate_Volume() {
        volume = a1.vec_x*(a2.vec_y * a3.vec_z - a2.vec_z * a3.vec_y) - a1.vec_y*(a2.vec_x* a3.vec_z - a2.vec_z*a3.vec_x) + a1.vec_z*(a2.vec_x * a3.vec_y - a2.vec_y*a3.vec_x);
    }
    
    void Calculate_Surface() {
        double surf_a1a2, surf_a2a3, surf_a1a3;
        double a1_length = sqrt((a1.vec_x * a1.vec_x) + (a1.vec_y * a1.vec_y) + (a1.vec_z * a1.vec_z));
         double a2_length = sqrt((a2.vec_x * a2.vec_x) + (a2.vec_y * a2.vec_y) + (a2.vec_z * a2.vec_z));
         double a3_length = sqrt((a3.vec_x * a3.vec_x) + (a3.vec_y * a1.vec_y) + (a3.vec_z * a3.vec_z));
        surf_a1a2 = a1_length * a2_length;
        surf_a2a3 = a2_length  * a3_length;
        surf_a1a3 = a1_length * a3_length;
        surface = 2*(surf_a1a2 + surf_a2a3 + surf_a1a3);
    }
    
    void Calculate_Value() {
        Calculate_Surface();
        Calculate_Volume();
        value = floor(volume + (4*v + 5) * surface);
    }
    
public:
    Parallelepiped() : v(3) {};
    
    void print_vecs() {
        std::cout << "(" << a1.vec_x << ", " << a1.vec_y << ", " << a1.vec_z << ")" << ", " ;
        std::cout << "(" << a2.vec_x << ", " << a2.vec_y << ", " << a2.vec_z << ")" << ", ";
        std::cout << "(" << a3.vec_x << ", " << a3.vec_y << ", " << a3.vec_z << ")" << ", ";
    }
    
    void GenerateVectors() {
        Point basic_point;
        basic_point.x = rand() % 201 - 100;
        basic_point.y = rand() % 201 - 100;
        basic_point.z = rand() % 201 - 100;
        
        int x_dist, y_dist, z_dist;
        x_dist = rand() % 201 - 100;
        y_dist = rand() % 201 - 100;
        z_dist = rand() % 201 - 100;
        
        Vector a1_x{{basic_point.x, basic_point.y, basic_point.z}, {basic_point.x + x_dist, basic_point.y, basic_point.z}, a1_x.end.x - a1_x.beg.x, a1_x.end.y - a1_x.beg.y, a1_x.end.z - a1_x.beg.z};
        Vector a2_y{{basic_point.x, basic_point.y, basic_point.z}, {basic_point.x, basic_point.y + y_dist, basic_point.z}, a2_y.end.x - a2_y.beg.x, a2_y.end.y - a2_y.beg.y, a2_y.end.z - a2_y.beg.z};
        Vector a3_z{{basic_point.x, basic_point.y, basic_point.z}, {basic_point.x, basic_point.y, basic_point.z + z_dist}, a3_z.end.x - a3_z.beg.x, a3_z.end.y - a3_z.beg.y, a3_z.end.z - a3_z.beg.z};

        a1 = a1_x;
        a2 = a2_y;
        a3 = a3_z;
    }
    
    double Get_Volume() {
        Calculate_Volume();
        return volume;
    }
    
    double Get_Surface() {
        Calculate_Surface();
        return surface;
    }
    
    double Get_Value() {
        Calculate_Value();
        return value;
    }
    
    int GetVariant() {
        return v;
    }
    
    void print_parallelepiped() {
        Calculate_Value();
        std::cout << "{";
        print_vecs();
        std::cout << value << "}";
    }
    
    std::string toString() {
        Calculate_Value();
        std::string s = "{(" + std::to_string(static_cast<int>(a1.vec_x)) + ", " + std::to_string(static_cast<int>(a1.vec_y)) + ", " + std::to_string(static_cast<int>(a1.vec_z)) + "), " + "(" + std::to_string(static_cast<int>(a2.vec_x)) + ", " + std::to_string(static_cast<int>(a2.vec_y)) + ", " + std::to_string(static_cast<int>(a2.vec_z)) + "), " + "(" + std::to_string(static_cast<int>(a3.vec_x)) + ", " + std::to_string(static_cast<int>(a3.vec_y)) + ", " + std::to_string(static_cast<int>(a3.vec_z)) + "), " + std::to_string(static_cast<int>(value)) + "}";
        return s;
    }
};
#endif /* Parallelepiped_hpp */
