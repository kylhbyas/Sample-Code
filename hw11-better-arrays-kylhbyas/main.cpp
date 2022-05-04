/**
 * @file main.cpp
 * @author Kyle Byassee
 * @date 2022-04-13
 * @brief The main fuction and the associated test functions live here.
 * 
 * The test functions test the functionality of the custom Array class. The resize and the copy constructor extra credits were attempted.
 */
#include <iostream>
#include "Array.h"

using namespace std;

//test get and set with valid positive indices (0 - size-1)
template <typename T>
void goodPosIndexTest(Array<T>& arr, int size);

//test [] with valid positive indices (0 - size-1)
template <typename T>
void goodPosBraceTest(Array<T>& arr, int size);

//test get and set with valid negative indices (-size - -1)
template <typename T>
void goodNegIndexTest(Array<T>& arr, int size);

//test [] with valid negative indices (-size - -1)
template <typename T>
void goodNegBraceTest(Array<T>& arr, int size);

//test get and set with invalid positive and negative indices (size, -(size + 1))
template <typename T>
void badIndexTest(Array<T>& arr, int size);

//test [] with invalid positive and negative indices (size, -(size + 1))
template <typename T>
void badBraceTest(Array<T>& arr, int size);

//test << overload
template <typename T>
void printTest(const Array<T>& arr);

//test deep copy
template <typename T>
void copyTest(const Array<T>& arr);

//test resize()
template <typename T>
void resizeTest(Array<T>& arr);

//test copy constructor. Note the pass by value condition.
template <typename T>
void copyCTest(const Array<T> arr);


int main() {
  Array<int> intArr;
  Array<char> charArr(26);

  cout << "Testing the integer array get/set with valid positive indices" << endl;
  goodPosIndexTest(intArr, 100);
  cout << endl << endl;

  cout << "Testing the character [] with valid positive indices" << endl;
  goodPosBraceTest(charArr, 26);
  cout << endl << endl;

  cout << "Testing the character array get/set with valid negative indices" << endl;
  goodNegIndexTest(charArr, 26);
  cout << endl << endl;

  cout << "Testing the integer array [] with valid negative indices" << endl;
  goodNegBraceTest(intArr, 100);
  cout << endl << endl;

  cout << "Testing the character array get/set with bad indices" << endl;
  badIndexTest(charArr, 26);
  cout << endl << endl;

  cout << "Testing the integer array [] with bad indices" << endl;
  badBraceTest(intArr, 100);
  cout << endl << endl;

  cout << "Testing print of integer array" << endl;
  printTest(intArr);
  cout << endl << endl;

  cout << "Testing deep copy" << endl;
  copyTest(charArr);
  cout << endl << endl;

  cout << "Testing resize() method" << endl;
  resizeTest(charArr);
  cout << endl << endl;

  cout << "Testing copy constructor" << endl;
  cout << "Original object address: " << &intArr << endl;
  copyCTest(intArr);
  cout << endl;  

  return 0;
}

/**
 * Tests set and get with valid positive indices (0 - size-1)
 *
 * @param Array<T>& arr The address of the array to be passed as a parameter.
 * @param int size The size of the array.
 * @pre A fully constructed object.
 * @return void 
 * @post Set and get have been tested with valid positive indices.
 * 
 */
