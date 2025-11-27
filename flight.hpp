#ifndef FLIGHT_HPP
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

    Flight(string id_num = "", int r = 25, int c = 6);

    void add_passenger(string id, string fname, string lname, string phone);
    void remove_passenger(string id);
    Passenger* get_passenger(string id);
    string get_id()const { return id; }
    void show_seat_map()const;
    void set_seat_status(int row, char col, char status);
    bool check_seat(int row, int col)const;
    void assign_seat(int row, char col, string passenger_id);
    vector<Passenger> get_passengers_list() const{return passengers;}
};

#endif /*flgiht.hpp*/