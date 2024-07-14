/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "Chemical.h"

class Cabinet
{

public:
    Cabinet();
    Cabinet(int id, int row, int column);
    Cabinet(const Cabinet &cabinet);
    ~Cabinet();
    void operator=(const Cabinet &right);

    //methods
    void addChemical(int row, int col, string type, int id);
    int getCabinetID();
    int getCabinetRow();
    int getCabinetColumn();
    int getEmptySlots();
    char getChemicalType(int row, int column);
    int getChemicalID(int row, int column);
    void setChemical(int row, int column, string chemType, int chemID);
    void decrementEmptySlots();
    void printAllChemicals();
    void printAllRemovedChemicals(int id);

    //helpers

private:
    int id;
    int row;
    int column;
    int emptySlots;
    Chemical **chemicals;
};
