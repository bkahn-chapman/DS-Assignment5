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

//printFaculty
