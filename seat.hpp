#ifndef SEAT_HPP
#define SEAT_HPP

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

#endif /*seat.hpp*/