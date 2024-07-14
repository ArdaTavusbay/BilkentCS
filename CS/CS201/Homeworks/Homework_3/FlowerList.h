/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "Flower.h"
class FlowerList
{
public:
    FlowerList();
    FlowerList(const FlowerList &aList);
    ~FlowerList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower &flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    bool exists(string flowerName) const;
    void listFlowers() const;
    void listFlowerFeatures(string flowerName) const;
    //additionalmethods
    void removeForDestructor();
    void findAndAdd(string flowerName, string feature);
    void findAndRemove(string flowerName, string feature);
    void getFlowersWithFeature(string feature) const;

private:
    struct FlowerNode
    {
        Flower f;
        FlowerNode *next;
    };
    int size;
    FlowerNode *head; //the flowers are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary
};
