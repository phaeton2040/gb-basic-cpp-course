#include <string>
#include <vector>

#ifndef CPPBASIC_ARRAY_LIB_H
#define CPPBASIC_ARRAY_LIB_H

using namespace std;

namespace ArrayLib {
    void InitRandomArray(float *arr, size_t size, float MAX);
    void PrintArray(float *arr, size_t size, const string &separator);
    void CountPositiveAndNegativeMembers(const float *arr, size_t size, vector<int>& result);
    void SortArray(int *arr, size_t size);
}

#endif //CPPBASIC_ARRAY_LIB_H
