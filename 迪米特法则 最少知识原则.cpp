#include<iostream>
#include<string>
#include<vector>
using namespace std;

//迪米特法则 又叫最少知识原则

class AbstractBuilding {
public:
	virtual void sale() = 0;
	virtual string getQuality() = 0;
};

class BuildingA :public AbstractBuilding {
public:
	BuildingA()
	{
		mQuality = "高品质";
	}
	virtual void sale()
	{
		cout << "楼盘A" << mQuality << "被售卖了" << endl;
	}
	virtual string getQuality() {
		return mQuality;
	}
public:
	string mQuality;
};

class BuildingB :public AbstractBuilding {
public:
	BuildingB()
	{
		mQuality = "低品质";
	}
	virtual void sale()
	{
		cout << "楼盘B" << mQuality << "被售卖了" << endl;
	}
	virtual string getQuality() {
		return mQuality;
	}
public:
	string mQuality;
};

//客户端
void test01()
{
	BuildingA* ba = new BuildingA;
	if (ba->mQuality == "低品质")
	{
		ba->sale();
	}
	delete ba;
	ba = nullptr;

	BuildingB* bb = new BuildingB;
	if (bb->mQuality == "低品质")
	{
		bb->sale();
	}
	delete bb;
	bb = nullptr;
}

//中介类 Mediator
class Mediator {
public:
	Mediator()
	{
		AbstractBuilding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}
	
	//对外提供接口
	AbstractBuilding* findMyBuilding(string quality)
	{
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end(); it++)
		{
			if ((*it)->getQuality() == quality)
			{
				return* it;
			}
		}
		return NULL;
	}

	~Mediator()
	{
		for (vector<AbstractBuilding*>::iterator it = vBuilding.begin(); it != vBuilding.end();it++)
		{
			if (*it != NULL)
			{
				delete* it;
			}
		}
	}

public:
	vector<AbstractBuilding*>vBuilding;
};

//
void test02()
{
	Mediator* mediator = new Mediator;
	AbstractBuilding * building = mediator->findMyBuilding("高品质");
	if (building != NULL)
	{
		building->sale();
	}
	else {
		cout << "没有符合您条件的楼盘" << endl;
	}
	delete mediator;
}

int main()
{
	test02();
	return 0;
}
