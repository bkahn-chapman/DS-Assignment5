#include "Person.h"

int Person::getid()
{
  return m_id;
}

void Person::setid(int id)
{
  m_id = id;
}

string Person::getname()
{
  return m_name;
}

void Person::setname(string name)
{
  m_name = name;
}

string Person::getlevel()
{
  return m_level;
}

void Person::setlevel(string level)
{
  m_level = level;
}
