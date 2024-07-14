/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "Stack.h"
#include <iostream>

// default constructor
Stack::Stack() {}

// copy constructor
Stack::Stack(const Stack &aStack) : aList(aStack.aList) {}

// destructor
Stack::~Stack() {}

bool Stack::isEmpty() const
{
    return aList.isEmpty();
}

bool Stack::getTop(StackItemType &stackTop)
    const
{
    return aList.retrieve(1, stackTop);
}

bool Stack::push(StackItemType newItem)
{
    return aList.insert(1, newItem);
}

bool Stack::pop()
{
    return aList.remove(1);
}

bool Stack::pop(StackItemType &stackTop)
{
    if (aList.retrieve(1, stackTop))
        return aList.remove(1);
    else
        return false;
}
