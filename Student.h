#include "Person.h"

class Student
{
  public:
    string major; //ask if major and department can be consolidated (string area in Person.h)
    double gpa;
    int advisor;

    //ask what we will need to be comparing (just GPA, or multiple?)
    bool isEqual(Student s);
    bool isGreaterThan(Student s);
    bool isLessThan(Student s);
};
