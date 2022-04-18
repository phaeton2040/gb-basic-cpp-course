#include <iostream>
#include <string>

using namespace std;

/** Задание 2 */
void SwapArraySymbols(int *arr, size_t SIZE) {
    if (!SIZE) {
        cout << "Function params are invalid" << endl;
        return;
    };

    for (int i; i < SIZE; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
        } else if (arr[i] == 1) {
            arr[i] = 0;
        } else {
            continue;
        }
    }
}

bool CheckBalance(int *arr, const size_t SIZE) {
    int last = arr[SIZE - 1];
    int first = arr[0];
    int balanceRight = last;
    int balanceLeft = first;
    int rightIndex = 1;
    int leftIndex = 1;

    while ((leftIndex + rightIndex) < SIZE) {
        if (balanceLeft < balanceRight) {
            balanceLeft += arr[leftIndex];
            leftIndex++;
        } else if (balanceLeft > balanceRight) {
            balanceRight += arr[SIZE - 1 - rightIndex];
            rightIndex++;
        } else {
            balanceLeft += arr[leftIndex];
            balanceRight += arr[SIZE - 1 - rightIndex];
            leftIndex++;
            rightIndex++;
        }
    }

    return balanceRight == balanceLeft;
}