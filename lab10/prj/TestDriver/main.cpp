#include "../ModulesZadorozhny.h"
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string path_input = "D:\\BMTP\\Zadorozhnyi-Kostiantyn-KB-21\\lab10\\TextFile\\input.txt";
    string path_output = "D:\\BMTP\\Zadorozhnyi-Kostiantyn-KB-21\\lab10\\TextFile\\output.txt";

    vector<string> input_db = Input();

    vector<string> Test_10_1 = ExpectedResultTest_10_1();

    vector<string> Test_10_2 = ExpectedResultTest_10_2();

    vector<string> Test_10_3 = ExpectedResultTest_10_3();


    ofstream auto_test("D:\\BMTP\\Zadorozhnyi-Kostiantyn-KB-21\\lab10\\TextFile\\auto_test.txt");
    for(int i = 0; i < 3; i++){
        auto_test << "Test " << i + 1 << endl;
        cout << "Test " << i + 1 << endl;

        ofstream file_input (path_input);
        file_input << input_db[i] << endl;
        file_input.close();

        //test task_10_1
        task_10_1(path_output, path_input);

        string read;
        read = ReadFile(path_output);

        if(read == Test_10_1[i]){
            auto_test << "Task 10.1 - passed" << endl;
            cout << "Task 10.1 - passed" << endl;
        }
        else{
            auto_test << "Task 10.1 - failed" << endl;
            cout << "Task 10.1 - failed" << endl;
        }

        //test task_10_2

        task_10_2(path_input);

        read = ReadFile(path_input);

        if(read == Test_10_2[i]){
            auto_test << "Task 10.2 - passed" << endl;
            cout << "Task 10.2 - passed" << endl;
        }
        else{
            auto_test << "Task 10.2 - failed" << endl;
            cout << "Task 10.2 - failed" << endl;
        }

        //test task_10_3
        task_10_3(10.5, 4.3, 5, 10, path_output);

        read = ReadFile(path_output);

        if(read == Test_10_3[i]){
            auto_test << "Task 10.3 - passed" << endl;
            cout << "Task 10.3 - passed" << endl;
        }
        else{
            auto_test << "Task 10.3 - failed" << endl;
            cout << "Task 10.3 - failed" << endl;
        }
    }
    auto_test.close();

    getchar();
    return 0;
}
