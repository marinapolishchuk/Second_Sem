//
//  benchmark.hpp
//  Lab2a_List_of_points
//
//  Created by Marina Polishchuk on 2/22/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef benchmark_hpp
#define benchmark_hpp

#include <iostream>
#include <ctime>
#include "Point.hpp"
#include "List.hpp"
#include "List_array.hpp"
#include "List_dynamic_arr.hpp"

void list_measurement() {
    
    std::cout << "Number of operations = 1: " << std::endl;
    
    {
        List<Point> list = List<Point>::create_empty();
        clock_t st = clock();
        list.append({0,0,0});
        clock_t et = clock();
        std::cout << "\tappend(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        list.insert(0, {0,0,0});
        et = clock();
        std::cout << "\tinsert(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        list.get(0);
        et = clock();
        std::cout << "\tget(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        list.set(0, {1,1,1});
        et = clock();
        std::cout << "\tset(): " << et - st << std::endl; st = et = 0;
        
        
        st = clock();
        list.remove(0);
        et = clock();
        std::cout << "\tremove(): " << et - st << std::endl; st = et = 0;
    }
    
    std::cout << "Number of operations = 10: " << std::endl;
    {
        List<Point> list = List<Point>::create_empty();
        
        clock_t st = clock();
        for (int i = 0; i < 10; ++i) {
            list.append({0,0,0});
        }
        clock_t et = clock();
        std::cout << "\tappend(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            list.insert(i, {0,0,0});
        }
        et = clock();
        std::cout << "\tinsert(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            list.get(i);
        }
        et = clock();
        std::cout << "\tget(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            list.set(i, {1,1,1});
        }
        et = clock();
        std::cout << "\tset(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            list.remove(i);
        }
        et = clock();
        std::cout << "\tremove(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
    }
    
    std::cout << "Number of operations = 100: " << std::endl;
    {
        List<Point> list = List<Point>::create_empty();
        
        clock_t st = clock();
        for (int i = 0; i < 100; ++i) {
            list.append({0,0,0});
        }
        clock_t et = clock();
        std::cout << "\tappend(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            list.insert(i, {0,0,0});
        }
        et = clock();
        std::cout << "\tinsert(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            list.get(i);
        }
        et = clock();
        std::cout << "\tget(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            list.set(i, {1,1,1});
        }
        et = clock();
        std::cout << "\tset(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            list.remove(i);
        }
        et = clock();
        std::cout << "\tremove(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
    }
}

void array_measurement() {
    
    std::cout << "Number of operations = 1: " << std::endl;
    
    {
        List_array<Point, 1000> arr = List_array<Point, 1000>::create_empty();
        clock_t st = clock();
        arr.append({0,0,0});
        clock_t et = clock();
        std::cout << "\tappend(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        arr.insert(0, {0,0,0});
        et = clock();
        std::cout << "\tinsert(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        arr.get(0);
        et = clock();
        std::cout << "\tget(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        arr.set(0, {1,1,1});
        et = clock();
        std::cout << "\tset(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        arr.remove(0);
        et = clock();
        std::cout << "\tremove(): " << et - st << std::endl; st = et = 0;
    }
    
    std::cout << "Number of operations = 10: " << std::endl;
    {
        List_array<Point, 1000> arr = List_array<Point, 1000>::create_empty();

        clock_t st = clock();
        for (int i = 0; i < 10; ++i) {
            arr.append({0,0,0});
        }
        clock_t et = clock();
        std::cout << "\tappend(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            arr.insert(i, {0,0,0});
        }
        et = clock();
        std::cout << "\tinsert(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            arr.get(i);
        }
        et = clock();
        std::cout << "\tget(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            arr.set(i, {1,1,1});
        }
        et = clock();
        std::cout << "\tset(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            arr.remove(i);
        }
        et = clock();
        std::cout << "\tremove(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
    }
    
    std::cout << "Number of operations = 100: " << std::endl;
    {
        List_array<Point, 1000> arr = List_array<Point, 1000>::create_empty();
        
        clock_t st = clock();
        for (int i = 0; i < 100; ++i) {
            arr.append({0,0,0});
        }
        clock_t et = clock();
        std::cout << "\tappend(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            arr.insert(i, {0,0,0});
        }
        et = clock();
        std::cout << "\tinsert(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            arr.get(i);
        }
        et = clock();
        std::cout << "\tget(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            arr.set(i, {1,1,1});
        }
        et = clock();
        std::cout << "\tset(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            arr.remove(i);
        }
        et = clock();
        std::cout << "\tremove(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
    }
}

