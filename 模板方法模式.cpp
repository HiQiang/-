#include<iostream>
using namespace std;

//模板方法模式
class DrinkTemplate {
public:
	virtual void boildWater() = 0;
	virtual void brew() = 0;
	virtual void pourInCup() = 0;
	virtual void addSomething() = 0;
	void make()
	{
		boildWater();
		brew();
		pourInCup();
		addSomething();
	}
};
//coffee
class Coffee : public DrinkTemplate {
public:
	virtual void boildWater() {
		cout << "纯净水" << endl;
	}
	virtual void brew() {
		cout << "冲泡咖啡" << endl;
	}
	virtual void pourInCup()
	{
		cout << "倒入咖啡杯中 " << endl;
	}
	virtual void addSomething()
	{
		cout << "加糖和牛奶" << endl;
	}
};

//Tea
class Tea : public DrinkTemplate {
public:
	virtual void boildWater() {
		cout << "纯净水" << endl;
	}
	virtual void brew() {
		cout << "冲泡Tea" << endl;
	}
	virtual void pourInCup()
	{
		cout << "倒入Tea杯中 " << endl;
	}
	virtual void addSomething()
	{
		cout << "加Tea和牛奶" << endl;
	}
};

void test01()
{
	Coffee coffee;
	coffee.make();
	Tea tea;
	tea.make();
}


int main()
{
	test01();
	return 0;
}
