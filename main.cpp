#include "student.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <vector>

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        // Добавленный пункт - 3
        std::cout << "3. Вывести список студентов в алфавитном порядке\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        printSeparator();

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            // Добавленный кейс
            case 3:
                displayStudentsSorted(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
