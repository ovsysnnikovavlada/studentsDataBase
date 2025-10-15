// student.h
#pragma once
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Добавьте объявление compareStudentsByName
bool compareStudentsByName(const Student& a, const Student& b);
void printSeparator();
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void displayStudentsSorted(std::vector<Student>& database);
