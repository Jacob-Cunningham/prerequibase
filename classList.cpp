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
        findIndex = tempString.find(',', findIndex) - 1;
        tempVector.push_back(tempString.substr(0, findIndex))
        tempString.replace(0, findIndex + 1);
    }

}

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