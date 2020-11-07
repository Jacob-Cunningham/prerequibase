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
        findIndex = tempString.find(',');
        tempVector.push_back(tempString.substr(0, findIndex));
        tempString.replace(0, findIndex + 1, "");
    }

    return tempVector;
}

void printAllClasses(vector<vector<string>> classes){
    for (int i = 0; i < classes.size(); i ++){
        for (int j = 0; j < classes.at(i).size(); j ++){
            //says the class then prerequisites
            if (j == 0){
                cout << "Class: " << classes.at(i).at(j) << "Prerequisities: ";
            }
            else{
                cout << classes.at(i).at(j) << " ";
            }
        }
    }
    cout << endl;
}

vector<vector<string>> makeClassVector(){
    vector<vector<string>> finalVector;
    string currentClass;
    ifstream classList;
    classList.open("listOfClasses.txt", ios::in | ios::app); //opens text file and allows input to program
    getline(classList, currentClass);

    while (currentClass != "end") {
        finalVector.push_back(splitLine(currentClass));
        getline(classList, currentClass);
    }
    classList.close();
    return finalVector;
}

int main () {
    vector<vector<string>> classList;
    classList = makeClassVector();
    cout << classList.at(0).at(0) << endl;


    return 0;
}