#include "StudentManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

StudentManager::StudentManager() {
    loadFromFile();
}

bool StudentManager::rollNumberExists(int rollNumber) const {
    for (const Student& student : students) {
        if (student.getRollNumber() == rollNumber) {
            return true;
        }
    }

    return false;
}

void StudentManager::saveToFile() const {
    ofstream file("students.txt");

    if (!file) {
        cout << "Error saving student records.\n";
        return;
    }

    for (const Student& student : students) {
        file << student.getRollNumber() << "|"
             << student.getName() << "|"
             << student.getAge() << "|"
             << student.getCourse() << "|"
             << student.getMarks() << "\n";
    }

    file.close();
}

void StudentManager::loadFromFile() {
    ifstream file("students.txt");

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {
        try {
            size_t p1 = line.find('|');
            size_t p2 = line.find('|', p1 + 1);
            size_t p3 = line.find('|', p2 + 1);
            size_t p4 = line.find('|', p3 + 1);

            if (p1 == string::npos || p2 == string::npos ||
                p3 == string::npos || p4 == string::npos) {
                continue;
            }

            int roll = stoi(line.substr(0, p1));
            string name = line.substr(p1 + 1, p2 - p1 - 1);
            int age = stoi(line.substr(p2 + 1, p3 - p2 - 1));
            string course = line.substr(p3 + 1, p4 - p3 - 1);
            float marks = stof(line.substr(p4 + 1));

            if (roll > 0 && age > 0 && marks >= 0 && marks <= 100 &&
                !rollNumberExists(roll)) {
                students.emplace_back(roll, name, age, course, marks);
            }
        }
        catch (...) {
            continue;
        }
    }

    file.close();
}

void StudentManager::addStudent() {
    int roll, age;
    float marks;
    string name, course;

    cout << "\nEnter Roll Number: ";
    if (!(cin >> roll) || roll <= 0) {
        cout << "Invalid roll number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (rollNumberExists(roll)) {
        cout << "Roll number already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    getline(cin >> ws, name);

    cout << "Enter Age: ";
    if (!(cin >> age) || age <= 0) {
        cout << "Invalid age.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter Course: ";
    getline(cin >> ws, course);

    cout << "Enter Marks (0-100): ";
    if (!(cin >> marks) || marks < 0 || marks > 100) {
        cout << "Invalid marks.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    students.emplace_back(roll, name, age, course, marks);

    saveToFile();

    cout << "\nStudent added successfully!\n";
}

void StudentManager::displayStudents() const {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n"
         << left
         << setw(12) << "Roll No."
         << setw(22) << "Name"
         << setw(8) << "Age"
         << setw(15) << "Course"
         << setw(10) << "Marks"
         << setw(8) << "Grade"
         << "\n";

    cout << string(75, '-') << "\n";

    for (const Student& student : students) {
        student.display();
    }
}

void StudentManager::searchStudent() const {
    int roll;

    cout << "\nEnter Roll Number to Search: ";
    if (!(cin >> roll)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (const Student& student : students) {
        if (student.getRollNumber() == roll) {
            cout << "\nStudent Found:\n";
            student.display();
            return;
        }
    }

    cout << "\nStudent not found!\n";
}

void StudentManager::updateStudent() {
    int roll;

    cout << "\nEnter Roll Number to Update: ";
    if (!(cin >> roll)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (Student& student : students) {
        if (student.getRollNumber() == roll) {
            string name, course;
            int age;
            float marks;

            cout << "Enter New Name: ";
            getline(cin >> ws, name);

            cout << "Enter New Age: ";
            if (!(cin >> age) || age <= 0) {
                cout << "Invalid age.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }

            cout << "Enter New Course: ";
            getline(cin >> ws, course);

            cout << "Enter New Marks (0-100): ";
            if (!(cin >> marks) || marks < 0 || marks > 100) {
                cout << "Invalid marks.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }

            student.setName(name);
            student.setAge(age);
            student.setCourse(course);
            student.setMarks(marks);

            saveToFile();

            cout << "\nStudent updated successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found!\n";
}

void StudentManager::deleteStudent() {
    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    if (!(cin >> roll)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    auto it = remove_if(students.begin(), students.end(),
        [roll](const Student& student) {
            return student.getRollNumber() == roll;
        });

    if (it == students.end()) {
        cout << "\nStudent not found!\n";
        return;
    }

    students.erase(it, students.end());

    saveToFile();

    cout << "\nStudent deleted successfully!\n";
}

void StudentManager::sortStudents() {
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getMarks() > b.getMarks();
        });

    cout << "\nStudents sorted by marks (highest first).\n";

    displayStudents();
}

void StudentManager::calculateAverage() const {
    if (students.empty()) {
        cout << "\nNo records available to calculate average.\n";
        return;
    }

    float total = 0;

    for (const Student& student : students) {
        total += student.getMarks();
    }

    cout << "\nClass Average: "
         << fixed << setprecision(2)
         << total / students.size() << "\n";
}