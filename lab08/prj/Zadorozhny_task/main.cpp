#include <iostream>
#include <cmath>
#include <ModulesZadorozhny.h>
#include <windows.h>
using namespace std;

int main()
{
    int x = 0.0;
    int y = 0.0;
    int z = 0.0;
    float a = 0.0;
    float b = 0.0;

    cout << "Enter x" << endl;
    cin >> x;
    cout << "Enter y" << endl;
    cin >> y;
    cout << "Enter z" << endl;
    cin >> z;
    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;

    cout << copyright() << endl;

    cout << returnExpression(a, b) << endl;

    cout << decimal(x, y, z) << endl;

    cout << hexADecimal(x, y, z) << endl;

    cout << s_calculation_to_string(x, y, z) << endl;

    return 0;
}
