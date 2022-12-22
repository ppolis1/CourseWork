// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h> 
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
const int n = 8;
void gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    this_thread::sleep_for(chrono::milliseconds(400));
}
void printmas(int (*arr)[n], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << arr[i][j];
            if (j == (n - 1))
                cout << "\n";
        }
    }
}
void printMatrix(int* pointer, int N, int* end) {
    for (int* i = pointer, count = 1; i <= end; count++, i++) {
        cout << setw(4) << *i;
        if (count % N == 0) { cout << "\n"; }
    }
    cout << "\n";
}
void task1(int* pointer, int N, int* end) {
    char exercise;
    cout << "\n\n\tTask 1\n\n";
    cout << "Choose the type of matrix (a or b):";
    cin >> exercise;
    cin.sync();
    system("cls");
    if (exercise == 'a') {
        int value = 1;
        for (int i = 0; i <= N / 2 - 1; i++) {
            bool flag = false;
            for (int* x = pointer + i * N + i, j = i; x <= pointer + (i + 1) * N - i - 1; x++, j++) {
                *x = value++;
                gotoXY(j * 4, i);
                cout << *x;
                flag = true;
            }
            if (!flag) { break; }
            flag = false;
            for (int* y = pointer + (i + 2) * N - i - 1, j = i + 1; y <= end - i * N - i; y += N, j++) {
                *y = value++;
                gotoXY((N - i - 1) * 4, j);
                cout << *y;
                flag = true;
            }
            if (!flag) { break; }

            flag = false;
            for (int* z = end - i * N - i - 1, j = N - i - 2; z >= end - (i + 1) * N + i + 1; z--, j--) {
                *z = value++;
                gotoXY(j * 4, N - i - 1);
                cout << *z;
                flag = true;
            }
            if (!flag) { break; }

            flag = false;
            for (int* w = end - (i + 2) * N + i + 1, j = N - 2 - i; w >= pointer + (i + 1) * N + i; w -= N, j--) {
                *w = value++;
                gotoXY(i * 4, j);
                cout << *w;
                flag = true;
            }
            if (!flag) { break; }

        }
    }
    else if (exercise == 'b') {
        int value = 1;
        for (int i = 0; i <= N - 1; i++) {
            bool flag = false;
            for (int* j = pointer + i, x = 0; j <= end - N + i + 1; j += N, x++) {
                *j = value++;
                gotoXY(i * 4, x);
                cout << *j;
                flag = true;
            }
            i++;
            if (!flag) { break; }
            flag = false;
            for (int* z = end - N + i + 1, x = N - 1; z >= pointer + i; z -= N, x--) {
                *z = value++;
                gotoXY(i * 4, x);
                cout << *z;
                flag = true;
            }
            if (!flag) { break; }

        }
    }
    else {
        task1(pointer, N, end);
    }
    getchar();
    system("cls");
    printMatrix(pointer, N, end);
}
void print(int* arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) {
            cout << setw(4) << arr[i][j];
            if (j == (n - 1))
                cout << "\n";
        }
    }
}



void quickSort(int* pointer, int N, int* end) {
    int* start = pointer, * finish = end;
    int* pivot = pointer;
    while (start <= finish) {
        while (*start < *pivot)
            start++;
        while (*finish > *pivot)
            finish--;
        if (start <= finish)
        {
            swap(*start, *finish);
            start++;
            finish--;
        }
    }
    if (finish > pointer)
        quickSort(pointer, N, finish);
    if (start < end)
        quickSort(start, N, end);
}
void printsort(int* pointer, int N, int* end) {
    quickSort(pointer, N, end);
    printMatrix(pointer, N, end);
}
int main3() {
    srand(time(0));
    int const n = 8;
    int i = 1, p = n / 2;
    
    int arr[n][n];
    int* ptr = (int*)arr;
    int * end = arr[0] + n * n - 1;
    for (int* i = arr[0]; i <= end; i++) {
        *i = 0;
    }
    task1(ptr, n, end);
    cout << "\n";

    cout << "\n\n\tTask 2\n\n";

    int arr1[n][n];
    int arr2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = i * n + j;
        }
    }

    printmas(&arr2[0],n);
    cout << "\n\n";
    cout << "Picture a\n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            arr1[i][j] = arr2[i + p][j];
            arr1[i][j + p] = arr2[i][j];
            arr1[i + p][j + p] = arr2[i][j + p];
            arr1[i + p][j] = arr2[i + p][j + p];
        }
    }
    printmas(&arr1[0],n);

    cout << "Picture b\n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            arr1[i][j] = arr[i + p][j + p];
            arr1[i][j + p] = arr[i+p][j];
            arr1[i + p][j + p] = arr[i][j];
            arr1[i + p][j] = arr[i][j + p];
        }
    }
    printmas(&arr1[0], n);
    cout << "Picture c\n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            arr1[i][j] = arr[i + p][j];
            arr1[i][j + p] = arr[i + p][j + p];
            arr1[i + p][j] = arr[i][j];
            arr1[i + p][j + p] = arr[i][j + p];
        }
    }
    printmas(&arr1[0], n);
    cout << "Picture d\n";
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            arr1[i][j] = arr[i][j + p];
            arr1[i][j + p] = arr[i][j];
            arr1[i + p][j] = arr[i + p][j + p];
            arr1[i + p][j + p] = arr[i + p][j];
        }
    }
    printmas(&arr1[0], n);

    cout << "\n\n\tTask 3\n\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = rand() % 49 + 1;
    printmas(&arr[0], n);

    cout << "\nQuick sort\n";
    printsort(ptr, n, end);
    

    cout << "\n\n\tTask 4\n\n";
    signed int mas[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] = i * n + j+1;
            cout << setw(4) << mas[i][j];
            if (j == (n - 1))
                cout << "\n";
        }
    }
    cout << "\nEnter a number (sub):";
    int l, d, o, s;
    cin >> l;
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] -= l;
            cout << setw(4) << mas[i][j];
            if (j == (n - 1))
                cout << "\n";
        }
    }
    cout << "Enter a number (add):";
    cin >> d;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] = i * n + j + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] += d;
            cout << setw(4) << mas[i][j];
            if (j == (n - 1))
                cout << "\n";

        }
    }
    cout << endl;
    cout << "Enter a number (mul):";
    cin >> o;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] = i * n + j + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] *= o;
            cout << setw(4) << mas[i][j];
            if (j == (n - 1))
                cout << "\n";

        }
    }
    cout << endl;
    cout << "Enter a number (div):";
    cin >> s;
    float w[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[i][j] = i * n + j + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[i][j] /= s;
            cout << w[i][j] <<'\t';
            if (j == (n - 1))
                cout << "\n";

        }
    }
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
