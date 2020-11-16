#include "er.h"

ER::ER(){
    course = nullptr;
    professor = nullptr;
    student = nullptr;
}

ER::~ER(){

}

float ER::calculate_final()
{
    return this->final;
}

void ER::scoring(float, float, float, int Absences)
{
    absences = Absences;
}