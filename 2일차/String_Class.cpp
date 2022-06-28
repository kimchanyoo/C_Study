#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)

class string {
	char* str;
	int len = 0;

public:
	string(char c, int n);
	string(const char* s_);
	string(const string& s);
	~string();

	void add_string(const string& s);
	void copy_string(const string& s);
	int strlen();
	void print();
};
string::string(char c, int n) {
	len = n + 1;
	str = new char[len];
	int i;
	for (i = 0; i < n; i++)
		str[i] = c;
	str[i] = char(NULL);
}
string::string(const char* s_) {
	len = sizeof(s_);
	str = new char[len + 1];
	strcpy(str, s_);
}
string::string(const string& s) {
	len = s.len;
	str = new char[s.len + 1];
	strcpy(str, s.str);

}
string::~string() {
	if (str != nullptr) delete[] str;
}
void string::add_string(const string& s) {
	len = len + s.len;
	char* temp = new char[len + 1];
	strcpy(temp, str);
	strcat(temp, s.str);
	delete[] str;
	str = new char[len + 1];
	strcpy(str, temp);
	delete[] temp;
}
void string::copy_string(const string& s) {
	delete[] str;
	len = s.len + 1;
	str = new char[len];
	strcpy(str, s.str);
}
int string::strlen() {
	return len;
}
void string::print() {
	std::cout << str << std::endl;
}
int main() {
	string s1("ccc");
	string s2("sss");
	string s3('a', 2);
	s1.print();
	s2.print();
	s3.print();
	s1.add_string(s2);
	s1.print();
	s2.copy_string(s1);
	s2.print();
}