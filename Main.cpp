#include <iostream>
#include <string>
#include "Controller.h"

using namespace std;

int main(int argc, char **argv)
{
  Controller *c = new Controller();
  c->addStudent();
  c->addStudent();
  c->printStudentsTree(c->studentList.root);
}
