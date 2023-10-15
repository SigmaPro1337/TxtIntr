#include <iostream>
#include <cmath>
#include <unistd.h>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "КАЛЬКУЛЯТОР" << endl;
        cout << "Чтобы выбрать действие, нужно ввести один из параметров:" << endl;
        cout << "-l, --ln: ln x (количество операндов - 1)" << endl;
        cout << "-o, --log: log(y) x (количество операндов - 2)" << endl;
        cout << "-h, --help: Помощь" << endl;
        cout << "Для того чтобы продолжить, запустите программу еще раз с нужными параметрами и введите значения через пробел" << endl;
    }

    int opt; 
    double x, base, result;

    option long_options[] = {
        {"ln", required_argument, nullptr, 'l'},
        {"log", required_argument, nullptr, 'o'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}
    };

    while ((opt = getopt_long(argc, argv, "l:o:h", long_options, nullptr)) != -1) {
        switch (opt) {
        case 'h':
            cout << "КАЛЬКУЛЯТОР" << endl;
            cout << "Чтобы выбрать действие, нужно ввести один из параметров:" << endl;
            cout << "-l, --ln: ln x (количество операндов - 1)" << endl;
            cout << "-o, --log: log(y) x (количество операндов - 2)" << endl;
            cout << "-h, --help: Помощь" << endl;
            cout << "Для того чтобы продолжить, запустите программу еще раз с нужными параметрами и введите значения через пробел" << endl;
            break;

        case 'l':
            if (argc != 3) {
                cout << "Ошибка: для параметра -l должен быть указан только один операнд." << endl;
                break;
            }
            x = stod(optarg);
            result = log(x);
            cout << "ln(" << x << ") = " << result << endl;
            break;

        case 'o':
            if (argc != 4) {
                cout << "Ошибка: для параметра -o должно быть указано два операнда." << endl;
                break;
            }
            base = stod(optarg);
            x = stod(argv[optind]);
            result = log(x) / log(base);
            cout << "log_" << base << "(" << x << ") = " << result << endl;
            break;
        }
    }

    return 0;
}