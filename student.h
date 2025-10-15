// student.h
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

inline bool compareStudentsByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// Объявления других функций...
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void printSeparator();
void displayStudentsSorted(std::vector<Student>& database);
