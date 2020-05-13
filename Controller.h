#include <iostream>
#include "BST.h"

using namespace std;

class Controller
{
public:
  BST<Student> studentList;
  BST<Faculty> facultyList;
  Controller();
  ~Controller();
  void addStudent();
  void addFaculty();
  void printStudentsTree(TreeNode<Student> *n);
  void printFacultyTree(TreeNode<Faculty> *n);
  void printStudentID(int val);
  void printFacultyID(int val);
};
