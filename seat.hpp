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
    // promises: sets row number to r, seat number to s, status to stat

    // getters
    int get_row_num() const { return row; }
    // promises: returns row number of seat
    char get_seat_char() const { return seat; }
    // promises: returns seat number of seat
    char get_status() const { return status; }
    // promises: returns status of seat

    // setters
    void set_row_num(int r) { row = r; }
    // requires: valid integer r 
    // promises: sets row number of seat to r
    void set_seat_char(char s) { seat = s; }
    // requires: valid char s
    // promises: sets seat number of seat to s
    void set_status(char stat) { status = stat; }
    // requires: valid char stat
    // promises: sets seat status to stat
};

#endif /*seat.hpp*/