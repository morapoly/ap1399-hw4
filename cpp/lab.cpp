#include "lab.h"
#include "course.h"
#include "student.h"
#include "prof.h"


Lab::Lab() : ER(){
    report = 0;
    activities = 0;
    final_exam = 0;
}

Lab::Lab(Course *Course, Student *Student, Prof *Professor, int Weight) : ER()
{
    course = Course;
    professor = Professor;
    student = Student;
    weight = Weight;
}

void Lab::scoring(float Report,float Activities,float finalExam,int Absences) {
    report = Report;
    final_exam = finalExam;
    activities = Activities;
    absences = Absences;
}

float Lab::calculate_final()
{
    final = (10*final_exam + 8*report + 2*activities)/20.00;
    passed = final > 10.00;
    return this->final;
}
