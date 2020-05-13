#include "Faculty.h"

Faculty::Faculty()
{

}

Faculty::Faculty(string nameIn, int idIn, string levelIn, string departmentIn)
{
  name = nameIn;
  id = idIn;
  level = levelIn;
  department = departmentIn;
}
Faculty::~Faculty()
{

}

int Faculty::getid()
{
  return id;
}

void Faculty::setid(int idIn)
{
  id = idIn;
}

string Faculty::getname()
{
  return name;
}

void Faculty::setname(string nameIn)
{
  name = nameIn;
}

string Faculty::getlevel()
{
  return level;
}

void Faculty::setlevel(string levelIn)
{
  level = levelIn;
}

string Faculty::getdep()
{
  return department;
}

void Faculty::setdep(string dep)
{
  department = dep;
}

void Faculty::printFaculty()
{
  cout << "Faculty name: " << name << endl;
  cout << "Faculty ID: " << id << endl;
  cout << "Faculty level: " << level << endl;
  cout << "Faculty department: " << department << endl;
  cout << "List of Advisee's ID numbers: " << endl;
  advisees->printList();
  cout << endl;
}
