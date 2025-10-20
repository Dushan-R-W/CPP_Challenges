#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <algorithm>
#include <vector>

class Student
{

private:
    int id;
    std::string name;
    int age;
    std::string course;

public:
    // constructors
    Student();
    Student(int id, const std::string& name, int age, const std::string& course);

    // getters and setters
    int getID() const;
    std::string getName() const;
    int getAge() const;
    std::string getCourse() const;

    void setName(const std::string& newName);
    void setAge(int newAge);
    void setCourse(const std::string& newCourse);

    void display() const;
};

void saveStudents(const std::vector<Student>& students);
void loadStudents(std::vector<Student>& students);


#endif