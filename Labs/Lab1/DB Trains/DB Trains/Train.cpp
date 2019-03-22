//
//  Train.cpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/13/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "Train.hpp"
#include <sstream>
#include <algorithm>

int Train::count = 0;

std::string Train::Serialize() {
    std::ostringstream os;
    
    std::replace(name.begin(), name.end(), ' ', static_cast<char>(36));
        
    os << id << ' ';
    os << train_number << ' ';
    os << name << ' ';
    os << static_cast<int>(type) << ' ';
    os << arrival_date.day << ' ' << arrival_date.month << ' ' << arrival_date.year << ' ';
    os << arrival_time.hours << ' ' << arrival_time.minutes << ' ';
    os << departure_date.day << ' ' << departure_date.month << ' ' << departure_date.year << ' ';
    os << departure_time.hours << ' ' << departure_time.minutes << ' ';
    os << ticket_requests << ' ';
    os << num_of_seats << ' ';
    os << popularity << std::endl;
    
    return os.str();
}

void Train::Unserialize(std::string str) {
    std::istringstream is(str);
    is >> id;
    is >> train_number;
    is >> name;
    std::replace(name.begin(), name.end(), static_cast<char>(36), ' ');
    int t; is >> t; type = static_cast<Type>(t);
    is >> arrival_date.day >> arrival_date.month >> arrival_date.year;
    is >> arrival_time.hours >> arrival_time.minutes;
    is >> departure_date.day >> departure_date.month >> departure_date.year;
    is >> departure_time.hours >> departure_time.minutes;
    is >> ticket_requests;
    is >> num_of_seats;
    is >> popularity;
}


void Train::SetNumber(int n) { train_number = n; }
void Train::SetTicketReq(int n) { ticket_requests = n; }
void Train::SetNumOfSeats(int n) { num_of_seats = n; }
void Train::SetDeparture(Date d, Time t) { departure_date = d; departure_time = t; }
void Train::SetArrival(Date d, Time t) { arrival_date = d; arrival_time = t; }
void Train::SetType(Type t) { type = t; }
void Train::SetName(std::string n) { name = n; }
