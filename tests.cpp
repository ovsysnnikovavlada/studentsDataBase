#define UNIT_TESTS
#include <student.h>
#include <main.cpp>
#include <algorithm>
#include <googletest-main/googletest/include/gtest/gtest.h>

// Тесты
// Тестируем добавление студента в базу данных
TEST(DatabaseTest, AddStudent) {
    std::vector<Student> database;
    Student testStudent{"Test", 25, "IT", 5.0};

    database.push_back(testStudent);

    EXPECT_EQ(database.size(), 1);
    EXPECT_EQ(database[0].name, "Test");
    EXPECT_EQ(database[0].age, 25);
    EXPECT_EQ(database[0].major, "IT");
    EXPECT_DOUBLE_EQ(database[0].gpa, 5.0);
}

// Тестируем сравнение студентов по имени
TEST(StudentTest, CompareStudentsByName) {
    Student s1{"Ivanov", 20, "CS", 4.5};
    Student s2{"Petrov", 21, "Math", 4.7};

    EXPECT_TRUE(compareStudentsByName(s1, s2));  // Ivanov < Petrov
    EXPECT_FALSE(compareStudentsByName(s2, s1)); // Petrov !< Ivanov
}

// Тестируем сортировку студентов в алфавитном порядке
TEST(SortingTest, AlphabeticalOrder) {
    std::vector<Student> database = {
        {"Petrov", 21, "Math", 4.7},
        {"Ivanov", 20, "CS", 4.5},
        {"Sidorov", 22, "Physics", 4.3}
    };

    std::sort(database.begin(), database.end(), compareStudentsByName);

    EXPECT_EQ(database[0].name, "Ivanov");
    EXPECT_EQ(database[1].name, "Petrov");
    EXPECT_EQ(database[2].name, "Sidorov");
}

// Тестируем проверку на пустую базу данных
TEST(DatabaseTest, EmptyDatabase) {
    std::vector<Student> emptyDB;
    EXPECT_TRUE(emptyDB.empty());
    EXPECT_EQ(emptyDB.size(), 0);
}

// Тестируем находится ли средний балл в допустимом диапазоне
TEST(GPATest, ValidGradesRange) {
    Student s{"Test", 20, "CS", 3.5};

    EXPECT_GE(s.gpa, 0.0);  // gpa >= 0
    EXPECT_LE(s.gpa, 5.0);  // gpa <= 5
}