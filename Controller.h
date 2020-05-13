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
  void printAdvisorOfStudent(int val);
  void printStudentsOfAdvisor(int val);
  void deleteStudent(int val);
  void deleteFaculty(int val);
  void changeAdvisor(int studID, int facID);
  void removeAdvisee(int facID, int studID);
};
