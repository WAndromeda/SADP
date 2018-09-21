#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool checkingEmail(string, string&);

int main(){
    setlocale(LC_ALL, "Russian");
    bool flag = false;
    string str = "", error = "";
    do {
        cout << "������� ����� ����������� �����: ";
        cin >> str;
        {
            string t = "";
            for (auto i : str)
                t += tolower(i);
            str = t;
        }
        flag = checkingEmail(str, error);
        if (flag)
            cout << "����� ������� �����: " << str << endl;
        else
            cout << error << endl;
    }while(!flag);
}

bool checkingEmail(string str, string& error) {
    bool symbols[4];
    for (bool &i : symbols)
        i = false;
    bool pointAfterDog = false;
    bool dog = false;
    bool hyphen = false;
    for (char i : str) {
        if (i == ' ') {
            if (symbols[0]) {
                error = "������: ���� �������� ������ email ����������";
                return false;
            }
        } else {
            if (i == '-') {
                if (hyphen) {
                    error = "������: ���������� ���� ���� �������� '-' ������";
                    return false;
                } else if (!dog) {
                    symbols[0] = true;
                    hyphen = true;
                } else if (!pointAfterDog) {
                    symbols[1] = true;
                    hyphen = true;
                } else if (!symbols[2]) {
                    symbols[2] = true;
                    hyphen = true;
                } else {
                    symbols[3] = true;
                    hyphen = true;
                }
            } else if (i == '@') {
                if (!symbols[0]) {
                    error = "����� �������� '@' ������ ���� ���� �� ���� ���� ������";
                    return false;
                } else if (dog) {
                    error = "������: ���������� ���� ���� �������� '@'";
                    return false;
                } else {
                    dog = true;
                    hyphen = false;
                }
            } else if (i == '.') {
                if (dog) {
                    if (!pointAfterDog) {
                        pointAfterDog = true;
                        hyphen = false;
                    }
                    else{
                        hyphen = false;
                        symbols[2] = false;
                        symbols[3] = false;
                    }
                } else if (!symbols[1]) {
                    symbols[0] = true;
                    hyphen = false;
                }
            } else if (!dog) {
                symbols[0] = true;
                hyphen = false;
            } else if (dog) {
                if (!pointAfterDog) {
                    symbols[1] = true;
                    hyphen = false;
                } else if (!symbols[2]) {
                    symbols[2] = true;
                    hyphen = false;
                } else {
                    symbols[3] = true;
                    hyphen = false;
                }
            }
        }
    }

    if (!dog){
        error = "������: ������ �������������� ������ '@'";
        return false;
    }else if (!symbols[0]) {
        error = "������: ����� �������� '@' ������ ���� ���� �� ���� ������";
        return false;
    } else if (!symbols[1]) {
        error = "������: ����� ������� '@' � �� ����� ������ ���� ���� �� ���� ������";
        return false;
    } else if (!pointAfterDog) {
        error = "������: ����� ����� ������� '@' ������ ���� ������� ���� �� ���� �����";
        return false;
    } else if (str[str.length() - 1] == '.') {
        error = "������: ������ �� ������ ������������ �� �����";
        return false;
    } else if (!symbols[2] || !symbols[3] ) {
        error = "������: ������ ���� 2 ������� ����� ��������� ����� ";
        return false;
    }
    return true;
}
