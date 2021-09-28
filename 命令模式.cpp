#include<iostream>
using namespace std;
#include<queue>
#include<Windows.h>

//命令模式

//协议处理类
class HandleClientProtocol {
public:
	//处理增加金币
	void addMoney()
	{
		cout << "给玩家增加金币" << endl;
	}
	//处理增加钻石
	void addDiamond()
	{
		cout << "给玩家增加钻石" << endl;
	}
	//处理玩家装备
	void addEquipment()
	{
		cout << "给玩家穿装备" << endl;
	}
	//处理玩家升级
	void addLevel() 
	{
		cout << "给玩家升级！" << endl;
	}
};

//命令接口
class AbstractCommand {
public:
	virtual void handle() = 0;//处理客户端请求的接口
};


//处理金币请求
class AddMoneyCommand : public AbstractCommand
{
public:
	AddMoneyCommand(HandleClientProtocol* protocol)
	{
		this->pProtocol = protocol;
	}
	virtual void handle()
	{
		this->pProtocol->addMoney();
	}
	HandleClientProtocol* pProtocol;
};

//处理钻石请求
class AddDiamondCommand : public AbstractCommand
{
public:
	AddDiamondCommand(HandleClientProtocol* protocol)
	{
		this->pProtocol = protocol;
	}
	virtual void handle()
	{
		this->pProtocol->addDiamond();
	}
	HandleClientProtocol* pProtocol;
};

//处理玩家装备
class AddEquipmentCommand : public AbstractCommand
{
public:
	AddEquipmentCommand(HandleClientProtocol* protocol)
	{
		this->pProtocol = protocol;
	}
	virtual void handle()
	{
		this->pProtocol->addEquipment();
	}
	HandleClientProtocol* pProtocol;
};

//处理玩家升级
class AddLevelCommand : public AbstractCommand
{
public:
	AddLevelCommand(HandleClientProtocol* protocol)
	{
		this->pProtocol = protocol;
	}
	virtual void handle()
	{
		this->pProtocol->addLevel();
	}
	HandleClientProtocol* pProtocol;
};

//服务器程序
class Server {
public:
	void addRequest(AbstractCommand* command)
	{
		mCommands.push(command);
	}
	void startHandle()
	{
		while (!mCommands.empty()) {

			Sleep(2000);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
	queue<AbstractCommand*>mCommands;
};

void test01()
{
	HandleClientProtocol* protocol = new HandleClientProtocol;

	//客户端增加金币的请求
	AbstractCommand* addMoney = new AddMoneyCommand(protocol);
	//客户端增加钻石的请求
	AbstractCommand* addDiamond = new AddDiamondCommand(protocol);
	// 客户端增加装备的请求
	AbstractCommand* addEquipment = new AddEquipmentCommand(protocol);
	// 客户端增加等级的请求
	AbstractCommand* addLevel = new AddLevelCommand(protocol);

	//将客户端请求加入队列中
	Server* server = new Server;
	server->addRequest(addMoney);
	server->addRequest(addDiamond);
	server->addRequest(addEquipment);
	server->addRequest(addLevel);

	server->startHandle();//服务器开始处理请求

	//堆区分配的内存还没有释放
}


int main()
{
	test01();
	return 0;
}
