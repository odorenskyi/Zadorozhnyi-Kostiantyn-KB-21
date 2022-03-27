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

int task_10_1(string path_output, string path_input){
    ofstream output(path_output);

    if(!output.is_open()) return -1;

    // Step 1
    output << "Задорожний Костянитин" << endl;
    output << "ЦНТУ | Кропивницький | Україна | 2022" << endl;


    // Step 2
    char punctuation[2] {'!', '?'};
    int countExclamationMark = 0;
    int countQuestionMark = 0;

    //vector<string> text;
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
    input.close();

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

vector<string> Input(){

    vector<string> input;
        string text_input_1 = R"(Блакитними очима дивиться мені в очі весна.
Вона ще молода, ніжна, усміхається святково й чисто, у її ледь чутному
диханні – збудлива таємниця свіжості, краси природи, що завжди відроджується й відроджується!

Ще недавно бігла по дніпровських кручах рудою лисицею осінь, бігла барвисто, холодним повівом несло від її прудкого руху.
Так недавно дихало в мої думки студеним запахом зів’ялого листя, а вже сьогодні лагідне, напрочуд шовковисте повітря весни купає мої очі.
Уся земля наче випромінює благодатну снагу, що помагає рости не тільки траві, квітам, деревам, а й мріям людським.

Стоять верби, опушені зелененьким листям, і, здається, вони чують сплески журавлиних сурем у піднебессі.

Упродовж усієї минулої зими я відчував: щось має статись у цьому світі, щось неминуче станеться.
І тепер, коли прийшла весна, коли війнула мені в груди першими своїми, тонкими, такими пам’ятними запахами,
коли все в мені помолоділо, мов вербове пагіння над дніпровською водою, то я добре знаю: очікуване прийшло,
наче народжене силою мого бажання, і наймення йому – синя та золота весна на дніпрових кручах.
???)";

    string text_input_2 = R"(Чим пахне літо? Стиглою полуницею, червоногарячим сонцем розігрітою, від чого її запах стає ще сильнішим,
а також теплою річковою водою, прогрітою на мілководді. Крім цього, є й аромат трави, недавно скошеної, у якій ще блукають квіткові відтінки,
але вже пробивається духмяність сіна.

Багато в червня пахощів і фарб. У яскравому його різнотрав’ї граціозно похитують голівками білосніжні ромашки,
малиново-червоними вуглинками світяться квіточки лісової герані, золотаво-жовтими зірочками блищать китички звіробою.
За народними прикметами, ось-ось у лісі з’являться перші, давно очікувані гриби.

А на початку липня до літніх пахощів і фарб доєднуються нові. Тільки не треба шукати їх на галявинах.
Вони там, де високі дерева гордо тримають кучеряві крони, а в тих кронах гудуть бджоли, збираючи з жовтуватих квітів нектар,
щоб зробити один із якнайцінніших продуктів – запашний світлий липовий мед.

Чи бачили ви, як цвіте липа? Глянеш – і застигнеш у захваті! Квіти в неї білувато-жовті, зібрані в суцвіття.
І мед, і липовий цвіт мають унікальні цілющі властивості, тому з давніх-давен народ їх шанує як ліки.
)";

    string text_input_3 = R"(Психологи стверджують, що кожній людині потрібне хобі.
Мабуть, це справді так. По-перше, хобі – це відпочинок для душі, по-друге, це – можливість відрити світу щось нове, не сказане ще ніким.
Таке захоплення дарує людині естетичне задоволення,  самовдосконалення, вирізняє її серед інших, а  ще, до речі, має значний терапевтичний ефект.
Різноманіття захоплень просто вражає: колекціонування, спорт, полювання, рибальство, фотографування – усього перелічити просто неможливо!
Особливо цікавими є творчі вподобання, які потребують певних рис характеру, а саме: терпіння, креативності, ретельного обдумування тощо.
Вишивання хрестиком і бісером, плетіння з газет, виготовлення листівок, різьблення, декупаж, малювання – усе це робить ваше життя яскравим, неповторним.

