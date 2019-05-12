//
//  main.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include <functional>
#include <vector>
#include "DataBase.hpp"
#include "Train.hpp"
#include "Benchmark.hpp"

#define SORT

std::string PATH = "/Users/marinapolishchuk/Second_Sem/Labs/Lab1/DB Trains/DB Trains/Trains.txt";
void interactive_mode_for_simple_saving(); //+
void demo_mode_for_simple_saving(); //+

void interactive_mode_for_file_saving(); //+
void demo_mode_for_file_saving(); //+

void simple_saving() {
    int choice;
    std::cout << "Choose demo(1) or interactive(2) mode: ";
    std::cin >> choice;
    switch (choice) {
        case 1: {
            demo_mode_for_simple_saving();
            break;
        }
        case 2: {
            interactive_mode_for_simple_saving();
            break;
        }
        default: std::cout << "Mode was chosen incorrectly." << std::endl;
            break;
    }
}
void file_saving() {
    int choice;
    std::cout << "Choose demo(1) or interactive(2) mode: ";
    std::cin >> choice;
    switch (choice) {
        case 1: {
            demo_mode_for_file_saving();
            break;
        }
        case 2: {
            interactive_mode_for_file_saving();
            break;
        }
        default: std::cout << "Mode was chosen incorrectly." << std::endl;
            break;
    }
}

#ifdef SORT

constexpr int COMP_BY_ID            = 1;
constexpr int COMP_BY_NUMBER        = 1 << 1;
constexpr int COMP_BY_NAME          = 1 << 2;
constexpr int COMP_BY_TYPE          = 1 << 3;
constexpr int COMP_BY_ARR_DATE      = 1 << 4;
constexpr int COMP_BY_ARR_TIME      = 1 << 5;
constexpr int COMP_BY_DEP_DATE      = 1 << 6;
constexpr int COMP_BY_DEP_TIME      = 1 << 7;
constexpr int COMP_BY_POPULARITY    = 1 << 8;

std::function<bool(Train, Train)> GetLambda(std::vector<int> comp_fields) {
    static auto comp_by_id          = [](Train a, Train b){ return a.GetID() < b.GetID(); };
    static auto comp_by_number      = [](Train a, Train b){ return a.GetNumber() < b.GetNumber(); };
    static auto comp_by_name        = [](Train a, Train b){ return a.GetName() < b.GetName(); };
    static auto comp_by_type        = [](Train a, Train b){ return a.GetType() < b.GetType(); };
    static auto comp_by_arr_date    = [](Train a, Train b){ return a.GetArrDate() < b.GetArrDate(); };
    static auto comp_by_arr_time    = [](Train a, Train b){ return a.GetArrTime() < b.GetArrTime(); };
    static auto comp_by_dep_date    = [](Train a, Train b){ return a.GetDepDate() < b.GetDepDate(); };
    static auto comp_by_dep_time    = [](Train a, Train b){ return a.GetDepTime() < b.GetDepTime(); };
    static auto comp_by_popularity  = [](Train a, Train b){ return a.GetPopularity() < b.GetPopularity(); };
    
    std::vector<std::function<bool(Train, Train)>> comps;
    
    for (auto comp_field: comp_fields) {
        if (comp_field & COMP_BY_ID) { comps.push_back(comp_by_id); }
        else if (comp_field & COMP_BY_NUMBER) { comps.push_back(comp_by_number); }
        else if (comp_field & COMP_BY_NAME) { comps.push_back(comp_by_name); }
        else if (comp_field & COMP_BY_TYPE) { comps.push_back(comp_by_type); }
        else if (comp_field & COMP_BY_ARR_DATE) { comps.push_back(comp_by_arr_date); }
        else if (comp_field & COMP_BY_ARR_TIME) { comps.push_back(comp_by_arr_time); }
        else if (comp_field & COMP_BY_DEP_DATE) { comps.push_back(comp_by_dep_date); }
        else if (comp_field & COMP_BY_DEP_TIME) { comps.push_back(comp_by_dep_time); }
        else if (comp_field & COMP_BY_POPULARITY) { comps.push_back(comp_by_popularity); }
    }
    
    auto comp_final = [comps](Train a, Train b){
        for (auto comp: comps) {
            if (comp(a, b)) { return true; }
        }
        return false;
    };
    return comp_final;
}


