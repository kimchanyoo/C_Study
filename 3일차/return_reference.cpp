#include <iostream>

class A {
	int x;
public:
	A(int c) :x(c) {}
	// 레퍼런스를 리턴
	int& access_x() {
		return x;
	}
	// 값을 리턴
	int get_x() {
		return x;
	}
	void show_x() {
		std::cout << "x : " << x << std::endl;
	}
};

int main() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	int e = a.get_x();
	e = 1;
	a.show_x();
	return 0;
}