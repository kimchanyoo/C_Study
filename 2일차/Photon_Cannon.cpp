#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)

class photon_cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
	char* name;

public:
	photon_cannon(int x, int y);
	photon_cannon(int x, int y, const char* pc_name);
	photon_cannon(const photon_cannon& pc);
	~photon_cannon();
	void show_state();
};
photon_cannon::photon_cannon(int x, int y) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}
photon_cannon::photon_cannon(int x, int y, const char* pc_name) {
	std::cout << "생성자 호출!" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(pc_name) + 1];
	strcpy(name, pc_name);
}
photon_cannon::photon_cannon(const photon_cannon& pc) {
	std::cout << "복사 생성자 호출!" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}
photon_cannon::~photon_cannon() {
	if (name) delete[] name;
}
void photon_cannon::show_state() {
	std::cout << "photon cannon :: " << name << std::endl;
	std::cout << "location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "hp : " << hp << std::endl;
}

int main() {
	photon_cannon pc1(3, 3, "cannon");
	photon_cannon pc2 = pc1;

	pc1.show_state();
	pc2.show_state();
	return 0;
}