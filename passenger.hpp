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
    // can act as a default constructor
    Passenger(string id_num = "0", string first = "", string last = "", string phone = "", Seat * s = nullptr)
        : id(id_num), first_name(first), last_name(last), phone_number(phone), seat(s) {}
    // PROMISES: - initializes id, first_name, last_name, and phone_number to id_num, first, last, and phone (respectively)
    //           - assigns seat a pointer to a Seat in a matrix of Seats in a flight object

    // getters
    string get_id() const { return id; }
    // PROMISES: returns the id of the passenger
    string get_first_name() const { return first_name; }
    // PROMISES: returns first name of passenger
    string get_last_name() const { return last_name; }
    // PROMISES: returns last name of passenger
    string get_phone_number() const { return phone_number; }
    // PROMISES: returns phone number of passenger
    const Seat * get_seat() const { return seat; }
    // PROMISES: returns a pointer to the passenger's seat

    // setters
    void set_id(string id_num) { id = id_num; }
    // PROMISES: id_num is assigned to passenger id
    void set_first_name(string first) { first_name = first; }
    // PROMISES: passenger first_name is set to first
    void set_last_name(string last) { last_name = last; }
    // PROMISES: passenger last_name is set to last
    void set_phone_number(string phone) { phone_number = phone; }
    // PROMISES: phone_number is set to phone
    void set_seat(Seat * s) { seat = s; }
    // PROMISES: seat points the Seat that s is pointing to
};

#endif /*passenger.hpp*/