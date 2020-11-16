#include "course.h"
#include "er.h"
#include "theorical.h"
#include "lab.h"
#include "student.h"
#include "person.h"
#include "prof.h"

Course::Course()
{
    students = nullptr;
    professor = nullptr;
    educational_reports = nullptr;
}

Course::~Course()
{
    delete students;
    delete educational_reports;
}

Course::Course(std::string Name, int Weight, bool Theorical)
{
    name = Name;
    weight = Weight;
    theorical = Theorical;
    students = nullptr;
    professor = nullptr;
    educational_reports = nullptr;
}

Course::Course(Prof* Profesor,std::string Name,int Weight,bool Theorical){
    students = nullptr;
    educational_reports = nullptr;
    name = Name;
    weight = Weight;
    theorical = Theorical;
    professor = Profesor;

    Course **tempCourse{new Course *[professor->n_classes + 1] {}};
    tempCourse[professor->n_classes] = this;
    for (int i{}; i < professor->n_classes; i++)
    {
        tempCourse[i] = professor->courses[i];
    }
    professor->courses = tempCourse;
    professor->n_classes++;
}

Course::Course(Prof *Profesor, Student *student, std::string Name, int Weight, bool Theorical)
{
    educational_reports = nullptr;
    name = Name;
    weight = Weight;
    theorical = Theorical;
    professor = Profesor;

    //Copy prof's courses and adding new one
    Course **tempCourse{new Course *[professor->n_classes + 1] {}};
    tempCourse[professor->n_classes] = this;
    for (int i{}; i < professor->n_classes; i++)
    {
        tempCourse[i] = professor->courses[i];
    }
    professor->courses = tempCourse;
    professor->n_classes++;
    population++;

    students = new Student *[1] { student };

    //Copy student's courses and adding new one
    Course **auxCourse{new Course *[student->n_classes + 1] {}};
    auxCourse[student->n_classes] = this;
    for (int i = 0; i < student->n_classes; i++)
    {
        auxCourse[i] = student->courses[i];
    }
    student->courses = auxCourse;
    student->n_classes++;
}

void Course::operator()(Student& newStudent,Theorical& newTheorical,int AR){
    if (AR == 1)
    {
        //Copy students and adding new one
        Student **tempStudent{new Student *[population + 1] {}};
        tempStudent[population] = &newStudent;
        for (int i{}; i < population; i++)
        {
            tempStudent[i] = students[i];
        }
        students = tempStudent;

        //copy ER's and adding new one 
        ER **tempER{new ER *[population + 1] {}};
        tempER[population] = &newTheorical;
        for (int i{}; i < population; i++)
        {
            tempER[i] = educational_reports[i];
        }
        educational_reports = tempER;
        population++;

        //copy theoricals and adding new one
        Theorical **tempTheorical{new Theorical *[newStudent.n_theo + 1] {}};
        tempTheorical[newStudent.n_theo] = &newTheorical;
        for (int i{}; i < newStudent.n_theo; i++)
        {
            tempTheorical[i] = newStudent.theoric_er[i];
        }
        newStudent.theoric_er = tempTheorical;
        newStudent.n_theo++;
        
        newTheorical.course = this;
        newTheorical.weight = weight;
        newTheorical.professor = professor;
        newTheorical.student = &newStudent;

        
        //copy courses and adding new one 
        Course **tempCourse{new Course *[newStudent.n_classes + 1] {}};
        tempCourse[newStudent.n_classes] = this;
        for (int i{}; i < newStudent.n_classes; i++)
        {
            tempCourse[i] = newStudent.courses[i];
        }
        newStudent.courses = tempCourse;
        newStudent.n_classes++;
    }
    else
    {
        //copy students and removign the specific one
        Student **tempStudent{new Student *[this->population - 1] {}};
        for (int i{}, j{}; i < this->population; i++)
        {
            if (newStudent.id != this->students[i]->id)
            {
                tempStudent[j] = this->students[i];
                j++;
            }
        }
        this->students = tempStudent;

        //copy Er's and removign the specefic one ( theorical will be removed automaticaly)
        ER **tempER{new ER *[this->population - 1] {}};
        for (int i{}, j{}; i < this->population; i++)
        {
            if (&newTheorical != this->educational_reports[i])
            {
                tempER[j] = this->educational_reports[i];
                j++;
            }
        }
        this->educational_reports = tempER;
        this->population--;

        //copy courses and removing the specific one
        Course **tempCourse{new Course *[newStudent.n_classes - 1] {}};
        for (int i{}, j{}; i < newStudent.n_classes; i++)
        {
            if (this != newStudent.courses[i])
            {
                tempCourse[j] = newStudent.courses[i];
                j++;
            }
        }
        newStudent.courses = tempCourse;
        newStudent.n_classes--;
    }
}