void vec_measurement() {
    
    std::cout << "Number of operations = 1: " << std::endl;
    
    {
        Vector<Point> vec = Vector<Point>::create_empty();
        clock_t st = clock();
        vec.append({0,0,0});
        clock_t et = clock();
        std::cout << "\tappend(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        vec.insert(0, {0,0,0});
        et = clock();
        std::cout << "\tinsert(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        vec.get(0);
        et = clock();
        std::cout << "\tget(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        vec.set(0, {1,1,1});
        et = clock();
        std::cout << "\tset(): " << et - st << std::endl; st = et = 0;
        
        st = clock();
        vec.remove(0);
        et = clock();
        std::cout << "\tremove(): " << et - st << std::endl; st = et = 0;
    }
    
    std::cout << "Number of operations = 10: " << std::endl;
    {
        Vector<Point> vec = Vector<Point>::create_empty();

        clock_t st = clock();
        for (int i = 0; i < 10; ++i) {
            vec.append({0,0,0});
        }
        clock_t et = clock();
        std::cout << "\tappend(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            vec.insert(i, {0,0,0});
        }
        et = clock();
        std::cout << "\tinsert(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            vec.get(i);
        }
        et = clock();
        std::cout << "\tget(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            vec.set(i, {1,1,1});
        }
        et = clock();
        std::cout << "\tset(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 10; ++i) {
            vec.remove(i);
        }
        et = clock();
        std::cout << "\tremove(): " << (double)(et - st) / 10 << std::endl; st = et = 0;
    }
    
    std::cout << "Number of operations = 100: " << std::endl;
    {
        Vector<Point> vec = Vector<Point>::create_empty();

        clock_t st = clock();
        for (int i = 0; i < 100; ++i) {
            vec.append({0,0,0});
        }
        clock_t et = clock();
        std::cout << "\tappend(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            vec.insert(i, {0,0,0});
        }
        et = clock();
        std::cout << "\tinsert(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            vec.get(i);
        }
        et = clock();
        std::cout << "\tget(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            vec.set(i, {1,1,1});
        }
        et = clock();
        std::cout << "\tset(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
        
        st = clock();
        for (int i = 0; i < 100; ++i) {
            vec.remove(i);
        }
        et = clock();
        std::cout << "\tremove(): " << (double)(et - st) / 100 << std::endl; st = et = 0;
    }
}


void benchmark_mode() {
    std::cout << "Welcome to the benchmark mode." << std::endl;
    std::cout << "We have list realization in three different ways: linked list, static array and dynamic array (vector)." << std::endl;
    std::cout << "There are basic methods for each realization:\n\tappend()\n\tinsert()\n\tget()\n\tset()\n\tremove()" << std::endl;
    
    std::cout << "\nTIME MEASUREMENT FOR LINKED LIST:" << std::endl;
    list_measurement();
    std::cout << "\nTIME MEASUREMENT FOR STATIC ARRAY:" << std::endl;
    array_measurement();
    std::cout << "\nTIME MEASUREMENT FOR DYNAMIC ARRAY:" << std::endl;
    vec_measurement();

}

#endif /* benchmark_hpp */


//unsigned int start_time =  clock();
//unsigned int end_time =  clock();
//unsigned int search_time = end_time - start_time;
