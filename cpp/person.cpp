#include "person.h"
#include <iostream>

Person::Person(){
    courses = nullptr;
    n_classes = 0;
}

Person::~Person(){
    delete courses;
}

float Person::get_mean(){
    return 0;
}