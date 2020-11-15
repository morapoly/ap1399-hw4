class Person;

class Prof : public Person
{
    public:
    Prof();
    Prof(std::string first_name,std::string last_name,int id);
    ~Prof();
    float get_mean();  // Each of professor's courses has mean. This function returns mean of those means.
};