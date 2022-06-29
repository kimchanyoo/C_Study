#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)

class Marine {
private:
	const static int i = 0;
	static int total_marine_num; // �� ������ ��
	int hp;
	int coord_x, coord_y;   // ������ ��ġ
	const int default_damage;
	bool is_dead;

public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);
	~Marine() {
		total_marine_num--;
	}
	int attack() const;	// �������� ����
	Marine& be_attacked(int damage_earn);	// �Դ� ������
	void move(int x, int y);	// ������ �����̱�
	
	void show_state();	// ������ ǥ��
	static void show_total_marine_num();
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine_num() {
	std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; }
Marine::Marine(int x, int y)
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), default_damage(default_damage), hp(50), is_dead(false) { 
	total_marine_num++;
}
int Marine::attack() const{
	return default_damage;
}
Marine& Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
	return *this;
}
void Marine::move(int x, int y) {
	coord_x += x;
	coord_y += y;
}
void Marine::show_state() {
	std::cout << "*** Marine ***" << std::endl;
	std::cout << "Location : ( " << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "Hp : " << hp << std::endl;
	std::cout << "���� �� ������ �� : " << total_marine_num << std::endl;
}

int main() {
	/*Marine marine1(1, 2);
	Marine marine2(3, 5);

	marine1.show_state();
	marine2.show_state();*/
	Marine* marines[100];
	marines[0] = new Marine(2, 3, 5);
	Marine::show_total_marine_num();

	marines[1] = new Marine(3, 5, 10);
	Marine::show_total_marine_num();

	std::cout << "����1�� ���� 2�� �ι� ����!!" << std::endl;

	marines[1]->be_attacked(marines[0]->attack()).be_attacked(marines[0]->attack());
	marines[0]->show_state();
	marines[1]->show_state();

	delete marines[0];
	delete marines[1];
	/*marine2.be_attacked(marine1.\attack());

	marine1.show_state();
	marine2.show_state();*/
	return 0;
}