int main() {
//    DataBase db;
//    db.generate(5);
//    db.print();
//    std::vector<int> comps = {COMP_BY_DEP_TIME};
//    auto comp = GetLambda(comps);
//    db.sort(comp);
//    std::cout << std::endl;
//    db.print();


    DataBase db;
    int size = 10;
    db.generate(size);
    std::cout << "Data base before sorting:\n";
    db.print();

    DataBase db_1field;
    DataBase db_2fields;
    DataBase db_counting;
    DataBase db_radix;

    for (int i  = 0; i < size; ++i) {
        std::vector<Train> temp = db.get_trains();
        db_1field.add(temp[i]);
        db_2fields.add(temp[i]);
        db_counting.add(temp[i]);
        db_radix.add(temp[i]);
    }

    std::vector<int> comps1 = {COMP_BY_POPULARITY};
    auto comp1 = GetLambda(comps1);
    clock_t start1 = clock();
    db_1field.sort(comp1);
    clock_t end1 = clock();
    clock_t res1 = end1 - start1;
    std::cout << "\n\nSorted by one field (POPULARITY):\n";
    db_1field.print();
    std::cout << "Time of working: " << res1 << std::endl;

    std::vector<int> comps2 = {COMP_BY_NUMBER, COMP_BY_TYPE};
    auto comp2 = GetLambda(comps2);
    clock_t start2 = clock();
    db_2fields.sort(comp2);
    clock_t end2 = clock();
    clock_t res2 = end2 - start2;
    std::cout << "\n\nSorted by two fields (NUMBER, TYPE):\n";
    db_2fields.print();
    std::cout << "Time of working: " << res2 << std::endl;
    
    clock_t start3 = clock();
    db_counting.counting_sort_by_type(0, 3);
    clock_t end3 = clock();
    clock_t res3 = end3 - start3;
    std::cout << "\n\nCounting sort by type:\n";
    db_counting.print();
    std::cout << "Time of working: " << res3 << std::endl;
    
    clock_t start4 = clock();
    db_radix.radix_sort_by_number();
    clock_t end4 = clock();
    clock_t res4 = end4 - start4;
    std::cout << "\n\nRadix sort by number:\n";
    db_radix.print();
    std::cout << "Time of working: " << res4 << std::endl;
    
    return 0;
}
#endif

#ifndef SORT
int main() {

//
//    DataBase db(PATH);
//    db.read();
//
//    Criteria c("dwa");
//    Criteria m(Type::INTERNATIONAL, 1111, 2222);
//    Criteria b({5,5,5}, {66, 23});
//    std::vector<Train> vec = db.search(m);
//
//    vec[0].PrintTrain();
//    DataBase db(PATH);
//    Train t;
//    t.SetName("train");
//    t.SetType(Type::INTERNATIONAL);
//    t.SetNumber(1234);
//    t.SetArrival({1, 2, 3}, {11, 22});
//    t.SetDeparture({6, 6, 6}, {77, 77});
//    t.SetTicketReq(1);
//    t.SetNumOfSeats(2);
//    t.SetPopularity();
//
//    db.Add(t);
//
//    t.SetType(Type::SUBURBAN);
//    t.SetName("trainn dwa");
//    db.Add(t);
   
    std::cout << "Choose the mechanism of saving to work with:"
    << "\n\t1. Simple saving (std::vector)"
    << "\n\t2. Saving in file"
    << "\n\t3. Benchmark mode" << std::endl;
    int choice = 0;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "You've chosen simple saving." << std::endl;
            simple_saving();
            break;
        }
        case 2: {
            std::cout << "You've chosen saving in file." << std::endl;
            file_saving();
            break;
        }
        case 3: {
            std::cout << "You've chosen benchmark mode." << std::endl;
            benchmark_mode();
            break;
        }
            
        default: {
            std::cout << "An option was chosen incorrectly." << std::endl;
            break;
        }
    }

    return 0;
}
#endif

