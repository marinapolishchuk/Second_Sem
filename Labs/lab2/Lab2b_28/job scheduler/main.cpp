//
//  main.cpp
//  job scheduler
//
//  Created by Marina Polishchuk on 2/24/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include "Task.hpp"
#include "Queue.hpp"
#include <string>

void Round_Robin(Queue<Task> q) {
    Queue<Task> main_q;
    
    if(!q.empty() && q.get_first()->data.arrival_time != Task::global_time_count) {
        Task::global_time_count++;
    }
    
    while(true) {
        
        for (int i = 0; i < Task::time_interval; ++i) {
            
            if(!q.empty() && q.get_first()->data.arrival_time == Task::global_time_count) {
                main_q.push_back(q.get_first()->data);
                q.remove_first_element();
                std::cout << Task::global_time_count << std::endl;
                main_q.print();
                std::cout << std::endl;
            }
            
            Task::global_time_count++;
            if (!main_q.empty()) { main_q.get_first()->data.execute_time--; }
                
            if(!main_q.empty() && i == Task::time_interval - 1 && main_q.get_first()->data.execute_time != 0) {
                main_q.remove_first_in_the_end();
                std::cout << Task::global_time_count << std::endl;
                main_q.print();
                std::cout << std::endl;
                i = 0;
                break;
            }
                
            if(!main_q.empty() && main_q.get_first()->data.execute_time == 0) {
                main_q.remove_first_element();
                std::cout << Task::global_time_count << std::endl;
                main_q.print();
                std::cout << std::endl;
                i = 0;
                break;
            }
        }
        if (main_q.empty() && q.empty()) {
            std::cout << "The list is empty." << std::endl;
            break;
        }
    }
}

int main() {
    std::cout << "Enter 1 to choose a demo mode or enter 2 to to choose an interactive mode:" << std::endl;
    int num = 0;
    std::cin >> num;
    switch (num) {
        case 1: {
            std::cout << "Welcome to the demo mode.\nThere are five tasks.\nTime interval = 100." << std::endl;
            Task task0{"TASK 0", 0, 250};
            Task task1{"TASK 1", 50, 170};
            Task task2{"TASK 2", 130, 75};
            Task task3{"TASK 3", 190, 100};
            Task task4{"TASK 4", 210, 130};
            Task task5{"TASK 5", 350, 50};
            
            Queue<Task> q;
        
            q.push_back(task0);
            q.push_back(task1);
            q.push_back(task2);
            q.push_back(task3);
            q.push_back(task4);
            q.push_back(task5);
            
            std::cout << std::endl;
            q.print_with_address();
            std::cout << std::endl;
            Round_Robin(q);
            break;
        }
            
        case 2: {
            std::cout << "Welcome to the interactive mode." << std::endl;
            
            std::cout << "Firstly, enter the time interval: ";
            int interval_by_user = 0;
            std::cin >> interval_by_user;
            std::cout << "Time interval = " << interval_by_user << "." << std::endl;
            Task::time_interval = interval_by_user;
            
            std::cout << "How many tasks would you like to add to your to do list? ";
            int num_of_tasks = 0;
            std::cin >> num_of_tasks;
            
            Queue<Task> q;
            for (int i = 0; i < num_of_tasks; ++i) {
                Task temp;
                
                std::cout << "Enter arrival time and execute time. Then enter the text: ";
                int arr_time, ex_time;
                std::cin >> arr_time >> ex_time;
                temp.arrival_time = arr_time;
                temp.execute_time = ex_time;
                getline(std::cin, temp.text);
                
                q.push_back(temp);
            }
            
            std::cout << "\nThere is your task list: " << std::endl;
            q.print();
            
            std::cout << "\nRound Robin for your list: " << std::endl;
            std::cout << std::endl;
            Round_Robin(q);
            
            break;
        }
            
        default:
            std::cout << "Mode was chosen incorrectly." << std::endl;
            break;
    }
    return 0;
}
