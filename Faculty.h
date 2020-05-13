#include "DoublyLinkedList.h"
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Faculty
{
  public:
    string name;
    int id;
    string level;
    string department;
    DoublyLinkedList<int> *advisees = new DoublyLinkedList<int>();

    Faculty();
    Faculty(string nameIn, int idIn, string levelIn, string departmentIn);
    ~Faculty();
    int getid();
    void setid(int idIn);
    string getname();
    void setname(string nameIn);
    string getlevel();
    void setlevel(string levelIn);
    string getdep();
    void setdep(string department);
    void printFaculty();
};
