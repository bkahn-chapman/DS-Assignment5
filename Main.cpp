#include <iostream>
#include <string>
#include "Controller.h"

using namespace std;

int main(int argc, char **argv)
{
  cout << "Welcome to our program!" << endl;
  Controller *c = new Controller();
  bool quitCheck = false;
  while(!quitCheck)
  {
    int numChoice = 0;
    cout << "Please input the number of the option you would like to choose." << endl;
    cout << "1. Create a new student." << endl;
    cout << "2. Create a new faculty." << endl;
    cout << "3. View all students." << endl;
    cout << "4. View all faculty." << endl;
    cout << "5. Quit the program." << endl;
    cin >> numChoice;
    if(numChoice == 1)
    {
      cout << endl;
      c->addStudent();
      cout << endl;
    }
    else if(numChoice == 2)
    {
      cout << endl;
      c->addFaculty();
      cout << endl;
    }
    else if(numChoice == 3)
    {
      cout << endl;
      c->printStudentsTree(c->studentList.root);
      cout << endl;
    }
    else if(numChoice == 4)
    {
      cout << endl;
      c->printFacultyTree(c->facultyList.root);
      cout << endl;
    }
    else if(numChoice == 5)
    {
      cout << endl;
      cout << "Thank you for using our program. Have a nice day!" << endl;
      quitCheck = true;
      break;
    }
    /*
    else if(numChoice == 2)
    {

    }
    else if(numChoice == 2)
    {

    }
    else if(numChoice == 2)
    {

    }
    else if(numChoice == 2)
    {

    }
    else if(numChoice == 2)
    {

    }
    else if(numChoice == 2)
    {

    }
    */
    else
    {
      cout << "That number was not on the list. Please enter a valid choice." << endl;
    }
  }
  c->addStudent();
  c->addStudent();
  c->printStudentsTree(c->studentList.root);


}
