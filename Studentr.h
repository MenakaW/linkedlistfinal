#pragma once

class Studentr{

 public:
  Studentr();
  ~Studentr();
  void setFirstName(char*);
  void setLastName(char*);
  void setStudentID(int);
  void setGPA(float);
  char* getFirstName();
  char* getLastName();
  int getStudentID();
  float getGPA();
 private:
  char* firstName;
  char* lastName;
  int studentId;
  float GPA;
};
