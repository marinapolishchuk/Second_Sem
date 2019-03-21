//
//  Train.hpp
//  DB Trains
//
//  Created by Marina Polishchuk on 3/9/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Train_hpp
#define Train_hpp

#include <string>
#include <iostream>

struct Date {
    int day;
    int month;
    int year;
};

struct Time {
    int hours;
    int minutes;
};

enum class Type {INTERNATIONAL, FAST, ORDINARY, SUBURBAN};

class Train {
private:
    static short count;
    int id;
    short train_number;
    std::string name;
    Type type;
    Date arrival_date;
    Time arrival_time;
    Date departure_date;
    Time departure_time;
    
    int ticket_requests;
    int num_of_seats;
    double popularity;
public:
    
    Train() {
        count++;
        id = count;
    };
    
    ~Train() = default;
        
    void SetNumber(int);
    void SetName(std::string);
    void SetType(Type);
    void SetArrival(Date, Time);
    void SetDeparture(Date, Time);
    void SetTicketReq(int);
    void SetNumOfSeats(int);
    void SetPopularity() {
        popularity = (double)ticket_requests/num_of_seats;
    }
    
    short GetNumber() { return train_number; }
    std::string GetName() { return name; }
    Type GetType() { return type; }
    Date GetArrDate() { return arrival_date; }
    Time GetArrTime() { return arrival_time; }
    Date GetDepDate() { return departure_date; }
    Time GetDepTime() { return departure_time; }
    int GetTicketReq() { return ticket_requests; }
    int GetNumOfSeats() { return num_of_seats; }
    double GetPopularity() { return popularity; }
    int GetID() { return id; }
    
    std::string Serialize();
    void Unserialize(std::string);
    
    void PrintTrain() {
        std::cout << "\nTrain's name: " << name
        << "\nID: " << id << " Number: " << train_number
        << "\nType (International/Fast/Ordinary/Suburban) (0/1/2/3): " << static_cast<int>(type)
        << "\nArrival date and time: " << arrival_date.day << '.' << arrival_date.month << '.' << arrival_date.year << ' ' << arrival_time.hours << ':' << arrival_time.minutes
        << "\nDeparture date and time: " << departure_date.day << '.' << departure_date.month << '.' << departure_date.year << ' ' << departure_time.hours << ':' << departure_time.minutes
        << "\nTrain popularity: " << popularity << std::endl;
    }
};


#endif /* Train_hpp */