Зі швидким розвитком інноваційних технологій з’явилося багато нових хобі: програмування, веб-дизайн, ведення сайтів і блогів тощо.
Щоправда, учені стверджують, що захоплення комп’ютерними іграми та спілкуванням у соціальних мережах може призвести до появи психологічної залежності.

Часто захоплення вимагає глибоких спеціальних знань, а іноді, крім відчуття задоволення та щастя, може стати ще й джерелом прибутку.
Звичайно, це відбувається тоді, коли рівень вашого захоплення високий, тобто ви стаєте справжнім майстром.
)";

    input.push_back(text_input_1);
    input.push_back(text_input_2);
    input.push_back(text_input_3);

    return input;

}

vector<string> ExpectedResultTest_10_1(){
    vector<string> expected_result;
    string er_test_10_1_1 = R"(Задорожний Костянитин
ЦНТУ | Кропивницький | Україна | 2022
Кількість знаків оклику - 1
Кількість знаків питання - 3
Блктнм чм двтьс мн в ч всн.
Вн щ млд, нжн, смхтьс свткв й чст,   лдь чтнм
дхнн – збдлв тмнц свжст, крс пррд, щ звжд вдрджтьс й вдрджтьс!

Щ ндвн бгл п днпрвськх крчх рд лсц снь, бгл брвст, хлднм пввм нсл вд  прдкг рх.
Тк ндвн дхл в м дмк стднм зпхм зв’лг лст,  вж сьгдн лгдн, нпрчд швквст пвтр всн кп м ч.
с змл нч впрмн блгдтн снг, щ пмг рст н тльк трв, квтм, дрвм,  й мрм лдськм.

Стть врб, пшн злннькм лстм, , здтьс, вн чть сплск жрвлнх срм  пднбсс.

прдвж с мнл зм  вдчвв: щсь м сттсь  цьм свт, щсь нмнч стнтьс.
 тпр, кл прйшл всн, кл вйнл мн в грд пршм свм, тнкм, ткм пм’тнм зпхм,
кл вс в мн пмлдл, мв врбв пгнн нд днпрвськ вд, т  дбр зн: чквн прйшл,
нч нрджн сл мг бжнн,  нймнн йм – сн т злт всн н днпрвх крчх.
???
)";

    string er_test_10_1_2 = R"(Задорожний Костянитин
ЦНТУ | Кропивницький | Україна | 2022
Кількість знаків оклику - 1
Кількість знаків питання - 2
Чм пхн лт? Стгл плнц, чрвнгрчм снцм рзгрт, вд чг  зпх ст щ сльншм,
 ткж тпл рчкв вд, пргрт н млквдд. Крм цьг,  й рмт трв, ндвн скшн,  кй щ блкть квткв вдтнк,
л вж прбвтьс дхмнсть сн.

Бгт в чрвн пхщв  фрб.  скрвм йг рзнтрв’ грцзн пхтть глвкм блснжн рмшк,
млнв-чрвнм вглнкм свттьс квтчк лсв грн, злтв-жвтм зрчкм блщть ктчк зврб.
З нрднм пркмтм, сь-сь  лс з’влтьс прш, двн чквн грб.

 н пчтк лпн д лтнх пхщв  фрб дднтьс нв. Тльк н трб шкт х н глвнх.
Вн тм, д вск дрв грд трмть кчрв крн,  в тх крнх гдть бджл, збрч з жвтвтх квтв нктр,
щб зрбт дн з кнйцнншх прдктв – зпшнй свтлй лпвй мд.

Ч бчл в, к цвт лп? Глнш –  зстгнш  зхвт! Квт в н блвт-жвт, збрн в сцвтт.
 мд,  лпвй цвт мть нкльн цлщ влствст, тм з двнх-двн нрд х шн к лк.

)";

    string er_test_10_1_3 = R"(Задорожний Костянитин
