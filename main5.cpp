#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class String
{
    char * value;
    int len;

public:
    String():value(new char[1] {}), len(0) {};
    String(int size) :value(new char[size + 1]), len(size) {}

    String(const String& s) {
        len = s.len;
        value = new char[len + 1];
        for (int i = 0; i <= len; i++)
            value[i] = s.value[i];
    }

    String(const char * s) {
        len = 0;
        while (s[len] != 0) len++;
        value = new char[len + 1];
        for (int i = 0; i <= len; i++)
            value[i] = s[i];
    }

    String operator-() const {
        String ret;
        ret.len = len;
        delete[] ret.value;
        ret.value = new char[len + 1];
        for (int i = 0; i < len; i++) {
            ret.value[i] = value[len - i - 1];
        }
        ret.value[len] = 0;
        return ret;
    }

    String operator+(const String& other) {
        String resalt;
        delete[] resalt.value;
        resalt.len = this->len + other.len; // Установка длины строки результата как суммы имеющейся и входной
        resalt.value = new char[this->len + other.len]; // Установка значения как массив сомволов
        int i = 0;
        int j;
        for (i = 0; i < this->len; i++)
            resalt.value[i] = this->value[i];
        j = i;
        for (i = 0; i < other.len; i++, j++)
            resalt.value[j] = other.value[i];

        return resalt;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] value;
            len = other.len;
            value = new char[len + 1];
            for (int i = 0; i <= len; i++) {
                value[i] = other.value[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& outputStream, const String & s) {
        return outputStream << s.value;
    }
    ~String() {
        delete[] value;
    }
};
int main()
{
    String str = "Hello World";
    String str2 = str;
    String str3= -str;
    cout<<str3<<endl;
    cout << str2 + str << endl;
    return 0;
}
