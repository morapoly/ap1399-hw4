#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Person;
class Course;
class Student;
class Prof;
class Theorical;
class Lab;


class Student : public Person
{
    public:
    Student();
    Student(std::string first_name,std::string last_name,int id,float mean_score,int passed);
    ~Student();
    float get_mean();  // It returns student's mean score
    void operator++();  // It adds a unit to student's semestes
    bool operator!=(const Student&);  
 
    int semesters{1};
    float mean_score;
    int passed{};             // sum of weights of passed courses
    Theorical** theoric_er;   // a set of poinetrs which point to active theorical courses of student
    int n_theo{};            // number of active theorical courses of student
    Lab** lab_er;       // a set of poinetrs which point to active labs of student
    int n_lab{};        // number of active labs of student
};

#endif