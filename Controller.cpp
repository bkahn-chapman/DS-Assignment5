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
  for(int i = 0; i < adviseeCount; ++i)
  {
    int adviseeID;
    cout << "Enter advisee ID number " << i << ": " << endl;
    cin >> adviseeID;
    newFacultyNode->data.advisees->insertBack(adviseeID);
  }
  facultyList.insert(newFacultyNode);
  cout << "Faculty added" << endl;
}
