#ifndef _VIEW_H
#define _VIEW_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Route.h"
using namespace std;
class View {
public:
	void viewAllDiary();
	void prompt();
	void viewByDate();
	void viewByLocation();
	void viewByRoute();
	void dateRange(string firstDate, string endDate);

	void setDay(string d);
	string getDay();
	void setMonth(string m);
	string getMonth();
	void setYear(string y);
	string getYear();

	void setDateStrings(string s);

	int stringToDigit(string dt);

	vector<Route> satisfiedRoutes;


	
	
private:
	string day, month, year;
};

#endif
