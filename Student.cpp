#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student() {
    rollNumber = 0;
    name = "";
    age = 0;
    course = "";
    marks = 0;
}

Student::Student(int roll, string studentName, int studentAge,
                 string studentCourse, float studentMarks) {
    rollNumber = roll;
    name = studentName;
    age = studentAge;
    course = studentCourse;
    marks = studentMarks;
}

int Student::getRollNumber() const {
    return rollNumber;
}

string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

string Student::getCourse() const {
    return course;
}

float Student::getMarks() const {
    return marks;
}

void Student::setName(string studentName) {
    name = studentName;
}

void Student::setAge(int studentAge) {
    age = studentAge;
}

void Student::setCourse(string studentCourse) {
    course = studentCourse;
}

void Student::setMarks(float studentMarks) {
    marks = studentMarks;
}

string Student::getGrade() const {
    if (marks >= 90) return "A+";
    if (marks >= 80) return "A";
    if (marks >= 70) return "B";
    if (marks >= 60) return "C";
    if (marks >= 50) return "D";
    if (marks >= 40) return "E";

    return "F";
}

void Student::display() const {
    cout << left
         << setw(12) << rollNumber
         << setw(22) << name
         << setw(8) << age
         << setw(15) << course
         << setw(10) << fixed << setprecision(2) << marks
         << setw(8) << getGrade()
         << endl;
}