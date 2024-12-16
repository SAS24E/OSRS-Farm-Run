//
// Created by Alex_ on 12/16/2024.
//

#ifndef FRUITTREERUN_H
#define FRUITTREERUN_H

#include "farmrun.h"

class fruittreerun : public farmrun {
    public:
    fruittreerun(); // Constructor
    ~fruittreerun(); // Destructor
    void run() override; // override the virtual function to implement logic

};



#endif //FRUITTREERUN_H
