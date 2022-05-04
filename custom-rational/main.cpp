/**
 * @file main.cpp
 * @author Kyle Byassee
 * @date 2022-04-06
 * @brief This program will implement a custom rational number class that behaves like a primitive type in the system.
 * 
 * This program will prompt the user for a character input that corresponds with a operation and then prompt the user for at least 2 integers to make at least one rational number and then perform that operation on the user defined rational numbers.
 */
#include "Rational.h"

using namespace std;

/**
 * Prompts the user for two integers and makes a Rational number from the inputs.
 *
 * @pre Rational Constructors.
 * @return Rational A Rational number.
 * @post The returned Rational number is assigned to a Rational variable.
 * 
 */
Rational maker();

int main() {  
  char choice = 'a';
  cout << "Please enter an operation: +, -, *, /, >, <, = (compare), ! (compare), f (float cast), d (double cast), r (reduce): ";
  cin >> choice;

  switch(choice) {
  case '+' : {
    Rational r = maker();
    Rational s = maker();
    
    cout << r << " + " << s << " = " << r + s << endl;
  } break;
    
  case '-' : {
    Rational r = maker();
    Rational s = maker();

    cout << r << " - " << s << " = " << r - s << endl;
  } break;
    
  case '*' : {
    Rational r = maker();
    Rational s = maker();

    cout << r << " * " << s << " = " << r * s << endl;
  } break;
    
  case '/' : {
    Rational r = maker();
    Rational s = maker();

    cout << r << " / " << s << " = " << r / s << endl;
  } break;
    
  case '>' : {
    Rational r = maker();
    Rational s = maker();

    if(r > s) {
      cout << r << " > " << s << " = True" << endl;
    } else {
      cout << r << " > " << s << " = False" << endl;
    }
  } break;

  case '<' : {
    Rational r = maker();
    Rational s = maker();

    if(r < s) {
      cout << r << " < " << s << " = True" << endl;
    } else {
      cout << r << " < " << s << " = False" << endl;
    }
  } break;
    
  case '=' : {
    Rational r = maker();
    Rational s = maker();

    if(r == s) {
      cout << r << " = " << s << " = True" << endl;
    } else {
      cout << r << " = " << s << " = False" << endl;
    }
  } break;

  case '!' : {
    Rational r = maker();
    Rational s = maker();

    if(r != s) {
      cout << r << " ! " << s << " = True" << endl;
    } else {
      cout << r << " ! " << s << " = False" << endl;
    }
  } break;
    
  case 'f' : {
    Rational r = maker();
    cout << r << " f = " << float(r) << endl;
  } break;

  case 'd' : {
    Rational r = maker();
    cout << r << " d = " << double(r) << endl;
  } break;
    
  case 'r' : {
    Rational r = maker();

    cout << r << " r = ";
    r.reduce();
    cout << r << endl;
  } break;
    
  default:
    cout << "Invalid selection" << endl;
  }

  return 0;
}

Rational maker() {
  int num = 0;
  cout << "Enter numerator: ";
  cin >> num;

  int denom = 0;
  cout << "Enter denominator: ";
  cin >> denom;

  Rational r(num, denom);
  return r;
}
