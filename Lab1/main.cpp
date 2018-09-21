#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double check();
bool checkBool();

int main(){
    setlocale(LC_ALL, "Russian");
    bool k;
        do {
            double *input = new double[2];
            double *point = new double[2];
            cout << "Введите радуис окружности: ";
            input[0] = check();
            cout << "Введите сторону квадрата: ";
            input[1] = check();
            cout << "Введите координату X: ";
            point[0] = check();
            cout << "Введите координату Y: ";
            point[1] = check();
            double temp[] = {point[0] * point[0] + point[1] * point[1], input[1] / 2};
            if (temp[0] > input[0] * input[0] && abs(point[0]) <= temp[1] && abs(point[1]) <= temp[1])
                cout << "Точка с координатами (" << point[0] << ";" << point[1] << ") входит в указанную область";
            else
                cout << "Точка с координатами (" << point[0] << ";" << point[1] << ") не входит в указанную область";
            cout << "\nПовторить ввод (1/0): ";
            cin >> k;
        }while(k);
}

double check(){
    string str;
    bool flag = true;
    for (auto i : str){

    }
}

bool checkBool(){
    string str;
    for (auto i : str){

    }
}
