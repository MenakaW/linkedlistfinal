#include <iostream>
#include <cstring>
#include "node.h"
#include "Studentr.h"

using namespace std;

node::node(Studentr* Student) {
  nodeStudent = Student;
  next = NULL;
}
node::~node() {
  //changed the constructor, because it was giving me errors
  delete nodeStudent;
}
void node::setNext(node* newnext) {
  next = newnext;
}
node* node::getNext() {
  return next;
}
Studentr* node::getstudent() {
  return nodeStudent;
}
