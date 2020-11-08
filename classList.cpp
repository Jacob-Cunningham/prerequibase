#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


bool isIn(vector<string> list, string a){
    bool isIn = false;
    for (int i = 0; i < list.size(); i ++){
        if (list.at(i) == a){
            isIn = true;
        }
    }
    return isIn;
}

void checkForClassesToTake(vector<vector<string>>* classList, vector<string> completedClasses){

    cout << "You can take: ";
    for(int i = 0; i < classList->size(); i ++){
        bool qualified = true;
        //if class has not been completed
        if(!isIn(completedClasses, classList->at(i).at(0))){
            //for classList->at(i)'s prerequisites{
                //if !(isIn(completedClasses, classList->at(i)'s prerequisite)){
                    //qualified = false;
                
        }
        if (qualified){
            cout << classList->at(i).at(0) << " ";
        }
    }
    cout << endl;
}


vector<string> splitLine(string inputLine, char splitChar) {

    vector<string> tempVector;
    string tempString = inputLine;
    int findIndex = 0;

    while(tempString.find(splitChar) != string::npos) {
        findIndex = tempString.find(splitChar);
        tempVector.push_back(tempString.substr(0, findIndex));
        tempString.replace(0, findIndex + 1, "");
    }

    return tempVector;
}

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
        finalVector.push_back(splitLine(currentClass, ','));
        currentClass = nextClass;
        getline(classList, nextClass);
    }
    finalVector.push_back(splitLine(currentClass, ',')); //the while loop prints all but the last item, this corrects that
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

    cout << "Hello fellow Computer Science Student at UCR" << endl;
    cout << "Our application keeps track of all of the classes" << endl;
    cout << "required for your major and their prerequisites." << endl << endl;

    cout << "Enter the classes you have completed, and the program will keep track" << endl;
    cout << "of them to determine which classes you are qualified to take." << endl;

    cout << "If you have any other classes that you would like to complete," << endl;
    cout << "feel free to add them and any prerequisites for taking the class." << endl;


    while(1){
        cout << "enter a command. Type help for a list of the commands" << endl;
        cin >> command;

        if (command == "help"){
            cout << "Commands are addClassToList, printClasses, addCompletedClasses, and whatClassesCanITake" << endl;
        }
        else if (command == "addClassToList"){

            saveClassInFile();
            classList = makeClassVector();
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
            checkForClassesToTake(&classList, completedClasses);
        }
        else{
            cout << "not a valid command. " << endl;
        }
        cout << endl;
    }

    
   return 0;
}

