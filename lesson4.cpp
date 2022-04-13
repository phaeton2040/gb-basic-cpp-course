#include <iostream>
#include "lesson4-functions-header.h"

using namespace std;

int main() {
    /** Задание 1 */
    int a, b;

    cout << "Please enter the number A: ";
    cin >> a;

    cout << "Please enter the number B: ";
    cin >> b;

    if (10 < (a + b) && (a + b) < 20) {
        cout << "True";
    } else {
        cout << "False";
    }

    cout << endl;

    /** Задание 2 */
    const int c1 = 2;
    const int c2 = 8;

    if ((c1 == 10 && c2 == 10) || c1 + c2 == 10) {
        cout << "True";
    } else {
        cout << "False";
    }

    cout << endl;

    /** Задание 3 */
    cout << "Your numbers: ";
    for (size_t i = 0; i < 50; i++) {
        if ((i % 2) == 0) continue;
        cout << i << ", ";
    }

    cout << endl;

    /** Задание 4 */
    int Num;
    cout << "Please enter the number to check if it's prime: ";

    cin >> Num;

    cout << "The entered number " << Num;
    if (isPrimary(Num)) {
        cout << " is prime";
    } else {
        cout << " is not prime";
    }

    cout << endl;

    /** Задание 5 */
    int Year;
    cout << "Please enter the year number between 1 and 3000: ";
    cin >> Year;

    try {
        if (isLeap(Year)) {
            cout << "The given year " << Year << " " << "is a leap year";
        } else {
            cout << "The given year " << Year << " " << "is NOT a leap year";
        }
    } catch (const std::invalid_argument &e) {
        cout << e.what();
    }
}