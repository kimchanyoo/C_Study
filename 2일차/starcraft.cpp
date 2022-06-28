#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>


class Marine {
private:
	int hp;
	int coord_x, coord_y;   // ������ ��ġ
	int damage;
	bool is_dead;
	char* name;
public:
	Marine();
	Marine(int x, int y, const char* marine_name);
	~Marine();

	int attack();	// �������� ����
	void be_attacked(int damage_earn);	// �Դ� ������
	void move(int x, int y);	// ������ �����̱�

	void show_state();	// ������ ǥ��
};
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
	name = new char[strlen(marine_name)+1];
	strcpy(name, marine_name);
}
Marine::~Marine() {
	std::cout << name << "�� �Ҹ��� ȣ��" << std::endl;
	if(name != NULL)
		delete[] name;
}
int Marine::attack() {
	return damage;
}
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp < 0)
		is_dead = true;
}
void Marine::move(int x, int y) {
	coord_x += x;
	coord_y += y;
}
void Marine::show_state() {
	std::cout << "*** Marine ***" << std::endl;
	std::cout << "Location : ( " << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "Name : " << name << std::endl;
	std::cout << "Hp : " << hp << std::endl;
}

int main() {
	/*Marine marine1(1, 2);
	Marine marine2(3, 5);

	marine1.show_state();
	marine2.show_state();*/
	Marine* marines[100];
	marines[0] = new Marine(2, 3, "Marine1");
	marines[1] = new Marine(3, 5, "Marine2");
	marines[0]->show_state();
	marines[1]->show_state();

	std::cout << "����1�� ���� 2�� ����!!" << std::endl;

	marines[1]->be_attacked(marines[0]->attack());
	marines[0]->show_state();
	marines[1]->show_state();

	delete marines[0];
	delete marines[1];
	/*marine2.be_attacked(marine1.\attack());
	
	marine1.show_state();
	marine2.show_state();*/
	return 0;
}