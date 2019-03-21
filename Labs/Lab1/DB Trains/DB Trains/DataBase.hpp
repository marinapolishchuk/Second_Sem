//
//  DataBase.hpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef DataBase_hpp
#define DataBase_hpp

#include <vector>
#include <fstream>
#include "Train.hpp"

enum class OpenMode {VECTOR, TXT, BINARY};
enum class SearchMode {NAME, TYPE_AND_NUMBER, DEP_DATE_AND_TIME};

struct Criteria {
    std::string name;
    struct TypeAndNum { Type t; short lower; short upper; } tan;
    struct DateAndTime { Date d; Time t; } dat;
    
    SearchMode tag;
    
    Criteria(std::string name): name(name), tag(SearchMode::NAME) {}
    Criteria(Type t, short lower, short upper) {
        tan.t = t;
        tan.lower = lower;
        tan.upper = upper;
        tag = SearchMode::TYPE_AND_NUMBER;
    }
    Criteria(Date d, Time t) {
        dat.d = d;
        dat.t = t;
        tag = SearchMode::DEP_DATE_AND_TIME;
    }
};

class DataBase {
    std::vector<Train> trains;
    std::fstream of;
    int len;
    OpenMode om;
    bool saved;
    bool wasRead;
public:
    DataBase(std::string path = "", OpenMode om = OpenMode::TXT);
    ~DataBase();
    
    bool isEmpty(); //+
    int length(); //+
    
    void Add(Train t); //+
    void Print(); //+
    void Printf(); //+
    
    void read();
    
    std::vector<Train> getTrains();
    
    std::vector<Train> search(Criteria sc);
    
    void save();
    
    
};

#endif /* DataBase_hpp */
