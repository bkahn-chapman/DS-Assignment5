#include "Student.h"
#include <string>

using namespace std;
//check if these are just comparing GPA or more
Student::Student()
{

}

Student::Student(string nameIn, int idIn, string levelIn, string majorIn, double gpaIn, int advisorIn)
{
  name = nameIn;
  id = idIn;
  level = levelIn;
  major = majorIn;
  gpa = gpaIn;
  advisor = advisorIn;
}

Student::~Student()
{

}

int Student::getid()
{
  return id;
}

void Student::setid(int idIn)
{
  id = idIn;
}

string Student::getname()
{
  return name;
}

void Student::setname(string nameIn)
{
  name = nameIn;
}

string Student::getlevel()
{
  return level;
}

void Student::setlevel(string levelIn)
{
  level = levelIn;
}
bool Student::isEqual(Student s)
{
  if(s.getgpa() == gpa)
  {
    return true;
  }
}

bool Student::isGreaterThan(Student s)
{
  if(s.getgpa() < gpa)
  {
    return true;
  }
}

bool Student::isLessThan(Student s)
{
  if(s.getgpa() > gpa)
  {
    return true;
  }
}

string Student::getmajor()
{
  return major;
}

void Student::setmajor(string majorIn)
{
  major = majorIn;
}

double Student::getgpa()
{
  return gpa;
}

void Student::setgpa(double gpaIn)
{
  gpa = gpaIn;
}

int Student::getadvisor()
{
  return advisor;
}

void Student::setadvisor(int advisorIn)
{
  advisor = advisorIn;
}
void Student::printStudent()
{
  cout << "Student name: " << name << endl;
  cout << "Student ID: " << id << endl;
  cout << "Student level: " << level << endl;
  cout << "Student major: " << major << endl;
  cout << "Student gpa: " << gpa << endl;
  cout << "Student advisor: " << advisor << endl;
  cout << endl;
}
