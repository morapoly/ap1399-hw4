#ifndef ER_H
#define ER_H

class Course;
class Prof;
class Student;

class ER
{
    public:
    ER();
    ~ER() = default;
    virtual float calculate_final();  // function which calculate final score
    virtual void scoring(float,float,float,int);  // function which score parameters
    Course* course;   
    Prof* professor;
    Student* student;  
    float final{};        // final changed to Final !!!!
    bool passed{false};   // student passed the course?
    int weight;           // weight of course
    int absences{};       // number of student's absences
};

#endif