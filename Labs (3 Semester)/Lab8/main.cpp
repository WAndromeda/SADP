#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void setN(int&);
void setM(int&);
void inPut(int**, int, int);
void inPut(string**, int, int);
void sort(int**, int, int);
void sort(string**, int, int);
void outPut(int**, int, int);
void outPut(string**, int, int);

int main(){
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    int** arrayI;
    string** arrayS;
    int n, m;
    setN(n);
    setM(m);
    bool com;
    cout << "����� ��� ������ ��� ����� �� ������ ������������: 0 - ����� ����� | 1 -  ������: ";
    cin >> com;
    switch(com){
    case 0:
        arrayI = new int*[n];
        for (int i = 0; i < n; i++)
            arrayI[i] = new int[m];
        inPut(arrayI, n, m);
        outPut(arrayI, n, m);
        sort(arrayI, n, m);
        outPut(arrayI, n, m);
        break;
    case 1:
        arrayS = new string*[n];
        for (int i = 0; i < n; i++)
            arrayS[i] = new string[m];
        inPut(arrayS, n, m);
        outPut(arrayS, n, m);
        sort(arrayS, n, m);
        outPut(arrayS, n, m);
    }
    return 0;
}

void setN(int& n){
    cout << "������� ���������� ����� �������: ";
    cin >> n;
}

void setM(int& m){
    cout << "������� ���������� ����� �������: ";
    cin >> m;
}

void inPut(int** array, int n, int m){
    cout << "������� " << n << " �����(-�, -�) � " << m << " ��������(-��, -��) (���� �� �������:)" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
}

void inPut(string** array, int n, int m){
    cout << "������� " << n << " �����(-�, -�) � " << m << " ��������(-��, -��) (���� �� �������:)" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
}

void sort(int** array, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-1; j++)
            for (int k = 0; k < m-1-j; k++)
                if (array[i][k] > array[i][k+1])
                    swap(array[i][k], array[i][k+1]);
}

void sort(string** array, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-1; j++)
            for (int k = 0; k < m-1-j; k++)
                if (array[i][k] > array[i][k+1])
                    swap(array[i][k], array[i][k+1]);
}

void outPut(int** array, int n, int m){
    cout << "������� ������ ���� (����� �� �������)" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

void outPut(string** array, int n, int m){
    cout << "������� ���������� ���� (����� �� �������): " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout <<  array[i][j] << " ";
        cout << endl;
    }
}
