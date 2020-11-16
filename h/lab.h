#ifndef LAB_H
#define LAB_H

#include "er.h"

class Course;
class Student;
class Prof;

class Lab : public ER
{
    public:
    Lab();
    ~Lab() = default;
    Lab(Course*,Student*,Prof*,int wight);
    float calculate_final() override;  // 10 points for final exam,8 points for report,2 points for activies
    void scoring(float report,float activities,float final_exam,int absences) override;
    float report;  // score of student's lab reports
    float activities;   // score of student's activities in class
    float final_exam;
};

#endif