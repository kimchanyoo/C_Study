#include <iostream>
#include <string>

class Employee {
protected:
	std::string name;
	int age;

	std::string position;
	int rank;
public:
	Employee(std::string name, int age, std::string position, int rank) :
		name(name), age(age), position(position), rank(rank) {}

	// 복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// 디폴트 생성자
	Employee() {}
	virtual void print_info() {
		std::cout << name << "(" << position << " , " << age << ") ==> "
				  << calculate_pay() << "만원" << std::endl;
	}
	virtual int calculate_pay() {
		return 200 + rank * 50;
	}
};

class Manager :public Employee {
	int year_of_service;
public:
	Manager(std::string name, int age, std::string position, int rank,
		int year_of_service) : year_of_service(year_of_service), Employee(name, age, position, rank) {}

	int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() override {
		std::cout << name << "(" << position << " , " << age << ", "
			<< year_of_service << "년차) ==> " << calculate_pay() << "만원" <<
			std::endl;
	}
};
class EmployeeList {
	int alloc_emlployee;  // 할당한 총 직원 수
	int current_employee; // 현재 직원수
	Employee** employee_list;  // 직원 데이터

public:
	EmployeeList(int alloc_employee) :alloc_emlployee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee* employee) {
		// 사실 current_employee 보다 alloc_employee 가 더
		// 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
		// 최대한 단순하게 생각해서 alloc_employee가 
		// 언제나 alloc_employee보다 크다고 생각한다.
		// (즉 할당된 크기는 현재 총 직원수보다 많음)
		employee_list[current_employee] = employee;
		current_employee++;
	}
};