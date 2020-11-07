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

void printAllClasses(vector<vector<string>>* classes){
    for (int i = 0; i < classes->size(); i ++){
        cout << "Class: " << classes->at(i).at(0) << " Prerequisities: " << classes->at(i).at(1) << endl;
    }
    cout << endl;
}

void printCompletedClasses(vector<string>* completedClasses){
    cout << "the classes you have completed are: ";
    for(int i = 0; i < completedClasses->size(); i ++){
        cout << completedClasses->at(i);
    }
    cout << endl;
}

void addCompletedClass(string cls, vector<vector<string>> *classList, vector<string>* completedClasses){
    int index = 0;
    bool isInClassList = false;
    while (index < classList->size()){
        if (classList->at(index).at(0) == cls){
            isInClassList = true;
        }
        index ++;
    }

    if (isInClassList){
        cout << "added" << endl;
        completedClasses->push_back(cls);
    }
    else{
        cout << "Class not found" << endl;
    }
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
    vector<string> completedClasses;
    classList = makeClassVector();
    string command;
    string input;

    while(1){
        cout << "enter a command. Type help for a list of the commands" << endl;
        cin >> command;
        if (command == "help"){
            cout << "Commands are printClasses, addCompletedClasses, and WhatClassesCanITake" << endl;
        }
        else if (command == "printClasses"){
            printAllClasses(&classList);
        }
        else if (command == "addCompletedClasses"){
            cout << "enter a class name" << endl;
            cin >> input;
            addCompletedClass(input, &classList, &completedClasses);
            printCompletedClasses(&completedClasses);
            cout << endl;
        }
        else if (command == "WhatClassesCanITake"){
            //TODO, Create a function that goes through every class and checks if all of its prerequisites
            //are in completedClasses. If they are, then print the class
        }
        else{
            cout << "not a valid command. " << endl;
        }
        cout << endl;
    }
    

   return 0;
}