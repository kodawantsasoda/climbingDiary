#include "View.h"

void View::viewAllDiary() {
	string myText;

	// Read from the text file
	ifstream MyReadFile("Climbing Diary.txt");

	// Use a while loop together with the getline() function to read the file line by line
	int count = 0;
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		//count mod is used to avoid printing out the "key" string
		if (count == 0) {
			cout << "************************\n";
		}
		if (count == 9) {
			cout << "V";
		}
		if (count % 2 != 0) {
			cout << myText << endl;
		}
		count++;
		if (count > 11) {
			count = 0;
		}
	}
}

void View::viewByDate() {
	cout << "Enter date range in format MM/DD/YEAR\n";
	string date1;
	Route justForDate;
	bool check = false;
	while (check == false) {
		cout << "Enter your first date : ";
		getline(cin, date1);

		if (justForDate.dateCheck(date1) == false) {
			cout << "INVALID DATE... TRY AGAIN\n";
		}
		else {
			check = true;
		}
	}
	check = false;
	string date2;
	while (check == false) {
		cout << "Enter your end date : ";
		getline(cin, date2);

		if (justForDate.dateCheck(date2) == false) {
			cout << "INVALID DATE... TRY AGAIN\n";
		}
		else {
			check = true;
		}
	}

	dateRange(date1, date2);

}

void View::dateRange(string firstDate, string endDate) { 
	Route a, b;
	View first, end;

	first.setDateStrings(firstDate);
	end.setDateStrings(endDate);

	a.setFileToVector(); //now i have a bunch of vector of routes stored from file. this can be accessed in 'a' functions...

	for (int i = 0; i < a.getFileToVector().size(); i++) {
		setDateStrings(a.getFileToVector()[i].getDate());
		if (stringToDigit(getYear()) == stringToDigit(first.getYear()) && stringToDigit(getMonth()) == stringToDigit(first.getMonth())) {
			if (stringToDigit(getDay()) <= stringToDigit(end.getDay())) {
				//satify!
				a.printVec(a.getFileToVector()[i]);
			}
			else {

			}
		}

		else if (stringToDigit(getYear()) == stringToDigit(end.getYear()) && stringToDigit(getMonth()) == stringToDigit(end.getMonth())) {
			if (stringToDigit(getDay()) >= stringToDigit(end.getDay())) {
				//satify!
				a.printVec(a.getFileToVector()[i]);
			}
			else {
				
			}
		}

		else if (stringToDigit(getYear()) == stringToDigit(first.getYear())) { //case if date in question = the initial date
			if (stringToDigit(getMonth()) > stringToDigit(first.getMonth())) {
				//satisfy
				a.printVec(a.getFileToVector()[i]);
			}
			else {
				
			}
		}

		else if (stringToDigit(getYear()) == stringToDigit(end.getYear())) { // case if date in question = end date
			if (stringToDigit(getMonth()) < stringToDigit(end.getMonth())) {
				//satisfy
				a.printVec(a.getFileToVector()[i]);
			}
			else {
		
			}
		}
		else if (stringToDigit(getYear()) > stringToDigit(first.getYear()) && stringToDigit(getYear()) < stringToDigit(end.getYear())) {
			//this means it lies in the middle... pretty much everything should satify
			a.printVec(a.getFileToVector()[i]);
		}
	}
}

void View::setDay(string d) {
	day = d;
}

string View::getDay() {
	return day;
}

void View::setMonth(string m) {
	month = m;
}

string View::getMonth() {
	return month;
}

void View::setYear(string y) {
	year = y;
}

string View::getYear() {
	return year;
}

void View::setDateStrings(string s) {
	string tempDate = "";

	tempDate.push_back(s[0]);
	tempDate.push_back(s[1]);
	setMonth(tempDate);

	tempDate.clear();

	tempDate.push_back(s[3]);
	tempDate.push_back(s[4]);
	setDay(tempDate);

	tempDate.clear();

	tempDate.push_back(s[6]);
	tempDate.push_back(s[7]);
	tempDate.push_back(s[8]);
	tempDate.push_back(s[9]);
	setYear(tempDate);
}

int View::stringToDigit(string dt) {
	if (dt.size() < 4) {
		return (dt[0] - '0') * 10 + (dt[1] - '0');
	}
	else return (dt[0] - '0') * 1000 + (dt[1] - '0') * 100 + (dt[2] - '0') * 10 + (dt[3] - '0');
}

void View::viewByLocation() {
	string tempState, tempLocation;
	cin.ignore();
	cout << "Enter State: ";
	getline(cin, tempState);
	cout << "Enter Location: ";
	getline(cin, tempLocation); 

	Route a; 
	a.setFileToVector();

	for (int i = 0; i < a.getFileToVector().size(); i++) {
		if (a.getFileToVector()[i].getState() == tempState && a.getFileToVector()[i].getLocation() == tempLocation) {
			satisfiedRoutes.push_back(a.getFileToVector()[i]); 
			cout << a.getFileToVector()[i].getState() << ", " << a.getFileToVector()[i].getLocation() << endl << a.getFileToVector()[i].getRouteName() << endl << "V" <<
				a.getFileToVector()[i].getRating() << endl << a.getFileToVector()[i].getDate() << endl << "NOTES: " << a.getFileToVector()[i].getNotes() << endl;
		}
	}
}

void View::viewByRoute() {
	string tempState, tempLocation, tempRouteName;
	cin.ignore();
	cout << "Enter State: ";
	getline(cin, tempState);
	cout << "Enter Location: ";
	getline(cin, tempLocation);
	cout << "Enter Route Name: ";
	getline(cin, tempRouteName);

	Route a;
	a.setFileToVector();

	for (int i = 0; i < a.getFileToVector().size(); i++) {
		if (a.getFileToVector()[i].getState() == tempState && a.getFileToVector()[i].getLocation() == tempLocation && a.getFileToVector()[i].getRouteName() == tempRouteName) {
			satisfiedRoutes.push_back(a.getFileToVector()[i]); 
			cout << a.getFileToVector()[i].getState() << ", " << a.getFileToVector()[i].getLocation() << endl << a.getFileToVector()[i].getRouteName() << endl << "V" <<
				a.getFileToVector()[i].getRating() << endl << a.getFileToVector()[i].getDate() << endl << "NOTES: " << a.getFileToVector()[i].getNotes() << endl;
		}
	}
	if (satisfiedRoutes.size() == 0) {
		cout << "Route not found\n";
	}
}

void View::prompt() {
	cout << "How would you like to view your diary?\n";
	cout << "1. View All\n2. View by date range\n3. View by location\n4. View by route\n";
	int choice;
	cin >> choice;
	//error check
	switch (choice) {
	case 1:
		viewAllDiary();
		break;
	case 2:
		cin.ignore();
		viewByDate();
		break;
	case 3:
		cin.ignore();
		viewByLocation();
		break;
	case 4:
		cin.ignore();
		viewByRoute();
		break;
	}
}