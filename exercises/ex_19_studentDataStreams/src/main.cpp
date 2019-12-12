#include <iostream>
#include <unordered_map>

#include "FileManager.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

typedef unordered_map<unsigned, StudentsData> students_type;

void add_students(const table_type &, students_type &);
void add_exams(const table_type &, students_type &);

int main()
{

    string filename_students = "lib/students.txt";
    string filename_exams = "lib/exams.txt";

    students_type students;

    FileManager FM;

    // parse students file
    table_type fields = FM.parse_file(filename_students);

    // add students to the map
    add_students(fields, students);

    // parse exams file
    fields = FM.parse_file(filename_exams);

    // add exams to the corresponding students, if they exist in the map
    add_exams(fields, students);

    // compute and print average of students' grades
    cout<<"here"<<endl;
    for(auto it=students.cbegin(); it!=students.cend(); ++it)
    {
        std::cout<< "Student ID: " << it->first <<endl;
        std::cout << "Student avarage: " << it->second.average_grade()<<std::endl;
        cout<< "------------------------------------------"<<endl;
    }
}

void add_students(const table_type &fields, students_type &students)
{
    for(auto it=fields.cbegin(); it!=fields.cend(); ++it)
    {
        unsigned ID((unsigned)std::stoi((*it)[0]));
        std::string name((*it)[1]);
        std::string last_name((*it)[2]);
        std::string birth((*it)[3]);
        students.insert(std::pair<unsigned,StudentsData>(ID, StudentsData(name,last_name,birth)));

    }
}

void add_exams(const table_type &fields, students_type &students)
{
    for(auto it=fields.cbegin(); it!=fields.cend(); ++it)
    {
        unsigned studentID((unsigned)std::stoi((*it)[0]));
        size_t courseID;((size_t)std::stoi((*it)[1]));
        std::string date((*it)[2]);
        unsigned grade((unsigned)std::stoi((*it)[3]));
        students_type::iterator stud=students.find(studentID);
        if(stud!=students.cend())
            stud->second.add_exam(Exam(courseID,date,grade));
        else
        {
            std::cerr<< "Student ID not present"<<std::endl;
        }
        
    }
}