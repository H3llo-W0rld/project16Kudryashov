// KudryashovAnatoliy16.cpp : Цей файл містить функцію "main". Тут починається і закінчується виконання програми

#include <iostream> //ввод вивід
#include <string> //строчний тип
#include <algorithm> //набір функцій (для факторіалу знадобиться)
// це клас
// Цей клас виконує завдання від А до Д 
#include <fstream> //для запису в і з файлу
#include <sstream> //робота з рядками через інтерфейс потоків
using namespace std; //

class Permutations { //перестановки
public:// Цей модіфікатор приватності. Він тут не обов'язковий, він відповідає за видимість полів и методів класу в наслідниках
    // Це поля класу
    // Їх можна вткликати в методах класу
    int n;// Це поле класу відповідає за кількість елементів в масиві
    // А це динамический массив нижче
    // Зірочка дозволяє виділяти місце в оперативці під масив не константою як в статичному, а змінною як ось n
    int* arr = new int[n];// Це поле відповідає за сам масив

    // Метод задає масив 
    void create_array()
    {
        cout << "Масив цїлих чисел\n"; //  cout вивід на екран
        for (int i = 0; i < n; i++) { // Це цикл - треба щоб задати масив. По факту він запитує n разів що помістити в i-ту ячейку масиву
            cout << "[" << i + 1 << "]: "; // але перед цим показує який елемет масиву по рахунку вводиться
            cin >> arr[i]; //це зчитує введене в консолі значення
        }
    }
    // ці поля треба щоб можна було порахувати кількість ітерацій рекурсії і виписати в поле з масивом відповіді. відповіді будуть в строчному типі
    string* ans = new string[pow(2, n)];// pow це зведення в степінь 2 в степені n
    int iteration = 0;
    // код шукає підмножини таким чином: Набір підмножин {1} становить {{}, {1}}
    //Для{ 1, 2 } візьміть{ {}, {1} }, додайте по 2 до кожної підмножини, щоб отримати{ {2}, {1, 2} } і візьміть об’єднання з{ {}, {1} }, щоб отримати{ {}, {1}, {2}, {1, 2} }
    //Повторюйте, поки не дійдете до n
    void show_all_subsets(int num = 0, string s = "") {

        if (num == n) // == це порівняння, а не надання значення
        {
            ans[iteration] = s;
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


    void show_subsets_k(int k) { //не  рекурсія
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
    int Fact(int x)
    {
        if (x == 0)
            return 1;
        return x * Fact(x - 1);
    }
    string* ans1 = new string[Fact(n)];
    void show_all_Permutations(int l = 0) {
        int i;
        string s;
        if (l == n) {
            for (i = 0; i < n; i++)
                s = s + to_string(arr[i]) + ' ';
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
                        cout << ans1[j] << "\n";
                }
                iteration = 0;
            }
        }
        else
            for (i = l; i < n; i++) {
                if (l ^ i) { // фрагмент, який робить перестановки. Сам не зовсі розумію як воно працює, але вже декілька разів використовував і воно працює
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

};
int main()
{
    setlocale(LC_ALL, "russian"); //ukrainian на жаль не працює
    int n;
    int k;
    int flg; //змінні описані - існують поза функцією, не описані лише в ній
    while (true) {
        cout << "Запустити тест з файлу - 2\n запустити тест - 1\n Завершити роботу - 0\n";
        cin >> flg;
        if (flg == 2) {
            ifstream in("test.txt"); //відкриваємо файл для читання
            string line;
            getline(in, line);
            n = stoi(line);
            getline(in, line);
            int* N = new int[n]; //n - кількість  цілих чисел в строці
            istringstream iss(line);
            for (int i = 0; i < n; ++i)
                iss >> N[i];
            cout << "Наш масив з файла:\n";
            for (int i = 0; i < n; ++i)
                cout << N[i] << " ";
            cout << "\n";
            Permutations test{ n };
            test.arr = N;
            cout << "Всї пїдмасиви заданого масиву\n";
            test.show_all_subsets();
            cout << "Вкажїть k довжину пїдмасивїв якї треба вивести\n";
            cin >> k;
            test.show_subsets_k(k);
            cout << "Кїлькість всїх перестановок без повторїв\n";
            test.show_all_Permutations();
            in.close();     // закриваємо файл
        }
        if (flg == 1) { //версія для перевірки
            cout << "Вкажїть n\n";
            cin >> n;
            Permutations test{ n };
            test.create_array();
            cout << "Всї пїдмасиви заданого масиву\n";
            test.show_all_subsets();
            cout << "Вкажїть k довжину пїдмасивїв якї треба вивести\n";
            cin >> k;
            test.show_subsets_k(k);
            cout << "Кїлькість всїх перестановок без повторїв\n";
            test.show_all_Permutations();
        }
        if (flg == 0) // зачинити програму
            return 0;
    }
    return 0;
}

