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

//adds a new student to the student tree
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

//adds a new faculty to the faculty tree
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

//prints the contents of the tree of students
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

//prints the contents of the tree of faculty members
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

//prints the data of a student given a specific id
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

//prints the data of a faculty member given a specific id
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

//prints the advisors of a given student
void Controller::printAdvisorOfStudent(int val)
{
  if(studentList.searchNode(val))
  {
    printFacultyID(studentList.returnData(val)->data.getadvisor());
  }
  else
  {
    cout << "This student does not have an advisor" << endl;
  }
}

//prints the students of a given advisor
void Controller::printStudentsOfAdvisor(int val)
{
  if(facultyList.searchNode(val))
  {
    Faculty f = facultyList.returnData(val)->data;
    DoublyLinkedList<int> *temp = new DoublyLinkedList<int>();
    int number;
    while(!f.advisees->isEmpty())
    {
      number = f.advisees->removeFront();
      printStudentID(number);
      temp->insertBack(number);
    }
    f.advisees = temp;
    delete temp;
  }
  else
  {
    cout << "This Faculty doesn't exist" << endl;
  }
}

//deletes a student from the tree given their id
void Controller::deleteStudent(int val)
{
  if(studentList.searchNode(val))
  {
    studentList.deleteNode(val);
    cout << "Student has been deleted" << endl;
  }
  else
  {
    cout << "That student doesn't exist " << endl;
  }
}

//deletes a faculty member given their id
void Controller::deleteFaculty(int val)
{
  if(facultyList.searchNode(val))
  {
    facultyList.deleteNode(val);
    cout << "Student has been deleted" << endl;
  }
  else
  {
    cout << "That faculty member doesn't exist " << endl;
  }
}

//changes a student's advisor if their advisor gets deleted
void Controller::changeAdvisor(int studID, int facID)
{
  if(studentList.searchNode(studID))
  {
    studentList.returnData(studID)->data.setadvisor(facID);
  }
  else
  {
    cout << "that student ID does not exist" << endl;
  }
}

//removes a student from an advisor if the student is deleted
void Controller::removeAdvisee(int facID, int studID)
{
  int value = 0;
  if(facultyList.searchNode(facID))
  {
    value = facultyList.returnData(facID)->data.advisees->search(studID);
    cout << value << endl;
    if(value != 0)
    {
      facultyList.returnData(facID)->data.advisees->removeAtPos(value);
    }
    else
    {
      cout << "Student ID is not correct" << endl;
    }
  }
  else
  {
    cout << "Faculty ID is incorrect" << endl;
  }
}
