#ifndef _ADD_H
#define _ADD_H
#include <iostream>
#include <vector>
#include "Route.h"
#include <fstream>

using namespace std;

//i need a function that will essentially create a new object from class route
class Add : public Route {
public:
    Add() = default;
    Route newRoute;
    void clearNewRoute();
    void prompt(); //welcome to the add function as well as directions
    void addRoute(Route r);
    void writeRoute(vector<Route> r);

private:
    
};

#endif