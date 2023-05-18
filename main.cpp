#include <iostream>
#include <list>

using namespace std;

double calculator(list<char>array, int numOfClass) {
    //This class takes the array of class grades and total number of classes and outputs the GPA
    //It does it by starting at the back of the array, added numbers together based on the letter in the array,
    // removing the last element in the array, repeat untill array is empty, then divides the number by total number of classes
    double gpa = 0;
    bool fail = false;
    for(int i = 0; i < numOfClass; i++){
        if( array.back() == 'A'){
            gpa += 4.0;
        }
        else if(array.back() == 'B'){
            gpa += 3.0;
        }
        else if(array.back() == 'C'){
            gpa += 2.0;
        }
        else if(array.back() == 'D'){
            gpa += 1.0;
        }
        else if(array.back() == 'F'){
            fail = true;
        }
        else{
           cout << "Error, Please enter a valid input." << endl;
           exit(1);
        }
        array.pop_back();
    }
    if(fail){
        cout << "With your current grades you will not receive all credits. " << endl;
    }
    gpa /= numOfClass;
    return gpa;
}

void gpaCalc(){
    //this class ask the user for the number of classes and the letter grade in each class
    //then it calls calculator and prints out the result
    int numOfClass;
    char grade;
    cout << "How many classes do you want to enter: " << endl;
    cin >> numOfClass;
    list<char> array = {};
    for(int i = 0; i < numOfClass; i++){
        cout << "What was the grade of class " << i+1 << ": (A, B, C, D, F)" << endl;
        cin >> grade;
        array.push_back(grade);
    }
    double clac = calculator(array, numOfClass);
    cout << "Your GPA is " << clac << endl;
}

void finalGrade(){
    //this code asks for the users current grade, weight of final, and there goal grade, then it calculates what they need to get in order to achieve there goal and
    // prints the result
    double problem1;
    double problem2;
    double problem3;
    double problem4;
    double grade;
    double weight;
    double want;
    cout << "What is your current grade (percentage): " << endl;
    cin >> grade;
    cout << "How much is your final worth (percentage): " << endl;
    cin >> weight;
    cout << "What grade do you want in the class (percentage): " << endl;
    cin >> want;
    problem1 = (1 - (weight/100));
    problem2 = problem1 * grade;
    problem3 = want - problem2;
    problem4 = problem3 / (weight/100);
    cout << "You need a " << problem4 << "% on your final to get your goal grade" << endl;
}

int main() {
    //this asks the user if they want to calculate there GPA or Final grade
    //it then calls either of the two classes
    //it will loop untill the user asks to stop
    int answer;
    while(true) {
        cout << "Please enter 1 to calculate your GPA and 2 to calculate your final grade: (enter anything else to exit)" << endl;
        cin >> answer;
        if (answer == 1) {
            gpaCalc();
        } else if (answer == 2) {
            finalGrade();
        }
        else{
            break;
        }
    }
    return 0;
}
