#include "airline.hpp"
#include "flight.hpp"
#include "passenger.hpp"
#include "route.hpp"
#include "seat.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// FUNCTION DEFINITIONS BELOW

void cleanStandardInputStream(void) {
    int leftover;
    do {
    leftover = cin.get();
    } while (leftover !='\n' && leftover != EOF);
}

void pressEnter() {
    cout << "\n<<< Press Return to Continue>>>>\n";
    cin.get();
}

void displayHeader() {
    cout << "\nFMAS Version: 1.0";
    cout << "\nTerm Project - Flight Management Application System";
    cout << "\nProduced by Group #: 8";
    cout << "\nNames: Chloe Khoo, Gianna Kong, Lindsey Quong\n";
    pressEnter();
}

int menu() {
    cout << "Please select one the following options:\n\n";
    cout << "1. Select a flight\n";
    cout << "2. Display Flight Seat Map.\n";
    cout << "3. Display Passengers Information.\n";
    cout << "4. Add a New Passenger.\n";
    cout << "5. Remove an Existing Passenger\n";
    cout << "6. Save data\n";
    cout << "7. Quit. \n";
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";
    int choice = -1;
    while (1) {
        cin >> choice;
        cleanStandardInputStream();
        if(!(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7)) {
            cout << "\nInvalid selection. Please try again.\n";
            cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";
        } else {
            break;
        }
    }
    return choice;
}

vector<vector<string>> read_file(string filepath, int row_size) {
    vector<vector<string>> file_contents;
    string line;

    ifstream newfile(filepath);
    
    if(newfile.fail()){
        cout << "Error opening file: " << filepath << endl;
        return file_contents;
    }
    
    // Filling out list with file contents
    while(getline(newfile, line)){
        vector<string> row;
        string current = "";

        for(int i = 0; i < (int) line.size(); i++){
            // getting non-whitespace characters
            if(line[i] != ' ' && line[i] != '\t'){
                current += line[i];
            } else{
                // push the finished string into vector
                if(current.size() > 0){
                    row.push_back(current);
                    current = "";
                }
            }
        }
        // last string push
        if(current.size() > 0){
            row.push_back(current);
        }

        // pushing into main vector
        if((int) row.size() == row_size){
            file_contents.push_back(row);
        }
   }

   newfile.close();

   return file_contents;
}

void populate_flights(vector<Flight> & flights, vector<vector<string>> & passenger_list) {
    // populate each flight with the correct passengers
    for (int i = 0; i < (int) passenger_list.size(); i++) {
        for (int j = 0; j < (int) flights.size(); j++) {
            if (passenger_list.at(i).at(0) == flights.at(j).get_id()) {
                vector<string> row = passenger_list.at(i);
                flights.at(j).add_passenger(row.at(5), row.at(1), row.at(2), row.at(3));
                
                // split seat string into a row number and seat character
                string seat_str = row.at(4);
                char seat_char = seat_str.back();
                seat_str.pop_back();
                int seat_row = stoi(seat_str);

                flights.at(j).assign_seat(seat_row, seat_char, row.at(5));

                break;
            }
        }
    }
}

Flight menu_1(vector<Flight> * ptr, vector<vector<string>> flight_list){
    cout << "\nPlease select one of the following flights...\n";
    
    for (int i = 0; i < (int) flight_list.size(); i++){
        cout << "\t" << i + 1 << ". ";
        for (int j = 0; j < (int) flight_list[i].size(); j++){
            cout << flight_list[i][j] << " ";
        }
        cout << endl;
    }

    int selection = -1;
    while(1){
        cout << "\nEnter your choice: ";
        cin >> selection;
        cleanStandardInputStream();
        if(selection > (int) flight_list.size() || selection == 0){
            cout << "\nInvalid selection. Please try again.\n";
            continue;
        }

        Flight f = (*ptr)[selection - 1];

        cout << "\nYou have chosen flight " << f.get_id() << " from " << flight_list.at(selection - 1).at(1) 
             << " to " << flight_list.at(selection - 1).at(2) << ".\n";
        return f;
    }
}

// MAIN PROGRAM

int main(void) {
    vector<vector<string>> passenger_list = read_file("flight_data/passengers.txt", 6);
    vector<vector<string>> flight_list = read_file("flight_data/flights.txt", 5);

    if (passenger_list.size() == 0 || flight_list.size() == 0) {
        cout << "File(s) empty or not read properly. Terminating program." << endl;
        return 1;
    }

    Airline currentAirline("WestJet");
    // vector<Flight> flights;

    // create flight objects from info read in from file
    for (int i = 0; i < (int) flight_list.size(); i++) {
        Flight new_flight(flight_list.at(i).at(0), stoi(flight_list.at(i).at(3)), stoi(flight_list.at(i).at(4)));
        currentAirline.add_flight(new_flight.get_id(), new_flight.get_rows(), new_flight.get_cols());
    }
    
    // must populate flights with currentAirline.flights
    populate_flights(currentAirline.get_flights(), passenger_list);

    vector<Flight>* flight_point = &currentAirline.get_flights();
    Flight flight_choice;

    displayHeader();

    int choice;
    bool quit = false;
    while(!quit){
        choice = menu();

        // check that the user has chosen a flight
        if (choice != 1 && choice != 7 && flight_choice.get_id() == "") {
            cout << "\nNo flight has been selected. Please choose a flight first.\n";
            pressEnter();
            continue;
        }

        switch(choice){
            case 1: {
                flight_choice = menu_1(flight_point, flight_list);
                pressEnter();
                break;
            }
            case 2: {
                cout << "\nAircraft Seat Map for Flight " << flight_choice.get_id() << "\n\n";
                flight_choice.show_seat_map();
                pressEnter();
                break;
            }
            case 3: {
                cout << "\nImplement Option 3 here\n";
                break;
            }
            case 4: {
                cout << "\nImplement Option 4 here\n";
                break;
            }
            case 5: {
                cout << "\nImplement Option 5 here\n";
                break;
            }
            case 6: {
                cout << "\nImplement Option 6 here\n";
                break;
            }
            case 7: {
                cout << "\nProgram terminated.\n";
                quit = true;
                break;
            }
        }
    }

    return 0;
}