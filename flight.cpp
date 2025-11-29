// flight.cpp

#include "seat.hpp"
#include "passenger.hpp"
#include "flight.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Flight::Flight(string id_num, int r, int c): id(id_num), num_rows(r), num_cols(c) {
    seat_map.resize(num_rows);

    for (int i = 0; i < num_rows; i++) {
        seat_map.at(i).resize(num_cols);
        for (int j = 0; j < num_cols; j++) {
            seat_map.at(i).at(j).set_row_num(i);
            seat_map.at(i).at(j).set_seat_char('A' + j);
        }
    }
}

Passenger* Flight::get_passenger(string id_num) {
    for (int i = 0; i < (int) passengers.size(); i++) {
        if (passengers.at(i).get_id() == id_num) {
            return &(passengers.at(i));
        }
    }

    cout << "Passenger not in the list.\n";
    return nullptr;
}

void Flight::add_passenger(string id_num, string fname, string lname, string phone) {
    Passenger new_passenger(id_num, fname, lname, phone);
    passengers.push_back(new_passenger);
}

void Flight::remove_passenger(string id_num) {
    for (int i = 0; i < (int) passengers.size(); i++) {
        if (passengers.at(i).get_id() == id_num) {
            set_seat_status(passengers.at(i).get_seat()->get_row_num(), passengers.at(i).get_seat()->get_seat_char(), ' ');
            
            cout << "\nPassenger " << passengers.at(i).get_first_name() << " " << passengers.at(i).get_last_name()
                 << " was successfully removed from flight " << id << ".\n";
            passengers.erase(passengers.begin() + i);
            return;
        }
    }

    cout << "\nPassenger was not found in the list.\n";
}

void Flight::set_seat_status(int row, char col, char status) {
    // Assume seat status has already been appropriately checked
    
    seat_map.at(row).at(col - 'A').set_status(status);
}

bool Flight::check_seat(int row, int col) const {
    // Returns true if the seat is not occupied
    
    if (seat_map.at(row).at(col - 'A').get_status() == ' ') {
        return true;
    } else {
        return false;
    }
}

void Flight::assign_seat(int row, char col, string passenger_id) {
    Passenger* new_passenger = get_passenger(passenger_id);
    // Might or might not need the following error handling depending on how we write the main program
    if (new_passenger == nullptr) {
        cout << "Passenger not in list.\n";
        return;
    }

    set_seat_status(row, col, 'X');
    new_passenger->set_seat(&seat_map.at(row).at(col - 'A'));
}

void Flight::show_seat_map() const {
    // print out headers for columns
    cout << "\t  " << 'A';
    for (int i = 1; i < num_cols; i++) {
        cout << "   " << (char) ('A' + i);
    }
    cout << endl;

    // print out rest of map
    int row = 0;
    for (int i = 0; i < 2 * num_rows + 1; i++) {
        if (i % 2 == 0) {
            // divider row
            cout << "\t+";
            for (int j = 0; j < num_cols; j++) {
                cout << "---+";
            }
        } else {
            // row containing actual seats
            cout << row << "\t|";
            for (int j = 0; j < num_cols; j++) {
                cout << " " << seat_map.at(row).at(j).get_status() << " |";
            }
            row++;
        }
        cout << endl;
    }
}