#include <iostream>
#include <string>
#include "Controller.h"

using namespace std;

int main(int argc, char **argv)
{
  Controller *c = new Controller();
  c->addFaculty();
  c->printFacultyID(123);
}
