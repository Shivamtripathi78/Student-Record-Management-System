#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>

class StudentManager {
private:
    vector<Student> students;

    bool rollNumberExists(int rollNumber) const;
    void saveToFile() const;
    void loadFromFile();

public:
    StudentManager();

    void addStudent();
    void displayStudents() const;
    void searchStudent() const;
    void updateStudent();
    void deleteStudent();
    void sortStudents();
    void calculateAverage() const;
};

#endif