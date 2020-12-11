
#include <iostream> //���� ����
#include <string> //�������� ���
#include <algorithm> //���� ������� (��� ��������� �����������)
// �� ����
// ��� ���� ������ �������� �� � �� � 
#include <fstream> //��� ������ � � � �����
#include <sstream> //������ � ������� ����� ��������� ������
//#include "Permutations.h"

#include "Permutations.h"
#include <iostream> //���� ����
#include <string> //�������� ���
#include <algorithm> //���� ������� (��� ��������� �����������)
// �� ����
// ��� ���� ������ �������� �� � �� �
#include <fstream> //��� ������ � � � �����
#include <sstream> //������ � ������� ����� ��������� ������
#include <cmath>

using namespace std;


// �����������
Permutations::Permutations(int n) {
    this->n = n;
    arr = new int[n];
    ans = new string[pow(2, n)];
    iteration = 0;
    ans1 = new string[Fact(n)];
}

//��������� ������
void Permutations::create_array() {

    cout << "����� ����� �����\n"; //  cout ���� �� �����
    for (int i = 0; i <
        n; i++) { // �� ���� - ����� ��� ������ �����. �� ����� �� ������ n ���� �� �������� � i-�� ������ ������
        cout << "[" << i + 1 << "]: "; // ��� ����� ��� ������ ���� ������ ������ �� ������� ���������
        cin >> arr[i]; //�� ����� ������� � ������ ��������
    }
}

void Permutations::show_all_subsets(int num, string s) {
    if (num == n) // == �� ���������, � �� ������� ��������
    {
        ans[iteration] = s; //�������
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


void Permutations::show_subsets_k(int k) { //��  �������
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

// ���������� ������� ��� ���� ��������
// ������� - �������, ��� ������� ���� ����
int Permutations::Fact(int x) // ��� ����� ��� ���� ��������
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
                i) { // ��������, ���� ������ ������������. ��� �� ���� ������ �� ���� ������, ��� ��� ������� ���� �������������� � ���� ������
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
