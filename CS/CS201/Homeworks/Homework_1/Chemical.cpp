/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "Chemical.h"

Chemical::Chemical()
{
    type = "+";
    id = -1;
}

Chemical::Chemical(string type, int id)
{
    this->type = type;
    this->id = id;
}

Chemical::~Chemical() {}

Chemical::Chemical(const Chemical &chemical)
{
    this->type = chemical.type;
    this->id = chemical.id;
}

void Chemical::operator=(const Chemical &right)
{
    type = right.type;
    id = right.id;
}

void Chemical::printChemical()
{
    cout << "Chemical - Id: " << id << " - Type: " << type << endl;
}
int Chemical::getChemicalID()
{
    return id;
}

char Chemical::getChemicalType()
{
    return type.at(0);
}

void Chemical::setChemicalID(int id)
{
    this->id = id;
}

void Chemical::setChemicalType(string type)
{
    this->type = type;
}