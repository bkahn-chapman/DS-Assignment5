#include <iostream>
#include <string>
#include "Controller.h"

using namespace std;

int main(int argc, char **argv)
{
  cout << "Welcome to our program!" << endl;
  Controller *c = new Controller();
  bool quitCheck = false;
  int input = 0;
  int input2 = 0;

  while(!quitCheck)
  {
    int numChoice = 0;
    cout << "Please input the number of the option you would like to choose." << endl;
    cout << "1. Add a new student." << endl;
    cout << "2. Add a new faculty." << endl;
    cout << "3. View all students." << endl;
    cout << "4. View all faculty." << endl;
    cout << "5. View Student by Id number" << endl;
    cout << "6. View Faculty by Id number" << endl;
    cout << "7. Advisor information with student ID" << endl;
    cout << "8. Advisee's with Faculty ID" << endl;
    cout << "9. Delete Student with ID" << endl;
    cout << "10. Delete Faculty with ID" << endl;
    cout << "11. Change a students advisor" << endl;
    cout << "12. Remove advisee from an advisor" << endl;
    cout << "14. Quit the program." << endl;
    cin >> numChoice;
    switch(numChoice)
    {
      case 1:
        cout << endl;
        c->addStudent();
        cout << endl;
        break;
      case 2:
        cout << endl;
        c->addFaculty();
        cout << endl;
        break;
      case 3:
        cout << endl;
        c->printStudentsTree(c->studentList.root);
        cout << endl;
        break;
      case 4:
        cout << endl;
        c->printFacultyTree(c->facultyList.root);
        cout << endl;
        break;
      case 5:
        cout << endl;
        cout << "what is the ID number of the student: ";
        cin >> input;
        c->printStudentID(input);
        cout << endl;
        break;
      case 6:
        cout << endl;
        cout << "what is the ID number of the Faculty: ";
        cin >> input;
        c->printFacultyID(input);
        cout << endl;
        break;
      case 7:
        cout << "What is the ID of the Student: ";
        cin >> input;
        cout << endl;
        c->printAdvisorOfStudent(input);
        break;
      case 8:
        cout << "What is the Advisor: ";
        cin >> input;
        cout << endl;
        c->printStudentsOfAdvisor(input);
        break;
      case 9:
        cout << "What is the ID of the student: ";
        cin >> input;
        cout << endl;
        c->deleteStudent(input);
        break;
      case 10:
        cout << "What is the ID of the faculty: ";
        cin >> input;
        cout << endl;
        c->deleteFaculty(input);
        break;
      case 11:
        cout << "What is the id of the student: ";
        cin >> input;
        cout << endl;
        cout << "What is the id of the new advisor: ";
        cin >> input2;
        c->changeAdvisor(input, input2);
        cout << "The students advisor has been changed" << endl;
        break;
      case 12:
        cout << "What is the ID of the faculty member: ";
        cin >> input;
        cout << "What is the ID of the Advisee to be removed: ";
        cin >> input2;
        c->removeAdvisee(input, input2);
        cout << "The advisee has been removed" << endl;
        break;
      case 14:
        cout << endl;
        cout << "Thank you for using our program. Have a nice day!" << endl;
        quitCheck = true;
        break;
      default:
        cout << "That number was not on the list. Please enter a valid choice." << endl;
    }
  }

}
