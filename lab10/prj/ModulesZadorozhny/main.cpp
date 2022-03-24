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
    return "Zadorozhny Konstantin �";
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

int task_10_1(string path_output, string path_input){
    ofstream output(path_output);
    ifstream input(path_input);

    if(!output.is_open()) return -1;
    if(!input.is_open()) return -1;
    // Step 1
    output << "���������� ����������" << endl;
    output << "���� | ������������� | ������ | 2022" << endl;

    // Step 2
    char punctuation[2] {'!', '?'};
    int countExclamationMark = 0;
    int countQuestionMark = 0;

    string line;
    vector<string> text;
    char vowels[] {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};

    while(getline(input, line)){
        for(int i = 0; i < line.length(); i++){
            if(line[i] == punctuation[0]) countExclamationMark++;
            if(line[i] == punctuation[1]) countQuestionMark++;
        }
        for(int i = 0; i < 10; i++){
            line.erase(remove(line.begin(), line.end(), vowels[i]), line.end());
        }
        text.push_back(line);
    }

    output << "ʳ������ ����� ������ - " << countExclamationMark << endl;
    output << "ʳ������ ����� ������� - " << countQuestionMark << endl;

    for(int i = 0; i < text.size(); i++){
        output << text[i] << endl;
    }
    output.close();
    input.close();
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

    char ukr[] {'a', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
                '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};

    vector<string> all_text;
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
        all_text.push_back(line);
    }

    fstream add(path_file, ios::app);

    for(int i = 0; i < all_text.size(); i++){
        add << all_text[i] << endl;
    }

    char cur_time[128];
    time_t t = time(NULL);
    struct tm* ptm = localtime(&t);

    strftime(cur_time, 128, "%Y-%m-%d %H:%M:%S", ptm);

    add << cur_time << endl;
    add.close();
    input.close();

    return 0;
}

int task_10_3(float x, float y, float z, int b,string path_file){
    fstream output(path_file,
                   ios:: app);

    if(!output.is_open()) return -1;
    output << s_calculation(x, y ,z) << endl;
    bitset<32> b_number(b);
    output << b_number << endl;
    return 0;
}

vector<string> Input(){

    vector<string> input;
        string text_input_1 = R"(���������� ����� �������� ��� � ��� �����.
���� �� ������, ����, ��������� �������� � �����, � �� ���� �������
������ � �������� ������� ������, ����� �������, �� ������ ����������� � �����������!

�� ������� ���� �� ����������� ������ ����� ������� ����, ���� ��������, �������� ������ ����� �� �� �������� ����.
��� ������� ������ � �� ����� �������� ������� ������� �����, � ��� ������� ������, �������� ���������� ������ ����� ���� �� ���.
��� ����� ���� ��������� ���������� �����, �� ������ ����� �� ����� ����, �����, �������, � � ���� ��������.

������ �����, ������ ����������� ������, �, �������, ���� ����� ������� ���������� ����� � ��������.

�������� �񳺿 ������ ���� � �������: ���� �� ������� � ����� ���, ���� �������� ���������.
� �����, ���� ������� �����, ���� ������ ��� � ����� ������� �����, �������, ������ ��������� ��������,
���� ��� � ��� ���������, ��� ������� ������ ��� ����������� �����, �� � ����� ����: ��������� �������,
���� ��������� ����� ���� �������, � �������� ���� � ���� �� ������ ����� �� �������� ������.
???)";

    string text_input_2 = R"(��� ����� ���? ������� ���������, �������������� ������ ��������, �� ���� �� ����� ��� �� ��������,
� ����� ������ ������� �����, �������� �� ��������. ��� �����, � � ������ �����, ������� �������, � ��� �� �������� ������ ������,
��� ��� ����������� ��������� ���.

������ � ������ ������� � ����. � ��������� ���� �������Ⓙ ��������� ��������� �������� ������� �������,
��������-��������� ���������� �������� ������� ����� �����, ��������-������� �������� ������� ������� �������.
�� ��������� ����������, ���-��� � �� ��������� �����, ����� �������� �����.

