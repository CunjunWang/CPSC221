#ifndef _ARRAYCLASS_H_
#define _ARRAYCLASS_H_

template <typename T>
class ArrayClass
{
  private:

    T* arr;
    int arr_size;
    int current_size;

  public:

    // Constructors and Destructors
    
    // Default constructor
    // POST:  Creates an ArrayClass object with an array of size 10
    // PARAM:
    ArrayClass();

    // Parameterized constructor
    // PRE:   array_size > 0
    // POST:  Creates an ArrayClass object with an array of size array_size
    // PARAM: array_size = size of the array to be created
    ArrayClass(int array_size);

    // Destructor
    // POST:  De-allocates dynamic memory associated with object
    ~ArrayClass();

    // Accessors (getters) and mutators (setters)

    // Sets the value of the next free element
    // PRE:   current_size < arr_size
    // POST:  Sets index current_size to value
    // PARAM: value = value to be inserted
    void Insert(T value);

    // Returns an element's value
    // PRE:   0 <= i < current_size
    // POST:  Returns the value at index i
    // PARAM: i = index of value to be returned
    T Get(int i) const;

    // Sets an element's value
    // PRE:   0 <= i < current_size
    // POST:  Sets index i to value
    // PARAM: i = index of element to be changed
    //        value = value to be set
    void Set(int i, T value);

    // POST: Returns the size of the underlying array
    int MaxSize() const;

    // POST: Returns the number of elements stored in the array
    int Size() const;
};

#include "arrayclass.tc"

#endif