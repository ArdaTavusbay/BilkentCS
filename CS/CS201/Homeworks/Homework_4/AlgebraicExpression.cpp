/*
 * AUTHOR: ARDA TAVUSBAY
 * STUDENT ID: 21902722
*/

#include "AlgebraicExpression.h"
#include "Stack.h"
#include <sstream>
#include <stdlib.h>

string infix2postfix(const string exp)
{
    Stack stack;
    string output;
    string tmp = "";
    string ch = "";

    for (int i = 0; i < exp.length(); i++)
    {
        // cout << "output: " << output << " / i: " << i << endl;
        // GET RID OF THE SPACES IN THE EXPRESSION
        while (exp[i] != ' ')
        {
            ch += string(1, exp[i]);
            i++;
            if (i >= exp.length())
            {
                break;
            }
        }
        stack.getTop(tmp);

        if (ch == "(")
        {
            stack.push(ch);
        }

        else if (ch == ")")
        {
            while (tmp != "(" && !stack.isEmpty())
            {
                output += tmp + " ";
                stack.pop();
                stack.getTop(tmp);
            }

            stack.pop(); // pop the '('
        }
        // IF OPERAND, ADD TO OUTPUT
        else if (!isOperator(ch))
        {
            output += ch + " ";
        }

        else
        {
            while (precedence(ch[0]) <= precedence(tmp[0]) && !stack.isEmpty())
            {
                output += tmp + " ";
                stack.pop();
                stack.getTop(tmp);
            }
            stack.push(ch);
        }
        ch = "";
    }
    stack.getTop(tmp);
    while (!stack.isEmpty())
    {
        output += tmp;
        stack.pop();
        stack.getTop(tmp);
    }

    return output;
}

string infix2prefix(const string exp)
{
    string result;
    string tmp;
    tmp = reverse(exp);
    result = infix2postfix(tmp);
    return reverse(result);
}

string prefix2infix(const string exp)
{
    Stack stack;
    string result;
    string ch;
    string tmp1, tmp2;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        while (exp[i] != ' ')
        {
            ch = string(1, exp[i]) + ch;
            i--;
            if (i >= exp.length())
            {
                break;
            }
        }
        if (isOperator(ch))
        {
            //"*-1/23-/145"
            stack.getTop(tmp1);
            stack.pop();
            stack.getTop(tmp2);
            stack.pop();

            stack.push("(" + tmp1 + " " + ch + " " + tmp2 + ")");
        }

        else
        {
            stack.push(ch);
        }
        ch = "";
    }

    stack.getTop(result);
    return result;
}

string prefix2postfix(const string exp)
{
    Stack stack;
    string result;
    string ch;
    string tmp1, tmp2;

    // reading from right to left
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        while (exp[i] != ' ')
        {
            ch = string(1, exp[i]) + ch;
            i--;
            if (i >= exp.length())
            {
                break;
            }
        }
        if (isOperator(ch))
        {
            //"*-1/23-/145"
            stack.getTop(tmp1);
            stack.pop();
            stack.getTop(tmp2);
            stack.pop();

            stack.push(tmp1 + " " + tmp2 + " " + ch);
        }
        else
        {
            stack.push(ch);
        }
        ch = "";
    }
    stack.getTop(result);
    return result;
}

string postfix2infix(const string exp)
{
    Stack stack;
    string tmp1, tmp2;
    string result;
    string ch = "";

    for (int i = 0; i < exp.length(); i++)
    {
        while (exp[i] != ' ')
        {
            ch += string(1, exp[i]);
            i++;
            if (i >= exp.length())
            {
                break;
            }
        }

        if (isOperator(ch))
        {
            stack.getTop(tmp1);
            stack.pop();
            stack.getTop(tmp2);
            stack.pop();
            stack.push("(" + tmp2 + " " + ch + " " + tmp1 + ")");
        }
        else
        {
            stack.push(ch);
        }

        ch = "";
    }
    stack.getTop(result);
    return result;
}

string postfix2prefix(const string exp)
{
    Stack stack;
    string tmp1, tmp2;
    string result;
    string ch = "";

    for (int i = 0; i < exp.length(); i++)
    {
        while (exp[i] != ' ')
        {
            ch += string(1, exp[i]);
            i++;
            if (i >= exp.length())
            {
                break;
            }
        }
        if (isOperator(ch))
        {
            stack.getTop(tmp1);
            stack.pop();
            stack.getTop(tmp2);
            stack.pop();
            stack.push(ch + " " + tmp2 + " " + tmp1);
        }

        else
        {
            stack.push(ch);
        }
        ch = "";
    }

    stack.getTop(result);
    return result;
}

double evaluatePrefix(const string exp)
{
    Stack stack;
    const char *a;
    string ch;
    double tmp1, tmp2, tmp3;
    string out1, out2;
    string b1, b2;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        while (exp[i] != ' ')
        {
            ch = string(1, exp[i]) + ch;
            i--;
            if (i >= exp.length())
            {
                break;
            }
        }

        if (!isOperator(ch))
        {
            stack.push(ch);
        }
        else
        {
            stack.getTop(out1);
            stack.pop();
            stack.getTop(out2);
            stack.pop();
            a = out1.c_str();
            tmp1 = atof(a);
            a = out2.c_str();
            tmp2 = atof(a);
            if (ch == "+")
            {
                tmp3 = tmp2 + tmp1;
                stack.push(toString(tmp3));
            }
            else if (ch == "-")
            {
                tmp3 = tmp1 - tmp2;
                stack.push(toString(tmp3));
            }
            else if (ch == "*")
            {
                tmp3 = tmp2 * tmp1;
                stack.push(toString(tmp3));
            }
            else if (ch == "/")
            {
                tmp3 = tmp1 / tmp2;
                stack.push(toString(tmp3));
            }
        }
        ch = "";
    }
    stack.getTop(out1);
    a = out1.c_str();
    return atof(a);
}

double evaluatePostfix(const string exp)
{
    string prefix = postfix2prefix(exp);
    return evaluatePrefix(prefix);
}

double evaluateInfix(const string exp)
{
    string prefix = infix2prefix(exp);
    return evaluatePrefix(prefix);
}

bool isOperator(string ch)
{
    if (ch == "+" || ch == "-" || ch == "/" || ch == "*")
    {
        return true;
    }
    return false;
}

int precedence(char operation)
{
    if (operation == '+' || operation == '-')
    {
        return 1;
    }
    if (operation == '/' || operation == '*')
    {
        return 2;
    }
    if (operation == '^')
    {
        return 3;
    }
    return -1;
}

string reverse(string str)
{
    string out = "";

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '(')
        {
            out += ")";
        }
        else if (str[i] == ')')
        {
            out += "(";
        }
        else
        {
            out += str[i];
        }
    }

    return out;
}

string toString(double value)
{

    ostringstream temp;
    temp << value;
    return temp.str();
}
