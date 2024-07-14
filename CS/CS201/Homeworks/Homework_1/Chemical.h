/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include <string>
#include <iostream>
using namespace std;

class Chemical
{

public:
    Chemical(const Chemical &chemical);
    Chemical();
    Chemical(string type, int id);
    ~Chemical();
    void operator=(const Chemical &right);

    //Methods

    //Helpers
    void printChemical();
    int getChemicalID();
    char getChemicalType();
    void setChemicalID(int id);
    void setChemicalType(string type);

private:
    string type;
    int id;

    friend class Cabinet;
};