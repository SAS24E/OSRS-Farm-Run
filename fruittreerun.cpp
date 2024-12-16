//
// Created by Alex_ on 12/16/2024.
//

#include "fruittreerun.h"
#include <iostream>

fruittreerun::fruittreerun() : farmrun() {  // Initialize the base class
    farmruntype = "Fruit Tree";  // Set the specific farm run name
}

fruittreerun::~fruittreerun() {
    std::cout << "Fruit Tree Run Destructor\n";
}

void fruittreerun::run() {
    std::cout << "Starting Fruit Tree Run...\n";
    // Implement logic for fruit tree farm run
    // Example: track locations, mark locations as completed, etc.
    completedlocations.push_back("Tree Gnome Stronghold");
    std::cout << "Completed location: Tree Gnome Stronghold\n";
}
