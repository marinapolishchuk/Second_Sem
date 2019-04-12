//
//  Benchmark.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 4/5/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "Benchmark.hpp"
#include "DataBase.hpp"


void benchmark_mode() {
    std::string PATH = "/Users/marinapolishchuk/Second_Sem/Labs/Lab1/DB Trains/DB Trains/Trains.txt";
    
    unsigned int start_time =  clock();
    DataBase db(PATH, OpenMode::TXT);
    db.generate(10);
    std::vector<Train> vec = db.getTrains();
    for (auto a: vec) {
        a.PrintTrain();
    }
    std::vector<Train> search_vec;
    Criteria c("85_5");
    search_vec = db.search(c);
    for (auto a: search_vec) {
        a.PrintTrain();
    }
    search_vec.clear();
    
    Criteria l(Type::ORDINARY, 5000, 6000);
    search_vec = db.search(l);
    for (auto a: search_vec) {
        a.PrintTrain();
    }
    search_vec.clear();
    
    Criteria m({1,1,2019}, {1, 1});
    search_vec = db.search(m);
    for (auto a: search_vec) {
        a.PrintTrain();
    }
    search_vec.clear();
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << search_time << std::endl;
}
