#include "../ModulesZadorozhny.h"

int main(){
    int salary[5]= {10000, 10000, 10000, 10000, 100000};
    int work_exp[5] = {3, 6, 11, 1, 30};
    int result_task_9_1[5] = {10500, 11000, 12500, 10000 , 125000};

    int size_head[5] = {53, 55, 58, 60, 61};
    string result_task_9_2 [5] = {"XS", "S", "M", "L", "XL"};

    int number[5] = {58, 39854, 67009, 40008050, 3987532};
    int result_task_9_3[5] = {28, 10, 26, 19, 11};

    cout << "Test task 9.1" << endl;
    for(int i = 0; i < 5; i++){
        cout << test_module( result_task_9_1[i] == task_9_1(salary[i], work_exp[i])) << endl;
    }

    cout << "Test task 9.2" << endl;
    for(int i = 0; i < 5; i++){
        cout << test_module(result_task_9_2[i] == task_9_2(size_head[i])) << endl;
    }

    cout << "Test task 9.3" << endl;
    for(int i = 0; i < 5; i++){
        cout << test_module(result_task_9_3[i] == task_9_3(number[i])) << endl;
    }

    return 0;
}

