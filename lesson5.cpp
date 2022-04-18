#include <iostream>
#include <string>

#include "ArrayFunctions.h"
#include "ArrayFunctions.hpp"

using namespace std;

int main() {
    const size_t size1 = 5;
    double arr1[size1] = { 1.04, 5.234, 3.432, 6.234, 1.654 };

    PrintArray(arr1, size1, ", ");

    const size_t size2 = 10;
    int arr2[size2] { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

    cout << "Old array: ";

    for (auto& elem : arr2) {
        printf("%u ", elem);
    }

    cout << endl;

    SwapArraySymbols(arr2, size2);

    cout << "New array: ";

    for (auto& elem : arr2) {
        printf("%u ", elem);
    }

    cout << endl;

    const size_t size4{10};
    int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int resArr[size4]{ 0 };

    ShiftArray(arr4, 2, resArr, size4);

    PrintArray(arr4, size4, ", ");
    PrintArray(resArr, size4, ", ");

    ShiftArray(arr4, -2, resArr, size4);

    PrintArray(arr4, size4, ", ");
    PrintArray(resArr, size4, ", ");

    string arr5[size4]{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
    string resArr2[size4]{};

    ShiftArray(arr5, 3, resArr2, size4);

    PrintArray(arr5, size4, ", ");
    PrintArray(resArr2, size4, ", ");

    const size_t BALANCE_SIZE = 5;
    int balanceArr[BALANCE_SIZE]{2,2,3,5,6};

    if (CheckBalance(balanceArr, BALANCE_SIZE)) {
        cout << "Balance correct" << endl;
    } else {
        cout << "Balance invalid" << endl;
    }

    int balanceArr2[BALANCE_SIZE]{10,1,2,3,4};

    if (CheckBalance(balanceArr2, BALANCE_SIZE)) {
        cout << "Balance correct" << endl;
    } else {
        cout << "Balance invalid" << endl;
    }
}