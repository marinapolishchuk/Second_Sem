//
//  Data.hpp
//  Lab6
//
//  Created by  Марина on 6/3/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Data_hpp
#define Data_hpp
#include "headers.h"

struct TimeAndDate {
    struct Time { int hours; int minutes; } time;
    struct Date { int day; int month; int year; } date;
    std::string to_string() {
        std::string res = "{" + std::to_string(date.day) + "." + std::to_string(date.month) + "." + std::to_string(date.year) + " " + std::to_string(time.hours) + ":" + std::to_string(time.minutes) + "}";
        return res;
    }
    bool operator>(const TimeAndDate& rhs){
        int d1 = this->date.day + this->date.month * 31 + this->date.year * 365;
        int d2 = rhs.date.day + rhs.date.month * 31 + rhs.date.year * 365;
        int t1 = this->time.minutes + this->time.hours * 60;
        int t2 = rhs.time.minutes + rhs.time.hours * 60;
        if(d1 > d2) { return true; }
        else if (d1 == d2 && t1 > t2) { return true; }
        return false;
    }
    bool operator<(const TimeAndDate& rhs){
        int d1 = this->date.day + this->date.month * 31 + this->date.year * 365;
        int d2 = rhs.date.day + rhs.date.month * 31 + rhs.date.year * 365;
        int t1 = this->time.minutes + this->time.hours * 60;
        int t2 = rhs.time.minutes + rhs.time.hours * 60;
        if(d1 < d2) { return true; }
        else if (d1 == d2 && t1 < t2) { return true; }
        return false;
    }
    bool operator==(const TimeAndDate& rhs){
        if(this->date.day == rhs.date.day && this->date.month == rhs.date.month && this->date.year == rhs.date.year && this->time.hours == rhs.time.hours && this->time.minutes == rhs.time.minutes) { return true; }
        return false;
    }
    void generate_random() {
        this->date.day = rand() % 31 + 1;
        this->date.month = rand() % 12 + 1;
        this->date.year = rand() % 120 + 1901;
        
        this->time.hours = rand() % 24 + 1;
        this->time.minutes = rand() % 60 + 1;
    }

};

#endif /* Data_hpp */
