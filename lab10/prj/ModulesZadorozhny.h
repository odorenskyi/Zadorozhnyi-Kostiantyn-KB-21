#ifndef MODULESZADOROZHNY_H_H_INCLUDED
#define MODULESZADOROZHNY_H_H_INCLUDED

#include <iostream>
#include <math.h>
#include <tgmath.h>
#include <windows.h>

#include <istream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <bitset>

using namespace std;


float s_calculation(int x, int y, int z);

string s_calculation_to_string(int x, int y, int z);

string decToHexa(int n);

string boolToString(bool b);

string copyright();

string returnExpression(int a, int  b);

string decimal(int x, int y, int z);

string hexADecimal(int x, int y, int z);

int task_10_1(string path_output, string path_input);

int task_10_2(string path_file);

int task_10_3(float x, float y, float z, int b, string path_file);

string ReadFile(string path_file);

vector<string> Input();

vector<string> ExpectedResultTest_10_1();

vector<string> ExpectedResultTest_10_2();

vector<string> ExpectedResultTest_10_3();

#endif // MODULESZADOROZHNY_H_H_INCLUDED
