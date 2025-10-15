cmake_minimum_required(VERSION 3.14)
project(studentsDataBase)

set(CMAKE_CXX_STANDARD 17)

# ВКЛЮЧАЕМ ПОДДЕРЖКУ CTEST
include(CTest)

include(FetchContent)

# Подтягиваем GoogleTest из интернета
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Основной проект
add_executable(studentsDataBase main.cpp)

# Тесты
add_executable(tests tests.cpp)
target_link_libraries(tests gtest_main)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# РЕГИСТРИРУЕМ ТЕСТЫ ДЛЯ CTEST
enable_testing()
add_test(NAME StudentDatabaseTests COMMAND tests)
