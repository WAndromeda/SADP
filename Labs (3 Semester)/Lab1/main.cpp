#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

double check();

int main(){
    setlocale(LC_ALL, "Russian");
    short int k;
        do {
            double *input = new double[2];
            double *point = new double[2];
            cout << "������� ������ ����������: ";
            input[0] = check();
            cout << "������� ������� ��������: ";
            input[1] = check();
            cout << "������� ���������� X: ";
            point[0] = check();
            cout << "������� ���������� Y: ";
            point[1] = check();
            double temp[] = {point[0] * point[0] + point[1] * point[1], input[1] / 2};
            if (temp[0] > input[0] * input[0] && abs(point[0]) <= temp[1] && abs(point[1]) <= temp[1])
                cout << "����� � ������������ (" << point[0] << ";" << point[1] << ") ������ � ��������� �������";
            else
                cout << "����� � ������������ (" << point[0] << ";" << point[1] << ") �� ������ � ��������� �������";
            cout << "\n��������� ���� (1/0): ";
            cin >> k;
        }while(k);
}

double check(){
    double str;
    bool flag;
    do{
        flag = false;
        cin >> str;
        if (str <= 0){
            flag = true;
            cout << "��������� ����: ";
        }
    }while(flag);
    return str;
}
