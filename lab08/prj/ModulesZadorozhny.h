#ifndef MODULESZADOROZHNY_H_H_INCLUDED
#define MODULESZADOROZHNY_H_H_INCLUDED

#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>

using namespace std;

float s_calculation(int x, int y, int z);

string s_calculation_to_string(int x, int y, int z);

string decToHexa(int n);

string boolToString(bool b);

string copyright();

string returnExpression(int a, int  b);

string decimal(int x, int y, int z);

string hexADecimal(int x, int y, int z);

#endif // MODULESZADOROZHNY_H_H_INCLUDED
