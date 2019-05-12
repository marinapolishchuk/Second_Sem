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
    
    bool is_empty(); //+
    int length(); //+
    
    void add(Train t); //+
    void print(); //+
    void printf(); //+
    
    void read();
    
    std::vector<Train> get_trains();
    
    std::vector<Train> search(Criteria sc);
    
    void save();
    
    void generate(size_t);
    void open(std::string path = "", OpenMode om = OpenMode::TXT);
    
    template <typename Func>
    void sort(Func);
    
    void counting_sort_by_type(int, int);
    void radix_sort_by_number();
};

template <typename Func>
int partition(std::vector<Train> &vec, int low, int high, Func comp) {
    int i = low;
    for (int j = low; j <= high - 1; j++) {
        if (comp(vec[j], vec[high])) {
            std::swap(vec[j], vec[i]);
            i++;
        }
    }
    std::swap(vec[i], vec[high]);
    return i;
}

template <typename Func>
void quick_sort(std::vector<Train> &vec, int low, int high, Func comp){
    if (low < high) {
        int p = partition(vec, low, high, comp);
        quick_sort(vec, low, p - 1, comp);
        quick_sort(vec, p + 1, high, comp);
    }
}

template <typename Func>
void DataBase::sort(Func comp) {
    quick_sort(trains, 0, trains.size() - 1, comp);
}


#endif /* DataBase_hpp */
