
#include "farmrun.h"
#include <iostream>

// Helper to mark and remove visited locations
void promptAndRemoveLocations(std::vector<std::string>& locations, const std::string& title) {
    while (!locations.empty()) {
        std::cout << title << "\n";
        for (size_t i = 0; i < locations.size(); ++i) {
            std::cout << i + 1 << ". " << locations[i] << std::endl;
        }
        std::cout << "Select location visited (0 to stop): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (choice >= 1 && choice <= static_cast<int>(locations.size())) {
            std::cout << "Marked " << locations[choice - 1] << " as visited.\n\n";
            locations.erase(locations.begin() + (choice - 1));
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    if (locations.empty()) {
        std::cout << "All locations completed. Run finished!\n";
    } else {
        std::cout << "Run paused with " << locations.size() << " remaining.\n";
    }
}

// ---------------------- HerbRun ----------------------
HerbRun::HerbRun() {
    herbLocations = {"Catherby", "Ardougne", "Falador", "Canifis", "Farming Guild","Trollheim", "Canafis"};
}

void HerbRun::displayLocations() const {
    std::cout << "Herb Patch Locations:\n";
    for (const auto& loc : herbLocations) {
        std::cout << "- " << loc << std::endl;
    }
}

void HerbRun::performRun() {
    std::cout << "Starting Herb Run...\n";
    promptAndRemoveLocations(herbLocations, "Remaining Herb Patches:");
}

std::string HerbRun::getName() const {
    return "Herb Run";
}

// ---------------------- TreeRun ----------------------
TreeRun::TreeRun() {
    treeLocations = {"Lumbridge", "Varrock", "Falador", "Taverley", "Gnome Stronghold", "Farming Guild",};
}

void TreeRun::displayLocations() const {
    std::cout << "Tree Patch Locations:\n";
    for (const auto& loc : treeLocations) {
        std::cout << "- " << loc << std::endl;
    }
}

void TreeRun::performRun() {
    std::cout << "Starting Tree Run...\n";
    promptAndRemoveLocations(treeLocations, "Remaining Tree Patches:");
}

std::string TreeRun::getName() const {
    return "Tree Run";
}

// ---------------------- FruitTreeRun ----------------------
FruitTreeRun::FruitTreeRun() {
    fruitTreeLocations = {"Catherby", "Gnome Stronghold", "Tree Gnome Maze", "Brimhaven", "Lletya", "Farming Guild"};
}

void FruitTreeRun::displayLocations() const {
    std::cout << "Fruit Tree Patch Locations:\n";
    for (const auto& loc : fruitTreeLocations) {
        std::cout << "- " << loc << std::endl;
    }
}

void FruitTreeRun::performRun() {
    std::cout << "Starting Fruit Tree Run...\n";
    promptAndRemoveLocations(fruitTreeLocations, "Remaining Fruit Tree Patches:");
}

std::string FruitTreeRun::getName() const {
    return "Fruit Tree Run";
}
