#include <iostream>
#include <ModulesZadorozhny.h>


using namespace std;

int main()
{
    int x [7]= {120, 30, 90, 7, 10, 10, 1};
    int y [7] = {2, 5, -2, -10, 4, 4, 0};
    int z [7] = {1000, 60, 6, 89, 1000, -1000, 1};

    float result [7] = {8.84, 2.10, 0.11, 408.25 , 180.64, -19.36, 2.00};

    for(int i = 0; i < 7; i ++){
        if(round(s_calculation(x[i], y[i], z[i]) * 100) / 100 == result[i] ){
            cout << "Test is passed" << endl;
        }
        else{
            cout << "Test failed" << endl;
        }
    }

    return 0;
}
