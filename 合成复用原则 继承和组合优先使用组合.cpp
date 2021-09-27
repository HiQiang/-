#include<iostream>
using namespace std;

//合成复用原则
//继承和组合 优先使用组合

class AbstractCar {
public:
	virtual void run() = 0;
};

class DaZhong :public AbstractCar {
public:
	virtual void run()
	{
		cout << "大众启动" << endl;
	}
};

class TuoLaJi : public AbstractCar
{
public:
	virtual void run()
	{
		cout << "拖拉机启动" << endl;
	}
};

//针对具体类
//class Person : public TuoLaJi {
//public:
//	void douFeng()
//	{
//		run();
//	}
//};

//可以使用组合
class Person {
public:
	void setCar(AbstractCar* car) {
		this->car = car;
	}
	void douFeng()
	{
		this->car->run();
	}
	~Person() {
		if (this->car != NULL)
		{
			delete this->car;
		}
	}
	AbstractCar* car;
};


void test01()
{
	Person* p = new Person;
	AbstractCar* myCar = new TuoLaJi;
	p->setCar(myCar);
	//p->setCar(new TuoLaJi);
	p->douFeng();
	delete p;

}




int main()
{
	test01();
	return 0;
}
