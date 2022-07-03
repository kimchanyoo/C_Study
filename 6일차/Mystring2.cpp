#include <iostream>
#include <string.h>

class Mystring {
private:
	char* string_content;
	int string_length;
	int memory_capacity;
public:

	explicit Mystring(int capacity);
	// ���ڿ��κ��� ����
	Mystring(const char* str);
	// ���� ������
	Mystring(const Mystring& str);
	// �Ҹ���
	~Mystring();

	int length() const;
	// �Ͻ����� ��ȯ�� �������ֱ⵵ ��
	// ����ڰ� �ǵ����� ���� �Ͻ����� ��ȯ�� ���� �� ����
	// explicit  Ű����� �Ͻ����� ��ȯ �� �� ���� ���� �� ����
	// explicit  Ű����� ���� �������� ���·ε� ȣ���� ���´�`	
	void DoSomethingWithString(Mystring s);
	void println() const;
	char& operator[](const int index);
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
char& Mystring::operator[](const int index) {
	return string_content[index];
}
void Mystring::println() const{
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}
int main() {
	Mystring str("abcdef");
	str[3] = 'c';

	str.println();  
	return 0;
}

