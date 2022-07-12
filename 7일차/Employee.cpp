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

	// ���� ������
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// ����Ʈ ������
	Employee() {}
	virtual void print_info() {
		std::cout << name << "(" << position << " , " << age << ") ==> "
				  << calculate_pay() << "����" << std::endl;
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
			<< year_of_service << "����) ==> " << calculate_pay() << "����" <<
			std::endl;
	}
};
class EmployeeList {
	int alloc_emlployee;  // �Ҵ��� �� ���� ��
	int current_employee; // ���� ������
	Employee** employee_list;  // ���� ������

public:
	EmployeeList(int alloc_employee) :alloc_emlployee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee* employee) {
		// ��� current_employee ���� alloc_employee �� ��
		// �������� ��� �ݵ�� ���Ҵ��� �ؾ� ������, ���⼭��
		// �ִ��� �ܼ��ϰ� �����ؼ� alloc_employee�� 
		// ������ alloc_employee���� ũ�ٰ� �����Ѵ�.
		// (�� �Ҵ�� ũ��� ���� �� ���������� ����)
		employee_list[current_employee] = employee;
		current_employee++;
	}
};