#include <iostream>
#include <math.h>
#include <tgmath.h>
#include <windows.h>
#include <bitset>
#include <string>

using namespace std;

float s_calculation(int x, int y, int z)
{
    return (pow(3 * sin(sqrt(12 * x + log(x - 3))), y) + z/x);
}

string s_calculation_to_string(int x, int y, int z){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    return "(3 * sin * √(12 * " + to_string(x) + " + lg(" + to_string(x) + " - 3)))^" +
     to_string(y) + " + " + to_string(z) + "/" + to_string(x) + " = " + to_string(s_calculation(x, y, z));
}

int task_9_1(int salary, int work_exp){

    if(work_exp >= 2 && work_exp < 5){
        return salary * 1.05;
    }
    else if(work_exp >= 5 && work_exp < 10){
        return salary * 1.1;
    }
    else if(work_exp >= 10){
        return salary * 1.25;
    }
    else{
        return salary;
    }
}

string head_task_9_1(int salary, int work_exp){

    if(work_exp >= 2 && work_exp < 5){
        return "Allowance - 5%, salary - " + to_string(salary * 1.05);
    }
    else if(work_exp >= 5 && work_exp < 10){
        return "Allowance - 10%, salary - " + to_string(salary * 1.1);
    }
    else if(work_exp >= 10){
        return "Allowance - 25%, salary - " + to_string(salary * 1.25);
    }
    else{
        return "Allowance - 0%, salary - " + to_string(salary);
    }
}

string task_9_2(int size_head){

    switch(size_head){
        case 53:
        case 54:
            return "XS";
        case 55:
        case 56:
            return "S";
        case 57:
        case 58:
            return "M";
        case 59:
        case 60:
            return "L";
        case 61:
        case 62:
            return "XL";
        default :
            return "not found";
        }
}

int task_9_3(int number){
    bitset<32> b_number(number);
    if(b_number[15]){
        return b_number.count();
    }
    else {
        return 32 - b_number.count();
    }
}

string test_module(bool result){
    if(result){
        return "Test is passed";
    }
    else{
        return "Test failed";
    }
}
