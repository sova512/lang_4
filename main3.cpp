#include <iostream> 
#include <cstring> 

using namespace std;
class String { char * value; int len;
public:
	String():value(new char[1]{}), len(0) {};
	String(const String& s) {
		len = s.len;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
			value[i] = s.value[i];  }
	String(const char * s) { 
		len = 0;
		while (s[len] != 0) len++;
		value = new char[len + 1]; 
		for (int i = 0; i <= len; i++) 
			value[i] = s[i];
	}
	friend ostream& operator<<(ostream& outputStream, const String & s) { 
        return outputStream << s.value; 
        }
	~String() { 
		delete[] value;
	}
 };
int main() {
	String str = "C-String";
	String str2(str);
	cout << str2 << endl;
	return 0;
}