#include "prof.h"
#include "course.h"

Prof::Prof() : Person() {

}

Prof::Prof(std::string firstName,std::string lastName,int Id) : Person(){
    first_name = firstName;
    last_name = lastName;
    id = Id;
}

float Prof::get_mean()
{
    float Sum{};
    for (int i{}; i < n_classes; i++){
        Sum += this->courses[i]->average();
    }
    return Sum / n_classes;
}