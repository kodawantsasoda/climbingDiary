#include "Route.h"

Route::Route(string st, string loc, string d, string rname, string rate, string n) {
    state = st;
    location = loc;
    date = d;
    routeName = rname;
    rating = rate;
    notes = n;
}
void Route::setState(string st) {
    state = st;
}

string Route::getState() {
    return state;
}

void Route::setLocation(string loc) {
    location = loc;
}

string Route::getLocation() {
    return location;
}

void Route::setDate(string d) {
    date = d;
}
string Route::getDate() {
    return date;
}
void Route::setRouteName(string rname) {
    routeName = rname;
}
string Route::getRouteName() {
    return routeName;
}
void Route::setRating(string rate) {
    rating = rate;
}
string Route::getRating() {
    return rating;
}
void Route::setNotes(string n) {
    notes = n;
}
string Route::getNotes() {
    return notes;
}

void Route::setFileToVector() {
    string myText;
    Route tempObject;
    int i = 0; //keeps track of position

    // Read from the text file
    ifstream MyReadFile("Climbing Diary.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        if (myText == key) {
            i++;
        }
        else {
            switch (i) {
            case 1:
                tempObject.setState(myText);
                break;
            case 2:
                tempObject.setLocation(myText);
                break;
            case 3:
                tempObject.setDate(myText);
                break;
            case 4:
                tempObject.setRouteName(myText);
                break;
            case 5:
                tempObject.setRating(myText);
                break;
            case 6:
                tempObject.setNotes(myText);
                vecRoutes.push_back(tempObject);
                i = 0;
                break;
            }
        }
    }
}

void Route::printVec(Route r) {
    cout << "************************\n";
    cout << r.getLocation() << endl << r.getState() << endl << r.getDate() << endl << r.getRouteName() << endl << "V" << r.getRating() << endl << r.getNotes() << endl;
}

vector<Route>Route::getFileToVector() {
    return vecRoutes;
}

bool Route::dateCheck(string dt) {
    string str;
    int m = 0, d = 0, y = 0;

    if (dt.size() != 10) {
        return false;
    }
    else if (dt[2] != '/' || dt[5] != '/') {
        return false;
    }
    else{
        str.push_back(dt[0]);
        str.push_back(dt[1]);
       
        for (char const& c : str) {
            if (std::isdigit(c) == 0) { cout << "This means false!"; return false; }
        }
        m = (dt[0] - '0') * 10 + (dt[1] - '0');
        if (m < 1 || m > 12) return false;

        str.push_back(dt[3]);
        str.push_back(dt[4]);
        for (char const& c : str) {
            if (std::isdigit(c) == 0) return false;
        }
        d = (dt[3] - '0') * 10 + (dt[4] - '0');
        if (d < 1 || d > 31) return false;

        str.push_back(dt[6]);
        str.push_back(dt[7]);
        str.push_back(dt[8]);
        str.push_back(dt[9]);
        for (char const& c : str) {
            if (std::isdigit(c) == 0) return false;
        }

        if (m == 2)
        {
            if (isLeap(y))
                return (d <= 29);
            else
                return (d <= 28);
        }

        if (m == 4 || m == 6 ||
            m == 9 || m == 11)
            return (d <= 30);

        return true;

    }
}

bool Route::isLeap(int yr){
    // Return true if year
    // is a multiple of 4 and
    // not multiple of 100.
    // OR year is multiple of 400.
    return (((yr % 4 == 0) &&
        (yr % 100 != 0)) ||
        (yr % 400 == 0));
}

void Route::clearVec() {
    vecRoutes.clear();
}

