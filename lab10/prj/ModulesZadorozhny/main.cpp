#include <iostream>
#include <math.h>
#include <tgmath.h>
#include <windows.h>

#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <bitset>

using namespace std;

float s_calculation(int x, int y, int z)
{
    return (pow(3 * sin(sqrt(12 * x + log(x - 3))), y) + z/x);
}

string decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
    string str = "";
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;

        // storing remainder in temp variable.
        temp = n % 16;

        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--)
        str += hexaDeciNum[j];

    return str;
}

string boolToString(bool b){
    return b ? "true" : "false";
}

string copyright(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    return "Zadorozhny Konstantin Р’В©";
}

string returnExpression(int a, int  b){
    return "a + 1 > |b - 2| ? " + boolToString(a + 1 > abs(b - 2));
}

string decimal(int x, int y, int z){
    return "x = " + to_string(x) +
           ", y = " + to_string(y) +
           ", z = " + to_string(z);
}

string hexADecimal(int x, int y, int z){
    return "x = " + decToHexa(x) +
           ", y = " + decToHexa(y) +
           ", z = " + decToHexa(z);
}

string s_calculation_to_string(int x, int y, int z){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    return "(3 * sin * v(12 * " + to_string(x) + " + lg(" + to_string(x) + " - 3)))^" +
     to_string(y) + " + " + to_string(z) + "/" + to_string(x) + " = " + to_string(s_calculation(x, y, z));
}

string ReadFile(string path_file){
    ifstream file(path_file);
    if(!file.is_open()) return "ERROR";
    string text = "";
    string line;
    while (getline(file, line)){
        text += line + '\n';
    }
    file.close();
    return text;
}

int task_10_1(string path_output, string path_input){
    ofstream output(path_output);
    if(!output.is_open()) return -1;

    output << "Задорожний Костянитин" << endl;
    output << "ЦНТУ | Кропивницький | Україна | 2022" << endl;

    char punctuation[2] {'!', '?'};
    int countExclamationMark = 0;
    int countQuestionMark = 0;

    char vowels[] {'а', 'е', 'и', 'і', 'о', 'у', 'я', 'ю', 'є', 'ї'};

    string text = ReadFile(path_input);

    for(int i = 0; i < 10; i++){
        text.erase(remove(text.begin(), text.end(), vowels[i]), text.end());
        text.erase(remove(text.begin(), text.end(), vowels[i] - 32), text.end());
    }
    text.erase(remove(text.begin(), text.end(), 'І'), text.end());

    for(int i = 0; i < text.length(); i++){
        if(text[i] == punctuation[0]) countExclamationMark++;
        if(text[i] == punctuation[1]) countQuestionMark++;
    }

    output << "Кількість знаків оклику - " << countExclamationMark << endl;
    output << "Кількість знаків питання - " << countQuestionMark << endl;

    output << text;

    output.close();
    return 0;
}

int task_10_2(string path_file){
    ifstream input(path_file);

    if(!input.is_open()) return - 1;


    string enLower[] {"a", "b", "v", "h", "g", "d", "e", "ie", "zh", "z", "y",
                      "i", "i", "i", "k", "l", "m", "n", "o", "p", "r", "s",
                      "t", "u", "f", "kh", "ts", "ch", "sh", "shch", "iu", "ia", ""};

    string enUpper[] = {"A", "B", "V", "H", "G", "D", "E", "Ye", "Zh", "Z", "Y",
                      "I", "Yi", "Y", "K", "L", "M", "N", "O", "P", "R", "S",
                      "T", "U", "F", "Kh", "Ts", "Ch", "Sh", "Shch", "Yu", "Ya", ""};

    char ukr[] {'a', 'б', 'в', 'г', 'ґ', 'д', 'е', 'є', 'ж', 'з', 'и',
                'і', 'ї', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с',
                'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ю', 'я', 'ь'};


    string all_text;
    string line;

    while(getline(input, line)){
        for(int i = 0; i < line.length(); i++){
            for(int j = 0; j < 33; j++){
                if(line[i] == ukr[j]) {
                    line.replace(i, 1, enLower[j]);
                    break;
                }
                if(line[i] == ukr[j] - 32) {
                    line.replace(i, 1, enUpper[j]);
                    break;
                }
            }
        }
        all_text += line + '\n';
    }
    input.close();

    fstream add(path_file, ios::app);

    add << all_text << endl;

    char cur_time[128];
    time_t t = time(NULL);
    struct tm* ptm = localtime(&t);

    strftime(cur_time, 128, "%Y-%m-%d %H:%M:%S", ptm);

    add << cur_time << endl;
    add.close();

    return 0;
}

int task_10_3(float x, float y, float z, int b,string path_file){
    fstream output(path_file, ios:: app);

    if(!output.is_open()) return -1;

    output << s_calculation(x, y ,z) << endl;
    bitset<32> b_number(b);
    output << b_number << endl;
    output.close();
    return 0;
}

vector<string> Input(string path_input_1, string path_input_2, string path_input_3){

    vector<string> input;
    string text_input_1 = ReadFile(path_input_1);

    string text_input_2 = ReadFile(path_input_2);

    string text_input_3 = ReadFile(path_input_3);

    input.push_back(text_input_1);
    input.push_back(text_input_2);
    input.push_back(text_input_3);

    return input;

}

vector<string> ExpectedResultTest_10_2(string path_test_10_2_1, string path_test_10_2_2, string path_test_10_2_3){
    char cur_time[128];
    time_t t = time(NULL);
    struct tm* ptm = localtime(&t);

    strftime(cur_time, 128, "%Y-%m-%d %H:%M:%S", ptm);

    vector<string> expected_result;
        string test_10_2_1 = ReadFile(path_test_10_2_1);
    test_10_2_1 += cur_time;
    test_10_2_1 += '\n';

    string test_10_2_2 = ReadFile(path_test_10_2_2);

    test_10_2_2 += cur_time;
    test_10_2_2 += '\n';

    string test_10_2_3 = ReadFile(path_test_10_2_3);

    test_10_2_3 += cur_time;
    test_10_2_3 += '\n';

    expected_result.push_back(test_10_2_1);
    expected_result.push_back(test_10_2_2);
    expected_result.push_back(test_10_2_3);

    return expected_result;
}
