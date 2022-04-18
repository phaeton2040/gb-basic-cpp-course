#include <iostream>
#include <string>

using namespace std;

#ifndef CPPBASIC_ARRAYFUNCTIONS_H
#define CPPBASIC_ARRAYFUNCTIONS_H

/** Задание 1 */
template<typename T>
void PrintArray(T *arr, int SIZE, const string& separator);

/** Задание 4 */
template<typename T>
void ShiftArray(T &arr, int n, T &outArray, size_t SIZE);

template<typename T>
void FillArray(T *arr, int count, ...);

void SwapArraySymbols(int *arr, size_t SIZE);
bool CheckBalance(int *arr, size_t SIZE);

#endif //CPPBASIC_ARRAYFUNCTIONS_H
