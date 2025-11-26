#include "flight_classes.hpp"
#include <iostream>
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
    cout << "\nFlight Mangement Application - Fall 2025\n";
    cout << "\nVersion: 1.0 ";
    cout << "\nTerm Project";
    cout << "\nProduced by: Chloe Khoo, Gianna Kong, Lindsey Quong (Group 8)\n\n";
    pressEnter();
}

int menu() {
    int choice = -1;
    cout << "Please select one the following options:\n\n";
    cout << "1. Display Flight Seat Map.\n";
    cout << "2. Display Passengers Information.\n";
    cout << "3. Add a New Passenger.\n";
    cout << "4. Remove an Existing Passenger\n";
    cout << "5. Save data\n";
    cout << "6. Quit. \n";
    cout << "\nEnter your choice: (1, 2, 3, 4, or 5) ";
    cin >> choice;
    cleanStandardInputStream();
    return choice;
}

// MAIN PROGRAM

int main(void) {

    displayHeader();

    int choice;
    while((choice = menu())){
        switch(choice){
            case 1:
                cout << "Implement Option 1 here\n";
                break;
            case 2:
                cout << "Implement Option 2 here\n";
                break;
            case 3:
                cout << "Implement Option 3 here\n";
                break;
            case 4:
                cout << "Implement Option 4 here\n";
                break;
            case 5:
                cout << "Implement Option 5 here\n";
                break;
            case 6:
                cout << "Implement Option 6 here\n";
                break;
        }
    }

    return 0;
}