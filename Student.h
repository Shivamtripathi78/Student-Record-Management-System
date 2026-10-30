#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int age;
    string course;
    float marks;

public:
    Student();
    Student(int roll, string studentName, int studentAge,
            string studentCourse, float studentMarks);

    int getRollNumber() const;
    string getName() const;
    int getAge() const;
    string getCourse() const;
    float getMarks() const;

    void setName(string studentName);
    void setAge(int studentAge);
    void setCourse(string studentCourse);
    void setMarks(float studentMarks);

    string getGrade() const;
    void display() const;
};

#endif