� �� ������� ����� �� ���� ������� � ���� ���������� ���. ҳ���� �� ����� ������ �� �� ���������.
���� ���, �� ����� ������ ����� �������� ������� �����, � � ��� ������ ������ ������, �������� � ���������� ���� ������,
��� ������� ���� �� ������������ �������� � �������� ������ ������� ���.

�� ������ ��, �� ���� ����? ������ � � ��������� � ������! ���� � �� �������-����, ����� � �������.
� ���, � ������� ��� ����� ������� ������ ����������, ���� � �����-����� ����� �� ���� �� ���.
)";

    string text_input_3 = R"(��������� �����������, �� ����� ����� ������� ���.
������, �� ������ ���. ��-�����, ��� � �� ��������� ��� ����, ��-�����, �� � ��������� ������ ���� ���� ����, �� ������� �� ����.
���� ���������� ���� ����� ��������� �����������,  �����������������, ������� �� ����� �����, �  ��, �� ����, �� ������� ������������� �����.
г��������� ��������� ������ �����: ���������������, �����, ���������, ����������, �������������� � ������ ��������� ������ ���������!
�������� �������� � ������ ����������, �� ���������� ������ ��� ���������, � ����: �������, �����������, ���������� ����������� ����.
��������� ��������� � ������, ������� � �����, ������������ �������, ���������, �������, ��������� � ��� �� ������ ���� ����� ��������, �����������.

ǳ ������� ��������� ������������ ��������� �������� ������ ����� ���: �������������, ���-������, ������� ����� � ����� ����.
��������, ���� �����������, �� ���������� ������������ ������ �� ����������� � ���������� ������� ���� ��������� �� ����� ����������� ���������.

����� ���������� ������ �������� ����������� �����, � ����, ��� ������� ����������� �� �����, ���� ����� �� � �������� ��������.
��������, �� ���������� ���, ���� ����� ������ ���������� �������, ����� �� ����� �������� ��������.
)";

    input.push_back(text_input_1);
    input.push_back(text_input_2);
    input.push_back(text_input_3);

    return input;

}

vector<string> ExpectedResultTest_10_1(){
    vector<string> expected_result;
    string er_test_10_1_1 = R"(���������� ����������
���� | ������������� | ������ | 2022
ʳ������ ����� ������ - 1
ʳ������ ����� ������� - 3
������ �� ����� �� � � ���.
�� � ���, ���, ������ ����� � ���,   ��� ����
���� � ����� ���� �����, ��� ����, � ���� �������� � ��������!

� ���� ��� � ��������� ���� �� ��� ���, ��� �����, ����� ���� ��� ��  ����� ��.
�� ���� ��� � � ��� ����� ���� ���� ���,  �� ����� ����, ����� ������ ���� ��� �� � �.
�� ��� �� ����� ������ ���, � ��� ��� � ���� ���, ����, ����,  � ��� ������.

���� ���, ��� ������� ����, , �����, �� ��� ����� ������ ���  ������.

������ � ��� ��  �����: ��� � �����  ��� ���, ��� ���� ������.
� ���, �� ����� ���, �� ���� �� � ��� ���� ���, ����, ��� ����� ����,
�� �� � �� �����, �� ���� ���� �� �������� ��, �  ��� ��: ���� �����,
�� ����� �� �� ����,  ����� �� � �� � ��� ��� � ������ ����.
???
)";

    string er_test_10_1_2 = R"(���������� ����������
���� | ������������� | ������ | 2022
ʳ������ ����� ������ - 1
ʳ������ ����� ������� - 2
�� ��� ��? ���� ����, �������� ���� �����, �� ��  ��� �� � ������,
 ��� ��� ���� ��, ����� � ������. ��� ���,  � ��� ���, ���� ����,  �� � ����� ����� �����,
� �� ������� ������� ��.

��� � ���� ����  ���. � ����� �� ������ ����� ����� ����� ������ ����,
����-����� ������ ������ ����� ��� ���, ����-���� ����� ����� ���� ����.
� ����� ������, ��-��  �� ������ ���, ��� ���� ���.

� � ���� ��� � ���� ����  ��� ������ ��. ���� � ��� ��� � � �����.
�� ��, � ��� ��� ��� ����� ���� ���,  � �� ���� ���� ����, ���� � ������ ���� ����,
�� ���� �� � �������� ������ � ����� ����� ���� ��.

