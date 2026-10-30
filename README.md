# Student Record Management System

A console-based student management application developed using C++. It allows users to manage student records efficiently through basic CRUD operations, searching, sorting, and file handling.

## Features

* Add new student records.
* Display all student records.
* Search students by roll number.
* Update existing student details.
* Delete student records.
* Sort students by marks.
* Calculate class average marks.
* Automatically save and load records using file handling.
* Calculate grades based on student marks.

## Technologies Used

* **Language:** C++
* **Concepts:** Object-Oriented Programming (OOP), Classes, Objects, Vectors, File Handling, Searching, Sorting, CRUD Operations.
* **Compiler:** GCC (G++)

## Project Structure

```text
Student-Record-Management-System/
│
├── main.cpp
├── Student.h
├── Student.cpp
├── StudentManager.h
├── StudentManager.cpp
├── students.txt
└── README.md
```

## How to Run

**1. Clone the repository**

```bash
git clone https://github.com/Shivamtripathi78/Student-Record-Management-System.git
```

**2. Open the project directory**

```bash
cd Student-Record-Management-System
```

**3. Compile the project**

```bash
g++ -std=c++17 main.cpp Student.cpp StudentManager.cpp -o StudentManagement
```

**4. Run the application**

On Windows:

```powershell
.\StudentManagement.exe
```

## Learning Outcomes

* Understanding OOP principles in C++.
* Implementing CRUD operations.
* Working with vectors and classes.
* Performing searching and sorting operations.
* Managing persistent data using file handling.
* Building menu-driven console applications.

## Future Enhancements

* Graphical user interface.
* Database integration.
* Student attendance management.
* Advanced academic performance reports.
* Login and authentication system.

## Author

**Shivam Tripathi**

GitHub: [Shivamtripathi78](https://github.com/Shivamtripathi78)

## License

This project is intended for educational and learning purposes.
