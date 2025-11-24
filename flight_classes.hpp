// flight_classes.hpp
// ENSF 337 Fall 2025 Term Project, Group 8

#ifndef FLIGHT_CLASSES_H
#define FLIGHT_CLASSES_H

#include <vector>
#include <string>

class Seat {
private:
    int row_number;
    char seat_character;
public:
    // constructor
    Seat(int row = -1, char seat = '\0') : row_number(row), seat_character(seat) {}

    // getters
    int get_row_num() const { return row_number; }
    char get_seat_char() const { return seat_character; }

    // setters
    void set_row_num(int row) { row_number = row; }
    void set_seat_char(char seat) { seat_character = seat; }
};

// NOTE: Logic is not implemented to check whether the given phone number is valid/formatted properly.
// Will need to implement this logic in the main program before calling constructor/setter.
class Passenger {
private:
    string first_name;
    string last_name;
    string phone_number;
public:
    // constructor
    Passenger(string first = "", string last = "", string phone = "")
        : first_name(first), last_name(last), phone_number(phone) {}

    // getters
    string get_first_name() const { return first_name; }
    string get_last_name() const { return last_name; }
    string get_phone_number() const { return phone_number; }

    // setters
    void set_first_name(string first) { first_name = first; }
    void set_last_name(string last) { last_name = last; }
    void set_phone_number(string phone) { phone_number = phone; }
};

#endif