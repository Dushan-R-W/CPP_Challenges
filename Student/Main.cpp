#include <iostream>
#include <vector>
#include "Student.h"


void addStudent(std::vector<Student>& students)
{
    int id, age;
    std::string name, course;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::cin >> name;
    std::cout << "Enter Age: ";
    std::cin >> age;
    std::cin.ignore();
    std::cout << "Enter Course: ";
    std::getline(std::cin, course);

    Student s(id, name, age, course);
    students.push_back(s);

    std::cout << "Student added successfully!\n";
}

void viewStudents(const std::vector<Student>& students)
{
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }
    for (const auto& s : students)
        s.display();
}

void searchByID(const std::vector<Student>& students) {

    int id_;
    std::cout << "Enter ID: ";
    std::cin >> id_;
    std::cin.ignore();
    for (const auto &s : students) {
        if (s.getID() == id_) {
            std::cout << "ID: " << s.getID() << "| Name: " << s.getName() << "| Age: " << s.getAge() << "| Course: " << s.getCourse() << "\n";
            return;
        }
    }
    std::cout << "No match found!\n";
}

void sort(std::vector<Student>& students, const std::string &soryBy) {

    std::sort(students.begin(), students.end(),
        [soryBy](const Student& a, const Student& b) {
            if (soryBy == "name") {
                return a.getName() < b.getName();
            }
            if (soryBy == "id") {
                return a.getID() < b.getID();
            }
        }
    );

}

int main()
{

    std::vector<Student> students;
    int choice;

    do
    {
        while (true) {
            std::cout << "\n-- Student Management System --\n";
            std::cout << "1. Add student\n";
            std::cout << "2. View Student\n";
            std::cout << "3. Search by ID\n";
            std::cout << "4. Sort by ID\n";
            std::cout << "5. Sort by Name\n";
            std::cout << "6. Save Students\n";
            std::cout << "7. Load Students\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter choice\n";
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input!\n";
            }
            else if (choice >= 0 || choice <= 6) {
                break;
            }
        }


        switch (choice)  
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            viewStudents(students);
            break;
        case 3:
            searchByID(students);
            break;
        case 4:
            sort(students, "id");
            viewStudents(students);
            break;
        case 5:
            sort(students, "name");
            viewStudents(students);
            break;
        case 6:
            saveStudents(students);
            break;
        case 7:
            loadStudents(students);
            break;
        case 0:
            std::cout << "Exiting..\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}