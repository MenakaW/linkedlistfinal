#include "Studentr.h"
#include <cstring>

Studentr::Studentr(){

}

void Studentr::setFirstName(char* newName){
  firstName = new char[20];
  strcpy(firstName,newName);
}

void Studentr::setLastName(char* newName){
  lastName = new char[20];
  strcpy(lastName,newName);
}

void Studentr::setStudentID(int newID){
  studentId = newID;
}

void Studentr::setGPA(float newGPA){
  GPA = newGPA;
}

char* Studentr::getFirstName(){
  return firstName;
}

char* Studentr::getLastName(){
  return lastName;
}

int Studentr::getStudentID(){
  return studentId;
}

float Studentr::getGPA(){
  return GPA;
}

Studentr::~Studentr(){

  delete firstName;
  delete lastName;
  
}
