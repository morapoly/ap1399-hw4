#ifndef THEORICAL_H
#define THEORICAL_H

#include "er.h"

class Course;
class Student;
class Prof;

class Theorical : public ER
{
    public:
    Theorical();
    ~Theorical() = default;
    Theorical(Course*,Student*,Prof*,int wight);
    float calculate_final() override; // 8 points for final exam,8 points for mid_term,4 points for homeWorks
    void scoring(float mid_term,float final_exam,float homeWorks,int absences) override;
    float mid_term;
    float final_exam;
    float homeWorks;
};

#endif