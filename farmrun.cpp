//
// farmrun.cpp
// Implementation of the Farmrun class
//

#include "farmrun.h"
#include <iostream>
#include <limits>

// Constructor: Initializes farm run locations to "unvisited" (false).
Farmrun::Farmrun() : totalFarmRuns(0), runCompleted(false) { // Initialize the counter
    locations = {
        {"Falador", false},
        {"Ardougne", false},
        {"Catherby", false},
        {"Hosidius", false},
        {"Troll Stronghold", false},
        {"Farming Guild", false},
        {"Canafis",  false}
    };
}
// Destructor: Clean-up if necessary (not used here).
Farmrun::~Farmrun() {}

// Displays the main menu and handles user input.
void Farmrun::menu() {
    int choice;
    do {
        std::cout << "\nFarm Run Tracker Menu:\n";
        std::cout << "1. Mark a location as visited\n";  // Loop for marking mode.
        std::cout << "2. Suggest the next location to visit\n";
        std::cout << "3. Reset all locations\n";
        std::cout << "4. View total farm runs completed\n"; // New menu option
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                while (true) {
                    // Suggest the next location
                    bool hasUnvisited = suggestLocation();
                    if (!hasUnvisited) {
                        celebrate();
                        break;
                    }

                    // Prompt user to select a location
                    int locationChoice;
                    std::cout << "Enter the number of the location to mark as visited: ";
                    std::cin >> locationChoice;

                    // Handle invalid input
                    if (std::cin.fail() || locationChoice <= 0 || locationChoice > locations.size()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid choice. Please enter a valid number.\n";
                        continue;
                    }

                    // Mark the selected location
                    markLocation(locationChoice);
                }
                break;
            }
            case 2:
                suggestLocation();
            break;
            case 3:
                resetFarmRun();
            break;
            case 4:
                viewTotalFarmRuns(); // New function call
            break;
            case 5:
                std::cout << "Exiting the Farm Run Tracker. Goodbye!\n";
            break;
            default:
                std::cout << "Invalid choice. Please select a number between 1 and 5.\n";
        }
    } while (choice != 5);
}



// Marks a specific location as visited using an integer index.
void Farmrun::markLocation(int locationIndex) {
    int currentIndex = 1; // Track numeric index
    for (auto& loc : locations) {
        if (currentIndex == locationIndex) {
            if (!loc.second) {
                loc.second = true;
                std::cout << loc.first << " has been marked as visited.\n";
            } else {
                std::cout << loc.first << " is already marked as visited.\n";
            }
            return;
        }
        currentIndex++;
    }
    std::cout << "Error: Invalid location number.\n";
}

// Suggests the next unvisited location.
bool Farmrun::suggestLocation() {
    std::cout << "\nUnvisited Locations:\n";
    bool found = false;
    int index = 1; // Numbered list index
    for (const auto& loc : locations) {
        if (!loc.second) {
            std::cout << index << "- " << loc.first << '\n';
            found = true;
        }
        index++;
    }
    if (!found) {
        std::cout << "All locations have been visited!\n";
    }
    return found; // returns found so if we find it in the loop we keep going.
}

// Celebrates when all locations have been visited.
void Farmrun::celebrate() {
    bool allVisited = true;
    for (const auto& loc : locations) {
        if (!loc.second) {
            allVisited = false;
            break;
        }
    }
    if (allVisited && !runCompleted) { // Only count once if all visited and not yet completed
        totalFarmRuns++; // Increment the total farm runs counter
        runCompleted = true; // Mark this run as completed
        std::cout << "######################################################";
        std::cout << "\nCongratulations! You've completed your farm run!\n";
        std::cout << "######################################################\n";
    } else if (!allVisited) {
        std::cout << "\nNot all locations have been visited yet. Keep going!\n";
    } else {
        std::cout << "\nFarm run already counted. Please reset locations to count again.\n";
    }
}

// Resets all locations to unvisited.
void Farmrun::resetFarmRun() {
    for (auto& loc : locations) {
        loc.second = false;
    }
    runCompleted = false; // allow the next run to be counted
    std::cout << "\nAll locations have been reset to unvisited.\n";
}

// Displays the total number of farm runs completed.
void Farmrun::viewTotalFarmRuns() {
    std::cout << "\nTotal farm runs completed: " << totalFarmRuns << "\n";
}