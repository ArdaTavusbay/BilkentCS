/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include <string>
#include <iostream>
using namespace std;

class Flower
{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower &aFlower);
    ~Flower();
    void operator=(const Flower &aFlower);

    bool isEmpty() const;
    int getLength() const;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    string getFlowerName();

    bool featureExists(string feature);

private:
    struct FeatureNode
    {
        string feature;
        FeatureNode *next;
    };
    int size;
    string flowerName;
    FeatureNode *head; //the features are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary
};
