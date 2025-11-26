// flight_classes.hpp
// ENSF 337 Fall 2025 Term Project, Group 8

#ifndef FLIGHT_CLASSES_H
#define FLIGHT_CLASSES_H

#include <vector>
#include <string>
using namespace std;

class Seat {
private:
    int row;
    char seat;
    char status;
public:
    // constructor
    Seat(int r = -1, char s = '\0', char stat = ' ') 
        : row(r), seat(s), status(stat) {}

    // getters
    int get_row_num() const { return row; }
    char get_seat_char() const { return seat; }
    char get_status() const { return status; }

    // setters
    void set_row_num(int r) { row = r; }
    void set_seat_char(char s) { seat = s; }
    void set_status(char stat) { status = stat; }
};

// NOTE: Logic is not implemented to check whether the given phone number is valid/formatted properly.
// Will need to implement this logic in the main program before calling constructor/setter.
class Passenger {
private:
    int id;
    string first_name;
    string last_name;
    string phone_number;
    Seat * seat;
public:
    // constructor
    Passenger(int id_num = 0, string first = "", string last = "", string phone = "", Seat * s = nullptr)
        : id(id_num), first_name(first), last_name(last), phone_number(phone), seat(s) {}

    // getters
    int get_id() const { return id; }
    string get_first_name() const { return first_name; }
    string get_last_name() const { return last_name; }
    string get_phone_number() const { return phone_number; }
    const Seat * get_seat() const { return seat; }

    // setters
    void set_id(int id_num) { id = id_num; }
    void set_first_name(string first) { first_name = first; }
    void set_last_name(string last) { last_name = last; }
    void set_phone_number(string phone) { phone_number = phone; }
    void set_seat(Seat * s) { seat = s; }
};

class Airline {
    private: 
        string name;
        vector<Flight> flights;

    public:
        Airline(string name);
        void add_flight(string id, int rows, int cols);
        void remove_flight(string id);
        string get_name()const{return name;}
        int get_flight(string id)const;
        vector<Flight>& get_flights(){return flights;}
};

class Route {
    private: 
        string source;
        string destination;
    public: 
        string get_source()const{return source;}
        string get_destination()const{return destination;}
        void set_source(string src){source = src;}
        void set_destination(string dest){destination = dest;}
}

#endif /* flight_classes.hpp */