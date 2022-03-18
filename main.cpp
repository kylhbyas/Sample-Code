
/**
 * @file main.cpp
 * @author Kyle Byassee
 * @date 2022-03-16
 * @brief main
 * 
 * main
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Attendees.h"

using namespace std;

int main() {
  cout << "Welcome to the confMAKER!" << endl;
  Attendees Audience;  // Declaration of the Audience object of type Attendees. The declaration calls the constructor implicitly.

  string fileName;
  cout << "Please enter the input file name: ";  // Prompt the user for the file name
  cin >> fileName;

  cout << "\nGetting number of attendees." << endl;  // Parse the file to determine the number of people in attendance to the conference.
  Audience.readAttendeeSize(fileName);

  cout << "\nAllocating memory for " << Audience.getAttendance() << " attendees." << endl;  // Allocate enough memory for the dynamic arrays based on attendance.
  Audience.allocate();
  
  cout << "\nReading attendee data from: " << fileName << endl;  // Read the file and save the entries into the appropriate arrays. (Opens the file a second time)
  Audience.readAttendeeData();

  cout << "\nPrinting records for " << Audience.getAttendance() << " attendees." << endl;  // Prints the information for each attendee. The destructor is called implicitly at the end of main().
  Audience.print();
  
  return 0;
}
