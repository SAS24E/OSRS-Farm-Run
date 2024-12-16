//
// farmrun.h
// Header file for the Farmrun class
//


#ifndef FARMRUN_H
#define FARMRUN_H
#include <iostream>
#include <string>
#include <map>
#include <vector>


class farmrun {
    public:
    farmrun(); // Constructor
    virtual ~farmrun(); // Destructor

    virtual void run()=0; //pure virtual function for specific farm run logic

    void menu(); // Menu

    bool getvalidnumber(int&); //validates numbers input


protected:
    std::string farmruntype;
    int choice;
    std::vector<std::string> completedlocations;

    bool runcompleted; // used to determine if the user's run is over.


};
#endif