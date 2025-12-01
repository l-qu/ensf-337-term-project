#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <string>

using namespace std;

class Route {
    private: 
        string source;
        string destination;
    public: 
        string get_source()const{return source;}
        // promises: returns the source of the route
        string get_destination()const{return destination;}
        // promises: returns the destination of the route
        void set_source(string src){source = src;}
        // requires: valid string src
        // promises: sets the source of the route to src
        void set_destination(string dest){destination = dest;}
        // requires: valid string dest
        // promises: sets the destination of the route to dest
};

#endif