/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "List.h"
typedef string StackItemType;

class Stack
{

public:
    Stack();
    Stack(const Stack &aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType &stackTop);
    bool getTop(StackItemType &stackTop) const;

private:
    List aList;
};
