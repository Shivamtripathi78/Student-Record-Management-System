#include <iostream>
#include "StudentManager.h"

using namespace std;

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "   STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort Students by Marks\n";
        cout << "7. Calculate Class Average\n";
        cout << "0. Exit\n";

        cout << "========================================\n";
        cout << "Enter Your Choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                manager.addStudent();
                break;

            case 2:
                manager.displayStudents();
                break;

            case 3:
                manager.searchStudent();
                break;

            case 4:
                manager.updateStudent();
                break;

            case 5:
                manager.deleteStudent();
                break;

            case 6:
                manager.sortStudents();
                break;

            case 7:
                manager.calculateAverage();
                break;

            case 0:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}