� ��� �, � ��� ��? ���� �  ������  ����! ��� � � ����-���, ���� � �����.
� ��,  ���� ��� ��� ����� ��� �������, �� � ����-��� ��� � �� � ��.

)";

    string er_test_10_1_3 = R"(���������� ����������
���� | ������������� | ������ | 2022
ʳ������ ����� ������ - 1
ʳ������ ����� ������� - 0
����� ��������, � ���� ��� ����� ��.
����, � ����� ��. �-���, �� � � ������ �� ��, �-���, � � ������� ���� ��� ��� ��, � ���� � ���.
�� ������ �� ��� ����� ������,  ����������, ����  ��� ���,   �, � ��, � ����� �������� ���.
������� ������ ���� ���: ��������, ����, �����, �������, �������� � ��� ����� ���� �����!
����� ����  ���� ������, � ������ ���� �� �����,  ��: �����, �������, ������ ������ ��.
����� ������  ����, ����� � ���, ������� �����, �������, ����, ����� � � � ���� �� ��� �����, �������.

� ����� ������ ������� ������ ���� ��� ��� ��: ��������, ��-����, ���� ����  ���� ��.
�����, �� ��������, � ������ ������� ��� � ��������  ������ ���� �� ������ � �� ������� ������.

��� ������ ��� ����� ������� ����,  ��, ��� ����� ������ � ���, �� ��� � � ����� �����.
�����, � ������� ��, �� ���� ��� ������ ����, ��� � ��� ������� ������.

)";

    expected_result.push_back(er_test_10_1_1);
    expected_result.push_back(er_test_10_1_2);
    expected_result.push_back(er_test_10_1_3);

    return expected_result;
}

vector<string> ExpectedResultTest_10_2(){
    char cur_time[128];
    time_t t = time(NULL);
    struct tm* ptm = localtime(&t);

    strftime(cur_time, 128, "%Y-%m-%d %H:%M:%S", ptm);

    vector<string> expected_result;
        string test_10_2_1 = R"(���������� ����� �������� ��� � ��� �����.
���� �� ������, ����, ��������� �������� � �����, � �� ���� �������
������ � �������� ������� ������, ����� �������, �� ������ ����������� � �����������!

�� ������� ���� �� ����������� ������ ����� ������� ����, ���� ��������, �������� ������ ����� �� �� �������� ����.
��� ������� ������ � �� ����� �������� ������� ������� �����, � ��� ������� ������, �������� ���������� ������ ����� ���� �� ���.
��� ����� ���� ��������� ���������� �����, �� ������ ����� �� ����� ����, �����, �������, � � ���� ��������.

������ �����, ������ ����������� ������, �, �������, ���� ����� ������� ���������� ����� � ��������.

�������� �񳺿 ������ ���� � �������: ���� �� ������� � ����� ���, ���� �������� ���������.
� �����, ���� ������� �����, ���� ������ ��� � ����� ������� �����, �������, ������ ��������� ��������,
���� ��� � ��� ���������, ��� ������� ������ ��� ����������� �����, �� � ����� ����: ��������� �������,
���� ��������� ����� ���� �������, � �������� ���� � ���� �� ������ ����� �� �������� ������.
???
Bl�kytnymy ochym� dyvyt�ia meni v ochi vesn�.
Von� shche molod�, nizhn�, usmikh�iet�ia sviatkovo i chysto, u ii led chutnomu
dykh�nni � zbudlyv� t�iemnytsia svizhosti, kr�sy pryrody, shcho z�vzhdy vidrodzhuiet�ia i vidrodzhuiet�ia!

Shche ned�vno bihl� po dniprovs�ykh kruch�kh rudoiu lysytseiu osin, bihl� b�rvysto, kholodnym povivom neslo vid ii prudkoho rukhu.
T�k ned�vno dykh�lo v moi dumky studenym z�p�khom ziv�ialoho lystia, � vzhe s�hodni l�hidne, n�prochud shovkovyste povitria vesny kup�ie moi ochi.
Usia zemlia n�che vyprominiuie bl�hod�tnu sn�hu, shcho pom�h�ie rosty ne til�y tr�vi, kvit�m, derev�m, � i mriiam liuds�ym.

Stoiat verby, opusheni zelenen�ym lystiam, i, zd�iet�ia, vony chuiut splesky zhur�vlynykh surem u pidnebessi.

Uprodovzh usiiei mynuloi zymy ia vidchuv�v: shchos m�ie st�tys u ts�mu sviti, shchos nemynuche st�net�ia.
� teper, koly pryishl� vesn�, koly viinul� meni v hrudy pershymy svoimy, tonkymy, t�kymy p�m�iatnymy z�p�kh�my,
koly vse v meni pomolodilo, mov verbove p�hinnia n�d dniprovs�oiu vodoiu, to ia dobre zn�iu: ochikuv�ne pryishlo,
n�che n�rodzhene syloiu moho b�zh�nnia, i n�imennia iomu � synia t� zolot� vesn� n� dniprovykh kruch�kh.
???
)";
    test_10_2_1 += cur_time;
    test_10_2_1 += '\n';

    string test_10_2_2 = R"(��� ����� ���? ������� ���������, �������������� ������ ��������, �� ���� �� ����� ��� �� ��������,
