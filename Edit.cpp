#include "Edit.h"

void Edit:: findRoute(string st, string loc, string rname) {
	//Route tempRoute;
	tempRoute.setFileToVector();

	for (int i = 0; i < tempRoute.getFileToVector().size(); i++) {
		if (tempRoute.getFileToVector()[i].getState() == st && tempRoute.getFileToVector()[i].getLocation() == loc && tempRoute.getFileToVector()[i].getRouteName() == rname) {
			foundRoutes.push_back(tempRoute.getFileToVector()[i]);
		}
	}
	
}

vector<Route> Edit:: getFoundRoutes() {
	return foundRoutes;
}

void Edit::editRoute(bool del) {
	//Route tempRoute;
	string s, l, r;
	if (del == true) {		
		cout << "Enter the State of the route you want to edit: ";
		cin.ignore();
		getline(cin, s);
		cout << "Enter the location of the route you want to edit: ";
		getline(cin, l);
		cout << "Enter the name of the Route: ";
		getline(cin, r);
	}
	else {
		//delete
		cout << "Enter the State of the route you want to delete: ";
		cin.ignore();
		getline(cin, s);
		cout << "Enter the location of the route you want to delete: ";
		getline(cin, l);
		cout << "Enter the name of the Route: ";
		getline(cin, r);
	}
	findRoute(s, l, r);
	
	if (foundRoutes.size() == 0) {
		cout << "NO ROUTES FOUND... TRY AGAIN.\n";
		tempRoute.clearVec();
		editRoute(del); 
	}
	else {
		cout << "ROUTES SATISFIED: " << foundRoutes.size() << endl;
		for (int i = 0; i < foundRoutes.size(); i++) {
			tempRoute.printVec(foundRoutes[i]);
			cout << endl << endl;
		}

		cout << "Enter the number in relation to the route would you like to edit: ";
		int choice; 
		cin >> choice; 
		choice--;

		if (choice < 0 || choice >= foundRoutes.size()) {
			cout << "INVALID ENTRY... TRY AGAIN\n";
			foundRoutes.clear();
			tempRoute.clearVec();
			editRoute(del);
		}
		else {
			//i have the choice enetered by the user which ends up being  location in foundRoutes vector foundRoutes(choice - 1)...
			//with this information, I can get its date, as well as the usual state and location... therefore i can easily find it again
			//and rewrite all vectors to the file
			//in terms of editing... i say we ask that user what needs to be changed... a series of yes or no questions... 
			Route foundTempRoute(foundRoutes[choice].getState(), foundRoutes[choice].getLocation(), foundRoutes[choice].getDate(), foundRoutes[choice].getRouteName(), foundRoutes[choice].getRating(), foundRoutes[choice].getNotes());
			//editing starts
			if (del == true) {
				int ed = 0;
				while (ed != 6) {
					cout << "What do you want to edit about the route?\n";
					cout << "1. State\n2. Location\n3. Route Name\n4. Date\n5. Notes\n6. Done\n";
					cin >> ed;
					if (ed < 1 || ed > 6) {
						cout << "INVALID ENTRY... TRY AGAIN\n";
					}
					else {
						string tempState;
						string tempLocation;
						string tempRouteName;
						string tempDate;
						string tempNotes;
						
						//string st, string loc, string d, string rname, string rate, string n
						cin.ignore();
						switch (ed) {
						case 1:
							
							cout << "Enter State: ";
							getline(cin, tempState);
							foundRoutes[choice].setState(tempState);
							break;
						case 2:
							
							cout << "Enter Location: ";
							getline(cin, tempLocation);
							foundRoutes[choice].setLocation(tempLocation);
							break;
						case 3:
							
							cout << "Enter Route Name: ";
							getline(cin, tempRouteName);
							foundRoutes[choice].setRouteName(tempRouteName);
							break;
						case 4:
							
							cout << "Enter Date: ";
							getline(cin, tempDate);
							foundRoutes[choice].setDate(tempDate);
							break;
						case 5:
							
							cout << "Enter Notes: ";
							getline(cin, tempNotes);
							foundRoutes[choice].setNotes(tempNotes);
							break;
						case 6:
							break;
						}
					}
				}

			}	
			
			vector<Route>replacementVector; 
			for (int i = 0; i < tempRoute.getFileToVector().size(); i++) {
				if (tempRoute.getFileToVector()[i].getState() == foundTempRoute.getState() && tempRoute.getFileToVector()[i].getLocation() == foundTempRoute.getLocation() &&
					tempRoute.getFileToVector()[i].getRouteName() == foundTempRoute.getRouteName() && tempRoute.getFileToVector()[i].getDate() == foundTempRoute.getDate()) {

					if (del == true) {
						replacementVector.push_back(foundRoutes[choice]);
					}
					else {
						//delete
					}
				}
				else{
					replacementVector.push_back(tempRoute.getFileToVector()[i]);
				}
			}
			
			Add add;
			add.writeRoute(replacementVector);
	
			//now i should have the replacement vector in question... i must write it to the file now...
		}
	}
	foundRoutes.clear();
	
}