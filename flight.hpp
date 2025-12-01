#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include "passenger.hpp"
#include "seat.hpp"
#include "route.hpp"
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
    Route flight_route;

public:

    Flight(string id_num = "", string src = "", string dest = "", int r = 0, int c = 0);
        // PROMISES: The creation of a flight containting an ID, source, destination, row, and columns.
        // REQUIRES: A valid id_src, dest, row, and column

    void add_passenger(string id_num, string fname, string lname, string phone);
        // PROMISES: The addition of one passenger to the passengers on the flight chosen
        // REQUIRES: A valid passenger ID, first name, last name, and phone number 

    void remove_passenger(string id_num);
        // PROMISES: The removal of one passenger from the passenger list of the flight
        // REQUIRES: A valid passenger ID

    Passenger* get_passenger(string id_num);
        // PROMISES: A pointer that points to a specified passenger in the flight
        // REQUIRES: A valid passenger ID

    string get_id()const { return id; }
        // PROMISES: The ID of a passenger

    int get_rows()const {return num_rows;}
        // PROMISES: The number of seat rows in the flight

    int get_cols()const {return num_cols;}
        // PROMISES: The number of seat columns in the flight

    void show_seat_map()const;
        // PROMISES: The printing of a seat map of the flight with seats either filled (in x) or empty (empty box)

    void set_seat_status(int row, char col, char status);
        // PROMISES: Sets the status of a sear to empty or filled
        // REQUIRES: Valid row, column, and either a space or 'x' for status

    bool check_seat(int row, int col)const;
        // PROMISES: A true or false if the seat is occupied
        // REQUIRES: A valid row and column of the flight

    void assign_seat(int row, char col, string passenger_id);
        // PROMISES: The assignment of a seat to an inputted passenger ID
        // REQUIRES: Valid row, column, and an existing passenger_ID
        
    vector<Passenger> get_passengers_list() const{return passengers;}
        // PROMISES: Retrieving the passenger list of the flight

    void show_passengers()const;
        // PROMISES: Displaying the passengers of the flight

    string get_flight_src()const {return flight_route.get_source();}
        // PROMISES: A string of where the flight is departing 
        
    string get_flight_dest()const {return flight_route.get_destination();}
        // PROMISES: A string of where the flight is going
};

#endif /*flight.hpp*/
