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

    Flight(string id_num = "", int r = 0, int c = 0);

    void add_passenger(string id_num, string fname, string lname, string phone);
    void remove_passenger(string id_num);
    Passenger* get_passenger(string id_num);
    string get_id()const { return id; }
    int get_rows()const {return num_rows;}
    int get_cols()const {return num_cols;}
    void show_seat_map()const;
    void set_seat_status(int row, char col, char status);
    bool check_seat(int row, int col)const;
    void assign_seat(int row, char col, string passenger_id);
    vector<Passenger> get_passengers_list() const{return passengers;}
};

#endif /*flgiht.hpp*/