#include "theorical.h"
#include "course.h"
#include "er.h"
#include "student.h"
#include "prof.h"

Theorical::Theorical() : ER(){
    mid_term = 0;
    final_exam = 0;
    homeWorks = 0;
}

Theorical::Theorical(Course *Course, Student *Student, Prof *Professor, int Weight) : ER()
{
    course = Course;
    professor = Professor;
    student = Student;
    weight = Weight;
}

void Theorical::scoring(float midTerm,float finalExam,float HomeWorks,int Absences) {
    mid_term = midTerm;
    final_exam = finalExam;
    homeWorks = HomeWorks;
    absences = Absences;
}

float Theorical::calculate_final(){
    final = (8*final_exam + 8*mid_term + 4*homeWorks)/20.00;
    passed = final > 10.00;
    return this->final;
}