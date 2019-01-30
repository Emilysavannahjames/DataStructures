//
//  Array.hpp
//  DataStructures
//
//  Created by James, Emily on 1/30/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <assert.h>
#include <iostream>

using namespace std;

template <class Type>
class Array
{
private:
    Type * internalArray;
    int size;
    
public:
    //Constructor
    Array<Type>(int size);
    
    //Copy Constuctor
    Array<Type>(const Array<Type> & toCopy);
    //Destructor
    ~Array<Type>();
    
    //operators
    Array<Type> & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    //Methods
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
}

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    
    internalArray = new Type[size];
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toCopy)
{
    this->size = toCopy.getSize();
    
    //build data structure
    internalArray = new Type[size];
    
    for(int index =0; index < size; index++)
    {
        internalArray[index] = toCopy[index];
    }
}

template <class Type>
Array<Type> :: ~Array()
{
    delete [] internalArray;
}

template<class Type>
Array<Type> & Array<Type> :: operator = (const Array<Type> & toAssign)
{
    if(&toAssign != this)
    {
        delete [] internalArray;
        size = toAssign.getSize();
        internalArray = new Type [size];
        
    }
    for(int index = 0; index < size; index++)
    {
        internalArray[index] = toAssign[index];
    }
    
    return *this;
}

template <class Type>
Type & Array<Type> :: operator [] (int index)
{
    assert(index >= 0 && index < size);
    return internalArray
}


#endif /* Array_h */