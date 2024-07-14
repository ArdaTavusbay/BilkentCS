/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "FlowerList.h"
class FlowerLibrary
{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name, string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;

private:
    FlowerList flowers;
    // ...
    //you may define additional member functions and data members, if necessary
};