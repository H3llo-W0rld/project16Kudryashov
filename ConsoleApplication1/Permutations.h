#include <string>
#ifndef Permutations_H
#define Permutations_H
using namespace std;

class Permutations
{
public:
    int n;
    int* arr;
    string* ans1;
    string* ans;
    int iteration;
    Permutations(int n);
    void create_array(void);
    void show_all_subsets(int num = 0, string s = "");


    void show_subsets_k(int k);
    // рекурсивна функція яка рахує факторіал
    // рекурсія - функція, яка викликає сама себе
    int Fact(int x);
    void show_all_Permutations(int l = 0);
};
#endif