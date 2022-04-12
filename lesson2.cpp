#include <iostream>

const int FIELD_SIZE = 9;

/** Задание 2
 * Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики
 * */
enum TicTacToeSymbols { ZERO = 0, CROSS = 1, NONE = 2 };

/** Задание 4
 * Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами
 * */
typedef struct {
    TicTacToeSymbols Cells[FIELD_SIZE]{
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE,
            TicTacToeSymbols::NONE
    };
    int RoundsLeft{9};
} TicTacToeField;

/**
 * Задание 5
 * Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении
 * */
union CurrentValue {
    int i;
    char c;
    float f;
};
struct CurrentValueType {
    int isInt : 1;
    int isChar : 1;
    int isFloat : 1;
};

std::string GetCurrentValueType(CurrentValueType t);

int lesson2() {

    /** Задание 1
     * Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double)
     * */
    short int a = 5;
    int b = 100;
    char c = 'B';
    long long d = 1000'000'000LL;
    float f = 36.f;
    double dd = 54.6f;

    printf("Variables:\nshort int a = %u,\nint b = %u,\nchar c = %c\nlong long d = %f\nfloat f = %f, double dd = %f\n", a, b, c, d, f, dd);

    /** Задание 3
     * Создать массив, способный содержать значения такого перечисления и инициализировать его
     * */
    TicTacToeSymbols symbols[FIELD_SIZE];

    srand(0);
    for (int i = 0; i < FIELD_SIZE; i++) {
        int randomValue = rand() % 3;
        *(symbols + i) = TicTacToeSymbols(randomValue);
    }

    std::cout << "Array: ";
    for (int i = 0; i < FIELD_SIZE; i++) {
        printf("%d, ", symbols[i]);
    }

    std::cout << std::endl;
    std::cout << "--------------" << std::endl;

    /**
     * Задание 4 (продолжение)
     * */
    TicTacToeField Field;
    printf("Rounds left: %d\n", Field.RoundsLeft);
    printf("Cells size: %d\n", sizeof(Field.Cells) / sizeof(*Field.Cells));


    std::cout << std::endl;
    std::cout << "--------------" << std::endl;
    /**
     * Задание 5 (продолжение)
     * */
    CurrentValue x{5};
    CurrentValueType t{1, 0, 0};

    printf("Current value - %d of type %s\n", x, GetCurrentValueType(t).c_str());

    x.f = 36.5f;
    t.isChar = 0;
    t.isInt = 0;
    t.isFloat = 1;

    printf("Current value - %f of type %s\n", x.f, GetCurrentValueType(t).c_str());

    x.c = 'c';
    t.isChar = 1;
    t.isInt = 0;
    t.isFloat = 0;

    printf("Current value - %c of type %s\n", x.c, GetCurrentValueType(t).c_str());

    return 0;
}

std::string GetCurrentValueType(CurrentValueType t) {
    if (t.isFloat) {
        return "Float";
    }

    if (t.isInt) {
        return "Integer";
    }

    if (t.isChar) {
        return "Char";
    }

    return "Unknown";
}
