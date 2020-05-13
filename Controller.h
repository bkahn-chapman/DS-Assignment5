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
  void addStudent(); //adds a student to the tree
  void addFaculty(); //adds a faculty to the tree
  void printStudentsTree(TreeNode<Student> *n); //prints the tree of students
  void printFacultyTree(TreeNode<Faculty> *n); //prints the tree of faculty
  void printStudentID(int val); //prints a student given their id
  void printFacultyID(int val); //prints a faculty given their id
  void printAdvisorOfStudent(int val); //prints a student's advisor
  void printStudentsOfAdvisor(int val); //prints an advisor's students
  void deleteStudent(int val); //deletes a student given their id
  void deleteFaculty(int val); //deletes a faculty given their id
  void changeAdvisor(int studID, int facID); //changes a student's advisor
  void removeAdvisee(int facID, int studID); //removes an advisor's student
};
