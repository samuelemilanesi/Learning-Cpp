#include <iostream>
using namespace std;
/*
Example of usage of a struct: collect the values inserted and
 display the mean of grades
*/
const unsigned numOfGrades=6; //define a costant value for the number of
//grades that every student must have

//define a struct that contains the infos about a Student
struct Student{
    string username;
    unsigned IDnumber;
    unsigned grades[numOfGrades];
};

int main() {

    Student sam;
    sam.username="Sam";
    sam.IDnumber=1000;

    cout<< "Hi, " << sam.username <<" insert your grades:"<<endl;

    unsigned sum=0;
    bool err=false; //error checking
    for(unsigned g: sam.grades){ //range-for loop
        cout<<"insert grade: "<<endl;
        cin >> g;
        if(!cin){
            cout<<"Error: invalid value"<<endl;
            err=true;
            break;
            }
        sum+=g;
    }
    if(!err) {
        float mean = (float) sum / numOfGrades;

        cout << "The mean of your grades is: " << mean << endl;
    }



    return 0;
}