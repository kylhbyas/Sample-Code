/**
 * @file Rational.h
 * @author Kyle Byassee
 * @date 2022-04-11
 * @brief This file contains the declaration of the Rational class.
 * 
 * The numerator and denominator are defined here.
 */
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>


/**
 * The custom Rational class is declared here.
 *
 * @class Rational Rational.h "homework-10-custom-rational-kylhbyas/Rational.h"
 * @brief This class 
 *
 */
class Rational {
private:
  int numerator, denominator;
    
  /**** private utility ****/

/**
 * Finds the greatest common divisor of two integers.
 *
 * @param int a one integer
 * @param int b second integer
 * @pre Object creation.
 * @return int The greatest common divisor
 * @post The reduce() function.
 * 
 */
  int gcd(int a, int b);

public:
  /**** Constructors ****/

/**
 * Properly constructs an object of the Rational class with no parameters.
 *
 * @pre Object creation.
 * @post Object.
 * 
 */
  Rational();

/**
 * Properly constructs an object of the Rational class with 2 parameters.
 *
 * @param int num numerator, integer.
 * @param int denom denominator, integer.
 * @pre main.
 * @post Object creation.
 * 
 */
  Rational(int num, int denom);

/**
 * Properly constructs an object of the Rational class with only one parameter.
 *
 * @param int num The numerator.
 * @pre Object creation.
 * @post Object creation.
 * 
 */
  Rational(int num);

  /**** Destructor ****/
  // ~Rational();

  /**** Copy Constructor ****/
  //Rational(const Rational &rhs);
  
  /**** Overloaded Operators ****/

/**
 * Assigns one member of the Rational class to another member of the same class.
 *
 * @param const Rational &rhs The address of the object to be assigned to the left hand side.
 * @pre Two objects.
 * @return Rational value of the right hand side object.
 * @post 
 * 
 */
  Rational operator=(const Rational &rhs);

/**
 * Adds two members of the Rational class together.
 *
 * @param const Rational &rhs The address of the object to be added to the left hand side.
 * @pre Two objects.
 * @return Rational The value of the two objects added together.
 * @post 
 * 
 */
  Rational operator+(const Rational &rhs);

/**
 * Subtracts the right hand side object from the left hand side object.
 *
 * @param const Rational &rhs The address of the object to be subtracted from the left hand side.
 * @pre Two objects.
 * @return Rational The object with the value of the result.
 * @post 
 * 
 */
  Rational operator-(const Rational &rhs);

/**
 * Divides the left hand side object by the right hand side object.
 *
 * @param const Rational &rhs The divisor.
 * @pre Two objects.
 * @return Rational The value of the quotient.
 * @post 
 * 
 */
  Rational operator/(const Rational &rhs);

/**
 * Multiplies two objects of the Rational class together.
 *
 * @param const Rational &rhs The address of the object to be multiplied.
 * @pre Two objects.
 * @return Rational The value of the product.
 * @post 
 * 
 */
  Rational operator*(const Rational &rhs);
  Rational operator+=(const Rational &rhs);
  Rational operator-=(const Rational &rhs);
  Rational operator/=(const Rational &rhs);
  Rational operator*=(const Rational &rhs);

  // Comparisons
  bool operator>(const Rational &rhs);

/**
 * Compares the value of two objects of the Rational class.
 *
 * @param const Rational &rhs The address of the object to be compared against the left hand side.
 * @pre Two objects.
 * @return bool Returns true of the value of the two objects are equal.
 * @post 
 * 
 */
  bool operator==(const Rational &rhs);

/**
 * Compares the value of two objects fo the Rational class.
 *
 * @param const Rational &rhs The address of the object to be compared against the left hand side.
 * @pre Two objects.
 * @return bool Returns true if the value of the two objects are not equal.
 * @post 
 * 
 */
  bool operator!=(const Rational &rhs);

/**
 * Compares the value of two objects of the Rational class.
 *
 * @param const Rational &rhs The value to be compared against the left hand side.
 * @pre Two objects.
 * @return bool Returns true if the value of the left hand side is less than the right hand side.
 * @post 
 * 
 */
  bool operator<(const Rational &rhs);
  bool operator>=(const Rational &rhs);
  bool operator<=(const Rational &rhs);

  // Reduce fraction

/**
 * Reduces a fraction to it's most reduced form.
 *
 * @pre One object.
 * @return void The object mutates it's own private data members.
 * @post The reduced version of the object.
 * 
 */
  void reduce();

  // Friend functions

/**
 * Defines the behavior of the object in the ostream.
 *
 * @param std::ostream &stream The address of the ostream object.
 * @param const Rational rhs The object to be inserted into the ostream.
 * @pre One object
 * @return friend A friend function of the Rational class.
 * @post The object is inserted into the ostream.
 * 
 */
  friend std::ostream& operator<<(std::ostream &stream, const Rational rhs);
  friend std::istream& operator>>(std::istream &stream, const Rational rhs);
  
  /**** Overloaded Typecast ****/

/**
 * Converts a rational number into it's float type equivalent.
 *
 * @pre One object.
 * @return operator The float equivalent of the Rational object.
 * @post Decimal representation.
 * 
 */
  operator float();

/**
 * Converts a rational number into it's double type equivalent.
 *
 * @pre One object.
 * @return operator The double equivalent of the Rational object.
 * @post Decimal representation.
 * 
 */
  operator double();
};

#endif //RATIONAL_H
