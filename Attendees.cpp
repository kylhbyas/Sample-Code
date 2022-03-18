/**
 * @file Attendees.cpp
 * @author Kyle Byassee
 * @date 2022-03-16
 * @brief Contains the class methods for the Attendees class.
 * 
 * Attendees.h is the class declaration that is included in this file and defines the methods declared in that file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Attendees.h"

using namespace std;

Attendees::Attendees() {
  name = nullptr;
  institution = nullptr;
  title = nullptr;
  attendance = 0;
  string fileName = "";
}

Attendees::~Attendees() {
  delete[] title;  // Destructed in reverse order in which they were constructed.
  delete[] institution;
  delete[] name;
}

void Attendees::allocate() {  
  name = new string[attendance];
  institution = new string[attendance];
  title = new string[attendance];
}

void Attendees::readAttendeeSize(std::string inFile) {
  fileName = inFile;
  
  ifstream filein;
  string temp = "temp";
  int i = 0;
  
  filein.open(fileName);
  getline(filein, temp);  
  while(filein) {
    i++;
    getline(filein, temp);
  }
  filein.close();

  attendance = i / 3;
}

void Attendees::readAttendeeData() {
  ifstream inFile;
  int i = 0;

  // No Priming read because it causes a segmentation fault
  inFile.open(fileName);
  while(inFile && i < attendance) {
    getline(inFile, name[i]);
    getline(inFile, institution[i]);
    getline(inFile, title[i]);
    i++;
  }
  inFile.close();
}

int Attendees::getAttendance() const {
  return attendance;
}

void Attendees::print() {
  for(int i = 0; i < attendance; i++) {
    cout << "Attendee " << i + 1 << ':' << endl
	 << "Name: " << name[i] << endl
	 << "Institution: " << institution[i] << endl
	 << "Title: " << title[i] << endl << endl;
  }
}
