// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main1()
{ // 1)

    cout << "\n\n\t\tTask 1\n";
    setlocale(0, "");
    cout << "int:" << sizeof(int) << "\n";
    cout << "short int:" << sizeof(short int) << "\n";
    cout << "long int:" << sizeof(long int) << "\n";
    cout << "float:" << sizeof(float) << "\n";
    cout << "double:" << sizeof(double) << "\n";
    cout << "long double:" << sizeof(long double) << "\n";
    cout << "char:" << sizeof(char) << "\n";
    cout << "bool:" << sizeof(bool);

    // 2)
    cout << "\n\n\t\tTask 2\n";
    cout << "Enter int: ";
    int input;
    cin >> input;
    int a = sizeof(int) * 8; // a = 32
    unsigned int mask = 1 << (a - 1); // 1000...00


    for (int i = 1; i <= a; i++)
    {
        cout << (bool)(input & mask);

        if (i == 1 || i % 8 == 0)
            cout << " ";

        mask >>= 1;
    }
    cout << "\n";


    // идз 2 (int)

    input = ~input;
    mask = 1 << (a - 1);
    for (int i = 1; i <= a; i++)
    {
        cout << (bool)(input & mask);

        if (i == 1 || i % 8 == 0)
            cout << " ";

        mask >>= 1;
    }
    cout << "\n";

    // 3)

    mask = 1 << (a - 1);

    cout << "\n\n\t\tTask 3\n";
    union {
        int tool;
        float f;
    };
    cout << "Enter float: ";
    cin >> f;

    for (int i = 1; i <= a; i++)
    {
        cout << ((tool & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        mask >>= 1;
    }
    cout << "\n";

    // идз 3 (float)

    tool = ~tool;
    mask = 1 << (a - 1);
    for (int i = 1; i <= a; i++)
    {
        cout << ((tool & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        mask >>= 1;
    }
    cout << "\n";

    // 4)

    cout << "\n\n\t\tTask 4\n";
    union {
        double d;
        int arr[2];
    };
    cout << "Enter double: ";
    cin >> d;
    mask = 1 << (a - 1);


    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[1] & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        mask >>= 1;
    }

    mask = 1 << (a - 1);
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[0] & mask) ? 1 : 0);
        if (i % 8 == 0)
            cout << " ";
        mask >>= 1;
    }
    cout << "\n";

    //идз 4 (double)

    mask = 1 << (a - 1);
    arr[1] = ~arr[1];
    arr[0] = ~arr[0];

    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[1] & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        mask >>= 1;
    }

    mask = 1 << (a - 1);
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[0] & mask) ? 1 : 0);
        if (i % 8 == 0)
            cout << " ";
        mask >>= 1;
    }
    cout << "\n";
    system("pause");
    return 0;
}
    


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
