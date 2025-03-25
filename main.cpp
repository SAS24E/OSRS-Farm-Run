
#include <iostream>
#include <memory>
#include <vector>
#include "farmrun.h"

int main() {
    std::vector<std::unique_ptr<RunType>> runs;
    runs.push_back(std::make_unique<HerbRun>());
    runs.push_back(std::make_unique<TreeRun>());
    runs.push_back(std::make_unique<FruitTreeRun>());

    std::cout << "Welcome to Farm Run Tracker!\n";
    std::cout << "Please choose a run type:\n";
    std::cout << "0. Exit\n";

    for (size_t i = 0; i < runs.size(); ++i) {
        std::cout << i + 1 << ". " << runs[i]->getName() << std::endl;
    }

    int choice;
    while(choice != 0) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(runs.size())) {
            runs[choice - 1]->performRun();
        } else(choice == 0); {
            std::cout << "Goodbye.\n";
        }
    }
    std::cout <<"Thanks for using Farmrun.";

    return 0;
}
