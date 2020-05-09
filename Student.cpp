#include "Student.h"

//check if these are just comparing GPA or more
bool Student::isEqual(Student s)
{
  if(s.getgpa() == m_gpa)
  {
    return true;
  }
}

bool Student::isGreaterThan(Student s)
{
  if(s.getgpa() < m_gpa)
  {
    return true;
  }
}

bool Student::isLessThan(Student s)
{
  if(s.getgpa() > m_gpa)
  {
    return true;
  }
}

string Student::getmajor()
{
  return m_major;
}

void Student::setmajor(string major)
{
  m_major = major;
}

double Student::getgpa()
{
  return m_gpa;
}

void Student::setgpa(double gpa)
{
  m_gpa = gpa;
}

int Student::getadvisor()
{
  return m_advisor;
}

void Student::setadvisor(int advisor)
{
  m_advisor = advisor;
}
