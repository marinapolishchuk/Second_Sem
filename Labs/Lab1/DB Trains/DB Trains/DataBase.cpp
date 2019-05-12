//
//  DataBase.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include "DataBase.hpp"

DataBase::DataBase(std::string path, OpenMode om): len(0), saved(true), wasRead(false){
    if(path.empty()) { this->om = OpenMode::VECTOR; return; }
    if(om == OpenMode::TXT) {
        of.open(path);
    } else {
        of.open(path, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
    }
    this->om = om;
    if(!of.is_open()) { std::cout << "Error in file opening" << std::endl; }
};

DataBase::~DataBase(){
    save();
    if (of.is_open()) of.close();
}

bool DataBase::is_empty() {
    if (len == 0) return true;
    return false;
}

int DataBase::length() { return len; }

void DataBase::add(Train t) { trains.push_back(t); len++; saved = false;}

void DataBase::print() {
    for (int i = 0; i < len; ++i) {
        std::cout << trains[i].Serialize();
    }
}
void DataBase::printf() {
    for (int i = 0; i < len; ++i) {
        trains[i].PrintTrain();
    }
}

void DataBase::save() {
    if (saved || om == OpenMode::VECTOR) return;
    for (auto a : trains) {
        of << a.Serialize();
    }
    trains.clear();
    saved = true;
}

std::vector<Train> DataBase::get_trains() {
    return trains;
}

void DataBase::read() {
    wasRead = true;
    if (om == OpenMode::VECTOR || !of.is_open()) {
        return;
    }
    
    Train t;
    std::string train;
    while (std::getline(of, train)) {
        t.Unserialize(train);
        trains.push_back(t);
    }
}

std::vector<Train> DataBase::search(Criteria sc) {
    std::vector<Train> res;
    if (!wasRead) read();
    if (sc.tag == SearchMode::NAME) {
        std::string name_to_search = sc.name;
        for (auto train: trains) {
            if (train.GetName().find(name_to_search) != std::string::npos)
                res.push_back(train);
        }
    }
    if (sc.tag == SearchMode::TYPE_AND_NUMBER) {
        for (auto train: trains) {
            if(train.GetType() == sc.tan.t && train.GetNumber() >= sc.tan.lower && train.GetNumber() < sc.tan.upper) {
                res.push_back(train);
            }
        }
    }
    if (sc.tag == SearchMode::DEP_DATE_AND_TIME) {
        for (auto train: trains) {
            if(train.GetDepDate().year > sc.dat.d.year &&
               train.GetDepDate().month > sc.dat.d.month &&
               train.GetDepDate().day > sc.dat.d.day &&
               train.GetDepTime().hours > sc.dat.t.hours &&
               train.GetDepTime().minutes > sc.dat.t.minutes
               ) {
                res.push_back(train);
            }
        }
    }

    return res;
}

void DataBase::open(std::string path, OpenMode om) {
    wasRead = false;
    if(path.empty()) { this->om = OpenMode::VECTOR; return; }
    if(om == OpenMode::TXT) {
        of.open(path);
    } else {
        of.open(path, std::ios::binary);
    }
    this->om = om;
    if(!of.is_open()) { std::cout << "Error in file opening" << std::endl; }
};

void DataBase::generate(size_t n) {
    for (int i = 0; i < n; ++i) {
        Train t;
        t.SetNumber(rand() % 9000 + 1000);
        t.SetName("train_" + std::to_string(t.GetNumber()) + "_" + std::to_string(t.GetID()));
        t.SetType(static_cast<Type>(rand() % 4));
        t.SetArrival({rand() % 32, rand() % 13, rand() % 2 + 2019}, {rand() % 25, rand() % 61});
        t.SetDeparture(t.GetArrDate(), {t.GetArrTime().hours + rand() % (24 - t.GetArrTime().hours + 1), t.GetArrTime().minutes + rand() % (60 - t.GetArrTime().minutes + 1)});
        t.SetTicketReq(rand() % 1000);
        t.SetNumOfSeats(rand() % 1000 + 1);
        t.SetPopularity();
        trains.push_back(t);
        len++;
    }
    saved = false;
}

void DataBase::counting_sort_by_type(int range_low, int range_high) {
    std::vector<Train> res_vec(len);
    int range = range_high - range_low + 1;
    int count[range];
    for (int i = 0; i < range; ++i) {
        count[i] = 0;
    }
    
    for (int i = 0; i < len; ++i) {
        count[static_cast<int>(trains[i].GetType())] += 1;
    }
    
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }
    
    for (int i = len; i >= 0; --i) {
        count[static_cast<int>(trains[i - 1].GetType())] -= 1;
        res_vec[count[static_cast<int>(trains[i - 1].GetType())]] = trains[i - 1];
    }
    
    for (int i = 0; i < len; ++i) {
        trains[i] = res_vec[i];
    }
}

void DataBase::radix_sort_by_number() {
    int digits = 4;
    int max_digits = digits;
    std::queue<Train> q[10];
    while (digits != 0) {
        int divisor = (int) (pow(10, max_digits - digits--));
        for (int i = 0; i < len; ++i) {
            int zeroth_place = (trains[i].GetNumber() / divisor) % 10;
            q[zeroth_place].push(trains[i]);
        }
        for (int i = 0, j = 0; i < 10; ++i) {
            while(!q[i].empty()) {
                trains[j++] = q[i].front();
                q[i].pop();
            }
        }
    }
}