� ����� ������ ������� �����, �������� �� ��������. ��� �����, � � ������ �����, ������� �������, � ��� �� �������� ������ ������,
��� ��� ����������� ��������� ���.

������ � ������ ������� � ����. � ��������� ���� �������Ⓙ ��������� ��������� �������� ������� �������,
��������-��������� ���������� �������� ������� ����� �����, ��������-������� �������� ������� ������� �������.
�� ��������� ����������, ���-��� � �� ��������� �����, ����� �������� �����.

� �� ������� ����� �� ���� ������� � ���� ���������� ���. ҳ���� �� ����� ������ �� �� ���������.
���� ���, �� ����� ������ ����� �������� ������� �����, � � ��� ������ ������ ������, �������� � ���������� ���� ������,
��� ������� ���� �� ������������ �������� � �������� ������ ������� ���.

�� ������ ��, �� ���� ����? ������ � � ��������� � ������! ���� � �� �������-����, ����� � �������.
� ���, � ������� ��� ����� ������� ������ ����������, ���� � �����-����� ����� �� ���� �� ���.

Chym p�khne lito? Styhloiu polunytseiu, chervonoh�riachym sontsem rozihritoiu, vid choho ii z�p�kh st�ie shche syl�ishym,
� t�kozh teploiu richkovoiu vodoiu, prohritoiu n� milkovoddi. Krim ts�ho, ie i �rom�t tr�vy, ned�vno skoshenoi, u iakii shche bluk�iut kvitkovi vidtinky,
�le vzhe probyv�iet�ia dukhmianist sin�.

B�h�to v chervnia p�khoshchiv i f�rb. U iaskr�vomu ioho riznotr�v�i hr�tsiozno pokhytuiut holivk�my bilosnizhni rom�shky,
m�lynovo-chervonymy vuhlynk�my svitiat�ia kvitochky lisovoi her�ni, zolot�vo-zhovtymy zirochk�my blyshch�t kytychky zviroboiu.
Z� n�rodnymy prykmet�my, os-os u lisi z�iavliat�ia pershi, d�vno ochikuv�ni hryby.

� n� poch�tku lypnia do litnikh p�khoshchiv i f�rb doiednuiut�ia novi. Til�y ne treb� shuk�ty ikh n� h�liavyn�kh.
Vony t�m, de vysoki derev� hordo trym�iut kucheriavi krony, � v tykh kron�kh hudut bdzholy, zbyr�iuchy z zhovtuv�tykh kvitiv nekt�r,
shchob zrobyty odyn iz iakn�itsinnishykh produktiv � z�p�shnyi svitlyi lypovyi med.

Chy b�chyly vy, iak tsvite lyp�? Hlianesh � i z�styhnesh u z�khv�ti! Kvity v nei biluv�to-zhovti, zibr�ni v sutsvittia.
� med, i lypovyi tsvit m�iut unik�l�i tsiliushchi vl�styvosti, tomu z d�vnikh-d�ven n�rod ikh sh�nuie iak liky.

)";

    test_10_2_2 += cur_time;
    test_10_2_2 += '\n';

    string test_10_2_3 = R"(��������� �����������, �� ����� ����� ������� ���.
