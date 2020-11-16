#ifndef PROF_H
#define PROF_H

#include "person.h"
#include <string>

class Prof : public Person
{
    public:
    Prof();
    Prof(std::string first_name,std::string last_name,int id);
    ~Prof() = default;
    float get_mean() override;  // Each of professor's courses has mean. This function returns mean of those means.
};

#endif

