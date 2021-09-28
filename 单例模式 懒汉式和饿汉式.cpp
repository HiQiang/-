#include<iostream>
using namespace std;

//单例模式
//这个系统中只能有一个A类型的对象

//控制这个A类型的对象的个数，单例模式。系统只有一个对象

//实现单例的步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态的对外接口，可以让用户获得单例对象



class A
{
private:
	A() {
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
public:
	static Singleton_hungry* getInstance() {
		return pSingleton;
	}
	//static void freeSpace()
	//{
	//	if (pSingleton != NULL)
	//	{
	//		delete pSingleton;
	//	}
	//}
	class Garbo {
		~Garbo()
		{
			if (pSingleton != NULL) {
				delete pSingleton;
			}
		}
	};
private:
	static Singleton_hungry* pSingleton;
	static Garbo garbo1;
};

//类外初始化
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;

void test01()
{
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();

	if (p1 == p2)
	{
		cout << "两个指针指向同一块内存" << endl;
	}
	else
	{
		cout << "不是单例" << endl;
	}

	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();

	if (p3 == p4)
	{
		cout << "两个指针指向同一块内存" << endl;
	}
	else
	{
		cout << "不是单例" << endl;
	}


}
//单例对象释放问题
void test02() {
	//Singleton_hungry::freeSpace();
}


int main()
{
	cout << "main函数开始执行！" << endl;

	test01();

	return 0;
}
