#include <iostream>
#include <fstream>
#include "array-lib.h"

#define SIZE 10
#define CHECK_IF_IN_RANGE(a, min, max) ((a < max && a >= min ? true : false))

using namespace ArrayLib;

void Task1_5() {
    const size_t size = 100;
    float arr[size];

    InitRandomArray(arr, size, 10.f);
    PrintArray(arr, size, ", ");

    vector<int> countResult(2);

    countResult.push_back(0);
    countResult.push_back(0);

    // Тут можно было использовать обычный массив, просто хотел поэкспериментировать с векторами
    CountPositiveAndNegativeMembers(arr, size, countResult);

    cout << "The amount of positive array members: " << countResult[0] << endl;
    cout << "The amount of negative array members: " << countResult[1] << endl;
}

void Task2() {
    int num, min = 0, max = 20;
    cout << "Please enter the number: ";
    cin >> num;

    cout << "The entered number is - ";
    CHECK_IF_IN_RANGE(num, min, max) ? cout << "in range" : cout << "out of range";
    cout << endl;
}

void Task3() {
    int arr[SIZE] = {8, 2, 5, 7, 3, 1, 9, 21, 4, 6};
    SortArray(arr, SIZE);

    cout << "Sorted array values: ";
    for (auto i : arr) {
        cout << i << ", ";
    }
    cout << endl;
}

#pragma pack(push, 1)
struct Employee {
    string name;
    int age{};
    float salary{};
    string department;
};
#pragma pack(pop)

void EmployeeOperation(const Employee& employee, ostream& operation) {
    operation << "Name: " << employee.name << endl;
    operation << "Age: " << employee.age << endl;
    operation << "Salary: " << employee.salary << endl;
    operation << "Department: " << employee.department << endl;
}

void Task4() {
    Employee employee;

    employee.name = "John Smith";
    employee.age = 35;
    employee.salary = 250000.f;
    employee.department = "IT";

    EmployeeOperation(employee, std::cout);

    string fileName = employee.name + "_INFO.txt";
    ofstream file(fileName);

    if (!file.is_open()) {
        cout << "File not found" << endl;
        return;
    }

    EmployeeOperation(employee, file);
}

int main() {
    Task1_5();
    Task2();
    Task3();
    Task4();
}

using namespace ArrayLib;
