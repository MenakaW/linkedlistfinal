#include "node.h"
#include "Studentr.h"
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

//class variables
node* head = NULL;
node* previous = NULL;
int deleteID;
float runningSum = 0;
int num=0;

//function prototypes
void printStudent(node* currentNode);
void addStudent();
void deleteStudent(node* &currentNode);
void sort(node* &toSort, node* &currentNode);
void getAverage(node* currentNode);

int main(){  
  while(true){
    char input[20];
    cout << "Type add, print, delete, average, or quit" << endl;
    cin.get(input,20);
    cin.get();
    if(input[1]=='d' || input[1]=='D'){
      addStudent();
    }
    //if average, then find the sum of all the GPAs and then divide by the number of students and then round to 2 decimal places
    if(input[1]=='v' || input[1]=='V'){
      runningSum = 0;
      num = 0;
      getAverage(head);
      cout << "Average GPA is: " << floor((runningSum/num)*100+0.5)/100 << endl;
    }
    if(input[0]=='p' || input[0]=='P'){
      printStudent(head);
    }
    if(input[0]=='d' || input[0]=='D'){
      cout << "Please enter the student id of the student you want to delete" << endl;
      cin >> deleteID;
      cin.get();
      deleteStudent(head);
    }
    if(input[0]=='q' || input[0]=='Q'){
      break;
    }
  }
  return 0;

}

//use recursion to get through the list, and add the gpa to the running sum
void getAverage(node* currentNode){

  if(currentNode!=NULL){
    runningSum+=currentNode->getstudent()->getGPA();
    currentNode = currentNode->getNext();
    num++;
    getAverage(currentNode);
  }
}

//use recursion to go through the list until you find the student with the matching id as the one you'd liek to delete
void deleteStudent(node* &currentNode){
  //if you haven't reached the end
  if(currentNode!=NULL){
    //if the student of the node has the same id as the input
    if(currentNode->getstudent()->getStudentID()==deleteID){
      //if the node is head, it's a special case
      if(currentNode==head){
	node* temp = head;
	if(temp->getNext()!=NULL){
	  head = temp->getNext();
	}
	else{
	  head = NULL;
	}
	delete temp;
	return;
      }
      //if it's the last node, then rearrange connections accordingly
      else if(currentNode->getNext()==NULL){
	previous->setNext(NULL);
	delete currentNode;
	return;
      }
      //if it has a node before and after, perform a regular delete
      else{
	previous->setNext(currentNode->getNext());
	delete currentNode;
	return;
      }
    }
    //if the id doesn't match in this node, try again with the next node
    else{
      previous = currentNode;
      node* next = currentNode->getNext();
      deleteStudent(next);
    }
  }
}

void printStudent(node* currentNode){
  if(currentNode!=NULL){
    //print out the data of each node
    cout << "Student's name is: " << currentNode->getstudent()->getFirstName() << " " << currentNode->getstudent()->getLastName();
    float gpa = currentNode->getstudent()->getGPA();
    float gpap = floor(gpa*100+0.5)/100;
    cout << ", ID is: " << currentNode->getstudent()->getStudentID() << ", and GPA is " << gpap << endl;
    if(currentNode->getNext()!=NULL){
      //once done with printing, then call the method on the next node
      node* next = currentNode->getNext();
      printStudent(next);
    }
  }
}

void addStudent(){
  //set up the student with all of the data fields
  Studentr* s = new Studentr();
  cout << "Please enter the student's first name" << endl;
  char firstNamee[20];
  cin.get(firstNamee,20);
  cin.get();
  s->setFirstName(firstNamee);
  cout << "Please enter the student's last name" << endl;
  char lastNamee[20];
  cin.get(lastNamee,20);
  cin.get();
  s->setLastName(lastNamee);
  cout << "Please enter the students id number" << endl;
  int studentIdd;
  cin >> studentIdd;
  cin.get();
  s->setStudentID(studentIdd);
  cout << "Please enter the student's GPA" << endl;
  float GPAA;
  cin >>  GPAA;
  cin.get();
  s->setGPA(GPAA);
  //create a new node with that student, and call the sort method
  node* n = new node(s);
  sort(n, head);
}

void sort(node* &toSort, node* &currentNode){
  if(head==NULL){
    head = toSort;
    return;
  }
  int ID1 = toSort->getstudent()->getStudentID();
  int ID2 = currentNode->getstudent()->getStudentID();
  //if you find the first node where the id is larger than the input
  if(ID1<ID2){
    //check if it's head because it will have a diff process
    if(head==currentNode){
      toSort->setNext(currentNode);
      head = toSort;
      return;
    }
    //otherwise perform a normal insertion
    previous->setNext(toSort);
    toSort->setNext(currentNode);
    return;
  }
  //if you've reached the end, and haven't foudn a place, just attach the node onto the end
  else if(currentNode->getNext()==NULL){
    currentNode->setNext(toSort);
  }
  //if it doens't match, try again with the next node
  else{
    previous = currentNode;
    node* next = currentNode->getNext();
    sort(toSort,next);
  }
}
