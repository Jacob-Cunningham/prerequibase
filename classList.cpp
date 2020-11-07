#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitLine(string inputLine) {
    vector<string> tempVector;
    string tempString = inputLine;
    int findIndex = 0;

    while(tempString.find(',') != string::npos) {
        findIndex = tempString.find(',', findIndex);
        tempVector.push_back(tempString.substr(0, findIndex));
        tempString.replace(0, findIndex, "");
    }

    return tempVector;
}

int main () {
    string currentClass;
    ifstream classList;
    classList.open("listOfClasses.txt", ios::in | ios::app);
    getline(classList, currentClass);
// this working?
    while (currentClass != "end") {
        cout << splitLine(currentClass).at(0) << endl;
        getline(classList, currentClass);
    }
    classList.close();



   return 0;

    return 0;
}
