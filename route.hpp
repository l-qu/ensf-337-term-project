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
        string get_destination()const{return destination;}
        void set_source(string src){source = src;}
        void set_destination(string dest){destination = dest;}
};

#endif