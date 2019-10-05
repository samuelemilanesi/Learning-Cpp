#include <iostream>
//declare some functions from std library in order to use them by name
using std::cout; using std::cin; using std::endl; using std::string;
/* ! it's better than use the whole namespace "using namespace std" because
one can create conflicts with existing function in the namespace*/

int main() {

    string first_name; //string variable in which store the first name
    unsigned age;
    //require the name from the user
    cout << "Enter your first name: "<<endl;
    cin >> first_name;
    cout << "Enter your age: "<<endl;
    cin >> age;

    cout << "You are "<< first_name << " and you are "<< age <<" years old"<<endl;

    return 0;
}