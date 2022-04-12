#include <iostream>

bool isPrimary(int Number) {
    if ((Number % 2) == 0 ) return false;

    for (size_t i = 3; i < Number; i += 2) {
        if (Number % i == 0) return false;
    }

    return true;
}
bool isLeap(int Year) {
    if (Year < 1 || Year > 3000) {
        throw std::invalid_argument("Year must be between 1 and 3000");
    }

    return (Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
}
