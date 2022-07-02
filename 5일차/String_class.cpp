#include <iostream>
#include <string.h>

class Mystring {
private:
	char* string_content;
	int string_length;
	int memory_capacity;
public:
	// 문자 하나로 생성
	Mystring(char c);
	// 문자열로부터 생성
	Mystring(const char* str);
	// 복사 생성자
	Mystring(const Mystring& str);
	// 소멸자
	~Mystring();

	int length() const;
	void print() const;
	void println() const;
	// 현재 문자열의 할당된 메모리 크기를 나타냄
	int capacity() const;
	// 할당된 문자열을 미리 예약
	void reserve(int size);
	// 임의의 위치의 문자를 리턴
	char at(int i) const;

	// 기존의 문자열을 수정
	Mystring& assign(const Mystring& str);
	Mystring& assign(const char* str);
	// 기존의 문자열에 문자열을 삽입
	Mystring& insert(int loc, const Mystring& str);
	Mystring& insert(int loc, const char* str);
	Mystring& insert(int loc, char c);
	// 기존의 문자열에서 문자를 삭제( loc - 입력 위치의 '앞', num - 지울 문자의 수)
	Mystring& erase(int loc, int num);
	// 짧은 문자열 검색
	int find(int find_from, Mystring& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
	// 크기 비교
	int compare(const Mystring& str) const;
	bool operator==(Mystring& str);
};
Mystring::Mystring(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
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
void Mystring::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void Mystring::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
Mystring& Mystring::assign(const Mystring& str) {
	if (str.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;

	return *this;
}
Mystring& Mystring::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;

	return *this;
}
int Mystring::capacity() const {
	return memory_capacity;
}
void Mystring::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++) {
			string_content[i] = prev_string_content[i];
		}
		delete[] prev_string_content;
	}
}
char Mystring::at(int i) const {
	if (i >= string_length || i < 0) {
		return NULL;
	}
	else
		return string_content[i];
}
Mystring& Mystring::insert(int loc, const char* str) {
	Mystring temp(str);
	return insert(loc, temp);
}
Mystring& Mystring::insert(int loc, char c) {
	Mystring temp(c);
	return insert(loc, temp);
}
Mystring& Mystring::insert(int loc, const Mystring& str) {
	if (loc < 0 || loc > string_length) return *this;
	if (string_length + str.string_length > memory_capacity) {
		if (memory_capacity * 2 > str.string_length + string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		int i = 0;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}
	for (int i = string_length - 1; i >= loc; i--) {
		string_content[i + str.string_length] = string_content[i];
	}
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];
	string_length = string_length + str.string_length;
	return *this;
}
Mystring& Mystring::erase(int loc, int num) {
	if (num < 0 || loc < 0 || loc > string_length || num + loc > string_length) return *this;
	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}
int Mystring::find(int find_from, Mystring& str) const {
	int i, j;
	if (str.string_length == 0)return -1;
	for (i = find_from; i <= string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j])break;
		}
		if (j == str.string_length) return i;
	}
	return -1;
}
int Mystring::find(int find_from, const char* str) const {
	Mystring temp(str);
	return find(find_from, temp);
}
int Mystring::find(int find_from, char c) const {
	Mystring temp(c);
	return find(find_from, temp);
}
int Mystring::compare(const Mystring& str) const {
	// (*this) - (str)을 수행해서 1, 0 , -1로 결과를 리턴한다.
	// 1은 (*this)가 사전적으로 더 뒤에 온다는 의미. 0은 두 문자열이 같다는 의미
	// -1은 (*this)가 사전적으로 더 앞으로 온다는 의미
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
		// 여기까지 했는데 끝나지 않는다면 앞부분까지는 모두 같은것이 된다.
		// 만일 문자열의 길이가 같다면 두 문자열은 아예 같은 문자열이 됨
		if (string_length == str.string_length) return 0;
		else if (string_length > str.string_length) return 1;
	}
	return -1;
}
bool Mystring::operator==(Mystring& str) {
	return !compare(str);
}
int main() {
	/*Mystring str1("very very very long string");
	Mystring str2("<some string inserted between> ");
	str1.reserve(30);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	str1.insert(5, str2);
	str1.println();
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();*/

	Mystring str1("a word");
	Mystring str2("sentence");
	Mystring str3("sentence");

	if (str1 == str2)
		std::cout << "str1과 str2가 같다" << std::endl;
	else
		std::cout << "str1과 str2가 다르다" << std::endl;
	if(str2==str3)
		std::cout << "str2와 str3가 같다" << std::endl;
	else
		std::cout << "str2과 str3가 다르다" << std::endl;
	return 0;
}