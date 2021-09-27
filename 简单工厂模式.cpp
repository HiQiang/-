#include<iostream>
using namespace std;

//简单工厂模式
//对象不用创建 直接拿来用
//由工厂创建
//传入参数，让工厂知道应该创建什么类型对象

//1.客户端和具体实现类解耦
//2.对于某些对象创建比较复杂情况，用户不用考虑

//简单工厂模式，增加新功能是通过修改源代码实现，不符合开闭原则
//这个类职责过重，这个类发生问题，会影响很多使用这个工厂的模块


//抽象水果
class AbstractFruit
{
public:
	virtual void showName() = 0;

};

class Apple:public AbstractFruit
{
public:
	virtual void showName()
	{
		cout << "苹果" << endl;
	}
};

class banana :public AbstractFruit
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

//水果工厂
class FruitFactory {
public:
	static AbstractFruit* CreateFruit(string flag)
	{
		if (flag == "apple")
		{
			return new Apple;
		}
		else if (flag == "banana")
		{
			return new banana;
		}
		else if (flag == "pear")
		{
			return new Pear;
		}
		else
		{
			return NULL;
		}
	}
};

void test01()
{
	FruitFactory* factory = new FruitFactory;
	AbstractFruit* fruit;
	fruit = FruitFactory::CreateFruit("apple");
	fruit->showName();
	delete fruit;

	fruit = factory->CreateFruit("apple");
	fruit->showName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->showName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->showName();	
	delete fruit;
	delete factory;
}


int main()
{
	test01();
	return 0;
}