ЦНТУ | Кропивницький | Україна | 2022
Кількість знаків оклику - 1
Кількість знаків питання - 0
Псхлг стврджть, щ кжнй лдн птрбн хб.
Мбть, ц спрвд тк. П-прш, хб – ц вдпчнк дл дш, п-дрг, ц – мжлвсть вдрт свт щсь нв, н скзн щ нкм.
Тк зхплнн др лдн сттчн здвлнн,  смвдскнлнн, врзн  срд ншх,   щ, д рч, м знчнй трпвтчнй фкт.
Рзнмнтт зхплнь прст врж: клкцнвнн, спрт, плвнн, рбльств, фтгрфвнн – сьг прлчт прст нмжлв!
сблв цквм  тврч впдбнн, к птрбть пвнх рс хрктр,  см: трпнн, кртвнст, ртльнг бдмвнн тщ.
Вшвнн хрсткм  бсрм, плтнн з гзт, вгтвлнн лствк, рзьблнн, дкпж, млвнн – с ц рбть вш жтт скрвм, нпвтрнм.

З швдкм рзвткм ннвцйнх тхнлгй з’влс бгт нвх хб: пргрмвнн, вб-дзйн, вднн сйтв  блгв тщ.
Щпрвд, чн стврджть, щ зхплнн кмп’трнм грм т сплквннм  сцльнх мржх мж прзвст д пв псхлгчн злжнст.

Чст зхплнн вмг глбкх спцльнх зннь,  нд, крм вдчтт здвлнн т щст, мж стт щ й джрлм прбтк.
Звчйн, ц вдбвтьс тд, кл рвнь вшг зхплнн вскй, тбт в стт спрвжнм мйстрм.

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
        string test_10_2_1 = R"(Блакитними очима дивиться мені в очі весна.
Вона ще молода, ніжна, усміхається святково й чисто, у її ледь чутному
диханні – збудлива таємниця свіжості, краси природи, що завжди відроджується й відроджується!

Ще недавно бігла по дніпровських кручах рудою лисицею осінь, бігла барвисто, холодним повівом несло від її прудкого руху.
Так недавно дихало в мої думки студеним запахом зів’ялого листя, а вже сьогодні лагідне, напрочуд шовковисте повітря весни купає мої очі.
Уся земля наче випромінює благодатну снагу, що помагає рости не тільки траві, квітам, деревам, а й мріям людським.

Стоять верби, опушені зелененьким листям, і, здається, вони чують сплески журавлиних сурем у піднебессі.

Упродовж усієї минулої зими я відчував: щось має статись у цьому світі, щось неминуче станеться.
І тепер, коли прийшла весна, коли війнула мені в груди першими своїми, тонкими, такими пам’ятними запахами,
коли все в мені помолоділо, мов вербове пагіння над дніпровською водою, то я добре знаю: очікуване прийшло,
наче народжене силою мого бажання, і наймення йому – синя та золота весна на дніпрових кручах.
???
Blаkytnymy ochymа dyvytсia meni v ochi vesnа.
Vonа shche molodа, nizhnа, usmikhаietсia sviatkovo i chysto, u ii led chutnomu
dykhаnni – zbudlyvа tаiemnytsia svizhosti, krаsy pryrody, shcho zаvzhdy vidrodzhuietсia i vidrodzhuietсia!

Shche nedаvno bihlа po dniprovsкykh kruchаkh rudoiu lysytseiu osin, bihlа bаrvysto, kholodnym povivom neslo vid ii prudkoho rukhu.
Tаk nedаvno dykhаlo v moi dumky studenym zаpаkhom ziv’ialoho lystia, а vzhe sоhodni lаhidne, nаprochud shovkovyste povitria vesny kupаie moi ochi.
Usia zemlia nаche vyprominiuie blаhodаtnu snаhu, shcho pomаhаie rosty ne tilкy trаvi, kvitаm, derevаm, а i mriiam liudsкym.

Stoiat verby, opusheni zelenenкym lystiam, i, zdаietсia, vony chuiut splesky zhurаvlynykh surem u pidnebessi.

