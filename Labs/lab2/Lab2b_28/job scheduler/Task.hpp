//
//  Task.hpp
//  job scheduler
//
//  Created by Marina Polishchuk on 2/24/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <iostream>
#include <string>

struct Task {
    std::string text;
    int arrival_time;
    int execute_time;
    static int global_time_count;
    static int time_interval; 
};

int Task::global_time_count = 0;
int Task::time_interval = 100;

#endif /* Task_hpp */
