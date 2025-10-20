#include "Student.h"
#include <iostream>
#include<fstream>
#include "json.hpp"
using json = nlohmann::json;

Student::Student() : id(0), name(""), age(0), course("") {}

Student::Student(int id, const std::string& name, int age, const std::string& course) : id(id), name(name), age(age), course(course) {}

int Student::getID() const { return id; }
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
std::string Student::getCourse() const { return course; }

void Student::setName(const std::string& newName) { name = newName; }
void Student::setAge(int newAge) { age = newAge; }
void Student::setCourse(const std::string& newCourse) { course = newCourse; }

void Student::display() const
{
    std::cout << "ID: " << id << "| Name: " << name << "| Age: " << age << "| Course: " << course << "\n";
}

void saveStudents(const std::vector<Student> &students){

    std::ofstream outFile("studentData.txt");
    if (!outFile) {
        std::cerr << "Cannot open file!\n";
        return;
    }

    json json_students = json::array();
    for (const auto &s : students) {
        json_students.push_back(
            {
                {"id", s.getID()},
                {"name", s.getName()},
                {"age", s.getAge()},
                {"course", s.getCourse()},
            });
    }

    outFile << json_students.dump(4);
    
}

void loadStudents(std::vector<Student>& students) {

    std::ifstream file("studentData.txt");
    if (!file) {
        std::cerr << "Cannot open file!\n";
        return;
    }

    json json_student;
    file >> json_student;

    for (const auto& s : json_student) {
        Student d(
            s.at("id").get<int>(),
            s.at("name").get<std::string>(),
            s.at("age").get<int>(),
            s.at("course").get<std::string>()
            );
        students.push_back(d);
    }

}


void loadStudents(std::vector<Student>& students) {

    //save to file
    std::ofstream file("TestFile1.txt");
    if (!file) {
        std::cout << "Can't open the file!";
        return;
    }

    json json_students = json::array();

    for (const Student &s : students) {
        json_students.push_back(
            {
                {"id", s.getID()},
                {"name", s.getName()},
                {"age", s.getAge()},
                {"course", s.getCourse()},
            });
    }

    file << json_students.dump(4);



    std::vector<Student> imported_students;

    //read from file
    std::ifstream file2("TestFile.txt");
    if (!file2) {
        std::cout << "Can't open the file!";
        return;
    }

    json json_student2 = json::parse(file2);

        
    for (const auto &t : json_student2) {
        Student r(
            t.at("id").get<int>(),
            t.at("name").get<std::string>(),
            t.at("age").get<int>(),
            t.at("course").get<std::string>()
        );

        imported_students.push_back(r);
    }



}


