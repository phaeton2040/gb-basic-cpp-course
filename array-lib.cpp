#include <iostream>
#include <string>
#include <vector>

#define SWAP_INT(a, b) {               \
                       (a) ^= (b); \
                       (b) ^= (a); \
                       (a) ^= (b); \
                   }

using namespace std;

namespace ArrayLib {
    void InitRandomArray(float *arr, size_t size, const float MAX) {
        srand(time(NULL));

        for(int i = 0; i < size; i++) {
            *(arr + i) = (float(rand()) / float(RAND_MAX)) * 2 * MAX - MAX;
        }
    }

    void PrintArray(float *arr, size_t size, const string &separator = " ") {
        if (!arr || size == 0) {
            cout << "Function params are invalid" << endl;
            return;
        };

        for (int i = 0; i < size; i++) {
            cout << arr[i];

            if (i < size - 1) {
                cout << separator;
            }
        }

        cout << endl;
    }

    void CountPositiveAndNegativeMembers(const float *arr, size_t size, vector<int>& result) {
        for (int i = 0; i < size; i++) {
            arr[i] > 0 ? result[0]++ : result[1]++;
        }
    }

    void SortArray(int *arr, size_t size) {
        int i, j;
        for (i = 0; i < size - 1; i++)

            // Last i elements are already in place
            for (j = 0; j < size - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    SWAP_INT(arr[j], arr[j + 1]);
    }
}