#include<iostream>
using namespace std;

//装饰模式

//一般情况下 用继承实现功能扩展

//装饰模式 可以动态的给一个类增加功能


class AbstractHero
{
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

//具体英雄
class HeroA :public AbstractHero
{
public:
	HeroA() 
	{
		 mHp=0;
		 mMp=0;
		 mAt=0;
		 mDf=0;
	}
	virtual void ShowStatus()
	{
		cout << "mHp:" << mHp << endl;
		cout << "mMp:" << mMp << endl;
		cout << "mAt:" << mAt << endl;
		cout << "mDf:" << mDf << endl;
	}
};

//英雄穿上某个装饰物 那么他还是那个英雄
class AbstractEquipment:public AbstractHero {
public:
	AbstractEquipment(AbstractHero* hero)
	{
		this->pHero = hero;
	}
	virtual void ShowStatus() {};
public:
	AbstractHero* pHero;
};

//
class KuangtuEquipment :public AbstractEquipment
{
public:
	KuangtuEquipment(AbstractHero* hero):AbstractEquipment(hero){}
	//增加额外功能
	void addKuangtu()
	{
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;
		delete this->pHero;
	}
	virtual void ShowStatus()
	{
		addKuangtu();
		cout << "mHp:" << mHp << endl;
		cout << "mMp:" << mMp << endl;
		cout << "mAt:" << mAt << endl;
		cout << "mDf:" << mDf << endl;
	}
};

//
class WuJinKnife :public AbstractEquipment
{
public:
	WuJinKnife(AbstractHero* hero) :AbstractEquipment(hero) {}
	//增加额外功能
	void addWuJinKnife()
	{
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 80;
		this->mDf = this->pHero->mDf;
		delete this->pHero;
	}
	virtual void ShowStatus()
	{
		addWuJinKnife();
		cout << "mHp:" << mHp << endl;
		cout << "mMp:" << mMp << endl;
		cout << "mAt:" << mAt << endl;
		cout << "mDf:" << mDf << endl;
	}
};

void test01()
{
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();
	cout << "*****" << endl;
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();
	cout << "*****" << endl;
	hero = new WuJinKnife(hero);
	hero->ShowStatus();


	//没有delete对象

}


int main()
{
	test01();
	return 0;
}
