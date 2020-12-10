class Permutations { //������������
public:// ��� ���������� ����������. ³� ��� �� ����'�������, �� ������� �� �������� ���� � ������ ����� � ����������
    // �� ���� �����
    // �� ����� ��������� � ������� �����
    int n;// �� ���� ����� ������� �� ������� �������� � �����
    // � �� ������������ ������ �����
    // ǳ����� �������� ������� ���� � ���������� �� ����� �� ���������� �� � ����������, � ������ �� ��� n
    int* arr = new int[n];// �� ���� ������� �� ��� �����
    ~Permutations() {//����������
        delete[] arr;
        delete[] ans;
    }
    // ����� ���� ����� 
    void create_array()
    {
        cout << "����� ����� �����\n"; //  cout ���� �� �����
        for (int i = 0; i < n; i++) { // �� ���� - ����� ��� ������ �����. �� ����� �� ������ n ���� �� �������� � i-�� ������ ������
            cout << "[" << i + 1 << "]: "; // ��� ����� ��� ������ ���� ������ ������ �� ������� ���������
            cin >> arr[i]; //�� ����� ������� � ������ ��������
        }
    }
    // �� ���� ����� ��� ����� ���� ���������� ������� �������� ������ � �������� � ���� � ������� ������. ������ ������ � ��������� ���
    string* ans = new string[pow(2, n)];// pow �� �������� � ������ 2 � ������ n
    int iteration = 0;
    // ��� ���� ��������� ����� �����: ���� �������� {1} ��������� {{}, {1}}
    //���{ 1, 2 } ������{ {}, {1} }, ������� �� 2 �� ����� ���������, ��� ��������{ {2}, {1, 2} } � ������ �ᒺ������ �{ {}, {1} }, ��� ��������{ {}, {1}, {2}, {1, 2} }
    //����������, ���� �� ������ �� n
    void show_all_subsets(int num = 0, string s = "") {

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


    void show_subsets_k(int k) { //��  �������
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
    int Fact(int x) // ��� ����� ��� ���� ��������
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
                if (l ^ i) { // ��������, ���� ������ ������������. ��� �� ���� ������ �� ���� ������, ��� ��� ������� ���� �������������� � ���� ������
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