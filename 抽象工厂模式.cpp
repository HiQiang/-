#include<iostream>
using namespace std;

//抽象工厂模式

//抽象工厂针对的是产品族，而不是产品等级结构
//产品族：同一产地或者同一厂商，功能不同
//产品等级：功能相同，产地或者厂商不同


//抽象苹果
class AbstractApple {
public:
	virtual void showName() = 0;
};

//中国苹果
class CHineseApple :public AbstractApple {
public:
	virtual void showName()
	{
		cout << "中国苹果" << endl;
	}
};
//美国苹果
class USAApple :public AbstractApple {
public:
	virtual void showName()
	{
		cout << "美国苹果" << endl;
	}
};
//日本苹果
class JapanApple :public AbstractApple {
public:
	virtual void showName()
	{
		cout << "日本苹果" << endl;
	}
};

//抽象香蕉
class AbstractBanana {
public:
	virtual void showName() = 0;
};
//中国香蕉
class CHineseBanana :public AbstractBanana {
public:
	virtual void showName()
	{
		cout << "中国香蕉" << endl;
	}
};
//美国香蕉
class USABanana :public AbstractBanana {
public:
	virtual void showName()
	{
		cout << "美国香蕉" << endl;
	}
};
//日本香蕉
class JapanBanana :public AbstractBanana {
public:
	virtual void showName()
	{
		cout << "日本香蕉" << endl;
	}
};

//抽象鸭梨
class AbstractPear {
public:
	virtual void showName() = 0;
};
//中国鸭梨
class CHinesePear :public AbstractPear {
public:
	virtual void showName()
	{
		cout << "中国鸭梨" << endl;
	}
};
//美国鸭梨
class USAPear :public AbstractPear {
public:
	virtual void showName()
	{
		cout << "美国鸭梨" << endl;
	}
};
//日本鸭梨
class JapanPear :public AbstractPear {
public:
	virtual void showName()
	{
		cout << "日本鸭梨" << endl;
	}
};

//抽象工厂 针对产品族
class AbstractFactory
{
public:
	virtual AbstractApple* createApple() = 0;
	virtual AbstractBanana* createBanana() = 0;
	virtual AbstractPear* createPear() = 0;
};
//中国工厂
class ChinaFactor :public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new CHineseApple;
	}
	virtual AbstractBanana* createBanana() {
		return new CHineseBanana;
	}
	virtual AbstractPear* createPear(){
		return new CHinesePear;
	}
};
//美国工厂
class USAFactor :public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new USAApple;
	}
	virtual AbstractBanana* createBanana() {
		return new USABanana;
	}
	virtual AbstractPear* createPear() {
		return new USAPear;
	}
};
//日本工厂
class JapanFactor :public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* createBanana() {
		return new JapanBanana;
	}
	virtual AbstractPear* createPear() {
		return new JapanPear;
	}
};

void test01()
{
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear * pear = NULL;

	factory = new ChinaFactor;
	apple = factory->createApple();
	banana = factory->createBanana();
	pear = factory->createPear();
	
	apple->showName();
	banana->showName();
	pear->showName();

	delete pear;
	delete banana;
	delete apple;
	delete factory;
}


int main()
{
	test01();
	return 0;
}
