#include <iostream>
#include<string>

using namespace std;

void computeLPS(string pat, int* lps) // Функция заполнения массива lps
{
    int j = 0;

    lps[0] = 0;

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void IsKPeriodic(int K, const string& str) // функция подсчета повторений на основе КМП 
{
    if (K < 1) 
    {
        cout << "K должно быть больше 0" << endl;
    }
    else
    {
        string pat; // формируем подстрку
        for (int i = 0; i < K; ++i)
            pat.push_back(str[i]);

        int* lps = new int[pat.size()];

        computeLPS(pat, lps); // вычисляем lps подстроки

        int i = 0;
        int j = 0;
        int value = 0;
        while (i < str.size()) {
            if (pat[j] == str[i])
            {
                j++;
                i++;
            }
            if (j == pat.size()) {
                value++; // подсчитываем повторения
                j = lps[j - 1];
            }

            else if (i < str.size() && pat[j] != str[i]) {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
        if (K * value == str.size()) 
            cout << "\nстрока " << str << " кратна " << K << endl;
        else cout << "\nстрока " << str << " не кратна " << K << endl;
        delete[] lps;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    string str;
    int K;
    char q;
    while (true)
    {
        cout << "\nВведите строку для проверки кратности (без пробелов): ";
        cin >> str;
        cout << "\nВведите число для проверки кратности К = ";
        cin >> K;
        IsKPeriodic(K, str);
        cout << "\nПовторим? (y or n): ";
        cin >> q;
        if (q == 'n') return 0;
    }


    return 0;
}