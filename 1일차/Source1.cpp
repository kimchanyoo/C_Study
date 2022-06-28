#include <iostream>

class Date {
private:
	int year_;
	int month_;
	int day_;
public:
	void SetDate(int year, int month, int day) {
		year_ = year;
		month_ = month;
		day_ = day;
	}
	void AddDay(int inc) {
		day_ += inc;
		while (1) {
			if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 10 || month_ == 12) {
				if (day_ > 31) {
					month_ += 1;
					day_ -= 31;
					if (month_ == 13) {
						year_ += 1;
						month_ = 1;
					}
				}
				else
					break;
			}
			else if (month_ == 2) {
				if (day_ > 28) {
					month_ += 1;
					if (year_ % 4 == 0 && year_ % 100 != 0)
						day_ -= 29;
					else if (year_ % 100 == 0 && year_ % 400 == 0)
						day_ -= 29;
					else
						day_ -= 28;
				}
				else
					break;
			}
			else {
				if (day_ > 30) {
					month_ += 1;
					day_ -= 30;
				}
				else
					break;
			}
		}
	}
	void AddMonth(int inc) {
		month_ += inc;
		while (month_ > 12) {
			year_ += 1;
			month_ -= 12;
		}
	}
	void AddYear(int inc) {
		year_ += inc;
	}
	void ShowDate() {
		std::cout << "현재 지정된 날짜는 " << year_ << "년 " << month_ << "월 " << day_ << "일입니다." << std::endl;
	}
};

int main() {
	Date date;
	date.SetDate(2011, 3, 1);
	date.ShowDate();
	date.AddDay(30);
	date.ShowDate();
	date.AddDay(2000);
	date.ShowDate();
	return 0;
}