Uprodovzh usiiei mynuloi zymy ia vidchuvаv: shchos mаie stаtys u tsоmu sviti, shchos nemynuche stаnetсia.
І teper, koly pryishlа vesnа, koly viinulа meni v hrudy pershymy svoimy, tonkymy, tаkymy pаm’iatnymy zаpаkhаmy,
koly vse v meni pomolodilo, mov verbove pаhinnia nаd dniprovsкoiu vodoiu, to ia dobre znаiu: ochikuvаne pryishlo,
nаche nаrodzhene syloiu moho bаzhаnnia, i nаimennia iomu – synia tа zolotа vesnа nа dniprovykh kruchаkh.
???
)";
    test_10_2_1 += cur_time;
    test_10_2_1 += '\n';

    string test_10_2_2 = R"(Чим пахне літо? Стиглою полуницею, червоногарячим сонцем розігрітою, від чого її запах стає ще сильнішим,
а також теплою річковою водою, прогрітою на мілководді. Крім цього, є й аромат трави, недавно скошеної, у якій ще блукають квіткові відтінки,
але вже пробивається духмяність сіна.

Багато в червня пахощів і фарб. У яскравому його різнотрав’ї граціозно похитують голівками білосніжні ромашки,
малиново-червоними вуглинками світяться квіточки лісової герані, золотаво-жовтими зірочками блищать китички звіробою.
За народними прикметами, ось-ось у лісі з’являться перші, давно очікувані гриби.

А на початку липня до літніх пахощів і фарб доєднуються нові. Тільки не треба шукати їх на галявинах.
Вони там, де високі дерева гордо тримають кучеряві крони, а в тих кронах гудуть бджоли, збираючи з жовтуватих квітів нектар,
щоб зробити один із якнайцінніших продуктів – запашний світлий липовий мед.

Чи бачили ви, як цвіте липа? Глянеш – і застигнеш у захваті! Квіти в неї білувато-жовті, зібрані в суцвіття.
І мед, і липовий цвіт мають унікальні цілющі властивості, тому з давніх-давен народ їх шанує як ліки.

Chym pаkhne lito? Styhloiu polunytseiu, chervonohаriachym sontsem rozihritoiu, vid choho ii zаpаkh stаie shche sylнishym,
а tаkozh teploiu richkovoiu vodoiu, prohritoiu nа milkovoddi. Krim tsоho, ie i аromаt trаvy, nedаvno skoshenoi, u iakii shche blukаiut kvitkovi vidtinky,
аle vzhe probyvаietсia dukhmianist sinа.

Bаhаto v chervnia pаkhoshchiv i fаrb. U iaskrаvomu ioho riznotrаv’i hrаtsiozno pokhytuiut holivkаmy bilosnizhni romаshky,
mаlynovo-chervonymy vuhlynkаmy svitiatсia kvitochky lisovoi herаni, zolotаvo-zhovtymy zirochkаmy blyshchаt kytychky zviroboiu.
Zа nаrodnymy prykmetаmy, os-os u lisi z’iavliatсia pershi, dаvno ochikuvаni hryby.

А nа pochаtku lypnia do litnikh pаkhoshchiv i fаrb doiednuiutсia novi. Tilкy ne trebа shukаty ikh nа hаliavynаkh.
Vony tаm, de vysoki derevа hordo trymаiut kucheriavi krony, а v tykh kronаkh hudut bdzholy, zbyrаiuchy z zhovtuvаtykh kvitiv nektаr,
shchob zrobyty odyn iz iaknаitsinnishykh produktiv – zаpаshnyi svitlyi lypovyi med.

Chy bаchyly vy, iak tsvite lypа? Hlianesh – i zаstyhnesh u zаkhvаti! Kvity v nei biluvаto-zhovti, zibrаni v sutsvittia.
І med, i lypovyi tsvit mаiut unikаlнi tsiliushchi vlаstyvosti, tomu z dаvnikh-dаven nаrod ikh shаnuie iak liky.

)";

    test_10_2_2 += cur_time;
    test_10_2_2 += '\n';

    string test_10_2_3 = R"(Психологи стверджують, що кожній людині потрібне хобі.
