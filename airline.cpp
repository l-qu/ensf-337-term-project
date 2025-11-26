#include "airline.hpp"
#include "flight.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Airline::Airline(string newName):name(newName){
    vector<Flight> flightList;
    flights = flightList;
}

void Airline::add_flight(string id, int rows, int cols) {
    Flight newFlight(id, rows, cols);
    flights.push_back(newFlight);
    return;
}

void Airline::remove_flight(string id) {
    for(size_t i = 0; i < flights.size(); i++) {
        if(flights.at(i).get_id() == id) {
            flights.erase(flights.begin() + i);
            break;
        }
    }
    return;
}

Flight Airline::get_flight(string id)const{
    for(size_t i = 0; i < flights.size(); i++) {
        if(flights.at(i).get_id() == id) {
            return flights.at(i);
        }
    }
    Flight emptyFlight;
    return emptyFlight;
}