������, �� ������ ���. ��-�����, ��� � �� ��������� ��� ����, ��-�����, �� � ��������� ������ ���� ���� ����, �� ������� �� ����.
���� ���������� ���� ����� ��������� �����������,  �����������������, ������� �� ����� �����, �  ��, �� ����, �� ������� ������������� �����.
г��������� ��������� ������ �����: ���������������, �����, ���������, ����������, �������������� � ������ ��������� ������ ���������!
�������� �������� � ������ ����������, �� ���������� ������ ��� ���������, � ����: �������, �����������, ���������� ����������� ����.
��������� ��������� � ������, ������� � �����, ������������ �������, ���������, �������, ��������� � ��� �� ������ ���� ����� ��������, �����������.

ǳ ������� ��������� ������������ ��������� �������� ������ ����� ���: �������������, ���-������, ������� ����� � ����� ����.
��������, ���� �����������, �� ���������� ������������ ������ �� ����������� � ���������� ������� ���� ��������� �� ����� ����������� ���������.

����� ���������� ������ �������� ����������� �����, � ����, ��� ������� ����������� �� �����, ���� ����� �� � �������� ��������.
��������, �� ���������� ���, ���� ����� ������ ���������� �������, ����� �� ����� �������� ��������.

Psykholohy stverdzhuiut, shcho kozhnii liudyni potribne khobi.
M�but, tse spr�vdi t�k. Po-pershe, khobi � tse vidpochynok dlia dushi, po-druhe, tse � mozhlyvist vidryty svitu shchos nove, ne sk�z�ne shche nikym.
T�ke z�khoplennia d�ruie liudyni estetychne z�dovolennia,  s�movdoskon�lennia, vyrizniaie ii sered inshykh, �  shche, do rechi, m�ie zn�chnyi ter�pevtychnyi efekt.
Riznom�nittia z�khoplen prosto vr�zh�ie: kolektsionuv�nnia, sport, poliuv�nnia, ryb�l�tvo, fotohr�fuv�nnia � us�ho perelichyty prosto nemozhlyvo!
Osoblyvo tsik�vymy ie tvorchi vpodob�nnia, iaki potrebuiut pevnykh rys kh�r�kteru, � s�me: terpinnia, kre�tyvnosti, retel�oho obdumuv�nnia toshcho.
Vyshyv�nnia khrestykom i biserom, pletinnia z h�zet, vyhotovlennia lystivok, riz�lennia, dekup�zh, m�liuv�nnia � use tse robyt v�she zhyttia iaskr�vym, nepovtornym.

Zi shvydkym rozvytkom innov�tsiinykh tekhnolohii z�iavylosia b�h�to novykh khobi: prohr�muv�nnia, veb-dyz�in, vedennia s�itiv i blohiv toshcho.
Shchopr�vd�, ucheni stverdzhuiut, shcho z�khoplennia komp�iuternymy ihr�my t� spilkuv�nniam u sotsi�l�ykh merezh�kh mozhe pryzvesty do poiavy psykholohichnoi z�lezhnosti.

Ch�sto z�khoplennia vym�h�ie hlybokykh spetsi�l�ykh zn�n, � inodi, krim vidchuttia z�dovolennia t� shch�stia, mozhe st�ty shche i dzherelom prybutku.
Zvych�ino, tse vidbuv�iet�ia todi, koly riven v�shoho z�khoplennia vysokyi, tobto vy st�iete spr�vzhnim m�istrom.

)";

    test_10_2_3 += cur_time;
    test_10_2_3 += '\n';

    expected_result.push_back(test_10_2_1);
    expected_result.push_back(test_10_2_2);
    expected_result.push_back(test_10_2_3);

    return expected_result;
}


