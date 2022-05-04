/**
 * @file Array.h
 * @author Kyle Byassee
 * @date 2022-04-13
 * @brief The declaration and implementation of the Array class and it's methods.
 * 
 * The Array class is an attempt to make plain old arrays have more convenient features and protections.
 */
#ifndef ARRAY_H
#define ARRAY_H

//need to forward declare these so we can use the << overload later
template <typename Type> class Array;
template <typename Type> std::ostream &operator<<(std::ostream& out, const Array<Type>& arr);

/**
 * The class declaration for the custom Array class.
 *
 * @class Array Array.h "hw11-better-arrays-kylhbyas/Array.h"
 * @brief The elements private member is a pointer to an array stored in the heap.
 *
 */
template <typename Type>
class Array {
 private:
  Type *elements;
  int size;

 public:
/**
 * The default constructor.
 *
 * @pre Class declaration.
 * @post Fully constructed object.
 * 
 */
  Array();

/**
 * A parameterized constructor.
 *
 * @param int num_elements The desired size of the array.
 * @pre Class declaration.
 * @post Fully constructed object.
 * 
 */
  Array(int num_elements);

/**
 * The destructor.
 *
 * @pre A fully constructed object.
 * @post Memory has been freed.
 * 
 */
  ~Array();

/**
 * How to assign a value to a specific index of an array.
 *
 * @param int index The position to be set with a value.
 * @param Type value The value to be saved to a position in the array.
 * @pre A fully constructed object.
 * @return void 
 * @post The array has been modified.
 * 
 */
  void set(int index, Type value);

/**
 * How to recall a value from an index.
 *
 * @param int index The position to be gotten.
 * @pre A fully constructed array.
 * @return Type A templated type. ie int or char.
 * @post A value to be used in various ways.
 * 
 */
  Type get(int index);

/**
 * Overloaded operator[] to replicate the functionality of normal arrays with enhanced features and protections.
 *
 * @param int index The location within the array to be recalled or modified.
 * @pre A fully constructed array.
 * @return Type A templated type ie int or char.
 * @post 
 * 
 */
  Type &operator[](int index);

/**
 * Overloaded assignment operator to define the behavior of assigning one array object to another array object.
 *
 * @param const Array<Type>& toCopy The rhs array or the object to be assigned to the lhs.
 * @pre Two fully constructed arrays.
 * @return Array<Type> An array object containing a templated type such as int or char.
 * @post Two arrays with the same internal values.
 * 
 */
  Array<Type> &operator=(const Array<Type>& toCopy);

/**
 * Overloaded insertion operator to define the behavior of inserting a array into a stream such as cout.
 *
 * @param std::ostream& out The output stream aka cout
 * @param const Array<Type>& arr The array to be inserted into the stream.
 * @pre A fully constructed array.
 * @return friend Not a class method but has the privilages of one.
 * @post The output stream aka cout.
 * 
 */
  friend std::ostream &operator<< <Type>(std::ostream& out, const Array<Type>& arr);

/**
 * Resizes the array to be double the size.
 *
 * @pre A fully constructed object.
 * @return Array<Type>& The address of the object to be resized.
 * @post The array has been resized.
 * 
 */
  Array<Type>& resize();

/**
 * A copy constructor to pass an object by value as a parameter.
 *
 * @param const Array<Type>& toCopy The address of the object to be copied.
 * @pre A fully constructed object.
 * @post The object has been deep copied.
 * 
 */
  Array(const Array<Type>& toCopy);
};

template <typename Type>
Array<Type>::Array() {
  size = 100;
  elements = new Type[size];
}

template <typename Type>
Array<Type>::Array(int num_elements) {
  if(num_elements > 0) {
    size = num_elements;
    elements = new Type[size];
  } else {
    std::cout << "Invalid size parameter, Defaulting size to 100." << std::endl;
    size = 100;
    elements = new Type[size];
  }
}

template <typename Type>
Array<Type>::~Array() {
  delete[] elements;
}

template <typename Type>
void Array<Type>::set(int index, Type value) {
  if(index >= -size && index < size) {
    int i = index;
    if(i < 0) {
      i += size;  // size + (-i) yields subtraction.
    }
    elements[i] = value;
  } else {
    std::cerr << "Bad index for set" << std::endl;
  }
}

template <typename Type>
Type Array<Type>::get(int index) {
  if(index >= -size && index < size) {
    int i = index;
    if(index < 0) {
      i += size;  // same technique as seen in set()
    }
    return elements[i];
  } else {
    throw "Bad index for get";
  }
}

template <typename Type>
Type& Array<Type>::operator[](int index) {
  if(index >= -size && index < size) {
    int i = index;
    if(index < 0) {
      i += size;
    }
    return elements[i];
  } else {
    throw "Bad index for []";
  }
}

template <typename Type>
Array<Type>& Array<Type>::operator=(const Array<Type>& toCopy) {
  if(this != &toCopy) {
    size = toCopy.size;

    delete[] elements;
    elements = new Type[size];
    for(int i = 0; i < size; i++) {
      elements[i] = toCopy.elements[i];  // elements[i] = toCopy.get(i);
    }
  } else {
    throw "Attempted self assignment";
  }

  return *this;
}

template <typename Type>
std::ostream &operator<<(std::ostream& out, const Array<Type>& arr) {
  int last = arr.size - 1;
  out << '[';
  for(int i = 0; i < last; i++) {  // loop ends after arr[arr.size - 2]
    out << arr.elements[i] << ',' << ' ';
  }
  // unique insertion statement for last element.
  out << arr.elements[last] << ']';
  return out;
}

template <typename Type>
Array<Type>& Array<Type>::resize() {
  Type *elements2 = new Type[size * 2];
  for(int i = 0; i < size; i++) {
    elements2[i] = elements[i];
  }
  delete[] elements;

  elements = elements2;
  size *= 2;

  return *this;
}

template <typename Type>
Array<Type>::Array(const Array<Type>& toCopy) {
  size = toCopy.size;

  elements = new Type[size];
  for(int i = 0; i < size; i++) {
    elements[i] = toCopy.elements[i];
  }
}

#endif //ARRAY_H
