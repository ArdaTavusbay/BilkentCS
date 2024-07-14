/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include <string>
#include <iostream>
using namespace std;

typedef string ListItemType;

class List
{
public:
    //Constructor & Destructor
    List();
    List(const List &aList);
    ~List();

    //List Methods
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, ListItemType &dataItem) const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);

private:
    struct ListNode
    {
        string item;
        ListNode *next;
    };

    int size;
    ListNode *head;
    ListNode *find(int index) const;
};
