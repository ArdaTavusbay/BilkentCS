/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include <string>
#include <iostream>
#include "Cabinet.h"
using namespace std;

class LabOrganizer
{

public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    // ...
    //you may define additional member functions and data members, if necessary
    bool chemicalIsUnique(int id);
    bool cabinetIsUnique(int id);
    bool isNearCombustant(Cabinet &cabinet, int row, int column);
    void placeSuggester(Cabinet &cabinet, int row, int column);

    string test(Cabinet &cabinet, int row, int col, bool isCombustant);

private:
    Cabinet *cabinets;
    int count;
    int size;
};
