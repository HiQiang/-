#include<iostream>

using namespace std;

//开闭原则 对扩展开放，对修改关闭，增加功能是通过增加代码来实现的，而不是去修改源代码

//写一个抽象类
class AbstractCalculator {
public:
	virtual void setOperatorNumber(int a, int b) = 0;
	virtual int getResult() = 0;
};

//加法计算器
class PlusCalculator :public AbstractCalculator {
public:
	void setOperatorNumber(int a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult() {
		return mA + mB;
	}
public:
	int mA = 0;
	int mB = 0;
};

//减法计算器
class MinuteCalculator :public AbstractCalculator {
public:
	void setOperatorNumber(int a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult() {
		return mA - mB;
	}
public:
	int mA = 0;
	int mB = 0;
};

//乘法计算器
class MultipleCalculator :public AbstractCalculator {
public:
	void setOperatorNumber(int a, int b)
	{
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult() {
		return mA * mB;
	}
public:
	int mA = 0;
	int mB = 0;
};

//增加取模功能 通过增加代码 实现

void test01()
{
	AbstractCalculator* calculator = new PlusCalculator;
	calculator->setOperatorNumber(10, 20);
	cout << calculator->getResult() << endl;
	delete calculator;
	calculator = nullptr;

	AbstractCalculator* calculator2 = new MinuteCalculator;
	calculator2->setOperatorNumber(10, 20);
	cout << calculator2->getResult() << endl;
	delete calculator2;
	calculator2 = nullptr;
}


int main()
{
	test01();
	return 0;
}
