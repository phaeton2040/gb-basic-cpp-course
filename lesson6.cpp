#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

#include "ArrayFunctions.h"
#include "ArrayFunctions.hpp"

using namespace std;

void FillArray(int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = pow(2, i);
    }
}

void Task1() {
    size_t size;

    cout << "Please enter array size: ";
    cin >> size;

    int *p = new(nothrow) int[size];

    if (p != nullptr) {
        FillArray(p, size);
        PrintArray(p, size, ", ");
    } else {
        cout << "Error while allocating memory" << endl;
    }
}

// Было бы неплохо на разборе ДЗ прокомментировать этот момент. Функция InitMatrix работает только если указатель на указатель передать по ссылке
// Не понятно почему так происходит
void InitMatrix(int **&ptr, const int size) {
    ptr = new(nothrow) int *[size];

    if (ptr != nullptr) {
        for (int i = 0; i < size; i++) {
            ptr[i] = new int[size];
        }
    } else {
        cout << "Error allocating memory" << endl;
    }
}

void Task2() {
    const size_t SIZE{4};

    int **ptr;
    InitMatrix(ptr, SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ptr[i][j] = rand() % 10;
        }
    }

    for (int k = 0; k < SIZE; k++) {
        PrintArray(ptr[k], SIZE);
    }

    // Release memory
    for (int p = 0; p < SIZE; p++) {
        delete[] ptr[p];
    }

    delete[] ptr;
}

vector<string> Task3() {
    string str1 = "to be, or not to be, that is the question: \n"
                  "Whether 'tis nobler in the mind to suffer The slings and arrows of outrageous fortune,\n"
                  "Or to take arms against a sea of troubles And by opposing end them.\n"
                  "To die—to sleep, No more; and by a sleep to say we end\n"
                  "The heart-ache and the thousand natural shocks\n"
                  "That flesh is heir to: 'tis a consummation Devoutly to be wish'd.\n"
                  "To die, to sleep; To sleep, perchance to dream—ay, there's the rub:\n"
                  "For in that sleep of death what dreams may come,\n"
                  "When we have shuffled off this mortal coil,\n"
                  "Must give us pause—there's the respect\n"
                  "That makes calamity of so long life.\n"
                  "For who would bear the whips and scorns of time,\n"
                  "Th'oppressor's wrong, the proud man's contumely,\n"
                  "The pangs of dispriz'd love, the law's delay,\n";
    string str2 = "The insolence of office, and the spurns\n"
                  "That patient merit of th'unworthy takes,\n"
                  "When he himself might his quietus make\n"
                  "With a bare bodkin? Who would fardels bear,\n"
                  "To grunt and sweat under a weary life,\n"
                  "But that the dread of something after death,\n"
                  "The undiscovere'd country, from whose bourn\n"
                  "No traveller returns, puzzles the will,\n"
                  "And makes us rather bear those ills we have Than fly to others that we know not of?\n"
                  "Thus conscience doth make cowards of us all,\n"
                  "And thus the native hue of resolution\n"
                  "Is sicklied o'er with the pale cast of thought,\n"
                  "And enterprises of great pith and moment\n"
                  "With this regard their currents turn awry\n"
                  "And lose the name of action.\n";

    string fileName1, fileName2;

    cout << "Please enter the 1st filename: ";
    cin >> fileName1;

    cout << "Please enter the 2nd filename: ";
    cin >> fileName2;

    ofstream file1, file2;

    file1.open(fileName1 + ".txt");
    file2.open(fileName2 + ".txt");

    if (file1.is_open()) {
        file1 << str1 << endl;
    }

    if (file2.is_open()) {
        file2 << str2 << endl;
    }

    file1.close();
    file2.close();

    return vector<string>{fileName1 + ".txt", fileName2 + ".txt"};
}

void Task4(string fileName1, string fileName2) {
    string mergedFileName;
    cout << "Please enter the 3rd filename: ";
    cin >> mergedFileName;

    ofstream mergedFile;
    ifstream file1(fileName1);
    ifstream file2(fileName2);

    mergedFile.open(mergedFileName + ".txt");

    if (mergedFile.is_open()) {
        string line;

        if (file1.is_open()) {
            while (!file1.eof()) {
                getline(file1, line);
                mergedFile << line << endl;
                cout << line << endl;
            }

            file1.close();
        }

        if (file2.is_open()) {
            while (!file2.eof()) {
                getline(file2, line);
                mergedFile << line << endl;
                cout << line << endl;
            }

            file2.close();
        }

        mergedFile.close();
    }
}

void Task5() {
    string fileName;
    cout << "Please enter the filename to search the string in: ";
    cin >> fileName;

    ifstream fin(fileName);

    if (!fin.is_open()) {
        cout << "File not found" << endl;
        return;
    }

    string search;
    cout << "Please enter string to search: ";
    cin >> search;

    string line;
    int lineNumber = 0;
    while (!fin.eof()) {
        std::getline(fin, line);
        lineNumber++;
        auto pos = line.find(search);
        if (pos != string::npos) {
            cout << "The string " << search << " found in " << fileName << " at the line number " << to_string(lineNumber)
                 << " at position " << to_string(pos);
            fin.close();
            return;
        }
    }

    cout << "The given search string is not find in the specified file" << endl;

    fin.close();
}

int main() {
    Task1();
    Task2();
    auto files = Task3();
    Task4(files[0], files[1]);
    Task5();
}