#include <iostream>
extern int a, b, c, d;

int lesson3() {
    /** Задание 1(4) */
    std::cout << "Task 1" << std::endl;

    float result = a * (b + (float(c) / float(d)));

    std::cout << "Result of a * (b + (c / d)): " << result << std::endl; // 15.4286

    /** Задание 2 */
    std::cout << "Task 2" << std::endl;

    int x;
    const int CheckerNumber = 21;

    std::cout << "Please enter the number X: ";
    std::cin >> x;

    if (x <= CheckerNumber) {
        std::cout << "The difference between X and " << CheckerNumber << " is " << CheckerNumber - x << std::endl;
    } else {
        std::cout << "The doubled difference between X and 21 is " << 2 * (x - CheckerNumber) << std::endl;
    }

    /** Задание 3 */
    std::cout << "Task 3" << std::endl;
    int arr[3][3][3] = {
            {
                    {
                        1,2,3
                        }, {
                        4,5,6
                        }, {
                        7,8,9
                    }
                },
            {
                    {
                        10,11,12
                        }, {
                        13,14,15
                        }, {
                        16,17,18
                    }
                },
            {
                    {
                        19,20,21
                        }, {
                        22,23,24
                        }, {
                        25,26,27
                    }
            }
    };
    int* ptr = &arr[1][1][1];

    std::cout << "Cube center value is: " << *ptr << std::endl;
}