#ifndef FLIGHT__HPP
#define FLIGHT_HPP

#include "passenger.hpp"
#include "seat.hpp"
#include <vector>
#include <string>
using namespace std;

class Flight{

private:
    string id;
    int num_rows;
    int num_cols;
    vector<Passenger> passengers;
    vector<vector<Seat>> seat_map;

public:

    Flight(): id(""), num_rows(0), num_cols(0) {}
    Flight(string id, int r, int c);

    void add_passenger(int id, string fname, string lname, string phone);
    void remove_passenger(int id);
    int get_passenger(int id)const;
    string get_id()const;
    void show_seat_map()const;
    void set_set_status(int row, char col, char status);
    bool check_seat(int row, int col)const;
    void assign_seat(int row, char col, int passenger_id);
    vector<Passenger> get_passengers_list() const{return passengers;}
};

#endif /*flgiht.hpp*/