void interactive_mode_for_simple_saving() {
    DataBase db;
    std::cout << "Welcome to the interactive mode fore simple saving." << std::endl;
    std::cout << "How many trains would you like to add to your data base?" << std::endl;
    int num_of_trains = 0;
    std::cin >> num_of_trains;
    std::vector<Train> vec;
    for (int i = 0; i < num_of_trains; ++i) {
        std::cout << "START" << std::endl;
        Train t;
        std::cout << "Enter name" << std::endl;
        std::string name;
        std::cin >> name;
        t.SetName(name);
        
        std::cout << "Enter type" << std::endl;
        int tp;
        std::cin >> tp;
        t.SetType(static_cast<Type>(tp));
        
        std::cout << "Enter number" << std::endl;
        int number;
        std::cin >> number;
        t.SetNumber(number);
        
        std::cout << "Enter arrival date and time" << std::endl;
        int d, m, y, h, min;
        std::cin >> d >> m >> y >> h >> min;
        t.SetArrival({d, m, y}, {h, min});
        
        std::cout << "Enter departure date and time" << std::endl;
        int d2, m2, y2, h2, min2;
        std::cin >> d2 >> m2 >> y2 >> h2 >> min2;
        t.SetDeparture({d2, m2, y2}, {h2, min2});
        
        std::cout << "Enter number of seats" << std::endl;
        int num_of_seats;
        std::cin >> num_of_seats;
        t.SetNumOfSeats(num_of_seats);
        
        std::cout << "Enter ticket requests" << std::endl;
        int tr;
        std::cin >> tr;
        t.SetTicketReq(tr);
        
        t.SetPopularity();
        vec.push_back(t);
    }
    
    std::cout << "There is your db: " << std::endl;
    for(auto a: vec) {
        a.PrintTrain();
    }
    
    std::cout <<  "\nSearching by criteria demonstration: " << std::endl;
    std::cout << "\nBy name: " << std::endl;
    std::string str;
    std::cout << "Enter by_name criteria:" << std::endl;
    std::cin >> str;
    Criteria a(str);
    std::vector<Train> search_vec = db.search(a);
    for (auto a: search_vec) {
        a.PrintTrain();
    }
    search_vec.clear();
    
    
    std::cout << "\nBy type and number: ";
    std::cout << "Enter by_type criteria:" << std::endl;
    int q = 0, w = 0, e = 0;
    std::cin >> q >> w >> e;
    Criteria b(static_cast<Type>(q), w, e);
    search_vec = db.search(b);
    for (auto a: search_vec) {
        a.PrintTrain();
    }
    search_vec.clear();
    
    std::cout << "\nBy departure date and time: ";
    std::cout << "Enter by_dep criteria:" << std::endl;
    int z, x, c, v, n;
    std::cin >> z >> x >> c >> v >> n;
    Criteria m({z, x, c}, {v, n});
    search_vec = db.search(m);
    for (auto a: search_vec) {
        a.PrintTrain();
    }
    search_vec.clear();
}
void demo_mode_for_simple_saving() {
    std::cout << "Welcome to the demo mode for simple saving." << std::endl;
    std::cout << "There are three trains." << std::endl;
    Train t1;
    t1.SetName("train1");
    t1.SetType(Type::INTERNATIONAL);
    t1.SetNumber(1111);
    t1.SetArrival({11, 11, 2001}, {11, 11});
    t1.SetDeparture({12, 12, 2001}, {11, 11});
    t1.SetTicketReq(100);
    t1.SetNumOfSeats(200);
    t1.SetPopularity();
    Train t2;
    t2.SetName("train2");
    t2.SetType(Type::SUBURBAN);
    t2.SetNumber(2222);
    t2.SetArrival({22, 22, 2002}, {22, 22});
    t2.SetDeparture({23, 23, 2002}, {22, 22});
    t2.SetTicketReq(200);
    t2.SetNumOfSeats(200);
    t2.SetPopularity();
    Train t3;
    t3.SetName("train3");
    t3.SetType(Type::FAST);
    t3.SetNumber(3333);
    t3.SetArrival({33, 33, 2003}, {33, 33});
    t3.SetDeparture({34, 34, 2003}, {33, 33});
    t3.SetTicketReq(400);
    t3.SetNumOfSeats(200);
    t3.SetPopularity();
    DataBase db;
    std::cout << "\n######################################" << std::endl;
    std::cout << "\nPrint and add method: ################" << std::endl;
    std::cout << "\nisEmpty method: " << db.is_empty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.add(t1);
    std::cout << "\nisEmpty method: " << db.is_empty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.print();
    db.add(t2);
    std::cout << "\nisEmpty method: " << db.is_empty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.print();
    db.add(t3);
    std::cout << "\nisEmpty method: " << db.is_empty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.print();
    db.printf();
    std::cout << "\n######################################" << std::endl;
    
    std::cout <<  "\nSearching by criteria demonstration: " << std::endl;
    std::cout << "\nBy name(Criteria c(\"2\")): ";
    Criteria c("2");
    std::vector<Train> vec = db.search(c);
    for (auto a: vec) {
        a.PrintTrain();
    }
    vec.clear();
    
    std::cout << "\nBy type and number(Criteria t(Type::INTERNATIONAL, 1110, 2222): ";
    Criteria t(Type::INTERNATIONAL, 1110, 2222);
    vec = db.search(t);
    for (auto a: vec) {
        a.PrintTrain();
    }
    vec.clear();
    
    std::cout << "\nBy departure date and time(Criteria m({30,30,2000}, {20, 20}): ";
    Criteria m({30,30,2000}, {20, 20});
    vec = db.search(m);
    for (auto a: vec) {
        a.PrintTrain();
    }
    vec.clear();
}

