//
//  Parallelepiped.hpp
//  modul1_2Sem
//
//  Created by Marina Polishchuk on 3/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Parallelepiped_hpp
#define Parallelepiped_hpp

#include <cstdlib> // rand()
// координаты вершин по модулю <= 100
// value = floor(volume + (4*v + 5)*surface)
class Parallelepiped {
private:
    struct Point { double x; double y; double z; };
    struct Vector {
        double vec_x;
        double vec_y;
        double vec_z;
        Point beg;
        Point end;
        double CalculateVecX() {
            vec_x = end.x - beg.x;
            return vec_x;
        }
        double CalculateVecY() {
            vec_y = end.y - beg.y;
            return vec_y;
        }
        double CalculateVecZ() {
            vec_z = end.z - beg.z;
            return vec_z;
        }
    };
    const int count_of_edges;
    Vector vec_arr[count_of_edges];
    int v; // номер варианта
    double value; // величина
    double volume; // объем
    double surface; // площадь
    void CalculateValue()

public:
    
    void GenerateVectors() {
        Vector basic1, basic2, basic3;
    }
};
#endif /* Parallelepiped_hpp */
