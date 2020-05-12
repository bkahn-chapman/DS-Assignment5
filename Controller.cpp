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

Controller::addStudent()
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
  cout << "Student's advisor ID: " << endl;
  cin >> advisor;
  Student *newStudent = new Student(name, id, level, major, advisor);
  TreeNode<Student> *newStudentNode = new TreeNode<Student>(*newStudent, id);
  studentList.insert(newStudentNode);
}