vector<string> ExpectedResultTest_10_3(){
    vector<string> expected_result;

        string test_10_3_1 = R"(���������� ����������
���� | ������������� | ������ | 2022
ʳ������ ����� ������ - 1
ʳ������ ����� ������� - 3
������ �� ����� �� � � ���.
�� � ���, ���, ������ ����� � ���,   ��� ����
���� � ����� ���� �����, ��� ����, � ���� �������� � ��������!

� ���� ��� � ��������� ���� �� ��� ���, ��� �����, ����� ���� ��� ��  ����� ��.
�� ���� ��� � � ��� ����� ���� ���� ���,  �� ����� ����, ����� ������ ���� ��� �� � �.
�� ��� �� ����� ������ ���, � ��� ��� � ���� ���, ����, ����,  � ��� ������.

���� ���, ��� ������� ����, , �����, �� ��� ����� ������ ���  ������.

������ � ��� ��  �����: ��� � �����  ��� ���, ��� ���� ������.
� ���, �� ����� ���, �� ���� �� � ��� ���� ���, ����, ��� ����� ����,
�� �� � �� �����, �� ���� ���� �� �������� ��, �  ��� ��: ���� �����,
�� ����� �� �� ����,  ����� �� � �� � ��� ��� � ������ ����.
???
80.6377
00000000000000000000000000001010
)";

    string test_10_3_2 = R"(���������� ����������
���� | ������������� | ������ | 2022
ʳ������ ����� ������ - 1
ʳ������ ����� ������� - 2
�� ��� ��? ���� ����, �������� ���� �����, �� ��  ��� �� � ������,
 ��� ��� ���� ��, ����� � ������. ��� ���,  � ��� ���, ���� ����,  �� � ����� ����� �����,
� �� ������� ������� ��.

��� � ���� ����  ���. � ����� �� ������ ����� ����� ����� ������ ����,
����-����� ������ ������ ����� ��� ���, ����-���� ����� ����� ���� ����.
� ����� ������, ��-��  �� ������ ���, ��� ���� ���.

� � ���� ��� � ���� ����  ��� ������ ��. ���� � ��� ��� � � �����.
�� ��, � ��� ��� ��� ����� ���� ���,  � �� ���� ���� ����, ���� � ������ ���� ����,
�� ���� �� � �������� ������ � ����� ����� ���� ��.

� ��� �, � ��� ��? ���� �  ������  ����! ��� � � ����-���, ���� � �����.
� ��,  ���� ��� ��� ����� ��� �������, �� � ����-��� ��� � �� � ��.

80.6377
00000000000000000000000000001010
)";

    string test_10_3_3 = R"(���������� ����������
���� | ������������� | ������ | 2022
ʳ������ ����� ������ - 1
ʳ������ ����� ������� - 0
����� ��������, � ���� ��� ����� ��.
����, � ����� ��. �-���, �� � � ������ �� ��, �-���, � � ������� ���� ��� ��� ��, � ���� � ���.
�� ������ �� ��� ����� ������,  ����������, ����  ��� ���,   �, � ��, � ����� �������� ���.
������� ������ ���� ���: ��������, ����, �����, �������, �������� � ��� ����� ���� �����!
����� ����  ���� ������, � ������ ���� �� �����,  ��: �����, �������, ������ ������ ��.
����� ������  ����, ����� � ���, ������� �����, �������, ����, ����� � � � ���� �� ��� �����, �������.

� ����� ������ ������� ������ ���� ��� ��� ��: ��������, ��-����, ���� ����  ���� ��.
�����, �� ��������, � ������ ������� ��� � ��������  ������ ���� �� ������ � �� ������� ������.

��� ������ ��� ����� ������� ����,  ��, ��� ����� ������ � ���, �� ��� � � ����� �����.
�����, � ������� ��, �� ���� ��� ������ ����, ��� � ��� ������� ������.

80.6377
00000000000000000000000000001010
)";

    expected_result.push_back(test_10_3_1);
    expected_result.push_back(test_10_3_2);
    expected_result.push_back(test_10_3_3);

    return expected_result;
}

string ReadFile(string path_file){
    ifstream file(path_file);
    vector<string> text;
    string read;
    while (getline(file, read)){
        text.push_back(read);
    }

    read = "";
    for(int i = 0; i < text.size(); i++){
        read += text[i] + '\n';
    }

    file.close();

    return read;
}
