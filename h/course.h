#ifndef COURSE_H
#define COURSE_H

#include <string>

class ER;
class Theorical;
class Lab;
class Person;
class Student;
class Prof;

class Course
{
    public:
    Course();
    ~Course();
    Course(std::string name,int weight,bool theorical);
    Course(Prof* profesor,std::string name,int weight,bool theorical);
    Course(Prof* profesor,Student* student,std::string name,int weight,bool theorical);
    bool operator<(const Course&); // comparing population of two course
    bool operator=(const Course&);  // comparing population of two course
    /* You can add or remove students to course by two below functions.
    Obviously you should give the function the student you want to add or remove and also a Theorical/Lab.
    If Theorical/Lab is blank and does not belong to student,it must belong.
    The last input to function is an integer number which could be one or zero.
    1 for adding student to class and 0 for removing student from class.
    Note: In these functions you must set all associated pointers which defined in associated classes.
    */
    void operator()(Student&,Theorical&,int);  
    void operator()(Student&,Lab&,int);
    float max(); // returm max score in this course
    float average(); // return average of class
    std::string name;  // name of course
    int weight;     // weight of course
    bool theorical;  // this course is lab or theorical?
    Student** students;   // a set of pointers which point to course students
    Prof* professor;      // points to course professor
    int population{};    // number of class students
    ER** educational_reports;   // a set of pointers which point to students ERs.
};

#endif