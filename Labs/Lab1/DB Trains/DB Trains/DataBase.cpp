//
//  DataBase.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include <cstdlib>
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

bool DataBase::isEmpty() {
    if (len == 0) return true;
    return false;
}

int DataBase::length() { return len; }

void DataBase::Add(Train t) { trains.push_back(t); len++; saved = false;}

void DataBase::Print() {
    for (int i = 0; i < len; ++i) {
        std::cout << trains[i].Serialize();
    }
}
void DataBase::Printf() {
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

std::vector<Train> DataBase::getTrains() {
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

void DataBase::Open(std::string path, OpenMode om) {
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
    }
    saved = false;
}


