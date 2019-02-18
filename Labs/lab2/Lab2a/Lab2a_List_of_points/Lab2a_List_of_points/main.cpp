//
//  main.cpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/11/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

/* РЕАЛИЗОВАТЬ СТРУКТУРУ ДАННЫХ "СПИСОК. ТОЧКА В ТРЕХМЕРНОМ ПРОСТРАНЕСТВЕ" ТРЕМЯ РАЗНЫМИ СПОСОБАМИ:
    1. НА ОСНОВЕ МАССИВА ФИКСИРОВАНОГО РАЗМЕРА. ПРИ ВЫХОДЕ ЗА ГРАНИЦЫ МАССИВА ВЫВОДИТЬ СООБЩЕНИЕ ОБ ОШИБКЕ. +++
    2. НА ОСНОВЕ ДИНАМИЧЕСКОГО МАССИВА (НАПРИМЕР std::vector).
    3. НА ОСНОВЕ СВЯЗНОГО СПИСКА +++
*/

/* РЕАЛИЗОВАТЬ ТРИ РЕЖИМА РАБОТЫ:
    1. ИНТЕРАКТИВНЫЙ ДИАЛОГОВЫЙ РЕЖИМ (список) () ()
    2. ДЕМОНСТРАЦИОННЫЙ РЕЖИМ (список) () ()
    3. АВТОМАТИЧЕСКИЙ РЕЖИМ "BENCHMARK" (в отдельном файле для всех способов одновременно)
*/

#include <iostream>
#include "List.hpp"
#include "modes_for_linked_list.hpp"
#include "List_array.hpp"

int main() {
    
    List_array<int, 5> arr = List_array<int, 5>::create_empty();
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.append(1);
    arr.print();


    /*List<Point> linked_list = List<Point>::create_empty();
    
    std::cout << "Select mode.\nEnter '1' to choose an interactive mode.\nEnter '2' to choose a demo mode." << std::endl;
    int mode = 0;
    std::cin >> mode;
    
    switch (mode) {
        case 1:
        { interactive_mode(linked_list); break; }
            
        case 2:
        { demo_mode(linked_list); break; }
            
        case 3:
        { break; }
            
        default:
        {
            std::cout << "Error. Mode was selected incorrectly" << std::endl;
            break;
        }
    }
     */
    return 0;
}
