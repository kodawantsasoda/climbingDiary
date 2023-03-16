#ifndef _ROUTE_H
#define _ROUTE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Route {
public:
    Route() = default;
    Route(string st, string loc, string d, string rname, string rate, string n);

    void setState(string st);
    string getState();

    void setLocation(string loc);
    string getLocation();

    void setDate(string d);
    string getDate();

    void setRouteName(string r);
    string getRouteName();

    void setRating(string rate);
    string getRating();

    void setNotes(string n);
    string getNotes();

    void setFileToVector();
    vector<Route> getFileToVector();

    void printVec(Route r);

    const string key = ")(*&^%$#@!"; //this is a signal to say hey this text is over!

    bool dateCheck(string d);
    bool isLeap(int yr);

    void clearVec();


private:
    string state, location, date, routeName, rating, notes;
    vector<Route> vecRoutes;

};

#endif