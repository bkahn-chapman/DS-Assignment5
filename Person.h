#include <iostream>
using namespace std;

class Person
{
  public:
    int m_id;
    string m_name;
    string m_level;

    int getid();
    void setid(int id);
    string getname();
    void setname(string name);
    string getlevel();
    void setlevel(string level);
};
