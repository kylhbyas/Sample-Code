/**
 * @file Attendees.h
 * @author Kyle Byassee
 * @date 2022-03-16
 * @brief Class Declaration.
 * 
 * Declares the Attendance class that holds name pointer, institution pointer, title pointer, attendance and fileName.
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
 * Reads the size of the audience from the file.
 *
 * @param std::string inFile The user entered fileName string.
 * @pre pre Correct fileName entered and correctly formatted text file list.
 * @return void 
 * @post post attendance is updated to the correct value.
 * 
 */
  void readAttendeeSize(std::string inFile);

/**
 * Reads each person's data from the file.
 *
 * @pre Correctly sized attendance.
 * @return void 
 * @post Arrays are loaded with the appropriate entries.
 * 
 */
  void readAttendeeData();

/**
 * Gets attendance without alteration.
 *
 * @pre Object constructed.
 * @return int attendance
 * @post attendance is used in various class methods.
 * 
 */
  int getAttendance() const;

/**
 * Prints the attendees along with their associated data.
 *
 * @pre All arrays and data members are correctly stored.
 * @return void 
 * @post Returns to main().
 * 
 */
  void print();

/**
 * Copy Constructor, used when an object is passed to a function as an arguement. Defined here due to the "Big 3" convention. As the Destructor was defined the other two functions being the copy constructor and the equal operator overloader are defined to conform to good practice.
 *
 * @param const Attendees& origObject Object to be copied into parameter
 * @pre Constructed object
 * @post function runs without altering the original object.
 * 
 */
  Attendees(const Attendees& origObject);

/**
 * Equal Operator Overloader
 *
 * @param const Attendees& objToCopy Original Object
 * @pre Constructed object.
 * @return Atendees& New object that equals the original object.
 * @post New object can be used.
 * 
 */
  Attendees& operator=(const Attendees& objToCopy);
};
#endif //ATTENDEES_H
