#include <iostream>
#include <string>
#include <stdarg.h>

using namespace std;

#ifndef CPPBASIC_ARRAYFUNCTIONS_HPP
#define CPPBASIC_ARRAYFUNCTIONS_HPP

/** Задание 1 */
template<typename T>
void PrintArray(T *arr, const size_t SIZE, const string& separator = " ") {
    if (!arr || SIZE == 0) {
        cout << "Function params are invalid" << endl;
        return;
    };

    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];

        if (i < SIZE - 1) {
            cout << separator;
        }
    }

    cout << endl;
}

/** Задание 4 */
template<typename T>
void ShiftArray(T &arr, int n, T &outArray, const size_t SIZE) {
    const auto first = arr[0];

    if (n > 0) {
        for (int i = 0; i < SIZE - n; i++) {
            outArray[i] = arr[i + n];
        }

        for (int j = 0; j <= n; j++) {
            outArray[SIZE - n + j] = arr[j];
        }
    } else {
        n = -n;
        for (int i = 0; i < SIZE - n; i++) {
            outArray[n + i] = arr[i];
        }

        for (int j = 0; j <= n; j++) {
            outArray[j] = arr[SIZE + j - n];
        }
    }

    arr[0] = first;
}

template<typename T>
void FillArray(T *arr, int count, ...) {
    va_list arguments;
    va_start(arguments, count);

    for (int i = 0; i < count; i++) {
        arr[i] = va_arg(arguments, T);
    }

    va_end(arguments);
}

#endif //CPPBASIC_ARRAYFUNCTIONS_HPP
