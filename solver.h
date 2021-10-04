#ifndef SOLVER_H
#define SOLVER_H

#include <string>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solver
{
private:
    string expression = "";
public:
    string getExpr() { return expression; };
    void setExpr(string expr) {
        expr.erase(std::remove(expr.begin(), expr.end(), ' '), expr.end());
        expression = expr;
    };

    Solver(string expr) {
        setExpr(expr);
    };

    double solve();

    pair<int, double> getNumberLeft (int pos);
    pair<int, double> getNumberRight (int pos);

    bool isDigit(char sym) {
        if (sym >= '0' && sym <= '9') return true;
        return false;
    }
};

#endif // SOLVER_H
