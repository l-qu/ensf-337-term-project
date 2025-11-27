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

// MAIN PROGRAM

int main(void) {
    vector<vector<string>> passenger_list = read_file("flight_data/passengers.txt", 6);
    vector<vector<string>> flight_list = read_file("flight_data/flights.txt", 5);

    if (passenger_list.size() == 0 || flight_list.size() == 0) {
        cout << "File(s) empty or not read properly. Terminating program." << endl;
        return 1;
    }

    displayHeader();

    int choice;
    bool quit = false;
    while(!quit){
        choice = menu();
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
                cout << "\nProgram terminated.\n";
                quit = true;
                break;
        }
    }

    return 0;
}