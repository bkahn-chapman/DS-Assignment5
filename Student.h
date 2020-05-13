#include <iostream>
#include <string>

using namespace std;

class Student
{
  public:
    string name;
    int id;
    string level;
    string major; //ask if major and department can be consolidated (string area in Person.h)
    double gpa;
    int advisor;

    Student();
    Student(string nameIn, int idIn, string levelIn, string majorIn, double gpaIn, int advisorID);
    ~Student();
    //ask what we will need to be comparing (just GPA, or multiple?)
    bool isEqual(Student s);
    bool isGreaterThan(Student s);
    bool isLessThan(Student s);

    int getid();
    void setid(int idIn);
    string getname();
    void setname(string nameIn);
    string getlevel();
    void setlevel(string levelIn);
    string getmajor();
    void setmajor(string major);
    double getgpa();
    void setgpa(double gpa);
    int getadvisor();
    void setadvisor(int advisor);
    void printStudent();
};
