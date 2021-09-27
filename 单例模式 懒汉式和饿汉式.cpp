#include<iostream>
using namespace std;

//单例模式
//这个系统中只能有一个A类型的对象

//控制这个A类型的对象的个数，单例模式。系统只有一个对象

//实现单例的步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态的对外接口，可以让用户获得单例对象

//私有静态成员函数和属性可以在类外调用

class A 
{
private:
	A(){
		a = new A;
	}
public:
	static A* getInstance()
	{
		return a;
	}
private:
	static A* a;
};
A* A::a = NULL;

//单例 分为 懒汉式 和 饿汉式

//懒汉式
class Singleton_lazy {
private:
	Singleton_lazy() { cout << "懒汉式构造函数" << endl; }
public:
	static Singleton_lazy* getInstance() { 
		if (pSingleton == NULL)
		{
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};

//类外初始化
Singleton_lazy* Singleton_lazy::pSingleton = NULL;


//饿汉式
class Singleton_hungry {
private:
	Singleton_hungry() { cout << "饿汉式构造函数" << endl; }
	static Singleton_hungry* getInstance() {
		return pSingleton;
	}
private:
	static Singleton_hungry* pSingleton;
};

//类外初始化
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

void test01()
{

}


int main()
{
	cout<<"main函数开始执行！" << endl;

	Singleton_lazy::getInstance();

	return 0;
}
