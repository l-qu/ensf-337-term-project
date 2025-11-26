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
        void add_flight(string id, int rows, int cols);
        void remove_flight(string id);
        string get_name()const{return name;}
        Flight get_flight(string id)const;
        vector<Flight>& get_flights(){return flights;}
};

#endif