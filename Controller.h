#include <iostream>
#include "BST.h"

using namespace std;

class Controller
{
public:
  BST<Student> studentList;
  BST<Faculty> FacultyList;
  Controller();
  ~Controller();
  void addStudent();
  void addFaculty();
};
