#include "../ModulesZadorozhny.h"

int main()
{
    int x = 0.0;
    int y = 0.0;
    int z = 0.0;

    int salary = 0;
    int work_exp = 0;

    int size_head = 0;

    int number = 0;
    char action;
    do{
        cout << "Enter action" << endl;
        cout << "==>";
        cin >> action;
        if(action == 'e'){
            cout << "Enter x" << endl;
            cout << "==>";
            cin >> x;
            cout << "Enter y" << endl;
            cout << "==>";
            cin >> y;
            cout << "Enter z" << endl;
            cout << "==>";
            cin >> z;
            cout << s_calculation_to_string(x, y, z) << endl;
        }
        else if(action == 'r'){
            cout << "Enter your salary" << endl;
            cout << "==>";
            cin >> salary;

            cout << "Enter your work experience" << endl;
            cout << "==>";
            cin >> work_exp;

            cout << head_task_9_1(salary, work_exp) << endl;
        }
        else if(action == 'f'){
            cout << "Enter your head circumference in centimeters" << endl;
            cout << "==>";
            cin >> size_head;

            cout << "Helmet size - ";
            cout << task_9_2(size_head) << endl;
        }
        else if(action == 't'){
            cout << "Enter number" << endl;
            cout << "==>";
            cin >> number;
            cout << task_9_3(number) << endl;
        }
        else if(action != 'g' && action != 'G' && action != 'o'){
            cout << '\a' << endl;
        }
    }while(action != 'g' && action != 'G' && action != 'o');
    return 0;
}
