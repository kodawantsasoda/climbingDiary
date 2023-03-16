#include "Add.h"
#include <string>

void Add::prompt() {
    cout << "Enter the State in which you completed the route: ";
    string st;
    cin >> st;
    cin.ignore();
    cout << "Enter the location in which you completed the route: ";
    string loc;
    getline(cin, loc);

    bool check = false;
    Route justForDate;
    string dt;
    while (check == false) {
        cout << "Enter the date in which you completed the route (mm/dd/year)";
        getline(cin, dt);

        if (justForDate.dateCheck(dt) == false) {
            cout << "INVALID DATE... TRY AGAIN\n";
        }
        else {
            check = true;
        }  
    }

    cout << "Enter the name of the route you completed: ";
    string route;
    getline(cin, route);
    cout << "Enter the rating of the route: ";
    string rate;
    getline(cin, rate);
    cout << "Enter any notes you have about the route: ";
    string n;
    getline(cin, n);

    Route tempObj(st, loc, dt, route, rate, n);
    addRoute(tempObj);
    vector<Route> empty;
    writeRoute(empty);

}

void Add::addRoute(Route r) {
    newRoute.setState(r.getState()); 
    newRoute.setLocation(r.getLocation());
    newRoute.setDate(r.getDate());
    newRoute.setRouteName(r.getRouteName());
    newRoute.setRating(r.getRating());
    newRoute.setNotes(r.getNotes());
}

void Add::writeRoute(vector<Route> r) {
    if (r.size() != 0) {
        ofstream log("Climbing Diary.txt");
        for (int i = 0; i < r.size(); i++) {
            //overwrite
            log << key << endl << r[i].getState() << endl << key << endl << r[i].getLocation() << endl << key << endl << r[i].getDate() << endl << key << endl
                << r[i].getRouteName() << endl << key << endl << r[i].getRating() << endl << key << endl << r[i].getNotes() << endl;

        }
        log.close();
    }
    //adding new file.. appending...
    if (newRoute.getState().size() != 0) {
        ofstream log2;
        log2.open("Climbing Diary.txt", std::ios_base::app);
        log2 << key << endl << newRoute.getState() << endl << key << endl << newRoute.getLocation() << endl << key << endl << newRoute.getDate() << endl << key << endl
            << newRoute.getRouteName() << endl << key << endl << newRoute.getRating() << endl << key << endl << newRoute.getNotes() << endl;
        log2.close();
    }
}

void Add::clearNewRoute() {
    newRoute.setState("");
    newRoute.setLocation("");
    newRoute.setDate("");
    newRoute.setRouteName("");
    newRoute.setRating("");
    newRoute.setNotes("");
}