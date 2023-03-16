#ifndef _EDIT_H
#define _EDIT_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Route.h"
#include "Add.h"
using namespace std;

class Edit {
public:
	void findRoute(string st, string loc, string rname);
	vector<Route> getFoundRoutes();

	void editRoute(bool del);

	Route tempRoute;

	vector<Route> foundRoutes;
private:
	 
};

#endif
