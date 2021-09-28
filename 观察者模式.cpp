#include<iostream>
using namespace std;
#include<list>

//抽线观察者基类
class AbstractObserver
{
public:
	virtual void Update() = 0;
};

class HeroA : public AbstractObserver {
public:
	HeroA() {
		cout << "A进行中..." << endl;
	}
	virtual void Update()
	{
		cout << "A暂停" << endl;
	}
};

class HeroB : public AbstractObserver {
public:
	HeroB() {
		cout << "B进行中..." << endl;
	}
	virtual void Update()
	{
		cout << "B暂停" << endl;
	}
};

class HeroC : public AbstractObserver {
public:
	HeroC() {
		cout << "C进行中..." << endl;
	}
	virtual void Update()
	{
		cout << "C暂停" << endl;
	}
};

class HeroD : public AbstractObserver {
public:
	HeroD() {
		cout << "D进行中..." << endl;
	}
	virtual void Update()
	{
		cout << "D暂停" << endl;
	}
};

class HeroE : public AbstractObserver {
public:
	HeroE() {
		cout << "E进行中..." << endl;
	}
	virtual void Update()
	{
		cout << "E暂停" << endl;
	}
};

//抽象观察目标基类
class AbstractBoss {
public:
	virtual void addObserver(AbstractObserver * hero) = 0;
	virtual void deleteObserver(AbstractObserver* hero) = 0;
	virtual void notify() = 0; //通知所有观察者
};

class BOSSA :public AbstractBoss
{
public:
	virtual void addObserver(AbstractObserver* hero) {
		pObserverList.push_back(hero);
	}

	virtual void deleteObserver(AbstractObserver* hero) {
		pObserverList.remove(hero);
	}
	virtual void notify()
	{
		for (list<AbstractObserver*>::iterator it = pObserverList.begin(); it != pObserverList.end(); it++)
		{
			(*it)->Update();
		}
	}
public:
	list<AbstractObserver*> pObserverList;
};

void test01()
{
	//创建观察者
	AbstractObserver* heroA = new HeroA;
	AbstractObserver* heroA2 = new HeroA;
	AbstractObserver* heroB = new HeroB;
	AbstractObserver* heroC = new HeroC;
	AbstractObserver* heroD = new HeroD;
	AbstractObserver* heroE = new HeroE;
	//创建观察目标
	AbstractBoss* bossA = new BOSSA;
	bossA->addObserver(heroA);
	bossA->addObserver(heroA2);
	bossA->addObserver(heroB);
	bossA->addObserver(heroC);
	bossA->addObserver(heroD);
	bossA->addObserver(heroE);

	cout << "heroC阵亡" << endl;
	bossA->deleteObserver(heroC);

	cout << "Boss死了" << endl;

	bossA->notify();
}


int main()
{
	test01();
	return 0;
}
