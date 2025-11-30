#include "airline.hpp"
#include "flight.hpp"
#include "passenger.hpp"
#include "route.hpp"
#include "seat.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
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
            if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r'){
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

void save_data(string filepath, int row_size, vector<vector<string>> to_save){
    string yes_no; 
    bool selection = true;
    while(selection){
        cout << "\nDo you want to save the data into 'passengers.txt'? "
            << "(Please answer <Y or N>) ";
        cin >> yes_no;
        cleanStandardInputStream();

        if(yes_no == "Y" || yes_no == "y"){
            ofstream overwrite(filepath);
            string holder;
            
            if(overwrite.fail()){
                cout << "Error opening file: " << filepath << endl;
                return;
            }
            
            for (int i = 0; i < (int) to_save.size(); i++){
                for (int j = 0; j < (int) to_save[i].size(); j++){
                    if((j + 1) == (int) to_save[i].size()){
                        holder += to_save[i][j];
                        break;
                    }
                    holder += to_save[i][j];
                    holder += "\t";
                }
                holder += "\n";
                overwrite << holder;
                holder = "";
            }
            overwrite.close();  
            cout << "All data in the passenger list were saved.\n" << endl;
            return;

        }else if (yes_no == "N" || yes_no == "n"){
            cout<< "\n All data in passenger list were not saved."<< endl;
            return;
        }else{
            cout<< "\n Invalid input, please try again." << endl;
            continue;
        }
    }  
}

void remove_from_list(vector<vector<string>> & passengers, string ID){
    for (int i = 0; i < (int)passengers.size(); i++){
        if (stoi(passengers.at(i).back()) == stoi(ID)){
            passengers.erase(passengers.begin() + i);
            return;
        }
    }
}

void add_to_list(Flight * flight, vector<vector<string>> & passengers, string id_num, string fname, string lname, string phone, int row, char seat){
    vector<string> newPassenger; 
    newPassenger.push_back((*flight).get_id());
    newPassenger.push_back(fname);
    newPassenger.push_back(lname);
    newPassenger.push_back(phone);
    newPassenger.push_back(to_string(row) + seat);
    newPassenger.push_back(id_num);

    passengers.push_back(newPassenger);
    
    return;
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

Flight* flight_selection(vector<Flight> * ptr, vector<vector<string>> flight_list){
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

        cout << "\nYou have chosen flight " << (*ptr)[selection - 1].get_id() << " from " << flight_list.at(selection - 1).at(1) 
             << " to " << flight_list.at(selection - 1).at(2) << ".\n";
        return &(*ptr)[selection - 1];
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

    // create flight objects from info read in from file
    for (int i = 0; i < (int) flight_list.size(); i++) {
        Flight new_flight(flight_list.at(i).at(0), flight_list.at(i).at(1), flight_list.at(i).at(2), stoi(flight_list.at(i).at(3)), stoi(flight_list.at(i).at(4)));
        currentAirline.add_flight(new_flight.get_id(), new_flight.get_flight_src(), new_flight.get_flight_dest(), new_flight.get_rows(), new_flight.get_cols());
    }
    
    populate_flights(currentAirline.get_flights(), passenger_list);

    vector<Flight>* flight_point = &currentAirline.get_flights();
    Flight * flight_choice = nullptr;

    displayHeader();

    int choice;
    bool quit = false;
    while(!quit){
        choice = menu();

        // check that the user has chosen a flight
        if (choice != 1 && choice != 7 && flight_choice == nullptr) {
            cout << "\nNo flight has been selected. Please choose a flight first.\n";
            pressEnter();
            continue;
        }

        switch(choice){
            case 1: {
                flight_choice = flight_selection(flight_point, flight_list);
                pressEnter();
                break;
            }
            case 2: {
                cout << "\nAircraft Seat Map for Flight " << (*flight_choice).get_id() << "\n\n";
                (*flight_choice).show_seat_map();
                pressEnter();
                break;
            }
            case 3: {
                (*flight_choice).show_passengers();
                pressEnter();
                break;
            }
            case 4: {
                string id, fname, lname, phone;
                int row;
                char seat;
                cout << "Please enter the passenger id: ";
                cin >> id;
                cleanStandardInputStream();
                vector<string> id_list;
                for(size_t i = 0; i < (*flight_choice).get_passengers_list().size(); i++) {
                    id_list.push_back((*flight_choice).get_passengers_list().at(i).get_id());
                }
                while(1) {
                    if(count(id_list.begin(), id_list.end(), id) == 1) {
                        cout << "A passenger with that ID is already on this flight. Please enter another." << endl;
                        cout << "Please enter the passenger id: ";
                        cin >> id;
                        cleanStandardInputStream();
                    } else {
                        break;
                    }
                }
                cout << "Please enter the passenger first name: ";
                cin >> fname;
                cleanStandardInputStream();
                cout << "Please enter the passenger last name: ";
                cin >> lname;
                cleanStandardInputStream();
                cout << "Please enter the passenger phone number: ";
                cin >> phone;
                cleanStandardInputStream();
                cout << "\nEnter the passenger's desired row: ";
                cin >> row;
                cleanStandardInputStream();
                while(1) {
                    if(row < 0 || row > (*flight_choice).get_rows()) {
                        cout << "That row does not exist. Please select another row." << endl;
                        cout << "\nEnter the passenger's desired row: ";
                        cin >> row;
                        cleanStandardInputStream();
                    } else {
                        break;
                    }
                }
                cout << "Enter the passenger's desired seat: ";
                cin >> seat;
                cleanStandardInputStream();
                seat = toupper(seat);
                while(1) {
                    if(seat < 'A' || seat >= 'A' + (*flight_choice).get_cols()) {
                        cout << "That seat does not exist. Please select another seat." << endl;
                        cout << "Enter the passenger's desired seat: ";
                        cin >> seat;
                        cleanStandardInputStream();
                        seat = toupper(seat);
                    } else {
                        break;
                    }
                }
                while(1) {
                    if((*flight_choice).check_seat(row, seat)) {
                        break;
                    } else {
                        cout << "\nThat seat is occupied. Please select another.";
                        cout << "\n\nEnter the passenger's desired row: ";
                        cin >> row;
                        cleanStandardInputStream();
                        cout << "Enter the passenger's desired seat: ";
                        cin >> seat;
                        cleanStandardInputStream();
                    }
                }
                (*flight_choice).add_passenger(id, fname, lname, phone);
                (*flight_choice).assign_seat(row, seat, id);
                add_to_list(flight_choice, passenger_list, id, fname, lname, phone, row, seat);
                pressEnter();
                break;
            }
            case 5: {
                string id;
                cout << "\nPlease enter the ID of the passenger that needs to be removed: ";
                cin >> id;
                cleanStandardInputStream();

                (*flight_choice).remove_passenger(id);
                remove_from_list(passenger_list, id);
                pressEnter();
                break;
            }
            case 6: {
                save_data("flight_data/passengers.txt", 6, passenger_list);
                pressEnter();
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