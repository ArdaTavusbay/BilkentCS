/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "Cabinet.h"

Cabinet::Cabinet()
{
    chemicals = NULL;
    emptySlots = 0;
    row = 0;
    column = 0;
    id = -1;
}

Cabinet::Cabinet(const Cabinet &cabinet)
{
    this->id = cabinet.id;
    this->row = cabinet.row;
    this->column = cabinet.row;
    this->emptySlots = cabinet.emptySlots;

    chemicals = new Chemical *[row];

    for (int i = 0; i < row; i++)
    {
        chemicals[i] = new Chemical[column];

        for (int j = 0; j < column; j++)
        {
            this->chemicals[i][j] = Chemical(cabinet.chemicals[i][j]);
        }
    }
}

Cabinet::Cabinet(int id, int row, int column)
{
    this->id = id;
    this->row = row;
    this->column = column;
    this->emptySlots = row * column;

    chemicals = new Chemical *[row];

    for (int i = 0; i < row; i++)
    {
        chemicals[i] = new Chemical[column];
    }
}

Cabinet::~Cabinet()
{
    for (int i = 0; i < row; i++)
    {
        delete[] chemicals[i];
    }

    delete[] chemicals;
}

void Cabinet::operator=(const Cabinet &right)
{
    if (&right != this)
    {
        if (row != 0 && column != 0)
        {
            for (int i = 0; i < row; i++)
            {
                delete[] chemicals[i];
            }
            delete[] chemicals;
        }

        row = right.row;
        column = right.column;
        id = right.id;
        emptySlots = right.emptySlots;

        chemicals = new Chemical *[row];

        for (int i = 0; i < row; i++)
        {
            chemicals[i] = new Chemical[column];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                chemicals[i][j] = right.chemicals[i][j];
            }
        }
    }
}

void Cabinet::addChemical(int row, int column, string type, int id)
{
    Chemical tmp(type, id);
    chemicals[row][column] = tmp;
}

int Cabinet::getCabinetID()
{
    return id;
}

int Cabinet::getCabinetRow()
{
    return row;
}
int Cabinet::getCabinetColumn()
{
    return column;
}

int Cabinet::getEmptySlots()
{
    return emptySlots;
}

char Cabinet::getChemicalType(int row, int column)
{
    return chemicals[row][column].getChemicalType();
}

int Cabinet::getChemicalID(int row, int column)
{
    return chemicals[row][column].getChemicalID();
}

void Cabinet::setChemical(int row, int column, string chemType, int chemID)
{

    chemicals[row][column].setChemicalID(chemID);

    chemicals[row][column].setChemicalType(chemType);
}

void Cabinet::decrementEmptySlots()
{
    emptySlots--;
}
void Cabinet::printAllChemicals()
{
    string location;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (chemicals[i][j].getChemicalID() != -1)
            {
                location = 'A' + i;
                cout << location << j + 1 << ": " << chemicals[i][j].getChemicalID() << ", ";
            }
        }
    }
}
void Cabinet::printAllRemovedChemicals(int id)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (chemicals[i][j].getChemicalID() != -1)
            {
                cout << "Chemical " << chemicals[i][j].getChemicalID() << " removed from cabinet " << id << endl;
            }
        }
    }
}