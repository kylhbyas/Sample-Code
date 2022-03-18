/**
 * @file Attendees.h
 * @author Kyle Byassee
 * @date 2022-03-16
 * @brief Class Declaration.
 * 
 * Declares the Attendance class.
 */

#ifndef ATTENDEES_H
#define ATTENDEES_H
#include <string>


/**
 * A class to hold information for an audience.
 *
 * @class Attendees Attendees.h "hw08-confmaker-the-conference-management-tool-kylhbyas/Attendees.h"
 * @brief Holds name, institution, title, attendance, and fileName.
 *
 */
class Attendees {
 private:
  std::string *name;
  std::string *institution;
  std::string *title;
  int attendance;
  std::string fileName;
  
 public:

/**
 * Constructor
 *
 * @pre Object declaration.
 * @post All data members are assigned the appropriate default values.
 * 
 */
  Attendees();

/**
 * Destructor
 *
 * @pre The object served it purpose.
 * @post The main() ends.
 * 
 */
  ~Attendees();

/**
 * Allocator
 *
 * @pre readAttendeeSize correctly stores the size of attendance.
 * @return void 
 * @post Memory is allocated for the dynamic arrays.
 * 
 */
  void allocate();

/**
 * Reads size
 *
 * @param std::string inFile The user entered fileName string.
 * @pre pre Correct fileName entered and correctly formatted text file list.
 * @return void 
 * @post post attendance is updated to the correct value.
 * 
 */
  void readAttendeeSize(std::string inFile);

/**
 * Reads data
 *
 * @pre Correctly sized attendance.
 * @return void 
 * @post Arrays are loaded with the appropriate entries.
 * 
 */
  void readAttendeeData();

/**
 * Gets attendance
 *
 * @pre Object constructed.
 * @return int attendance
 * @post attendance is used in various class methods.
 * 
 */
  int getAttendance() const;

/**
 * Prints
 *
 * @pre All arrays and data members are correctly stored.
 * @return void 
 * @post Returns to main().
 * 
 */
  void print();
};
#endif //ATTENDEES_H
