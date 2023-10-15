#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "КАЛЬКУЛЯТОР" << endl;
        cout << "Чтобы выбрать действие, нужно ввести один из параметров:" << endl;
        cout << "-l: ln x (количество операндов - 1)" << endl;
        cout << "-o: log(y) x (количество операндов - 2)" << endl;
        cout << "Для того чтобы продолжить, запустите программу еще раз с нужными параметрами и введите значения через пробел" << endl;
    }

    int opt; 
    double x, base, result;

    while ((opt = getopt(argc, argv, "l:o:h")) != -1) {
        switch (opt) {
        case 'h':
            cout << "КАЛЬКУЛЯТОР" << endl;
            cout << "Чтобы выбрать действие, нужно ввести один из параметров:" << endl;
            cout << "-l: ln x (количество операндов - 1)" << endl;
            cout << "-o: log(y) x (количество операндов - 2)" << endl;
            cout << "Для того чтобы продолжить, запустите программу еще раз с нужными параметрами и введите значения через пробел" << endl;
            break;

        case 'l':
            if (argc != 3) {
                cout << "Ошибка: для параметра -l должен быть указан только один операнд." << endl;
                break;
            }
            x = stod(argv[2]);
            result = log(x);
            cout << "ln(" << x << ") = " << result << endl;
            break;

        case 'o':
            if (argc != 4) {
                cout << "Ошибка: для параметра -o должно быть указано два операнда." << endl;
                break;
            }
            base = stod(argv[2]);
            x = stod(argv[3]);
            result = log(x) / log(base);
            cout << "log_" << base << "(" << x << ") = " << result << endl;
            break;
        }
    }

    return 0;
}
