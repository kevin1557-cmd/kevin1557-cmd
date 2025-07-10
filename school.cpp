#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string grade;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Grade (e.g., 10A): ";
    getline(cin, s.grade);

    students.push_back(s);
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students registered.\n";
        return;
    }

    cout << "\n--- Registered Students ---\n";
    for (const Student &s : students) {
        cout << "ID: " << s.id << "\n";
        cout << "Name: " << s.name << "\n";
        cout << "Age: " << s.age << "\n";
        cout << "Grade: " << s.grade << "\n";
        cout << "-------------------------\n";
    }
}

void searchStudent() {
    int searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;

    for (const Student &s : students) {
        if (s.id == searchId) {
            cout << "\n--- Student Found ---\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Age: " << s.age << "\n";
            cout << "Grade: " << s.grade << "\n";
            return;
        }
    }

    cout << "Student with ID " << searchId << " not found.\n";
}

void menu() {
    int choice;
    do {
        cout << "\n=== School Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);
}

int main() {
    menu();
    return 0;
    