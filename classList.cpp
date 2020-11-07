#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
    string currentClass;
    ifstream classList;
    classList.open("listOfClasses.txt", ios::in | ios::app);
    getline(classList, currentClass);

    while (currentClass != "end") {
        cout << currentClass << endl;
        getline(classList, currentClass);
    }
    classList.close();



   return 0;

    return 0;
}