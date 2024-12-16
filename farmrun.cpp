

#include "farmrun.h"
#include <iostream>
#include <iomanip>
#include <limits>




farmrun::farmrun() {
    // constructor will initalize the options then we can in theory select the particular farm run ex.
    // Fruit tree run and herb run and tree run.
    std:: cout << "Farmrun constructor called! Choose your farm run. \n";


} // Constructor

farmrun::~farmrun() {
    std::cout << "Farmrun Destructor called. Goodbye! \n";

}
// Destructor

bool visited() {
    // Example: In the future, implement logic to mark locations.
    return true;
}
// marks a location off

void farmrun::menu() {
    std::cout << "##################### \n";
    std::cout << "*      Farm Run     * \n";
    std::cout << "##################### \n";
    int choice = 0;

    do{
        std::cout << "Select an option:\n";
        std::cout << "1. Start fruit tree run.\n";
        std::cout << "2. start herb run.\n";
        std::cout << "3. Start Tree run. \n";
        std::cout << "4. Exit.\n";
        std::cin >> choice;
        getvalidnumber(choice);
        switch (choice) {
            case 1:
                farmrun();
            break;
            case 2:
                //Fruit tree run;
                break;
            case 3:
                //herb run
                break;
            case 4:
                //tree run
                std::cout << "Exit.\n";
                break;
            default:
                std::cout << "Invalid Option.Try again\n";

            break;
        }
    }while (choice != 2);
}


// #####################################
// Makes sure user is selecting a number
// #####################################
bool farmrun::getvalidnumber(int& x) {
    std::cin >> x;
    while (true) {
        std::cin >> x;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'n'); // discard invalid input
            std::cout << "Invalid Input. Try again.\n";
        } else {
            return true;
        }
    }
}

