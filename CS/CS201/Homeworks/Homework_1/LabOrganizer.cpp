/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "LabOrganizer.h"
#include <cctype>

LabOrganizer::LabOrganizer()
{
    cabinets = NULL;
    size = 0;
}
LabOrganizer::~LabOrganizer()
{
    delete[] cabinets;
}

void LabOrganizer::addCabinet(int id, int rows, int columns)
{
    if (rows > 9 || columns > 9)
    {
        cout << "Cannot add the cabinet: dimensions are out of bounds" << endl;
    }
    else if (cabinetIsUnique(id))
    {
        if (size == 0)
        {
            cabinets = new Cabinet[size + 1];
        }
        else
        {
            Cabinet *resized = cabinets;

            cabinets = new Cabinet[size + 1];

            for (int i = 0; i < size; i++)
            {
                cabinets[i] = resized[i];
            }

            delete[] resized;
        }

        Cabinet tmp(id, rows, columns);
        cabinets[size] = tmp;
        size++;
        cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
    }
    else
    {
        cout << "Cannot add the cabinet: ID " << id << " already in the system" << endl;
    }
}

void LabOrganizer::removeCabinet(int id)
{
    if (size <= 0)
    {
        cout << "Cabinet " << id << " does not exist in the system" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        if (cabinets[i].getCabinetID() == id)
        {
            cabinets[i].printAllRemovedChemicals(id);

            if (size == 1)
            {
                delete[] cabinets;
            }
            else
            {
                Cabinet *oldArray;
                oldArray = cabinets;

                cabinets = new Cabinet[size - 1];

                for (int k = 0; k < i; k++)
                {
                    cabinets[k] = oldArray[k];
                }

                for (int j = i; j < size - 1; j++)
                {
                    cabinets[j] = oldArray[j + 1];
                }

                cout << "Cabinet " << oldArray[i].getCabinetID() << " has been removed" << endl;

                delete[] oldArray;

                size--;
            }
            return;
        }
    }
    cout << "Cabinet " << id << " does not exist in the system" << endl;
}

void LabOrganizer::listCabinets()
{
    cout << "List of all cabinets:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "ID: " << cabinets[i].getCabinetID();
        cout << " Dim: " << cabinets[i].getCabinetRow() << "X" << cabinets[i].getCabinetColumn();
        cout << ", Number of empty slots: "
             << cabinets[i].getEmptySlots() << endl;
    }
}

void LabOrganizer::cabinetContents(int id)
{
    char asciiChar;
    for (int i = 0; i < size; i++)
    {
        if (cabinets[i].getCabinetID() == id)
        {
            int row;
            int column;
            row = cabinets[i].getCabinetRow();
            column = cabinets[i].getCabinetColumn();
            cout << "ID: " << id << ", " << row << "x" << column << ", empty: " << cabinets[i].getEmptySlots() << ". Chemicals: ";
            cabinets[i].printAllChemicals();
            cout << endl;
            // TODO => PRINT CHEMICALS INSIDE

            cout << "  ";
            for (int j = 0; j < column; j++)
            {
                cout << j + 1 << " ";
            }
            for (int k = 0; k < row; k++)
            {
                asciiChar = 65 + k;
                cout << endl;
                cout << asciiChar;

                for (int m = 0; m < column; m++)
                {
                    cout << " ";
                    cout << cabinets[i].getChemicalType(k, m);
                }
            }
            cout << endl;
            return;
        }
    }
    cout << "Cabinet " << id << " is not in the system" << endl;
}

