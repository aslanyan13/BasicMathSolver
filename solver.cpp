#include "solver.h"

double Solver::solve () {
    assert(expression.length() != 0);

    // First need to check brackets
    int startPos = -1;
    int endPos = -1;

    int openBrackets = 0, closedBrackets = 0;

    for (int i = 0; i < (int)expression.length(); i++)
    {
        if (expression[i] == '(') {
            openBrackets++;
            if (startPos == -1) startPos = i;
        }
        if (expression[i] == ')') {
            closedBrackets++;
            if (endPos == -1) endPos = i;
        }

        if (openBrackets == closedBrackets && openBrackets != 0)
        {
            Solver temp(expression.substr(startPos + 1, endPos - (startPos + 1)));
            double res = temp.solve();
            string newExpr = expression.substr(0, startPos) + to_string(res) + expression.substr(endPos + 1);
            expression = newExpr;
            i = -1;

            startPos = -1;
            endPos = -1;

            openBrackets = 0;
            closedBrackets = 0;
        }
    }

    // Check multiplications and dividings
    for (int i = 0; i < (int)expression.length(); i++)
    {
        if (expression[i] == '/') {
            auto left = getNumberLeft(i);
            auto right = getNumberRight(i);

            double res = left.second / right.second;

            string newExpr = expression.substr(0, left.first) + to_string(res) + expression.substr(right.first);
            //cout << newExpr << endl;
            expression = newExpr;
            i = -1;
        }
        if (expression[i] == '*') {
            auto left = getNumberLeft(i);
            auto right = getNumberRight(i);

            double res = left.second * right.second;

            string newExpr = expression.substr(0, left.first) + to_string(res) + expression.substr(right.first);
            //cout << newExpr << endl;
            expression = newExpr;
            i = -1;
        }
    }

    // Check additions and subtractions
    for (int i = 1; i < (int)expression.length(); i++)
    {
        if (expression[i] == '+') {
            auto left = getNumberLeft(i);
            auto right = getNumberRight(i);

            double res = left.second + right.second;

            string newExpr = expression.substr(0, left.first) + to_string(res) + expression.substr(right.first);
            //cout << newExpr << endl;
            expression = newExpr;
            i = -1;
        }
        if (expression[i] == '-' && isDigit(expression[i - 1])) {
            // cout << expression << endl;
            auto left = getNumberLeft(i);
            auto right = getNumberRight(i);

            double res = left.second - right.second;

            string newExpr = expression.substr(0, left.first) + to_string(res) + expression.substr(right.first);
            //cout << newExpr << endl;
            expression = newExpr;
            i = -1;
        }
    }

    return stod(expression);
}
pair<int, double> Solver::getNumberLeft (int pos) {
    int start = -1;
    int end = pos;
    string number = "";

    while (start == -1) {
        pos--;

        if (pos < 0) start = 0;
        if (expression[pos] != '.' && !isDigit(expression[pos]))
        {
            if (expression[pos] == '-' && (pos == 0 || pos != 0 && !isDigit(expression[pos - 1])))
                start = pos;
            else if (expression[pos] == '-')
                start = pos + 1;
            else
                start = pos + 1;
        }
    }

    number = expression.substr(start, end);
    double num = stod(number);
    return make_pair(start, num);
}

pair<int, double> Solver::getNumberRight (int pos) {
    int start = pos + 1;
    int end = -1;
    string number = "";

    while (end == -1) {
        pos++;

        if (pos == expression.size()) end = expression.size() - 1;
        if (expression[pos] != '.' && !isDigit(expression[pos]))
        {
            if (expression[pos] == '-' && pos == start) continue;
            else
                end = pos;
        }
    }

    number = expression.substr(start, end);
    double num = stod(number);
    return make_pair(end, num);
}
