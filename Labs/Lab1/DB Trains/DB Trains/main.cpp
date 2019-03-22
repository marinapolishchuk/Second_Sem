//
//  main.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include "DataBase.hpp"
#include "Train.hpp"

std::string PATH = "/Users/marinapolishchuk/Second_Sem/Labs/Lab1/DB Trains/DB Trains/Trains.txt";

void interactive_mode_for_simple_saving();
void demo_mode_for_simple_saving() {
    std::cout << "Welcome to the demo mode fore simple saving." << std::endl;
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
    std::cout << "\nisEmpty method: " << db.isEmpty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.Add(t1);
    std::cout << "\nisEmpty method: " << db.isEmpty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.Print();
    db.Add(t2);
    std::cout << "\nisEmpty method: " << db.isEmpty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.Print();
    db.Add(t3);
    std::cout << "\nisEmpty method: " << db.isEmpty() << "\nThere are " << db.length() << " trains.(length() method)" << std::endl;
    db.Print();
    db.Printf();
    std::cout << "\n######################################" << std::endl;
    
    // . . . // демонстрация поиска по заданному критерию.
    
}

void interactive_mode_for_txt_saving();
void demo_mode_for_txt_saving();

void interactive_mode_for_bin_saving();
void demo_mode_for_bin_saving();

void simple_saving();
void txt_saving();
void binary_saving();

int main() {
    
    DataBase db(PATH);
    db.generate(50000);
    
    
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
    
    
   /* //1 1234 train 0 1 2 3 11 22 6 6 6 77 77 50 51
    Train t, n;
    t.SetName("train");
    t.SetType(Type::INTERNATIONAL);
    t.SetNumber(1234);
    t.SetArrival({1, 2, 3}, {11, 22});
    t.SetDeparture({6, 6, 6}, {77, 77});
    t.SetTicketReq(1);
    t.SetNumOfSeats(2);
    t.SetPopularity();
   // n.Unserialize(t.Serialize());
    DataBase db;
    db.Add(t);
    db.Add(n);
    std::cout << db.isEmpty() << ' ' << db.length() << std::endl;
    db.Print();
    
    DataBase dbtxt("aaa.txt", OpenMode::TXT);
    dbtxt.AddToTxt(t);
    dbtxt.AddToTxt(n);
    std::cout << dbtxt.isEmpty() << ' ' << dbtxt.length() << std::endl;
   
    
    
    
    
    std::cout << "Choose the mechanism of saving to work with:"
    << "\n\t1. Simple saving (std::vector)"
    << "\n\t2. Saving in txt file"
    << "\n\t3. Saving in binary file" << std::endl;
    int choice = 0;
    std::cin >> choice;
    
    switch (choice) {
        case 1: {
            std::cout << "You've chosen simple saving." << std::endl;
            demo_mode_for_simple_saving();
            //simple_saving();
            break;
        }
        case 2: {
            std::cout << "You've chosen saving in txt file." << std::endl;
//            txt_saving();
            break;
        }
        case 3: {
            std::cout << "You've chosen saving in binary file." << std::endl;
//            binary_saving();
            break;
        }
        default: {
            std::cout << "An option was chosen incorrectly." << std::endl;
            break;
        }
    }*/
   
    return 0;
}



