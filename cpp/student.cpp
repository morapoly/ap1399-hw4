#include "student.h"

Student::Student() : Person(){
    theoric_er = nullptr;
    lab_er = nullptr;
    n_theo = 0;
    n_lab = 0;
}

Student::~Student()
{
    this->~Person();
}

Student::Student(std::string firstName,std::string lastName,int Id,float meanScore,int Passed) : Person(){
    first_name = firstName;
    last_name = lastName;
    id = Id;
    mean_score = meanScore;
    passed = Passed;
    theoric_er = nullptr;
    lab_er = nullptr;
    n_theo = 0;
    n_lab = 0;  
}

void Student::operator++()
{
    semesters++;
}

bool Student::operator!=(const Student &inputStudent)
{
    return (id != inputStudent.id);
}

float Student::get_mean(){
    return mean_score;
}