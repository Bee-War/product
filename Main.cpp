#include <iostream>
#include "product.h"
using namespace std;

#include <string>
#include <sstream>
#include <vector>

// Функция для преобразования строки в вектор чисел типа double
vector<double> stringToDoubleArray(const string& inputString) {
    vector<double> result;
    stringstream ss(inputString);
    double num;
    // Читаем числа из stringstream и добавляем их в вектор
    while (ss >> num) {
        result.push_back(num); //1 2 5 6 7
        // Пропускаем пробел после числа, если есть
        if (ss.peek() == ' ') { // считываем следующий символ
            ss.ignore();        // отбрасывает следующий символ если он пробел
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Product> backpack;

    int cickle = 1;
    while (cickle)
    {
        cout <<"-1 - Запустить тестовое приложение \n1- Добавить продукт \n2- Получить название продукта \n3- Получить массу продукта \n4- Получить текущую температуру продукта \n5- Получить максимальную температуру продукта\n6- Получить минимальную температуру продукта\n7- Получить состояние продукта \n8- Получить теплоемкость продукта\n9- Передать тепло продукту\n10- Протестирвать передачу тепла\n0- завершить программу\n:" ;
        cin >> cickle;

        switch (cickle)
        {
        case -1:
            MySpace::Test();

            break;
        case 1:
        {
            string name, str; // сохранение имени продукта и строки его данных
            vector<double> data;
            bool check = true; // проверка на корректность ввода
            cout << "Введите наименование продукта:";
            cin >> name;
            cout << "Введите данные продукта в формате:\nмасса температура макс.темп мин.темп теплоёмкость\n";
            cout << "Или введите -1 для выхода из раздела\n:";
            cin.ignore(); // пропуск потока данных, что бы не захватывалась пустая строка
            getline(cin,str); // ввод строки данных продукта
            data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double

            while (check)
            {
                if (data[0] != -1)
                {
                    if ((data[0] > 0) && (data[2] > data[3]) && (data[4] > 0) && (data[1] > data[3]) && (data[1] < data[2]))
                    {
                        check = false;
                        cout << "Продукт добавлен.\n";
                        system("pause"); // удержание консоли для удобства чтения
                    }
                    else
                    {
                        cout << "введены неккоректные данные, введите корректные данные снова, или введите -1, для выхода из раздела\n";
                        cout << "Введите данные продукта в формате:\n";
                        cout << "масса температура макс.темп мин.темп теплоёмкость\n:";
                        getline(cin, str); // ввод строки данных продукта
                        data = stringToDoubleArray(str); // разбиение строки и перевод в вектор формата double
                    }
                }
                else
                    break;
            }
            if (check)
                break; // выход из программы записи

            Product eda(name,data[0], data[1], data[2], data[3], data[4] ); // создание записи данных продукта
            backpack.push_back(eda); // запись данных продукта в вектор
        }
            break;

        case 2:
            if (backpack.size() != 0)
            {
                for (int i=0; i < backpack.size(); i++) {
                    cout << backpack[i].getName() << endl;
                }
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 3:
            if (backpack.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < backpack.size(); i++) {
                    cout << i+1 << "-" << backpack[i].getName() << endl;
                }
                cout << "Введите номер продукта, чью массу вы хотели бы узнать:" << endl;
                cin >> j;
                if (j>0 && j< backpack.size()+1)
                {
                    j = j - 1;
                    cout << "вес " << backpack[j].getName() << " = " << backpack[j].getMass() << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 4:
            return 0;
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 5:
            if (backpack.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < backpack.size(); i++) {
                    cout << i + 1 << "-" << backpack[i].getName() << endl;
                }
                cout << "Введите номер продукта, чью максимальную температуру вы хотели бы узнать:" << endl;
                cin >> j;
                if (j > 0 && j < backpack.size() + 1)
                {
                    j = j - 1;
                    cout << "Максимальная температура " << backpack[j].getName() << " = " << backpack[j].getMaxTemperature() << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 6:
            if (backpack.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < backpack.size(); i++) {
                    cout << i + 1 << "-" << backpack[i].getName() << endl;
                }
                cout << "Введите номер продукта, чью минимльную температуру вы хотели бы узнать:" << endl;
                cin >> j;
                if (j > 0 && j < backpack.size() + 1)
                {
                    j = j - 1;
                    cout << "Минимальная температура " << backpack[j].getName() << " = " << backpack[j].getMinTemperature() << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 7:
            if (backpack.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < backpack.size(); i++) {
                    cout << i + 1 << "-" << backpack[i].getName() << endl;
                }
                cout << "Введите номер продукта, чьё состояние вы хотели бы узнать:" << endl;
                cin >> j;
                if (j > 0 && j < backpack.size() + 1)
                {
                    j = j - 1;
                    cout << "Состояние " << backpack[j].getName() << " = " << backpack[j].getState() << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 8:
            if (backpack.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < backpack.size(); i++) {
                    cout << i + 1 << "-" << backpack[i].getName() << endl;
                }
                cout << "Введите номер продукта, чью теплоёмкость вы хотели бы узнать:" << endl;
                cin >> j;
                if (j > 0 && j < backpack.size() + 1)
                {
                    j = j - 1;
                    cout << "Теплоёмкость " << backpack[j].getName() << " = " << backpack[j].getHeatCapacity() << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        case 9:
            
        return 0;
        case 10:
            if (backpack.size() != 0)
            {
                int j = 0;
                for (int i = 0; i < backpack.size(); i++) {
                    cout << i + 1 << "-" << backpack[i].getName() << endl;
                }
                cout << "Введите номер продукта, которому передаётся тепло:" << endl;
                cin >> j;
                if (j > 0 && j < backpack.size() + 1)
                {
                    j = j - 1;
                    double Q = 0;
                    cout << "Введите количество передаваемого тепла:" << endl;
                    cin >> Q;
                    cout << "Если продукту " << backpack[j].getName() << " будет передано столько тепла "  << endl;
                    cout << "Его температура " << backpack[j].getName() << " станет " << backpack[j].getFinalTemperatureAfterHeatTransfer(Q) << endl;
                }
                else
                    cout << "Неверно набран номер...";
            }
            else
                cout << "В рюкзаке нет продуктов\n";
            system("pause"); // удержание консоли для удобства чтения
            break;
        default:
            break;
        }

    }

    return 0;
}