template <typename T>
void goodPosIndexTest(Array<T>& arr, int size) {
  for(int i = 0; i < size; i++) {
    cout << "Setting index " << i << " to " << i << endl;
    arr.set(i, i);
  }

  try {
    for(int i = 0; i < size; i++) {
      cout << "Array at index " << i << ": " << arr.get(i) << endl;
    }
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test [] with valid positive indices (0 - size-1)
 *
 * @param Array<T>& arr The address of the array to be passed as a parameter.
 * @param int size The size of the array.
 * @pre A fully constructed object.
 * @return void 
 * @post The [] operator have been tested wit valid positive indices.
 * 
 */
template <typename T>
void goodPosBraceTest(Array<T>& arr, int size) {
  char j = 'a';
  for(int i = 0; i < size; i++) {
    arr.set(i, j);
    j++;
  }

  try {
    for(int i = 0; i < size; i++) {
      cout << "Array[" << i << "]: " << arr[i] << endl;
    }
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test set and get with valid negative indices (-size - -1)
 *
 * @param Array<T>& arr The address of the array to be passed as a parameter.
 * @param int size The size of the array.
 * @pre A fully constructed object.
 * @return void 
 * @post The get and set methods have been tested with valid negative indices.
 * 
 */
template <typename T>
void goodNegIndexTest(Array<T>& arr, int size) {
  char j = static_cast<char> (64);  // typecasting int -size to char '@'

  for(int i = -size; i < 0; i++) {
    // j = i;
    cout << "Setting index " << i << " to " << i << endl;
    arr.set(i, j);
    j++;
  }

  try {
    for(int i = -size; i < 0; i++) {
      cout << "Array at index " << i << ": " << arr.get(i) << endl;
    }
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test [] with valid negative indices (-size - -1)
 *
 * @param Array<T>& r The address of the array to be passed as a parameter.
 * @param int size The size of the array.
 * @pre A fully constructed array.
 * @return void 
 * @post The [] operator have been tested with valid negative indices.
 * 
 */
template <typename T>
void goodNegBraceTest(Array<T>& arr, int size) {
  int j = -size;
  for(int i = 0; i < size; i++) {
    arr.set(i, j);
    j++;
  }

  try {
    for(int i = -size; i < 0; i++) {
      cout << "Array[" << i << "]: " << arr[i] << endl;
    }
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test set and get with invalid positive and negative indices (size, -(size + 1))
 *
 * @param Array<T>& arr The address of the array to be passed as a parameter.
 * @param int size The size of the array.
 * @pre A fully constructed object.
 * @return void 
 * @post The set and get methods have been tested with invalid positive and negative indices.
 * 
 */
template <typename T>
void badIndexTest(Array<T>& arr, int size) {
  cout << "Trying to set index " << size << " to \'?\'" << endl;
  arr.set(size, '?');

  cout << "Trying to set index " << -size - 1 << " to \'?\'" << endl;
  arr.set(-size - 1, '?');

  try{
    cout << "Trying to get index " << size << ": " << arr.get(size);
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }

  try{
    cout << "Trying to get index " << -size - 1 << ": " << arr.get(-size - 1);
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test [] with invalid positive and negative indices (size, -(size + 1))
 *
 * @param Array<T>& arr The address of the array to be passed as a parameter.
 * @param int size The size of the array.
 * @pre A fully constructed object.
 * @return void 
 * @post The [] operator has been tested with invalid positive and negative indices.
 * 
 */
template <typename T>
void badBraceTest(Array<T>& arr, int size) {
  try {
    cout << "Trying to modify Array[" << size << "] to -1000" << endl;
    arr[size] = -1000;
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }

  try {
    cout << "Trying to access Array[" << -(size + 1) << "]: " << arr[-(size + 1)] << endl;
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test << overload
 *
 * @param const Array<T>& arr The address of the array to be passed as a parameter.
 * @pre A fully constructed object.
 * @return void 
 * @post The << overloaded operator has been tested with the custom array object.
 * 
 */
template <typename T>
void printTest(const Array<T>& arr) {
  //try {
  cout << arr << endl;
  //} catch (const char* msg) {
  //cerr << msg << endl;
  //}
}

/**
 * test deep copy
 *
 * @param const Array<T>& arr The address of the array to be passed as a parameter.
 * @pre A fully constructed object.
 * @return void 
 * @post The assignment operator has been tested by making a deep copy of another array object.
 * 
 */
template <typename T>
void copyTest(const Array<T>& arr) {
  cout << "Creating test array and initializing it to \'?\'" << endl;
  int testSize = 4;
  Array<char> test(testSize);
  for(int i = 0; i < testSize; i++) {
    test.set(i, '?');
  }

  try {
  cout << "Original: " << arr << endl;
  cout << "Starting test array: " << test << endl;

  cout << "Setting test array = original..." << endl;
  test = arr;

  cout << "Original now: " << arr << endl;
  cout << "Test array now: " << test << endl;

  cout << "Modifying test array[-1]..." << endl;
  test[-1] = '!';

  cout << "Original now: " << arr << endl;
  cout << "Test array now: " << test << endl;
  } catch (const char* msg) {
    cerr << "Error: " << msg << endl;
  }
}

/**
 * test resize
 *
 * @param Array<T>& arr The address of the object to be resized.
 * @pre A fully constructed object.
 * @return void 
 * @post The resize method has been tested.
 * 
 */
template <typename T>
void resizeTest(Array<T>& arr) {
  cout << "Original: " << arr << endl;

  cout << "Doubling size of array" << endl;
  arr.resize();

  cout << "Result: " << arr << endl;  
}

/**
 * test the copy constructor
 *
 * @param const Array<T> arr The object to be passed by value.
 * @pre A fully constructed object.
 * @return void 
 * @post The copy constructor has been tested by printing the different addresses of the two objects.
 * 
 */
template <typename T>
void copyCTest(const Array<T> arr) {
  // The extra whitespace in the string literal is there to line up the addresses for an easier comparison.
  cout << "Copied  object  address: " << &arr << endl;
}