bool LabOrganizer::chemicalIsUnique(int id)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < cabinets[i].getCabinetRow(); j++)
        {
            for (int k = 0; k < cabinets[i].getCabinetColumn(); k++)
            {
                if (cabinets[i].getChemicalID(j, k) == id)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool LabOrganizer::isNearCombustant(Cabinet &cabinet, int row, int column)
{
    //check left
    //cout << "12345678" << endl;
    if (column != 0)
    {
        //cout << "1234567" << endl;
        if (cabinet.getChemicalType(row, column - 1) == 'c')
        {
            return true;
        }
    }
    //check right
    if (column != cabinet.getCabinetColumn() - 1)
    {
        //cout << "123456" << endl;
        if (cabinet.getChemicalType(row, column + 1) == 'c')
        {
            return true;
        }
    }
    //check up
    if (row != 0)
    {
        //cout << "12345" << endl;
        if (cabinet.getChemicalType(row - 1, column) == 'c')
        {
            return true;
        }
    }
    //check down
    if (row != cabinet.getCabinetRow() - 1)
    {
        //cout << "1234" << endl;
        if (cabinet.getChemicalType(row + 1, column) == 'c')
        {
            return true;
        }
    }
    //check up-left diagonal
    if (row != 0 && column != 0)
    {
        //cout << "123" << endl;
        if (cabinet.getChemicalType(row - 1, column - 1) == 'c')
        {
            return true;
        }
    }
    //check up-right diagonal
    if (row != 0 && column != cabinet.getCabinetColumn() - 1)
    {
        //cout << "12" << endl;
        if (cabinet.getChemicalType(row - 1, column + 1) == 'c')
        {
            return true;
        }
        //cout << "???" << endl;
    }
    //check down-left diagonal
    if (row != cabinet.getCabinetRow() - 1 && column != 0)
    {
        //cout << "1" << endl;
        if (cabinet.getChemicalType(row + 1, column - 1) == 'c')
        {
            return true;
        }
    }
    //check down-right diagonal
    if (row != cabinet.getCabinetRow() - 1 && column != cabinet.getCabinetColumn() - 1)
    {
        //cout << "0" << endl;
        if (cabinet.getChemicalType(row + 1, column + 1) == 'c')
        {
            return true;
        }
    }
    return false;
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID)
{
    int row, column;
    string type;
    string suggestion;
    bool isCombustant = false;

    type = chemType;
    type[0] = toupper(chemType[0]);

    if (type[0] == 'C')
    {
        isCombustant = true;
    }

    column = location.at(1) - '1';
    row = toupper(location.at(0)) - 'A';

    for (int i = 0; i < size; i++)
    {
        if (cabinets[i].getCabinetID() == cabinetId)
        {
            if (cabinets[i].getChemicalID(row, column) != -1)
            {
                cout << "Location " << location << " in cabinet " << cabinetId << " is already occupied. Nearest possible locations for this chemical: ";
                suggestion = test(cabinets[i], row, column, isCombustant);
                cout << suggestion.substr(0, suggestion.size() - 2) << endl;
                return;
            }
            else if (chemicalIsUnique(chemID))
            {

                if (isCombustant)
                {
                    if (isNearCombustant(cabinets[i], row, column))
                    {
                        cout << "Location " << location << " in cabinet " << cabinets[i].getCabinetID() << " is not suitable combustive chemical. Nearest possible locations for this chemical: ";
                        suggestion = test(cabinets[i], row, column, isCombustant);
                        cout << suggestion.substr(0, suggestion.size() - 2) << endl;
                    }
                    else
                    {
                        cabinets[i].setChemical(row, column, chemType, chemID);
                        cabinets[i].decrementEmptySlots();
                        cout << "Combustive chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
                    }
                }
                else
                {
                    cabinets[i].setChemical(row, column, chemType, chemID);
                    cabinets[i].decrementEmptySlots();
                    cout << "Retardant chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
                }
                return;
            }
            else
            {
                cout << "Chemical with ID " << chemID << " already exists in the system" << endl;
            }
        }
    }
}

void LabOrganizer::findChemical(int id)
{
    int rows, cols;

    for (int i = 0; i < size; i++)
    {
        rows = cabinets[i].getCabinetColumn();
        cols = cabinets[i].getCabinetRow();

        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                if (cabinets[i].getChemicalID(j, k) == id)
                {
                    cout << "Chemical " << id << " is at location " << (char)(k + 65) << j + 1 << " in cabinet " << cabinets[i].getCabinetID() << endl;
                    return;
                }
            }
        }
    }
    cout << "Chemical " << id << " is not in the system" << endl;
}

void LabOrganizer::removeChemical(int id)
{
    int rows, cols;

    for (int i = 0; i < size; i++)
    {
        rows = cabinets[i].getCabinetRow();
        cols = cabinets[i].getCabinetColumn();

        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                if (cabinets[i].getChemicalID(j, k) == id)
                {
                    cabinets[i].setChemical(j, k, "+", -1);
                    cout << "Chemical " << id << " removed from cabinet " << cabinets[i].getCabinetID() << endl;
                    return;
                }
            }
        }
    }

    cout << "Chemical " << id << " is not in the system" << endl;
}

bool LabOrganizer::cabinetIsUnique(int id)
{
    for (int i = 0; i < size; i++)
    {
        if (cabinets[i].getCabinetID() == id)
        {
            return false;
        }
    }
    return true;
}

void LabOrganizer::placeSuggester(Cabinet &cabinet, int currRow, int currCol)
{
    string suggestion;
    int totalRows, totalCols;

    totalCols = cabinet.getCabinetColumn();
    totalRows = cabinet.getCabinetRow();

    for (int i = currRow; i < totalRows; i++)
    {
        for (int j = currCol; j < totalCols; j++)
        {
            if (cabinet.getChemicalID(i, j) == -1)
            {
                if (!isNearCombustant(cabinet, i, j))
                {
                    suggestion = 'A' + i;
                    cout << suggestion << j << endl;
                }
            }
        }
    }
}

string LabOrganizer::test(Cabinet &cabinet, int row, int col, bool isCombustant)
{
    string rowS, colS, suggestion = "";
    int totalCols = cabinet.getCabinetColumn();
    int totalRows = cabinet.getCabinetRow();

    // cout << "THISSSS ROW: " << totalRows << " - " << row << endl;
    // cout << "THISSSS COL: " << totalCols << " - " << col << endl;

    int max = totalCols;
    bool flag = false;

    if (totalRows > totalCols)
        max = totalRows;

    for (int pass = 1; pass < max; pass++)
    {
        for (int x = row - pass; x <= row + pass; x++)
        {
            for (int y = col - pass; y <= col + pass; y++)
            {
                //cout << "GIRDIK: Row: " << x << "Col: " << y << endl;
                if (x >= 0 && x < totalRows && y >= 0 && y < totalCols)
                {
                    //cout << "LOOK: Row: " << x << "Col: " << y << endl;

                    if (cabinet.getChemicalID(x, y) != -1)
                    {
                    }
                    else if (!isCombustant)
                    {
                        rowS = 'A' + x;
                        colS = '1' + y;
                        suggestion = suggestion + rowS + colS + ", ";
                        flag = true;
                    }

                    else if (isCombustant && !isNearCombustant(cabinet, x, y))
                    {
                        rowS = 'A' + x;
                        colS = '1' + y;
                        suggestion += rowS + colS + ", ";
                        // cout << suggestion << y + 1 << ", ";
                        flag = true;
                    }
                    //cout << "CIKTIK" << endl;
                }
            }
        }

        if (flag)
        {
            return suggestion;
        }
    }

    return suggestion;
}
