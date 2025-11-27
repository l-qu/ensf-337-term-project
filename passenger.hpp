#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "seat.hpp"
#include <vector>
#include <string>
// NOTE: Logic is not implemented to check whether the given phone number is valid/formatted properly.
// Will need to implement this logic in the main program before calling constructor/setter.
class Passenger {
private:
    string id;
    string first_name;
    string last_name;
    string phone_number;
    Seat * seat;
public:
    // constructor
    Passenger(string id_num = "0", string first = "", string last = "", string phone = "", Seat * s = nullptr)
        : id(id_num), first_name(first), last_name(last), phone_number(phone), seat(s) {}

    // getters
    string get_id() const { return id; }
    string get_first_name() const { return first_name; }
    string get_last_name() const { return last_name; }
    string get_phone_number() const { return phone_number; }
    const Seat * get_seat() const { return seat; }

    // setters
    void set_id(string id_num) { id = id_num; }
    void set_first_name(string first) { first_name = first; }
    void set_last_name(string last) { last_name = last; }
    void set_phone_number(string phone) { phone_number = phone; }
    void set_seat(Seat * s) { seat = s; }
};

#endif /*passenger.hpp*/