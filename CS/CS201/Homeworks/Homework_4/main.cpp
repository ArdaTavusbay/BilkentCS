/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include <iostream>
using namespace std;
#include "AlgebraicExpression.h"
#include "Stack.h"

int main()
{
    cout << endl;
    cout << "Testing Infix to Postfix" << endl;
    cout << endl;
    cout << infix2postfix("1 + 2") << endl;               // EXPECTED = 1 2 +
    cout << infix2postfix("5 / 4 + 3") << endl;           // EXPECTED = 5 4 / 3 +
    cout << infix2postfix("7 * ( 27 / 3 ) + 5") << endl;  // EXPECTED = 7 27 3 / * 5 +
    cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl; // EXPECTED = 12 5 + 20 4 *-
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Infix to Prefix" << endl;
    cout << endl;
    cout << infix2prefix("( 27 * 4 ) - ( 16 / 4 )") << endl; // EXPECTED = - * 27 4 / 16 4
    cout << infix2prefix("( 12 + 5 ) - 20 * 4") << endl;     // EXPECTED = - + 12 5 * 20 4
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Prefix to Postfix" << endl;
    cout << endl;
    cout << prefix2postfix("- 1 2") << endl;                 // EXPECTED = 1 2 -
    cout << prefix2postfix("* + * 100 2 4 - 12 40") << endl; // 100 2 * 4 + 12 40 - *
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Prefix to Infix" << endl;
    cout << endl;
    cout << prefix2infix("* 1 + 2 3") << endl;             // EXPECTED = (1 * (2 + 3))
    cout << prefix2infix("* + * 100 2 4 - 12 40") << endl; // EXPECTED = (((100 * 2) + 4) * (12 - 40))
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Postfix to Infix" << endl;
    cout << endl;
    cout << postfix2infix("2 1 + 3 *") << endl;  // EXPECTED = ((2 + 1) * 3)
    cout << postfix2infix("10 2 * 3 +") << endl; // EXPECTED = ((10 * 2) + 3)
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Postfix to Prefix" << endl;
    cout << endl;
    cout << postfix2prefix("10 2 * 3 +") << endl;      // EXPECTED = + * 10 2 3
    cout << postfix2prefix("6 30 60 * + 2 -") << endl; // EXPECTED = - + 6 * 30 60 2
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Evaluate Prefix" << endl;
    cout << endl;
    cout << evaluatePrefix("/ 1 2") << endl;                 // EXPECTED = 0.5
    cout << evaluatePrefix("- 1 2") << endl;                 // EXPECTED = -1
    cout << evaluatePrefix("* + * 100 2 4 - 12 40") << endl; // EXPECTED = -5712
    cout << evaluatePrefix("* + * 9 2 4 - 2 4") << endl;     // EXPECTED = -44
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Evaluate Postfix" << endl;
    cout << endl;
    cout << evaluatePostfix("1 2 /") << endl;      // EXPECTED = 0.5
    cout << evaluatePostfix("1 2 -") << endl;      // EXPECTED = -1
    cout << evaluatePostfix("10 2 * 3 +") << endl; // EXPECTED = 23
    cout << evaluatePostfix("18 2 / 3 -") << endl; // EXPECTED = 6
    // -----
    // WORKS
    // -----
    cout << endl;
    cout << "Testing Evaluate Infix" << endl;
    cout << endl;
    cout << evaluateInfix("10 / 2") << endl;                               // EXPECTED = 5
    cout << evaluateInfix("39 - 13") << endl;                              // EXPECTED = 26
    cout << evaluateInfix("( 12 + 5 ) - 20 * 4") << endl;                  // EXPECTED = -63
    cout << evaluateInfix("( 12 + 5 ) - ( 20 * 4 ) / ( 64 / 4 )") << endl; // EXPECTED = 12
    return 0;
}