void Course::operator()(Student &newStudent, Lab &newLab, int AR)
{
    if (AR == 1)
    {
        //copy students and adding new one
        Student **tempStudent{new Student *[this->population + 1] {}};
        tempStudent[population] = &newStudent;
        for (int i{}; i < population; i++)
        {
            tempStudent[i] = students[i];
        }
        students = tempStudent;

        //copy ER's and adding new one
        ER **tempER{new ER *[population + 1] {}};
        tempER[population] = &newLab;
        for (int i{}; i < population; i++)
        {
            tempER[i] = this->educational_reports[i];
        }
        educational_reports = tempER;
        population++;

        //copy labs and adding new one 
        Lab **tempLab{new Lab *[newStudent.n_lab + 1] {}};
        tempLab[newStudent.n_lab] = &newLab;
        for (int i{}; i < newStudent.n_lab; i++)
        {
            tempLab[i] = newStudent.lab_er[i];
        }
        newStudent.lab_er = tempLab;
        newStudent.n_lab++;
        delete tempLab;

        newLab.course = this;
        newLab.weight = this->weight;
        newLab.professor = this->professor;
        newLab.student = &newStudent;

        //copy courses and adding new one
        Course **tempCourse{new Course *[newStudent.n_classes + 1] {}};
        tempCourse[newStudent.n_classes] = this;
        for (int i{}; i < newStudent.n_classes; i++)
        {
            tempCourse[i] = newStudent.courses[i];
        }
        newStudent.courses = tempCourse;
        newStudent.n_classes++;
        delete tempCourse;
    }
    else
    {
        //copy students and removing the specific one
        Student **tempStudent{new Student *[population - 1] {}};
        for (int i{}, j{}; i < population; i++)
        {
            if (newStudent.id != students[i]->id)
            {
                tempStudent[j] = students[i];
                j++;
            }
        }
        students = tempStudent;

        //copy ER's and removing the specific one ( lab will be removed automatically )
        ER **tempER{new ER *[population - 1] {}};
        for (int i{}, j{}; i < population; i++)
        {
            if (&newLab != educational_reports[i])
            {
                tempER[j] = educational_reports[i];
                j++;
            }
        }
        educational_reports = tempER;
        population--;

        //copy courses and removing the specific one
        Course **tempCourse{new Course *[newStudent.n_classes - 1] {}};
        for (int  i{}, j{}; i < newStudent.n_classes; i++)
        {
            if (this != newStudent.courses[i])
            {
                tempCourse[j] = newStudent.courses[i];
                j++;
            }
        }
        newStudent.courses = tempCourse;
        newStudent.n_classes--;
    }
}

bool Course::operator<(const Course &inputCourse)
{
    return (population < inputCourse.population);
}

bool Course::operator=(const Course &inputCourse)
{
    return (population == inputCourse.population);
}

float Course::max()
{
    float Max{};
    for (int i{}; i < population; i++)
        if (educational_reports[i]->final > Max)
            Max = educational_reports[i]->final;
    return Max;
}

float Course::average()
{
    float Sum{};
    for (int i{}; i < population; i++)
        Sum += educational_reports[i]->final;
    return Sum/population;
}