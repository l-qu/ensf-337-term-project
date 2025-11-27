#include "airline.hpp"
#include "airline.cpp"
#include "flight.hpp"
#include "flight.cpp"
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
    cout << "\nFlight Management Application - Fall 2025\n";
    cout << "\nVersion: 1.0 ";
    cout << "\nTerm Project";
    cout << "\nProduced by: Chloe Khoo, Gianna Kong, Lindsey Quong (Group 8)\n\n";
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
            cout << "Invalid selection. Please try again.";
            cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";
        } else {
            break;
        }
    }
    return choice;
}

// MAIN PROGRAM

int main(void) {
    ifstream passfile("passengers.txt");
    ifstream flightfile("flights.txt");
    
    if(passfile.fail()){
        cout << "Error opening passenger file" << endl;
        return 1;
    }
    if(flightfile.fail()){
        cout << "Error opening flights file" << endl;
        return 1;
    }

   vector<vector<string>> passenger_list;
   vector<vector<string>> flight_list;
   string line;

    // Filling out passenger list
   while(getline(passfile, line)){
        vector<string> row;
        string current = "";

        for(int i = 0; i < line.size(); i++){
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
        if(row.size() == 6){
            passenger_list.push_back(row);
        }
   }

   // Filling out flight list
   while(getline(flightfile, line)){
        vector<string> row;
        string current = "";

        for(int i = 0; i < line.size(); i++){
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

        // pushing into main vector if at the end of row
        if(row.size() == 5){
            flight_list.push_back(row);
        }
   }
    passfile.close();
    flightfile.close();

    displayHeader();

    int choice;
    while((choice = menu())){
        switch(choice){
            case 1:
                cout << "\nImplement Option 1 here\n";
                break;
            case 2:
                cout << "\nImplement Option 2 here\n";
                break;
            case 3:
                cout << "\nImplement Option 3 here\n";
                break;
            case 4:
                cout << "\nImplement Option 4 here\n";
                break;
            case 5:
                cout << "\nImplement Option 5 here\n";
                break;
            case 6:
                cout << "\nImplement Option 6 here\n";
                break;
            case 7:
                cout << "\nImplement Option 7 here\n";
                break;
        }
    }

    return 0;
}