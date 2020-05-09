#include "Person.h"

class Student
{
  public:
    string m_major; //ask if major and department can be consolidated (string area in Person.h)
    double m_gpa;
    int m_advisor;

    //ask what we will need to be comparing (just GPA, or multiple?)
    bool isEqual(Student s);
    bool isGreaterThan(Student s);
    bool isLessThan(Student s);

    string getmajor();
    void setmajor(string major);
    double getgpa();
    void setgpa(double gpa);
    int getadvisor();
    void setadvisor(int advisor);
};
