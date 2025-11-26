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
    cout << "1. Select a flight\n";
    cout << "2. Display Flight Seat Map.\n";
    cout << "3. Display Passengers Information.\n";
    cout << "4. Add a New Passenger.\n";
    cout << "5. Remove an Existing Passenger\n";
    cout << "6. Save data\n";
    cout << "7. Quit. \n";
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";
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