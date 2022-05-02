#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

#include "ModulesKozlov.h"
#include "ModulesZadorozhny.h"
#include "ModulesIsachenkov.h"

int main()
{
    system("chcp 1251 && cls");
    vector<entry> database;
    loadDatabase(database, "database.dat");
    do {
        int option = 0;
        cout << setfill('=') << setw(48) << "|ВІДДІЛ КАДРІВ|" << setw(32) << "" << endl;
        cout << setfill(' ') << "| " << setw(77) << left << " Це програмне забезпечення "
                "створене для роботи з особовими картками" << "|" << endl;
        cout << "| " << setw(77) << left << "працівників ф. П-2. Нижче наведено список "
                "опцій, доступних користувачу." << "|" << endl;
        cout << "| " << setw(77) << "" << "|" << endl;
        cout << "| " << setw(77) << "1. Вивести всю базу даних на екран або у текстовий файл." << "|" << endl;
        cout << "| " << setw(77) << "2. Додати новий запис до бази даних." << "|" << endl;
        cout << "| " << setw(77) << "3. Пошук запису за прізвищем." << "|" << endl;
        cout << "| " << setw(77) << "4. Вилучити запис з бази даних." << "|" << endl;
        cout << "| " << setw(77) << "5. Завершити роботу програми." << "|" << endl;
        cout << setfill('=') << setw(80) << "" << endl << setfill(' ');
        cout << "Введіть номер операції, яку ви бажаєте виконати: " << endl << ">>> ";

        if (!(cin >> option)) {
            cin.clear();
            cin.ignore();
        }

        cout << resetiosflags(ios::left);
        string surname = "";
        int id = 0;
        switch (option) {
            case 1:
                showDatabase(database);
                break;
            case 2:
                AddPersonalCard(database);
                break;
            case 3:
                cout << "Введіть прізвище працівника, чию картку ви шукаєте: " << endl << ">>> ";
                cin >> surname;
                searchPersonalCard(database, surname);
                break;
            case 4:
                cout << "Введіть ідентифікаційний номер картки, яку ви хочете вилучити: " << endl << ">>> ";
                cin >> id;
                RemovePersonalCard(database, id);
                break;
            case 5:
                saveDatabase(database, "database.dat");
                return 0;
            default:
                continue;
        }
    } while(true);
}