void demo_mode_for_file_saving() {
    std::cout << "Choose txt(1) or binary(2) file:" << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            DataBase db(PATH, OpenMode::TXT);
            std::cout << "Txt was chosen" << std::endl;
            std::cout << "\nGenerating of 10 trains." << std::endl;
            db.generate(10);
            std::cout << "10 elements were generated." << std::endl;
            std::cout << "Here they are: " << std::endl;
            std::vector<Train> vec = db.get_trains();
            for (auto a: vec) {
                a.PrintTrain();
            }
            std::cout << "\nDemonstration of adding method: " << std::endl;
            Train t;
            t.SetName("train1");
            t.SetType(Type::INTERNATIONAL);
            t.SetNumber(1111);
            t.SetArrival({11, 11, 2001}, {11, 11});
            t.SetDeparture({12, 12, 2001}, {11, 11});
            t.SetTicketReq(100);
            t.SetNumOfSeats(200);
            t.SetPopularity();
            db.add(t);
            vec = db.get_trains();
            
            std::cout << "Data base after adding an element: " << std::endl;
            for (auto a: vec) {
                a.PrintTrain();
            }
            
            std::vector<Train> search_vec;
            std::cout <<  "\nSearching by criteria demonstration: " << std::endl;
            std::cout << "\nBy name(Criteria c(\"85_5\")): ";
            Criteria c("85_5");
            search_vec = db.search(c);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            std::cout << "\nBy type and number(Criteria l(Type::Ordinary, 5000, 6000): ";
            Criteria l(Type::ORDINARY, 5000, 6000);
            search_vec = db.search(l);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            std::cout << "\nBy departure date and time(Criteria m({1,1,2019}, {1,1}): ";
            Criteria m({1,1,2019}, {1, 1});
            search_vec = db.search(m);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            break;
        }
        case 2: {
            DataBase db(PATH, OpenMode::BINARY);
            std::cout << "Binary was chosen" << std::endl;
            std::cout << "Generating of 10 trains." << std::endl;
            db.generate(10);
            std::cout << "10 elements were generated." << std::endl;
            std::cout << "Here they are: " << std::endl;
            std::vector<Train> vec = db.get_trains();
            for (auto a: vec) {
                a.PrintTrain();
            }
            std::cout << "\nDemonstration of adding method: " << std::endl;
            Train t;
            t.SetName("train1");
            t.SetType(Type::INTERNATIONAL);
            t.SetNumber(1111);
            t.SetArrival({11, 11, 2001}, {11, 11});
            t.SetDeparture({12, 12, 2001}, {11, 11});
            t.SetTicketReq(100);
            t.SetNumOfSeats(200);
            t.SetPopularity();
            db.add(t);
            vec = db.get_trains();
            
            std::cout << "Data base after adding an element: " << std::endl;
            for (auto a: vec) {
                a.PrintTrain();
            }
            
            std::vector<Train> search_vec;
            std::cout <<  "\nSearching by criteria demonstration: " << std::endl;
            std::cout << "\nBy name(Criteria c(\"85_5\")): ";
            Criteria c("85_5");
            search_vec = db.search(c);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            std::cout << "\nBy type and number(Criteria l(Type::Ordinary, 5000, 6000): ";
            Criteria l(Type::ORDINARY, 5000, 6000);
            search_vec = db.search(l);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            std::cout << "\nBy departure date and time(Criteria m({1,1,2019}, {1,1}): ";
            Criteria m({1,1,2019}, {1, 1});
            search_vec = db.search(m);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            break;
        }
        default: {
            std::cout << "An option was chosen incorrectly." << std::endl;
            break;
        }
    }
}

