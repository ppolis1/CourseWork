// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace chrono;
void quicksort(int* arr, int  endn, int begin)
{
	int mid;
	int f = begin;
	int l = endn;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++; //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (arr[l] > mid) l--; // В правой части пропускаем элементы, которые больше центрального
		if (f <= l)
		{
			swap(arr[f], arr[l]); ////Меняем элементы местами
			f++;
			l--;
		}
	}
	////Рекурсивные вызовы, если осталось, что сортировать
	if (begin < l) quicksort(arr, l, begin);
	if (f < endn) quicksort(arr, endn, f);

}
int main2()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	auto start = steady_clock::now();
	cout << endl;
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "Время: " << result.count() << " ns";

	cout << "\n\n";
	cout << "Входной массив:\n";
	const int n = 100;
	int a[n], a_sort[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 199 - 99;
		a_sort[i] = a[i];
		cout << a[i] << " ";
	}

	cout << "\n\nBubble sort";
	cout << endl;
	start = steady_clock::now();
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n - i - 1; j++)
			if (a_sort[j] > a_sort[j + 1]) {
				flag = false;
				swap(a_sort[j], a_sort[j + 1]);
			}
		if (flag)
			break;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя: " << result.count() << " ns";

	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		cout << a_sort[i] << " ";
		a_sort[i] = a[i];
	}

	cout << "\n\nShaker sort";
	cout << endl;
	start = steady_clock::now();
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n - 1 - i; j++)
			if (a_sort[j] > a_sort[j + 1]) {
				flag = false;
				swap(a_sort[j], a_sort[j + 1]);
			}
		for (int j = n - 2 - i; j > i; j--)
			if (a_sort[j] < a_sort[j - 1]) {
				flag = false;
				swap(a_sort[j], a_sort[j - 1]);
			}
		if (flag)
			break;
	}

	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя: " << result.count() << " ns";

	cout << "\nОтсортированный массив:\n";

	for (int i = 0; i < n; i++) {
		cout << a_sort[i] << " ";
		a_sort[i] = a[i];
	}

	cout << "\n\nComb sort"; //расческа

	cout << endl;
	start = steady_clock::now();
	int count = 0;
	float k = 1.247, S = n;
	while (k < S)
	{
		for (int i = 0; i + k < S; i++)
		{
			if (a_sort[i] > a_sort[int(i + k)])
				swap(a_sort[i], a_sort[int(i + k)]);
		}
		S /= k;
	}
	while (true)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (a_sort[i] > a_sort[i + 1])
			{
				swap(a_sort[i], a_sort[i + 1]);
			}
			else count++;
		}
		if (count == n - 1)
			break;
		else
			count = 0;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя: " << result.count() << " ns";

	cout << "\nОтсортированный массив:\n";

	for (int i = 0; i < n; i++) {
		cout << a_sort[i] << " ";
		a_sort[i] = a[i];
	}

	cout << "\n\nInsert sort"; // сортировка вставками

	cout << endl;
	start = steady_clock::now();
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a_sort[i];
		int j = i;
		while ((j > 0) && (x < a_sort[j - 1]))
		{
			a_sort[j] = a_sort[j - 1];
			j--;
		}
		a_sort[j] = x;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя: " << result.count() << " ns";

	cout << "\nОтсортированный массив:\n";

	for (int i = 0; i < n; i++) {
		cout << a_sort[i] << " ";
	}


	cout << "\n\nМаксимальный и минимальный элементы";

	cout << endl;
	// ищем max и min для неотсортированного массива
	int max = a[0], min = a[0];
	start = steady_clock::now();
	for (int i = 0; i < n; ++i)
	{
		max = a[i] > max ? a[i] : max;
		min = a[i] < min ? a[i] : min;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << endl;
	cout << "\nМаксимальный элемент: " << max;
	cout << "\nМинимальный элемент: " << min;
	cout << "\nВремя (неотсорт массив): " << result.count() << " ns";
	
	// ищем max и min для отсортированного массива

	start = steady_clock::now();
	int max1 = a_sort[99], min1 = a_sort[0];
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя (отсорт массив): " << result.count() << " ns";


	// сред значение  max и min
	float m, m1;

	m = float((min + max) / 2);
	cout << "\nСред значение max и min в неотсорт массиве: " << m;
	m1 = float((min1 + max1) / 2);
	cout << "\nСред значение max и min в отсорт массиве: " << m1;

	//Выводит индексы всех элементов, которые равны этому значению, и их количество.
	cout << "\n\nИндексы элементов, которые равны среднему значению:";
	start = steady_clock::now();
	int count3 = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == int(m)) {
			cout << i << " ";
			count3 += 1;
		}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << endl << "Количество элементов:" << count3;
	cout << "\nВремя в неотсорт: " << result.count() << " ns";

	start = steady_clock::now();
	int count4 = 0;
	for (int i = 0; i < n; i++)
		if (a_sort[i] == int(m)) {
			cout << i << " ";
			count4 += 1;
		}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << endl << "Количество элементов:" << count4;
	cout << "\nВремя в неотсорт: " << result.count() << " ns";


	//Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.
	cout << "\n\nВведите число a: ";

	int an, count1 = 0;
	cin >> an;
	for (int i = 0; i < n; i++)
		if (a_sort[i] < an)
			count1 += 1;
	cout << "Количество элементов меньше а: " << count1;

	//Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.
	cout << "\nВведите число b: ";

	int b, count2 = 0;
	cin >> b;
	for (int i = 0; i < n; i++)
		if (a_sort[i] > b)
			count2 += 1;
	cout << "Количество элементов больше b: " << count2;

	cout << endl;

	for (int i = 0; i < n; i++)
		a_sort[i] = a[i];


	//*
	cout << "\n\nQuick sort";

	cout << endl;
	start = steady_clock::now();

	int endn = n - 1, begin = 0;
	quicksort(a_sort, endn, begin);

	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя: " << result.count() << " ns";

	cout << endl << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
		cout << a_sort[i] << " ";


	//Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве.
	cout << "\n\nБинарный поиск";
	cout << "\nВведите число: ";

	int key;
	cin >> key;
	bool flag = false;
	int l = 0;
	int r = n - 1;
	int mid;
	start = steady_clock::now();
	while ((l <= r) && (flag != true))
	{
		mid = (l + r) / 2;
		if (a_sort[mid] == key)
			flag = true;
		if (a_sort[mid] > key)
			r = mid - 1;
		else l = mid + 1;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);

	if (flag)
		cout << "\nЧисло есть в массиве";
	else
		cout << "\nТакого элемента в массиве нет";
	cout << "\nВремя: " << result.count() << " ns";

	cout << "\n\nОбычный перебор";
	cout << "\nВведите число: ";
	int key1;
	cin >> key1;
	bool flag1 = false;
	start = steady_clock::now();
	for (int i = 0; i < n; i++) {
		if (a[i] == key1)
			flag1 = true;
		else
			flag1 = false;
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "\nВремя: " << result.count() << " ns";
	if (flag1)
		cout << "\nЧисло есть в массиве";
	else
		cout << "\nТакого элемента в массиве нет";


	//Меняет местами элементы массива, индексы которых вводит пользователь.
	cout << "\n\nИсходный массив: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << "\nВведите 2 индекса: ";
	int c, d;
	cin >> c >> d;
	cout << "\nИзмененный массив: ";
	start = steady_clock::now();
	int swap = a[c];
	a[c] = a[d];
	a[d] = swap;
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\nВремя: " << result.count() << " ns\n";    //скорость обмена

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
