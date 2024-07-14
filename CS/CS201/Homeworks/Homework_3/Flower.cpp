/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "Flower.h"

Flower::Flower() {}
Flower::Flower(string flowerName)
{
    size = 0;
    head = NULL;
    this->flowerName = flowerName;
}
Flower::Flower(const Flower &aFlower)
{
    if (aFlower.head == NULL)
        head = NULL; // original list is empty
    else
    {
        // copy first node
        head = new FeatureNode;
        head->feature = aFlower.head->feature;
        // copy rest of list
        FeatureNode *newPtr = head; // new list ptr

        for (FeatureNode *origPtr = aFlower.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new FeatureNode;
            newPtr = newPtr->next;
            newPtr->feature = origPtr->feature;
        }
        newPtr->next = NULL;
    }
}
void Flower::operator=(const Flower &aFlower)
{
    size = aFlower.size;
    flowerName = aFlower.flowerName;
    head = aFlower.head;
}
Flower::~Flower()
{
    while (!isEmpty())
    {
        remove(head->feature);
    }
}

bool Flower::isEmpty() const
{
    return size == 0;
}
int Flower::getLength() const
{
    return size;
}
bool Flower::add(string feature)
{
    FeatureNode *newPtr = new FeatureNode;
    FeatureNode *curr;

    newPtr->feature = feature;

    if (size == 0 || head->feature > feature)
    {
        newPtr->next = head;
        head = newPtr;
    }
    else
    {
        curr = head;
        while (curr->next != NULL && curr->next->feature < feature)
        {
            curr = curr->next;
        }
        newPtr->next = curr->next;
        curr->next = newPtr;
    }

    size++;

    return true;
}

bool Flower::remove(string feature)
{
    FeatureNode *curr;
    FeatureNode *prev;
    bool exists = false;

    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->feature == feature)
        {
            exists = true;
        }
    }
    if (!exists)
    {
        return false;
    }

    if (size == 1 || head->feature == feature)
    {
        curr = head;
        head = head->next;
    }
    else
    {
        ;
        prev = head;
        while (prev->next != NULL && prev->next->feature != feature)
        {
            prev = prev->next;
        }
        curr = prev->next;
        prev->next = curr->next;
    }
    curr->next = NULL;
    delete curr;
    curr = NULL;
    size--;

    return true;
}
string Flower::printFlower() const
{
    string str = flowerName + ": ";
    if (size == 0)
    {
        return "No feature";
    }
    for (FeatureNode *curr = head; curr != NULL; curr = curr->next) // head instead of head->next???
    {
        str += curr->feature + ", ";
    }
    return str;
}

string Flower::getFlowerName()
{
    return flowerName;
}

bool Flower::featureExists(string feature)
{
    for (FeatureNode *curr = head; curr != NULL; curr = curr->next)
    {
        if (curr->feature == feature)
        {
            return true;
        }
    }
    return false;
}