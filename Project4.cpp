// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

//1. С клавиатуры или с файла (*) (пользователь сам может выбрать способ ввода) вводится последовательность,
// содержащая от 1 до 50 слов, в каждом из которых от 1 до 10 строчных латинских букв и цифр.
// Между соседними словами произвольное количество пробелов. За последним символом стоит точка.
string task1() {
incorrect:
    cout << "Введите способ ввода (1 - файл; 2 - клавиатура):";
    int input;
    cin >> input;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    string str;
    if (input == 1) {
        ifstream File;
        File.open("C:\\Users\\kotlo\\source\\repos\\ConsoleApplication8\\ConsoleApplication8\\T.txt");
        if (File.is_open()) {
            while (!File.eof()) {
                string str1;
                getline(File, str1);
                str += str1;
            }
        }
        else {
            cout << "file could not be opened";
            return "";
        }
        File.close();
    }
    else if (input == 2) {
        getline(cin, str);
    }
    else {
        goto incorrect;
    }
    return str;
}
//2. Необходимо отредактировать входной текст:
//·удалить лишние пробелы;
//·удалить лишние знаки препинания (под «лишними» подразумевается несколько подряд идущих знаков;
//·исправить регистр букв, если это требуется (пример некорректного использования регистра букв: пРиМЕр);
string task2(string str) {
    string strRes = "";
    cout << "Строка до преобразований:" << "\n" << str << "\n";
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (flag) {
                continue;
            }
            else {
                flag = true;
                strRes += str[i];
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9') {
            if (str[i] >= 'A' && str[i] <= 'Z' && !flag) {
                strRes += str[i] + 32;
            }
            else {
                strRes += str[i];
            }
            flag = false;
        }
        else {
            flag = false;
            if (str[i] == '.' && str[i + 1] == '.' && str[i + 2] == '.') {
                i += 2;
                strRes += "...";
                continue;
            }
            else if (str[i] == '.') {
                strRes += '.';
                break;
            }
            if (str[i] != str[i - 1]) {
                strRes += str[i];
            }
        }
    }
    cout << "Строка после преобразований:" << "\n" << strRes;
    return strRes;
}

//3.5. Вывести на экран только те слова последовательности, в которых первая буква слова встречается в этом слове еще раз.
void task3(string str) {
    cout << "Слово(а), в которых 1-я буква встречается ещё раз:";
    bool flagSpace = false, flag = false;
    char first = 0;
    string str1 = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (flag) {
                cout << str1 << " ";
            }
            flagSpace = true;
            flag = false;
            str1 = "";
        }
        else {
            if (flagSpace) {
                flagSpace = false;
                str1 += str[i];
                first = str[i];
                continue;
            }
            if (first == str[i]) {
                flag = true;
            }
            str1 += str[i];
        }
    }
}

//4.5. Вывести на экран ту же последовательность, переместив все цифры, содержащиеся в словах, в конец соответствующих слов.
void task4(string str) {
    cout << "Полученная строка: " << "\n";
    string str1 = "";
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            str1 += str[i];
            str.erase(i, 1);
            flag = true;
            if (str[i] >= '0' && str[i] <= '9') {
                i--;
            }
        }
        else if ((str[i] == ' ' || !(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')) && flag) {
            str.insert(i, str1);
            i += str1.length() - 1;
            str1 = "";
            flag = false;
        }
    }
    cout << str;
}

//5. Необходимо найти все подстроки, которую введёт пользователь в имеющейся строке. Реализуйте два алгоритма:
// первый алгоритма – Линейный поиск, а второй – Бойера-Мура.
void linesearch(string str)
{
    string substr, strRes = "не найдена";
    int count = 0;
    cout << "Введите искомую подстроку:";

    getline (cin, substr);
 
    cout << "\nЛинейный поиск:" << "\n";
    cout << "Индексы:";
    string str1 = "";
  
    for (int i = 0; i <= str.length() - substr.length(); i++) {
        str1 = "";
        for (int j = i; j < substr.length() + i; j++) {
            if (str[j] == substr[j - i]) {
                str1 += str[j];
            }
            else {
                continue;
            }
        }
        if (substr == str1) {
            cout << i << " ";
            strRes = "найдена";
            count += 1;
        }
    }
    cout << "; Подстрока - " << strRes << "; Найдено " << count << " соответствие(ий);\t\n";
    
}
# define NO_OF_CHARS 256
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}
void BoyerMoores(string str)
{
    string substr;
    
    cout << "Введите искомую подстроку:";
    getline(cin, substr);
    cout << "Поиск Бойера-Мура:\n";
    int m = substr.size();
    int n = str.size();
    int count = 0;
    int badchar[NO_OF_CHARS];

   
    badCharHeuristic(substr, m, badchar);

    int s = 0; 
    cout << "Индексы: ";
    while (s <= (n - m))
    {
        int j = m-1;

        while (j >= 0 && substr[j] == str[s + j])
            j--;

        if (j < 0)
        {
            cout << s << " ";
            count += 1;
            s += (s + m < n) ? m - badchar[str[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[str[s + j]]);
    }
    
    cout << "; Найдено " << count << " соответствие(ий);\t\n";
}
void newFile(string str) {
    fstream File("C:\\Users\\kotlo\\source\\repos\\ConsoleApplication8\\ConsoleApplication8\\T_new.txt", ios::out | ios::trunc);
    if (File.is_open()) {
        File << str;
    }
    else {
        cout << "file could not be opened";
    }
}

int main4() {
    setlocale(LC_ALL, "RUSSIAN");
    string str;
    string substr;
    //string sub;
    //cout << "Введите подстроку, которую вы хотите найти в строке:";
    //getline(cin, sub);
    int input = 0;
  
    while (!input) 
    {
        cout << "\nTask1\n\n";
        str = task1();
      
        cout << "\nTask2\n\n";
        str = task2(str);
        cout << "\n";

        cout << "\nTask3\n\n";
        task3(str);
        cout << "\n";
        
        cout << "\nTask4\n\n";
        task4(str);
        cout << "\n";

        cout << "\nTask5\n\n";

        linesearch(str);
        cout << "\n";
        BoyerMoores(str);
        cout << "\n";
       
        
        cout << "\n";
        cout << "Для повтора программы нажмите 0:";
        cin >> input;
    }
    newFile(str);
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
