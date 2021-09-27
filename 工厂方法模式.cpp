#include<iostream>
using namespace std;

//工厂方法模式

//1.类的个数成倍增加 导致类越来越多 增加维护成本
//2.
//3.符合开闭原则

//抽象水果
class AbstractFruit
{
public:
	virtual void showName() = 0;

};

class Apple :public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "苹果" << endl;
	}
};

class Banana :public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "香蕉" << endl;
	}
};

class Pear :public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "鸭梨" << endl;
	}
};

//抽象工厂
class AbstractFruitFactory {
public:
	virtual AbstractFruit* createFruit() = 0;
};

//苹果工厂
class AppleFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit* createFruit() {
		return new Apple;
	}
};

//香蕉工厂
class BananaFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit* createFruit() {
		return new Banana;
	}
};

//鸭梨工厂
class PearFactory :public AbstractFruitFactory {
public:
	virtual AbstractFruit* createFruit() {
		return new Pear;
	}
};

void test01()
{
	AbstractFruitFactory* factory = NULL;
	AbstractFruit* fruit = NULL;

	factory = new AppleFactory;
	fruit = factory->createFruit();
	fruit->showName();
	delete fruit;
	delete factory;

	factory = new BananaFactory;
	fruit = factory->createFruit();
	fruit->showName();
	delete fruit;
	delete factory;

	factory = new PearFactory;
	fruit = factory->createFruit();
	fruit->showName();
	delete fruit;
	delete factory;

}


int main()
{
	test01();
	return 0;
}
