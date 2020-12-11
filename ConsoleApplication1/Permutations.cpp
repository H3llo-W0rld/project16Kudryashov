
#include <iostream> //ввод вивід
#include <string> //строчний тип
#include <algorithm> //набір функцій (для факторіалу знадобиться)
// це клас
// Цей клас виконує завдання від А до Д 
#include <fstream> //для запису в і з файлу
#include <sstream> //робота з рядками через інтерфейс потоків
//#include "Permutations.h"

#include "Permutations.h"
#include <iostream> //ввод вивід
#include <string> //строчний тип
#include <algorithm> //набір функцій (для факторіалу знадобиться)
// це клас
// Цей клас виконує завдання від А до Д
#include <fstream> //для запису в і з файлу
#include <sstream> //робота з рядками через інтерфейс потоків
#include <cmath>

using namespace std;


// Конструктор
Permutations::Permutations(int n) {
    this->n = n;
    arr = new int[n];
    ans = new string[pow(2, n)];
    iteration = 0;
    ans1 = new string[Fact(n)];
}

//Створення масиву
void Permutations::create_array() {

    cout << "Масив цїлих чисел\n"; //  cout вивід на екран
    for (int i = 0; i <
        n; i++) { // Це цикл - треба щоб задати масив. По факту він запитує n разів що помістити в i-ту ячейку масиву
        cout << "[" << i + 1 << "]: "; // але перед цим показує який елемет масиву по рахунку вводиться
        cin >> arr[i]; //це зчитує введене в консолі значення
    }
}

void Permutations::show_all_subsets(int num, string s) {
    if (num == n) // == це порівняння, а не надання значення
    {
        ans[iteration] = s; //рекурсія
        iteration++;
        if (iteration == pow(2, n)) {
            int flag;
            for (int j = 0; j < pow(2, n); j++) {
                flag = 0;
                for (int k = 0; k < j; k++) {
                    if (ans[j] == ans[k])
                        flag = 1;
                }
                if (flag == 0)
                    cout << ans[j] << "\n";
            }
            iteration = 0;
        }
        return;
    }
    show_all_subsets(num + 1, s);
    s = s + to_string(arr[num]) + ' ';
    show_all_subsets(num + 1, s);
}


void Permutations::show_subsets_k(int k) { //не  рекурсія
    int flag;
    for (int j = 0; j < pow(2, n); j++) {
        flag = 0;
        for (int k = 0; k < j - 1; k++) {
            if (ans[j] == ans[k])
                flag = 1;
        }
        if (flag == 0 && count(ans[j].begin(), ans[j].end(), ' ') == k)
            cout << ans[j] << "\n";
    }
}

// рекурсивна функція яка рахує факторіал
// рекурсія - функція, яка викликає сама себе
int Permutations::Fact(int x) // для цього був клас алгоритм
{
    if (x == 0)
        return 1;
    return x * Fact(x - 1);
}

void Permutations::show_all_Permutations(int l) {
    int i;
    string s;
    if (l == n) {
        for (i = 0; i < n; i++)
            s = s + std::to_string(arr[i]) + ' ';
        ans1[iteration] = s;
        iteration++;
        if (iteration == Fact(n)) {
            int flag;
            for (int j = 0; j < Fact(n); j++) {
                flag = 0;
                for (int k = 0; k < j; k++) {
                    if (ans1[j] == ans1[k])
                        flag = 1;
                }
                if (flag == 0)
                    std::cout << ans1[j] << "\n";
            }
            iteration = 0;
        }
    }
    else
        for (i = l; i < n; i++) {
            if (l ^
                i) { // фрагмент, який робить перестановки. Сам не зовсі розумію як воно працює, але вже декілька разів використовував і воно працює
                arr[l] ^= arr[i];
                arr[i] ^= arr[l];
                arr[l] ^= arr[i];
                show_all_Permutations(l + 1);
                arr[l] ^= arr[i];
                arr[i] ^= arr[l];
                arr[l] ^= arr[i];
            }
            else
                show_all_Permutations(l + 1);
        }
}
