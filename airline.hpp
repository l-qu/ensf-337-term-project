#ifndef AIRLINE_H
#define AIRLINE_H

#include "flight.hpp"
#include <vector>
#include <string>

using namespace std;

class Airline {
    private: 
        string name;
        vector<Flight> flights;

    public:
        Airline(string newName);
        // requires: newName is the name of the airline
        // promises: assigns name and empty flight vector to object
        void add_flight(string id, string src, string dest, int rows, int cols);
        // requires: valid strings for id, src and dest, valid integers for rows and cols
        // promises: adds flight to flight vector containing provided information
        void remove_flight(string id);
        // requires: valid string id of a flight that exists
        // promises: removes flight with given id from flight vector
        string get_name()const{return name;}
        // promises: returns name of airline
        Flight* get_flight(string id);
        // requires: valid string id of a flight that exists
        // promises: returns flight with given id
        vector<Flight>& get_flights(){return flights;}
        // promises: returns airline's vector of flights
};

#endif