Мабуть, це справді так. По-перше, хобі – це відпочинок для душі, по-друге, це – можливість відрити світу щось нове, не сказане ще ніким.
Таке захоплення дарує людині естетичне задоволення,  самовдосконалення, вирізняє її серед інших, а  ще, до речі, має значний терапевтичний ефект.
Різноманіття захоплень просто вражає: колекціонування, спорт, полювання, рибальство, фотографування – усього перелічити просто неможливо!
Особливо цікавими є творчі вподобання, які потребують певних рис характеру, а саме: терпіння, креативності, ретельного обдумування тощо.
Вишивання хрестиком і бісером, плетіння з газет, виготовлення листівок, різьблення, декупаж, малювання – усе це робить ваше життя яскравим, неповторним.

Зі швидким розвитком інноваційних технологій з’явилося багато нових хобі: програмування, веб-дизайн, ведення сайтів і блогів тощо.
Щоправда, учені стверджують, що захоплення комп’ютерними іграми та спілкуванням у соціальних мережах може призвести до появи психологічної залежності.

Часто захоплення вимагає глибоких спеціальних знань, а іноді, крім відчуття задоволення та щастя, може стати ще й джерелом прибутку.
Звичайно, це відбувається тоді, коли рівень вашого захоплення високий, тобто ви стаєте справжнім майстром.

Psykholohy stverdzhuiut, shcho kozhnii liudyni potribne khobi.
Mаbut, tse sprаvdi tаk. Po-pershe, khobi – tse vidpochynok dlia dushi, po-druhe, tse – mozhlyvist vidryty svitu shchos nove, ne skаzаne shche nikym.
Tаke zаkhoplennia dаruie liudyni estetychne zаdovolennia,  sаmovdoskonаlennia, vyrizniaie ii sered inshykh, а  shche, do rechi, mаie znаchnyi terаpevtychnyi efekt.
Riznomаnittia zаkhoplen prosto vrаzhаie: kolektsionuvаnnia, sport, poliuvаnnia, rybаlсtvo, fotohrаfuvаnnia – usоho perelichyty prosto nemozhlyvo!
Osoblyvo tsikаvymy ie tvorchi vpodobаnnia, iaki potrebuiut pevnykh rys khаrаkteru, а sаme: terpinnia, kreаtyvnosti, retelнoho obdumuvаnnia toshcho.
Vyshyvаnnia khrestykom i biserom, pletinnia z hаzet, vyhotovlennia lystivok, rizбlennia, dekupаzh, mаliuvаnnia – use tse robyt vаshe zhyttia iaskrаvym, nepovtornym.

Zi shvydkym rozvytkom innovаtsiinykh tekhnolohii z’iavylosia bаhаto novykh khobi: prohrаmuvаnnia, veb-dyzаin, vedennia sаitiv i blohiv toshcho.
Shchoprаvdа, ucheni stverdzhuiut, shcho zаkhoplennia komp’iuternymy ihrаmy tа spilkuvаnniam u sotsiаlнykh merezhаkh mozhe pryzvesty do poiavy psykholohichnoi zаlezhnosti.

Chаsto zаkhoplennia vymаhаie hlybokykh spetsiаlнykh znаn, а inodi, krim vidchuttia zаdovolennia tа shchаstia, mozhe stаty shche i dzherelom prybutku.
Zvychаino, tse vidbuvаietсia todi, koly riven vаshoho zаkhoplennia vysokyi, tobto vy stаiete sprаvzhnim mаistrom.

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

        string test_10_3_1 = R"(Задорожний Костянитин
ЦНТУ | Кропивницький | Україна | 2022
Кількість знаків оклику - 1
Кількість знаків питання - 3
Блктнм чм двтьс мн в ч всн.
Вн щ млд, нжн, смхтьс свткв й чст,   лдь чтнм
дхнн – збдлв тмнц свжст, крс пррд, щ звжд вдрджтьс й вдрджтьс!

Щ ндвн бгл п днпрвськх крчх рд лсц снь, бгл брвст, хлднм пввм нсл вд  прдкг рх.
Тк ндвн дхл в м дмк стднм зпхм зв’лг лст,  вж сьгдн лгдн, нпрчд швквст пвтр всн кп м ч.
с змл нч впрмн блгдтн снг, щ пмг рст н тльк трв, квтм, дрвм,  й мрм лдськм.

Стть врб, пшн злннькм лстм, , здтьс, вн чть сплск жрвлнх срм  пднбсс.

