#include <iostream>
#include <string.h>

class Complex {
private:
	double real, img;
	double get_number(const char* str, int from, int to);
public:
	Complex(double real, double img) :real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	// 문자열로 Complex 계산
	Complex(const char* str);

	// Complex뒤에 &를 안 붙이는 이유는 사칙연산 한 값이 원본 객체에 영향을 주지 않고 
	// 레퍼런스만 전달해줘야 하기 때문
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	Complex& operator=(const Complex& c);

	void println() { std::cout << "(" << real << " , " << img << ")" << std::endl; }
};
Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다
	// 문자열의 꼴은 다음과 같다. "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능함. (생략시 +라 가정)

	int begin = 0, end = strlen(str);
	double img = 0.0, real = 0.0;

	// 먼저 기준이 되는 i의 위치를 먼저 찾는다
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}

	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	// 만일 'i' 가 있다면 실수부와 허수부로 나누어서 처리
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real + c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp((real*c.real+img*c.img)/(c.real*c.real+c.img*c.img),(img*c.real-real*c.img)/(c.real*c.real+c.img*c.img));
	return temp;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}
double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to)return 0;

	if (str[from] == '-')minus = true;
	if (str[from] == '-' || str[from] == '+')from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break; // 그 이외의 이상한 문자들이 올 경우
	}
	if (minus) num *= -1.0;
	
	return num;
}
int main() {
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex c(0.0, 0.0);
	c = a * b + a / b * a + b;
	c.println();

	Complex d(0.0,0.0);
	d = d + "-1.1+i3.923";
	d.println();
	d = d - "1.2-i1.823";
	d.println();
	d = d * "2.3+i22";
	d.println();
	d = d / "-12+i55";
	d.println();
	/*Complex c = a * b;

	c.println();*/
	return 0;
}