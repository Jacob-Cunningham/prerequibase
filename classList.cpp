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

    cout << "Class name?" << endl;
    getline(cin, userString);
    classList << userString + ',';
    cout << "Enter any prerequisite classes one at a time. Type done to finish" << endl;
    getline(cin, userString);
    while(userString != "done") {
        classList << userString + ',';
        getline(cin, userString);
    }
    classList << endl;
    cout << "Thank you" << endl;
    
    classList.close();
}

int main () {
    vector<vector<string>> classList;
    classList = makeClassVector();
    cout << classList.at(2).at(0);

    return 0;
}