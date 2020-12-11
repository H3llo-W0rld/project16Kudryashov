// KudryashovAnatoliy16.cpp : Цей файл містить функцію "main". Тут починається і закінчується виконання програми

#include <iostream> //ввод вивід
#include <string> //строчний тип
#include <algorithm> //набір функцій (для факторіалу знадобиться)
// це клас
// Цей клас виконує завдання від А до Д 
#include <fstream> //для запису в і з файлу
#include <sstream> //робота з рядками через інтерфейс потоків
#include "Permutations.h"



int main()
{

    setlocale(LC_ALL, "russian"); //ukrainian на жаль не працює
    int n;
    int k;
    int flg; //змінні описані - існують поза функцією, не описані лише в ній
    while (true) {
        std::cout << "Запустити тест з файлу - 2\n запустити тест - 1\n Завершити роботу - 0\n";
        std::cin >> flg;
        if (flg == 2) {
            std::ifstream in("test.txt"); //відкриваємо файл для читання
            std::string line;
            std::getline(in, line);
            n = stoi(line);
            getline(in, line);
            int* N = new int[n]; //n - кількість  цілих чисел в строці
            std::istringstream iss(line);
            for (int i = 0; i < n; ++i)
                iss >> N[i];
            std::cout << "Наш масив з файла:\n";
            for (int i = 0; i < n; ++i)
                std::cout << N[i] << " ";
            std::cout << "\n";
            Permutations test{ n };
            test.arr = N;
            std::cout << "Всї пїдмасиви заданого масиву\n";
            test.show_all_subsets();
            std::cout << "Вкажїть k довжину пїдмасивїв якї треба вивести\n";
            std::cin >> k;
            test.show_subsets_k(k);
            std::cout << "Кїлькість всїх перестановок без повторїв\n";
            test.show_all_Permutations();
            in.close();     // закриваємо файл
        }
        if (flg == 1) { //версія для перевірки
            std::cout << "Вкажїть n\n";
            std::cin >> n;
            Permutations test{ n };
            test.create_array();
            std::cout << "Всї пїдмасиви заданого масиву\n";
            test.show_all_subsets();
            std::cout << "Вкажїть k довжину пїдмасивїв якї треба вивести\n";
            std::cin >> k;
            test.show_subsets_k(k);
            std::cout << "Кїлькість всїх перестановок без повторїв\n";
            test.show_all_Permutations();
        }
        if (flg == 0) // зачинити програму
            return 0;
    }
    return 0;
}

