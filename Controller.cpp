#include <string>
#include <fstream>
#include <iostream>
#include "Controller.h"

using namespace std;

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::addStudent()
{
  string name;
  int id;
  string level;
  string major;
  double gpa;
  int advisor;
  cout << "Enter the students information as it is requested" << endl;
  cout << "Student's name: " << endl;
  cin >> name;
  cout << "Student's ID: " << endl;
  cin >> id;
  cout << "Student's entry level: " << endl;
  cin >> level;
  cout << "Student's major: " << endl;
  cin >> major;
  cout << "Student's gpa: " << endl;
  cin >> gpa;
  cout << "Student's advisor ID: " << endl;
  cin >> advisor;
  Student *newStudent = new Student(name, id, level, major, gpa, advisor);
  TreeNode<Student> *newStudentNode = new TreeNode<Student>(*newStudent, id);
  studentList.insert(newStudentNode);
  cout << "Student Added" << endl;
}

void Controller::addFaculty()
{
  string name;
  int id;
  string level;
  string department;
  int adviseeCount;
  cout << "Enter the faculty's information as it is requested" << endl;
  cout << "Faculty's name: " << endl;
  cin >> name;
  cout << "Faculty's ID: " << endl;
  cin >> id;
  cout << "Faculty's teaching level: " << endl;
  cin >> level;
  cout << "Faculty's department: " << endl;
  cin >> department;
  cout << "Number of advisees: " << endl;
  cin >> adviseeCount;
  Faculty *newFaculty = new Faculty(name, id, level, department);
  TreeNode<Faculty> *newFacultyNode = new TreeNode<Faculty>(*newFaculty, id);
  int count = 1;
  for(int i = 0; i < adviseeCount; ++i)
  {
    int adviseeID;
    cout << "Enter advisee ID number " << count << ": " << endl;
    cin >> adviseeID;
    newFacultyNode->data.advisees->insertBack(adviseeID);
    count++;
  }
  facultyList.insert(newFacultyNode);
  cout << "Faculty added" << endl;
}

void Controller::printStudentsTree(TreeNode<Student> *n)
{
  if (n != NULL)
  {
    if(n->left != NULL)
    {
      printStudentsTree(n->left);
    }
    n->data.printStudent();
    if(n->right != NULL)
    {
      printStudentsTree(n->right);
    }
  }
  else
  {
    cout << "Tree is Empty" << endl;
  }
}

void Controller::printFacultyTree(TreeNode<Faculty> *n)
{
  if (n != NULL)
  {
    if(n->left != NULL)
    {
      printFacultyTree(n->left);
    }
    n->data.printFaculty();
    if(n->right != NULL)
    {
      printFacultyTree(n->right);
    }
  }
  else
  {
    cout << "Tree is Empty" << endl;
  }
}

void Controller::printStudentID(int val)
{
  if(studentList.searchNode(val))
  {
    studentList.returnData(val)->data.printStudent();
  }
  else
  {
    cout << "no student matches this ID" << endl;
  }
}

void Controller::printFacultyID(int val)
{
  if(facultyList.searchNode(val))
  {
    facultyList.returnData(val)->data.printFaculty();
  }
  else
  {
    cout << "no faculty matches this ID" << endl;
  }
}
