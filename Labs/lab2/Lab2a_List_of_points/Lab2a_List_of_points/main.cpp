//
//  main.cpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/11/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

/* РЕАЛИЗОВАТЬ СТРУКТУРУ ДАННЫХ "СПИСОК. ТОЧКА В ТРЕХМЕРНОМ ПРОСТРАНЕСТВЕ" ТРЕМЯ РАЗНЫМИ СПОСОБАМИ:
    1. НА ОСНОВЕ МАССИВА ФИКСИРОВАНОГО РАЗМЕРА. ПРИ ВЫХОДЕ ЗА ГРАНИЦЫ МАССИВА ВЫВОДИТЬ СООБЩЕНИЕ ОБ ОШИБКЕ. +++
    2. НА ОСНОВЕ ДИНАМИЧЕСКОГО МАССИВА (НАПРИМЕР std::vector). +++
    3. НА ОСНОВЕ СВЯЗНОГО СПИСКА +++
*/

/* РЕАЛИЗОВАТЬ ТРИ РЕЖИМА РАБОТЫ:
    1. ИНТЕРАКТИВНЫЙ ДИАЛОГОВЫЙ РЕЖИМ (список) (массив) (вектор)
    2. ДЕМОНСТРАЦИОННЫЙ РЕЖИМ (список) (массив) (вектор)
    3. АВТОМАТИЧЕСКИЙ РЕЖИМ "BENCHMARK" (в отдельном файле для всех способов одновременно)
*/

#include <iostream>
#include "List.hpp"
#include "modes_for_linked_list.hpp"
#include "modes_for_array.hpp"
#include "modes_for_dynamic_arr.hpp"
#include "List_array.hpp"
#include "List_dynamic_arr.hpp"
#include "benchmark.hpp"

int main() {
    
    List<Point> linked_list = List<Point>::create_empty(); //связный список
    List_array<Point, 1000> arr = List_array<Point, 1000>::create_empty(); //статический массив
    Vector<Point> vec = Vector<Point>::create_empty();
   
    
    std::cout << "Select mode.\nEnter '1' to choose an interactive mode.\nEnter '2' to choose a demo mode.\nEnter '3' to choose a benchmark mode." << std::endl;
    int mode = 0;
    std::cin >> mode;
    
    switch (mode) {
        
        //Интерактивный режим для всех реализаций отдельно
        case 1:
        {
            std::cout << "Choose array (a), dynamic_array (b) or linked_list (c). " << std::endl;
            char way = '\0';
            std::cin >> way;
            switch (way) {
                case 'a':
                    interactive_mode(arr);
                    break;
                case 'b':
                    interactive_mode(vec);
                    break;
                case 'c':
                    interactive_mode(linked_list);
                    break;
                default:
                    std::cout << "Error. " << std::endl;
                    break;
            }
            break;
        }

         
        //Демонстрационный режим для всех реализаций отдельно
        case 2:
        {
            std::cout << "Choose array (a), dynamic_array (b) or linked_list (c). " << std::endl;
            char way = '\0';
            std::cin >> way;
            switch (way) {
                case 'a':
                    demo_mode(arr);
                    break;
                case 'b':
                    demo_mode(vec);
                    break;
                case 'c':
                    demo_mode(linked_list);
                    break;
                default:
                    std::cout << "Error. " << std::endl;
                break;
            }
            break;
        }
           
        
        //Режим benchmark. Сценарий для всех раелизаций вместе.
        case 3:
        {
            benchmark_mode();
            break;
        }
            
            
        //Опция, если режим был выбран неправильно 
        default:
        {
            std::cout << "Error. Mode was selected incorrectly" << std::endl;
            break;
        }
    } 
    
    return 0;
}
