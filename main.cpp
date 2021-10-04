#include <iostream>

#include "solver.h"

using namespace std;

int main()
{
    Solver expr1("(3 + 6) * 5");
    Solver expr2("2 + 5 * 6 * (1 + 4 * 7) + 20 * (30 + 10)");
    Solver expr3("2 * 2/3 - 1/5 + 7/8 / 8/7");
    Solver expr4("(-5 + 3 * 4) * 10 / 30 * (14 + 58)");
    Solver expr5("1.3 * 3 + 0.1");

    cout << expr1.solve() << " = " << ((3 + 6) * 5) << endl;
    cout << expr2.solve() << " = " << (2 + 5 * 6 * (1 + 4 * 7) + 20 * (30 + 10)) << endl;
    cout << expr3.solve() << " = " << (2 * 2/3.0 - 1/5.0 + 7/8.0 / 8/7.0) << endl;
    cout << expr4.solve() << " = " << ((-5 + 3 * 4) * 10 / 30.0f * (14 + 58)) << endl;
    cout << expr5.solve() << " = " << (1.3 * 3 + 0.1) << endl;

    cout << "\nEnter some expression: ";

    string expr;
    getline(cin, expr);

    Solver solv(expr);
    cout << "Result: " << solv.solve() << endl;

    return 0;
}
