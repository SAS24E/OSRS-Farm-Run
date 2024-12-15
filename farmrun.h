//
// farmrun.h
// Header file for the Farmrun class
//

#ifndef FARMRUN_H
#define FARMRUN_H

#include <map>
#include <string>

// A class to track farm run progress in Old School RuneScape
class Farmrun {
public:
    // Constructor: Initializes the farm run locations.
    Farmrun();

    // Destructor: Cleans up resources (if needed).
    ~Farmrun();

    // Displays the main menu and handles user input.
    void menu();
/*
    // Marks a location as visited.
    void markLocation(const std::string& location);
*/
   // int locationIndex
    void markLocation(int locationIndex);

    // Suggests the next unvisited location to visit.
    bool suggestLocation();

    // Celebrates the completion of a farm run.
    void celebrate();

    // Resets all locations to unvisited.
    void resetFarmRun();
    //View Total Farm runs function
    void viewTotalFarmRuns();

private:
    // A map to track locations and whether they have been visited.
    std::map<std::string, bool> locations;
    int totalFarmRuns = 0;
    bool runCompleted;
};

#endif // FARMRUN_H