прдвж с мнл зм  вдчвв: щсь м сттсь  цьм свт, щсь нмнч стнтьс.
 тпр, кл прйшл всн, кл вйнл мн в грд пршм свм, тнкм, ткм пм’тнм зпхм,
кл вс в мн пмлдл, мв врбв пгнн нд днпрвськ вд, т  дбр зн: чквн прйшл,
нч нрджн сл мг бжнн,  нймнн йм – сн т злт всн н днпрвх крчх.
???
80.6377
00000000000000000000000000001010
)";

    string test_10_3_2 = R"(Задорожний Костянитин
ЦНТУ | Кропивницький | Україна | 2022
Кількість знаків оклику - 1
Кількість знаків питання - 2
Чм пхн лт? Стгл плнц, чрвнгрчм снцм рзгрт, вд чг  зпх ст щ сльншм,
 ткж тпл рчкв вд, пргрт н млквдд. Крм цьг,  й рмт трв, ндвн скшн,  кй щ блкть квткв вдтнк,
л вж прбвтьс дхмнсть сн.

Бгт в чрвн пхщв  фрб.  скрвм йг рзнтрв’ грцзн пхтть глвкм блснжн рмшк,
млнв-чрвнм вглнкм свттьс квтчк лсв грн, злтв-жвтм зрчкм блщть ктчк зврб.
З нрднм пркмтм, сь-сь  лс з’влтьс прш, двн чквн грб.

 н пчтк лпн д лтнх пхщв  фрб дднтьс нв. Тльк н трб шкт х н глвнх.
Вн тм, д вск дрв грд трмть кчрв крн,  в тх крнх гдть бджл, збрч з жвтвтх квтв нктр,
щб зрбт дн з кнйцнншх прдктв – зпшнй свтлй лпвй мд.

Ч бчл в, к цвт лп? Глнш –  зстгнш  зхвт! Квт в н блвт-жвт, збрн в сцвтт.
 мд,  лпвй цвт мть нкльн цлщ влствст, тм з двнх-двн нрд х шн к лк.

80.6377
00000000000000000000000000001010
)";

    string test_10_3_3 = R"(Задорожний Костянитин
ЦНТУ | Кропивницький | Україна | 2022
Кількість знаків оклику - 1
Кількість знаків питання - 0
Псхлг стврджть, щ кжнй лдн птрбн хб.
Мбть, ц спрвд тк. П-прш, хб – ц вдпчнк дл дш, п-дрг, ц – мжлвсть вдрт свт щсь нв, н скзн щ нкм.
Тк зхплнн др лдн сттчн здвлнн,  смвдскнлнн, врзн  срд ншх,   щ, д рч, м знчнй трпвтчнй фкт.
Рзнмнтт зхплнь прст врж: клкцнвнн, спрт, плвнн, рбльств, фтгрфвнн – сьг прлчт прст нмжлв!
сблв цквм  тврч впдбнн, к птрбть пвнх рс хрктр,  см: трпнн, кртвнст, ртльнг бдмвнн тщ.
Вшвнн хрсткм  бсрм, плтнн з гзт, вгтвлнн лствк, рзьблнн, дкпж, млвнн – с ц рбть вш жтт скрвм, нпвтрнм.

З швдкм рзвткм ннвцйнх тхнлгй з’влс бгт нвх хб: пргрмвнн, вб-дзйн, вднн сйтв  блгв тщ.
Щпрвд, чн стврджть, щ зхплнн кмп’трнм грм т сплквннм  сцльнх мржх мж прзвст д пв псхлгчн злжнст.

Чст зхплнн вмг глбкх спцльнх зннь,  нд, крм вдчтт здвлнн т щст, мж стт щ й джрлм прбтк.
Звчйн, ц вдбвтьс тд, кл рвнь вшг зхплнн вскй, тбт в стт спрвжнм мйстрм.

80.6377
00000000000000000000000000001010
)";

    expected_result.push_back(test_10_3_1);
    expected_result.push_back(test_10_3_2);
    expected_result.push_back(test_10_3_3);

    return expected_result;
}
