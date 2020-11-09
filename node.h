#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "Studentr.h"

using namespace std;

class node {
 public:
  //constructor and destructor
  node(Studentr* Student);
  ~node();
  //set and get next
  void setNext(node* newnext);
  node* getNext();
  Studentr* getstudent();
 private:
  //variables for next and the node's student
  Studentr* nodeStudent;
  node* next;
};
#endif
