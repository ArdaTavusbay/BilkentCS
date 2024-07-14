/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "FlowerLibrary.h"

FlowerLibrary::FlowerLibrary()
{
    flowers = FlowerList();
}
FlowerLibrary::~FlowerLibrary() {}
void FlowerLibrary::addFlower(string name)
{
    flowers.add(name);
}
void FlowerLibrary::removeFlower(string name)
{
    flowers.remove(name);
}
void FlowerLibrary::listFlowers() const
{
    flowers.listFlowers();
}
void FlowerLibrary::listFeatures(string name) const
{
    flowers.listFlowerFeatures(name);
}
void FlowerLibrary::addFeature(string name, string feature)
{
    flowers.findAndAdd(name, feature);
    // Flower *flower;
    // flowers.retrieve(name, *flower);
    // (*flower).add(feature);
}
void FlowerLibrary::removeFeature(string name, string feature)
{
    flowers.findAndRemove(name, feature);
}
void FlowerLibrary::findFlowers(string feature) const
{
    flowers.getFlowersWithFeature(feature);
}