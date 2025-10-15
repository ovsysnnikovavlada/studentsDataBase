// student.cpp
#include "student.h"
#include <iostream>
#include <algorithm>

bool compareStudentsByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

void printSeparator() {
    std::cout << "----------------------------------------\n";
}

void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

void displayStudentsSorted(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::vector<Student> sortedDatabase = database;
    std::sort(sortedDatabase.begin(), sortedDatabase.end(), compareStudentsByName);
    
    printSeparator();
    std::cout << "Список студентов в алфавитном порядке:\n";
    printSeparator();

    for (const Student& student : sortedDatabase) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}
