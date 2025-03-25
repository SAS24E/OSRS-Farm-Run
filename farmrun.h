
#ifndef FARMRUN_H
#define FARMRUN_H

#include <string>
#include <vector>

class RunType {
public:
    virtual void displayLocations() const = 0;
    virtual void performRun() = 0;
    virtual std::string getName() const = 0;
    virtual ~RunType() {}
};

class HerbRun : public RunType {
private:
    std::vector<std::string> herbLocations;
    std::vector<bool> visited;

public:
    HerbRun();
    void displayLocations() const override;
    void performRun() override;
    std::string getName() const override;
    void markLocationVisited();
};

class TreeRun : public RunType {
private:
    std::vector<std::string> treeLocations;
    std::vector<bool> visited;

public:
    TreeRun();
    void displayLocations() const override;
    void performRun() override;
    std::string getName() const override;
    void markLocationVisited();
};

class FruitTreeRun : public RunType {
private:
    std::vector<std::string> fruitTreeLocations;
    std::vector<bool> visited;

public:
    FruitTreeRun();
    void displayLocations() const override;
    void performRun() override;
    std::string getName() const override;
    void markLocationVisited();
};

#endif
