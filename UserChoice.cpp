#include "UserChoice.h"

void UserChoice::userChoice() {
    Add r;
    View v;
    Edit e;
    DeleteRoute d;
    Title t;

    int n;
    int exit = 0;

    while (exit != -1) {
        t.title();
        cout << "What would you like to do?" << endl;
        cin >> n;
        switch (n) {
        case 1:
            //call function in add
            r.prompt();
            r.clearNewRoute();
            break;

        case 2:
            //call function in view
            v.prompt();
            break;

        case 3:
            //call function in edit
            e.editRoute(true);
            break;

        case 4:
            //call function in delete
            d.delRoute();
            break;

        case 5:
            //call quit
            exit = -1;
            break;

        default:
            cout << "Invalid Entry... Please try again.\n";
        }
    }
}