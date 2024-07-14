/*
 * CS201 - HOMEWORK_ASSIGNMENT_2
 * AUTHOR: Arda Tavusbay
 * ID: 21902722
 * DATE: 05.12.2021
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int algorithm1(int *arr1, int *arr2, int n, int m)
{
    bool exists;
    for (int i = 0; i < n; i++)
    {
        exists = false;
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                exists = true;
            }
        }
        // If an element in the second array does not exist in the first array
        // Function returns 0
        if (!exists)
        {
            return 0;
        }
    }

    return 1;
}

void algorithm2(int *arr1, int *arr2, int n, int m)
{
    int r, l;
    int mid;
    bool exists;

    for (int i = 0; i < m; i++)
    {
        exists = false;
        r = n - 1;
        l = 0;
        while (r > l)
        {
            mid = (r + l) / 2;
            if (arr2[i] == arr1[mid])
            {
                exists = true;
                break;
            }
            else if (arr2[i] > arr1[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        // Terminate the function if a value is not found,
        // and thus arr2 is not a subset of arr1
        if (!exists)
        {
            return;
        }
    }
}

int algorithm3(int *arr1, int *arr2, int n, int m)
{
    int *freqTable;
    int max = arr1[0];

    for (int i = 1; i < n; i++)
    {
        if (arr1[i] > max)
        {
            max = arr1[i];
        }
    }

    freqTable = new int[max];

    for (int j = 0; j < max; j++)
    {
        freqTable[j] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        freqTable[arr1[k] - 1]++;
    }

    for (int x = 0; x < m; x++)
    {
        if (arr2[x] > max || freqTable[arr2[x - 1]] == 0)
        {
            // IF AT LEAST ONE ELEMENT FROM THE SECOND ARRAY
            // IS NOT EXISTENT IN THE FIRST ARRAY, RETURN 0
            return 0;
        }
        else
        {
            freqTable[arr2[x] - 1]--;
        }
    }

    // IF EVERY ELEMENT IN THE SECOND ARRAY ALSO EXIST IN THE FIRST ARRAY,
    // SECOND ARRAY IS THE SUBSET OF THE FIRST ARRAY AND FUNCTION RETURNS 1
    return 1;
}

int main()
{
    int n, m;
    int *arr1;
    int *arr2;

    //TEST VALUES
    //CHANGING N FROM 10^5 TO 10^6 (10 DIFFERENT TESTS IN TOTAL)
    //CHANGING M BETWEEN 10^3 AND 10^4
    n = 100000;
    m = 1000;

    arr1 = new int[n];
    arr2 = new int[m];

    for (int i = 0; i < n; i++)
    {
        //FOR DETERMINING THE WORST CASE
        //arr1[i] = 0;

        //FOR DETERMINING THE AVERAGE CASE
        arr1[i] = rand() % n;
    }
    for (int j = 0; j < m; j++)
    {
        //FOR DETERMINING THE WORST CASE
        //arr2[j] = 0;

        //FOR DETERMINING THE AVERAGE CASE
        arr2[j] = rand() % m;
    }

    //  CALCULATING EXECUTION TIME
    double duration;
    clock_t startTime = clock();
    //Code block

    //********ALGORITHM_1**********
    //algorithm1(arr1, arr2, n, m);
    //*****************************

    //********ALGORITHM_2**********
    //SINCE BINARY SEARCH IS VERY FAST, WE RUN THIS FUNCTION REPEATEDLY
    //AND GET INDIVIDUAL EXECUTION TIME BY DIVIDING THE RESULT TO REPEATED AMOUNT
    // for (int i = 0; i < 10000; i++)
    // {
    //     algorithm2(arr1, arr2, n, m);
    // }
    //*****************************

    //********ALGORITHM_3**********
    //algorithm3(arr1, arr2, n, m);
    //*****************************

    //Compute the number of seconds that passed since the starting
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration / 10000 << " milliseconds." << endl;

    return 0;
}
