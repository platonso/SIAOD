#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct element {
    int tab;
    string group;
    int codediscip;
    string day;
    string pair;
    string audit;
};

struct data {
    int n = 0;
    int N = 100;
    struct element* table = new struct element[100];  //Динамический массив
};

void t_display_row(struct element row) {
    cout << setfill(' ') << setw(1) << row.group;
    cout << setfill(' ') << setw(13) << row.codediscip;
    cout << setfill(' ') << setw(18) << row.day;
    cout << setfill(' ') << setw(14) << row.pair;
    cout << setfill(' ') << setw(16) << row.audit;
    cout << endl;
}

void t_display(struct data info)
{
    cout << "Номер группы\t" << "Код дисциплины\t" << "  День недели\t" << " Номер пары\t" << "Номер аудитории" << endl;
    int count = info.n;
    for (int row = 0; row < count; row++) {
        t_display_row(info.table[row]);
    }
}

void t_add(struct data* info)
{
    if ((*info).n < (*info).N) {
        struct element a;
        string dest;


        std::cout << "Номер группы:";
        cin >> a.group;

        string Discip[] = { "\t0 - Иностранный язык", "\t1 - Искусственный интеллект",
                "\t3 - Линейная алгебра и аналитическая геометрия",
                "\t4 - Матемаическая логика и теория алгоритмов",
                "\t5 - Математический анализ",
                "\t6 - Объектно-ориентированние программирование",
                "\t7 - Правоведение",
                "\t8 - Русский язык и культура речи",
                "\t9 - Структуры и алгоритмы обработки данных",
                "\t10 - Физика" };

        cout << "\tСправочкник дисциплин(код,дисциплина):" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << Discip[i] << endl;
        }

        std::cout << "Код дисциплины:";
        cin >> a.codediscip;

        std::cout << "День недели:";
        cin >> a.day;

        std::cout << "Номер пары:";
        cin >> a.pair;

        std::cout << "Номер аудитории:";
        cin >> a.audit;


        (*info).n += 1;
        for (int i = 0; i < (*info).n; i++) {

            for (int j = (*info).n - 1; j > i; j--) {
                (*info).table[j] = (*info).table[j - 1];
                (*info).table[j].tab = j + 1;
            }
            (*info).table[i] = a;
            (*info).table[i].tab = a.codediscip;
            break;


        }

        std::cout << "Запись добавленна!\n";
    }
    else {
        std::cout << "Таблица уже заполненна";
    }
}

void t_delete(struct data* info)
{
    if ((*info).n > 0) {
        int ind;
        std::cout << "Введите код дисциплины: ";
        cin >> ind;
        if ((ind > 0)) {
            for (int i = ind - 1; i < (*info).n; i++) {
                element a = (*info).table[i + 1];
                a.tab -= 1;
                (*info).table[i] = a;
            }
            (*info).n -= 1;
            std::cout << "Запись удаленна!";
        }
        else {
            std::cout << "Неправильный ввод";
        }
    }
    else {
        std::cout << "Таблица уже пуста";
    }
}

void d_search(struct data info) {

    string a[100];
    int ind = 0;
    for (int i = 0; i < info.n; i++) {
        bool in_list = false;
        for (int j = 0; j < ind; j++) {
            if (info.table[i].day.compare(a[j]) == 0) {
                in_list = true;
            }
        }
        if (!in_list) {
            a[ind] = info.table[i].day;
            ind++;
        }
    }
    for (int i = 0; i < ind; i++) {
        std::cout << i + 1 << ") " << a[i] << endl;
    }
    std::cout << "Выберите день недели: ";
    int n;
    cin >> n;
    cout << endl << "Номер группы\t" << "Код дисциплины\t" << "  День недели\t" << " Номер пары\t" << "Номер аудитории" << endl;
    for (int i = 0; i < info.n; i++) {
        if (info.table[i].day.compare(a[n - 1]) == 0) {
            t_display_row(info.table[i]);
        }
    }

}