void interactive_mode_for_file_saving() {
    std::cout << "Choose txt(1) or binary(2) file:" << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            DataBase db(PATH, OpenMode::TXT);
            std::cout << "Txt was chosen" << std::endl;
            std::cout << "How many trains would you like to generate?" << std::endl;
            size_t n;
            std::cin >> n;
            db.generate(n);
            std::cout << n << " elements were generated." << std::endl;
            
            std::cout << "How many trains would you like to add to your data base?" << std::endl;
            int num_of_trains = 0;
            std::cin >> num_of_trains;
            for (int i = 0; i < num_of_trains; ++i) {
                std::cout << "START" << std::endl;
                Train t;
                std::cout << "Enter name" << std::endl;
                std::string name;
                std::cin >> name;
                t.SetName(name);
                
                std::cout << "Enter type" << std::endl;
                int tp;
                std::cin >> tp;
                t.SetType(static_cast<Type>(tp));
                
                std::cout << "Enter number" << std::endl;
                int number;
                std::cin >> number;
                t.SetNumber(number);
                
                std::cout << "Enter arrival date and time" << std::endl;
                int d, m, y, h, min;
                std::cin >> d >> m >> y >> h >> min;
                t.SetArrival({d, m, y}, {h, min});
                
                std::cout << "Enter departure date and time" << std::endl;
                int d2, m2, y2, h2, min2;
                std::cin >> d2 >> m2 >> y2 >> h2 >> min2;
                t.SetDeparture({d2, m2, y2}, {h2, min2});
                
                std::cout << "Enter number of seats" << std::endl;
                int num_of_seats;
                std::cin >> num_of_seats;
                t.SetNumOfSeats(num_of_seats);
                
                std::cout << "Enter ticket requests" << std::endl;
                int tr;
                std::cin >> tr;
                t.SetTicketReq(tr);
                
                t.SetPopularity();
                db.add(t);
            }
            
            
            std::cout <<  "\nSearching by criteria demonstration: " << std::endl;
            std::cout << "\nBy name: " << std::endl;
            std::string str;
            std::cout << "Enter by_name criteria:" << std::endl;
            std::cin >> str;
            Criteria a(str);
            std::vector<Train> search_vec = db.search(a);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            
            std::cout << "\nBy type and number: ";
            std::cout << "Enter by_type criteria:" << std::endl;
            int q = 0, w = 0, e = 0;
            std::cin >> q >> w >> e;
            Criteria b(static_cast<Type>(q), w, e);
            search_vec = db.search(b);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            std::cout << "\nBy departure date and time: ";
            std::cout << "Enter by_dep criteria:" << std::endl;
            int z, x, c, v, o;
            std::cin >> z >> x >> c >> v >> o;
            Criteria m({z, x, c}, {v, o});
            search_vec = db.search(m);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
        
            break;
        }
            
        case 2: {
            std::cout << "Binary was chosen" << std::endl;
            DataBase db(PATH, OpenMode::BINARY);
            std::cout << "binary was chosen" << std::endl;
            std::cout << "How many trains would you like to generate?" << std::endl;
            size_t n;
            std::cin >> n;
            db.generate(n);
            std::cout << n << " elements were generated." << std::endl;
            
            std::cout << "How many trains would you like to add to your data base?" << std::endl;
            int num_of_trains = 0;
            std::cin >> num_of_trains;
            for (int i = 0; i < num_of_trains; ++i) {
                std::cout << "START" << std::endl;
                Train t;
                std::cout << "Enter name" << std::endl;
                std::string name;
                std::cin >> name;
                t.SetName(name);
                
                std::cout << "Enter type" << std::endl;
                int tp;
                std::cin >> tp;
                t.SetType(static_cast<Type>(tp));
                
                std::cout << "Enter number" << std::endl;
                int number;
                std::cin >> number;
                t.SetNumber(number);
                
                std::cout << "Enter arrival date and time" << std::endl;
                int d, m, y, h, min;
                std::cin >> d >> m >> y >> h >> min;
                t.SetArrival({d, m, y}, {h, min});
                
                std::cout << "Enter departure date and time" << std::endl;
                int d2, m2, y2, h2, min2;
                std::cin >> d2 >> m2 >> y2 >> h2 >> min2;
                t.SetDeparture({d2, m2, y2}, {h2, min2});
                
                std::cout << "Enter number of seats" << std::endl;
                int num_of_seats;
                std::cin >> num_of_seats;
                t.SetNumOfSeats(num_of_seats);
                
                std::cout << "Enter ticket requests" << std::endl;
                int tr;
                std::cin >> tr;
                t.SetTicketReq(tr);
                
                t.SetPopularity();
                db.add(t);
            }
            
            
            std::cout <<  "\nSearching by criteria demonstration: " << std::endl;
            std::cout << "\nBy name: " << std::endl;
            std::string str;
            std::cout << "Enter by_name criteria:" << std::endl;
            std::cin >> str;
            Criteria a(str);
            std::vector<Train> search_vec = db.search(a);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            
            std::cout << "\nBy type and number: ";
            std::cout << "Enter by_type criteria:" << std::endl;
            int q = 0, w = 0, e = 0;
            std::cin >> q >> w >> e;
            Criteria b(static_cast<Type>(q), w, e);
            search_vec = db.search(b);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            std::cout << "\nBy departure date and time: ";
            std::cout << "Enter by_dep criteria:" << std::endl;
            int z, x, c, v, o;
            std::cin >> z >> x >> c >> v >> o;
            Criteria m({z, x, c}, {v, o});
            search_vec = db.search(m);
            for (auto a: search_vec) {
                a.PrintTrain();
            }
            search_vec.clear();
            
            break;
        }
        default: {
            std::cout << "An option was chosen incorrectly." << std::endl;
            break;
        }
    }

}

