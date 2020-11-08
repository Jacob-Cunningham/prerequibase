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

//needs to be changed
void printAllClasses(vector<vector<string>>* classes){
    for (int i = 0; i < classes->size(); i ++){
        if(classes->at(i).at(1).size() < 2){
            cout << "Class: " << classes->at(i).at(0) << " Prerequisities: None" << endl;
        }
        else{
            cout << "Class: " << classes->at(i).at(0) << " Prerequisities: " << classes->at(i).at(1) << endl;
        }
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

//needs to be changed 
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
    string nextClass;
    ifstream classList;
    classList.open("listOfClasses.txt", ios::in | ios::app); //opens text file and allows input to program
    getline(classList, currentClass);
    getline(classList, nextClass);

    while (currentClass != nextClass) {
        finalVector.push_back(splitLine(currentClass));
        currentClass = nextClass;
        getline(classList, nextClass);
    }
    finalVector.push_back(splitLine(currentClass)); //the while loop prints all but the last item, this corrects that
    classList.close();
    return finalVector;
}

void saveClassInFile() {
    string userString;
    ofstream classList;
    classList.open("listOfClasses.txt", ios::out | ios::app);
    getline(cin, userString); //clear the input buffer
    cout << "Class name?" << endl;
    getline(cin, userString);
    classList << userString + ',';
    cout << "Enter any prerequisite classes one at a time. Type done to finish" << endl;
    getline(cin, userString);
    if (userString == "done") {
        classList << ',';
    }
    while(userString != "done") {
        classList << userString + ' ';
        getline(cin, userString);
    }
    classList << ',' << endl;
    cout << "Thank you" << endl;
    
    classList.close();
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
            cout << "Commands are addClassToList, printClasses, addCompletedClasses, and whatClassesCanITake" << endl;
        }
        else if (command == "addClassToList"){
            saveClassInFile();
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
        else if (command == "whatClassesCanITake"){
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

