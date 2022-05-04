/**
 * @file Rational.cpp
 * @author Kyle Byassee
 * @date 2022-04-06
 * @brief The methods of the Rational class are implemented here.
 * 
 * The methods of the Rational class include Constructors, Greatest Common Divisor function, select binary operators, select comparisons, select typecast operations, and select friend functions.
 */
#include "Rational.h"

using namespace std;

/**** Constructors ****/
Rational::Rational() {
  numerator = 0;
  denominator = 0;
}
Rational::Rational(int num, int denom) {
  numerator = num;
  denominator = denom;
}
Rational::Rational(int num) {
  numerator = num;
  denominator = 1;
}

/**** Destructor ****/
// Rational::~Rational() {
  
// }

/**** Copy Constructor ****/
// Rational::Rational(const Rational &rhs) {
//   int* numerator = new int;
//   *numerator = rhs.numerator;

//   int* denominator = new int;
//   *denominator = rhs.denominator;
// }

/**** private utility ****/
int Rational::gcd(int a, int b) {
  if(b == 0) {
    return a;
  }
  a = gcd(b, a % b);
  return a;

  // int t = 0;
  // while (b != 0) {
  //   t = b;
  //   b = a % b;
  //   a = t;
  // }
  // return a;
}

// Reduce fraction
void Rational::reduce() {
  int d = gcd(numerator, denominator);
  numerator /= d;
  denominator /= d;
}

/**** Overloaded Operators ****/
Rational Rational::operator+(const Rational &rhs) {
  // not common denominators
  if(denominator != rhs.denominator) {
    Rational r(numerator * rhs.denominator + rhs.numerator * denominator,
    	       denominator * rhs.denominator);
    return r;
  }
  // common denominators
  Rational r(numerator + rhs.numerator, denominator);
  return r;
}
Rational Rational::operator*(const Rational &rhs) {
  Rational r(numerator * rhs.numerator, denominator * rhs.denominator);
  return r;
}
Rational Rational::operator/(const Rational &rhs) {
  Rational r(numerator * rhs.denominator, denominator * rhs.numerator);
  return r;
}
Rational Rational::operator-(const Rational &rhs) {
  // no common denominators
  if(denominator != rhs.denominator) {
    Rational r(numerator * rhs.denominator - rhs.numerator * denominator,
	       denominator * rhs.denominator);
    return r;
  }
  // common denominators
  Rational r(numerator - rhs.numerator, denominator);
  return r;
}
Rational Rational::operator=(const Rational &rhs) {
  if(*this == rhs) {  // Checks for self assignment
    return *this;
  }
  numerator = rhs.numerator;
  denominator = rhs.denominator;  
  return *this;
}
Rational Rational::operator+=(const Rational &rhs) {
  // not common denominators
  if(denominator != rhs.denominator) {
    Rational r(numerator * rhs.denominator + rhs.numerator * denominator,
    	       denominator * rhs.denominator);
    return r;
  }
  // common denominators
  Rational r(numerator + rhs.numerator, denominator);
  return r;
}
Rational Rational::operator-=(const Rational &rhs) {
  // no common denominators
  if(denominator != rhs.denominator) {
    Rational r(numerator * rhs.denominator - rhs.numerator * denominator,
	       denominator * rhs.denominator);
    return r;
  }
  // common denominators
  Rational r(numerator - rhs.numerator, denominator);
  return r;
}
Rational Rational::operator/=(const Rational &rhs) {
  Rational r(numerator * rhs.denominator, denominator * rhs.numerator);
  return r;
}
Rational Rational::operator*=(const Rational &rhs) {
  Rational r(numerator * rhs.numerator, denominator * rhs.denominator);
  return r;
}

// Comparisons
bool Rational::operator==(const Rational &rhs) {
  // common denominators
  if(denominator == rhs.denominator) {
    if(numerator == rhs.numerator) {
      return true;
    }
    return false;
  }
  // not common denominators
  if(numerator * rhs.denominator == rhs.numerator * denominator) {
    return true;
  }
  return false;
}
bool Rational::operator>(const Rational &rhs) {
  // common denominators
  if(denominator == rhs.denominator) {
    if(numerator > rhs.numerator) {
      return true;
    }
    return false;
  }    
  // not common denominators
  if(numerator * rhs.denominator > rhs.numerator * denominator) {
    return true;
  }
  return false;
}
bool Rational::operator<(const Rational &rhs) {
  // common denominators
  if(denominator == rhs.denominator) {
    if(numerator < rhs.numerator) {
      return true;
    }
    return false;
  }
  // not common denominators
  if(numerator * rhs.denominator < rhs.numerator * denominator) {
    return true;
  }
  return false;
}
bool Rational::operator>=(const Rational &rhs) {
  // common denominators
  if(denominator == rhs.denominator) {
    if(numerator >= rhs.numerator) {
      return true;
    }
    return false;
  }
  // not common denominators
  if(numerator * rhs.denominator >= rhs.numerator * denominator) {
    return true;
  }
  return false;
}
bool Rational::operator<=(const Rational &rhs) {
  // common denominators
  if(denominator == rhs.denominator) {
    if(numerator <= rhs.numerator) {
      return true;
    }
    return false;
  }
  // not common denominator
  if(numerator * rhs.denominator <= rhs.numerator * denominator) {
    return true;
  }
  return false;
}
bool Rational::operator!=(const Rational &rhs) {
  // common denominators
  if(denominator == rhs.denominator) {
    if(numerator != rhs.numerator) {
      return true;
    }
    return false;
  }
  // not common denominators
  if(numerator * rhs.denominator != rhs.numerator * denominator) {
    return true;
  }
  return false;
}

/**** Overloaded Typecast ****/
Rational::operator float() {
  return float(numerator) / denominator;
}
Rational::operator double() {
  return double(numerator) / denominator;
}

// Friend functions
ostream& operator<<(std::ostream &stream, const Rational rhs) {
  stream << rhs.numerator << '/' << rhs.denominator;
  return stream;
}
istream& operator>>(std::istream &stream, const Rational rhs) {
  stream >> rhs.numerator >> '/' >> rhs.denominator;
  return stream;
}
