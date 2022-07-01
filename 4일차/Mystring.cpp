#include <iostream>
#include <string.h>

class Mystring {
private:
	char* string_content;
	int string_length;
	int memory_capacity;
public:

	explicit Mystring(int capacity);
	// 문자열로부터 생성
	Mystring(const char* str);
	// 복사 생성자
	Mystring(const Mystring& str);
	// 소멸자
	~Mystring();

	int length() const;
	// 암시적인 변환을 수행해주기도 함
	// 사용자가 의도하지 않은 암시적인 변환이 생길 수 있음
	// explicit  키워드로 암시적인 변환 할 수 없게 만들 수 있음
	// explicit  키워드는 복사 생성자의 형태로도 호출을 막는다`	
	void DoSomethingWithString(Mystring s);
};
Mystring::Mystring(int capacity) {
	string_content = new char[capacity];
	string_length = 0;
	memory_capacity = capacity;
}
Mystring::Mystring(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
Mystring::Mystring(const Mystring& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
Mystring::~Mystring() {
	delete[] string_content;
}
int Mystring::length() const {
	return string_length;
}
void Mystring::DoSomethingWithString(Mystring s) {

}
int main(){
	Mystring s(3);
	return 0;
}
