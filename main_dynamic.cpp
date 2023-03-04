#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "header_dynamic.h"
using namespace std;


int main()
{
    system("chcp 1251 > nul");  //Подключение русского языка

    struct data info;
    info.n = 3;
    info.table[0] = { 1,"ИКБО-16-22", 8, "пн", "3", "A-1" };
    info.table[1] = { 2,"ИКБО-16-22", 4, "вт", "2", "A-2" };
    info.table[2] = { 3,"ИКБО-16-22", 3, "ср", "1", "A-3" };

    while (true) {
        std::cout << "\nОперации\n";
        std::cout << "1 - Добавить запись\n";
        std::cout << "2 - Удалить запись\n";
        std::cout << "3 - Вывести всё расписание\n";
        std::cout << "4 - Вывести расписание по дням недели\n";
        std::cout << "5 - Выйти из программы\n";
        std::cout << "Выбор: ";

        int option;
        cin >> option;
        std::cout << endl;
        switch (option) {
        case 1:
            t_add(&info);
            break;
        case 2:
            t_delete(&info);
            break;
        case 3:
            t_display(info);
            break;
        case 4:
            d_search(info);
            break;                    
            break;
        case 5:
            return(0);
            break;
        default:
            break;
        }

    }
    return 0;
}
