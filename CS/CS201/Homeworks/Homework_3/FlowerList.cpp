/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "FlowerList.h"

FlowerList::FlowerList()
{
    size = 0;
    head = NULL;
}

FlowerList::FlowerList(const FlowerList &aList)
{
    if (aList.head == NULL)
        head = NULL;
    else
    {

        head = new FlowerNode;
        head->f = aList.head->f;

        FlowerNode *newPtr = head;

        for (FlowerNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new FlowerNode;
            newPtr = newPtr->next;
            newPtr->f = origPtr->f;
        }
        newPtr->next = NULL;
    }
}

FlowerList::~FlowerList()
{
    while (!isEmpty())
    {
        removeForDestructor();
    }
}

bool FlowerList::isEmpty() const
{
    return size == 0;
}
int FlowerList::getLength() const
{
    return size;
}
bool FlowerList::exists(string flowerName) const
{
    for (FlowerNode *prev = head; prev != NULL; prev = prev->next)
    {
        if (prev->f.getFlowerName() == flowerName)
        {
            return true;
        }
    }
    return false;
}

// Deprecated, instead of retrieve(), I created and used findAndAdd() method
bool FlowerList::retrieve(string flowerName, Flower &flower) const
{
    FlowerNode *curr = head;

    if (!exists(flowerName))
    {
        return false;
    }

    while (curr->next != NULL && curr->f.getFlowerName() != flowerName)
    {
        curr = curr->next;
    }

    cout << curr->f.getLength() << endl;
    flower = curr->f;
    cout << flower.getFlowerName() << endl;
    return true;
}

bool FlowerList::add(string flowerName)
{
    string str = "";
    for (int i = 0; i < flowerName.length(); i++)
    {
        str += tolower(flowerName[i]);
    }

    if (exists(str))
    {
        cout << str << " cannot be added into the library because it already exists." << endl;
        return false;
    }
    FlowerNode *newNode = new FlowerNode;
    FlowerNode *prev;

    newNode->f = Flower(str);

    if (size == 0 || head->f.getFlowerName() > str)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {

        prev = head;
        while (prev->next != NULL && prev->next->f.getFlowerName() < flowerName)
        {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }

    size++;
    cout << str << " has been added into the library." << endl;

    return true;
}
bool FlowerList::remove(string flowerName)
{
    string str = "";
    for (int i = 0; i < flowerName.length(); i++)
    {
        str += tolower(flowerName[i]);
    }

    FlowerNode *curr;
    bool exists = false;

    for (FlowerNode *prev = head; prev != NULL; prev = prev->next)
    {
        if (prev->f.getFlowerName() == str)
        {
            exists = true;
        }
    }
    if (!exists)
    {
        cout << str << " cannot be removed because it's not in the library." << endl;
        return false;
    }

    if (size == 1 || head->f.getFlowerName() == str)
    {
        curr = head;
        head = head->next;
    }
    else
    {
        for (FlowerNode *prev = head; prev != NULL; prev = prev->next) // head instead of head->next???
        {

            curr = prev->next; // if prev reaches end, curr is prev->next == NULL ?????????s
            if (curr->f.getFlowerName() == str)
            {
                prev->next = curr->next;
                break;
            }
        }
    }
    curr->next = NULL;
    delete curr;
    curr = NULL;
    size--;

    cout << str << " has been removed from the library." << endl;

    return true;
}

// Same as remove but removes only the head of the list
// Doesn't print anything so that when destructor is called, nothing is printed.
void FlowerList::removeForDestructor()
{
    FlowerNode *curr;

    curr = head;
    head = head->next;
    curr->next = NULL;
    delete curr;
    curr = NULL;
    size--;
}

void FlowerList::listFlowers() const
{
    if (size == 0)
    {
        cout << "Library is empty." << endl;
        return;
    }
    for (FlowerNode *count = head; count != NULL; count = count->next)
    {
        if (count->f.printFlower() == "No feature")
        {
            cout << count->f.getFlowerName() << ": " << count->f.printFlower() << endl;
        }
        else
        {
            cout << count->f.printFlower() << endl;
        }
    }
}

void FlowerList::listFlowerFeatures(string flowerName) const
{
    string str = "";
    for (int i = 0; i < flowerName.length(); i++)
    {
        str += tolower(flowerName[i]);
    }
    for (FlowerNode *count = head; count != NULL; count = count->next)
    {
        if (count->f.getFlowerName() == flowerName)
        {
            cout << count->f.printFlower() << endl;
            return;
        }
    }
    cout << str << " isn't found in library." << endl;
}

void FlowerList::findAndAdd(string flowerName, string feature)
{
    string str = "";
    for (int i = 0; i < flowerName.length(); i++)
    {
        str += tolower(flowerName[i]);
    }
    if (!exists(str))
    {
        cout << str << " isn't found in the library" << endl;
        return;
    }

    for (FlowerNode *count = head; count != NULL; count = count->next)
    {
        if (count->f.getFlowerName() == str)
        {
            if (!(count->f.featureExists(feature)))
            {
                count->f.add(feature);
                cout << feature << " is added into " << str << endl;
                return;
            }
        }
    }
    cout << feature << " already exists in " << str << endl;
}
void FlowerList::findAndRemove(string flowerName, string feature)
{
    string str = "";
    for (int i = 0; i < flowerName.length(); i++)
    {
        str += tolower(flowerName[i]);
    }
    if (!exists(str))
    {
        cout << str << " isn't found in the library" << endl;
        return;
    }
    for (FlowerNode *count = head; count != NULL; count = count->next)
    {
        if (count->f.getFlowerName() == flowerName)
        {
            if (count->f.featureExists(feature))
            {
                count->f.remove(feature);
                cout << feature << " is removed from " << str << endl;
                return;
            }
        }
    }
    cout << feature << " doesn't exist in " << str << endl;
}

void FlowerList::getFlowersWithFeature(string feature) const
{
    string str = "";
    for (FlowerNode *count = head; count != NULL; count = count->next)
    {
        if (count->f.featureExists(feature))
        {
            str += count->f.getFlowerName() + ", ";
        }
    }
    if (str == "")
    {
        cout << feature + " flowers: there is no such flower" << endl;
    }
    else
    {
        cout << feature << " flowers: " << str << endl;
    }
}