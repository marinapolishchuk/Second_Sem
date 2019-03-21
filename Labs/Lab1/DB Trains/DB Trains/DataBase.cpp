//
//  DataBase.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include <iostream>
#include "DataBase.hpp"

DataBase::DataBase(std::string path, OpenMode om): len(0), saved(true), wasRead(false){
    if(path.empty()) { this->om = OpenMode::VECTOR; return; }
    if(om == OpenMode::TXT) {
        of.open(path);
    } else {
        of.open(path, std::ios::binary);
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
//        of.seekg(0);
//        Train t;
//        std::string train;
//        while (std::getline(of, train)) {
//            t.Unserialize(train);
//            if (t.GetName().find(name_to_search) != std::string::npos) {
//                res.push_back(t);
//            }
//        }
        for (auto train: trains) {
            if (train.GetName().find(name_to_search) != std::string::npos)
                res.push_back(train);
        }
        
    }
    
    return res;
}
