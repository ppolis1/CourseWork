// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h> 
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <cstdlib>
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
void cols_by_snake(int (*a)[n], int n) {
    int i, j, k = 1;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++) {
            a[i][j] = (j % 2 ? (j + 1) * n - i  : k);
            k++;
        }
}

void output_matrix(int (*a)[n], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Sleep(30);
            cout << setw(4) << a[i][j];
            if (j == (n - 1))
                cout << "\n";
        }
    }
}


void qsort(int *arr[], int endl, int begin)
{
    int mid;
    int f = begin;
    int l = endl;
    mid = *arr[(f + l) / 2];
    while (f < l)
    {
        while (*arr[f] < mid) f++; //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (*arr[l] > mid) l--; // В правой части пропускаем элементы, которые больше центрального
        if (f <= l)
        {
            swap(arr[f], arr[l]); ////Меняем элементы местами
            f++;
            l--;
        }
    }
    ////Рекурсивные вызовы, если осталось, что сортировать
    if (begin < l) qsort(arr, l,begin);
    if (l < endl) qsort(arr, endl, f);
}
#define N 4
int main3() {
    srand(time(0));
    int const n = 8;
    int i = 1, I, j, k,
        p = n / 2;
    int M[n][n], *ptr[n * n];

    // Обнуление матрицы и инициализация указателя
    for (I = 0; I < n; ++I)
        for (j = 0; j < n; ++j)
        {
            M[I][j] = 0; ptr[I * n + j] = &M[I][j];
        }

    for (k = 1; k <= p; k++) // Число спиралей

    {

        //Верхний горизонтальный столбец 
        for (j = (k - 1), I = k-1; j < (n - k + 1); j++, I++) {
            *ptr[(k - 1) * n + j] = i++;
            gotoXY(I * 3, k-1);
            cout << *ptr[(k - 1) * n + j];
        }
        //Правый верхний столбец

        for (j = k, I = k; j < (n - k + 1); j++, I++) {
            *ptr[j * n + (n - k)] = i++;
            gotoXY((n-k)*3, I);
            cout << *ptr[j * n + (n - k)];
        }

        //Нижний горизонтальный столбец
        for (j = (n - k - 1), I=n-k-1; j >= (k - 1); --j, I--) {
            *ptr[(n - k) * n + j] = i++;
            gotoXY(I * 3, n - k );
            cout << *ptr[(n - k) * n + j];
        }

        //Левый верхний столбец

        for (j = (n - k - 1),I=n-k-1; j >= k; j--,I--) {
            *ptr[j * n + (k - 1)] = i++;
            gotoXY((k-1) * 3, I);
            cout << *ptr[j * n + (k - 1)];
        }
    }
    cout << "\n\n\n\n\n";
    cout << "b)\n";

    int arr[n][n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = i * n + j;
        }
    }
    cols_by_snake(&arr[0],n);
    output_matrix(&arr[0],n);

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
    int* pa[n];
    for (i = 0; i < n; i++)
        pa[i] = arr[i];
    qsort(pa, 0, n);
    print(pa, n);

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
