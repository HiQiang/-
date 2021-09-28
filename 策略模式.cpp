#include<iostream>
using namespace std;

//策略模式

//
class WeaponStrategy {
public:
	virtual void useWeapon() = 0;
};

class Knife :public WeaponStrategy {
public:
	virtual void useWeapon(){
		cout << "使用Knife" << endl;
	}
};

class AK47 :public WeaponStrategy {
public:
	virtual void useWeapon() {
		cout << "使用AK47" << endl;
	}
};

class Character {
public:
	void setWeapon(WeaponStrategy* weapon) {
		this->pWeapon = weapon;
	}
	void ThrowWeapon() {
		this->pWeapon->useWeapon();
	}
	WeaponStrategy* pWeapon;
};

void test01()
{
	//创建角色
	Character* character = new	Character;
	//武器策略
	WeaponStrategy* knife = new Knife;
	WeaponStrategy* ak47 = new AK47;

	character->setWeapon(knife);
	character->ThrowWeapon();


	character->setWeapon(ak47);
	character->ThrowWeapon();

	delete knife;
	delete ak47;
	delete character;

}


int main()
{
	test01();
	return 0;
}
