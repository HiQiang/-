#include<iostream>
using namespace std;

//代理模式
//提供一种代理来控制对其它对象的访问

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

//我已经写好了系统
class MySystem: AbstractCommonInterface {
public:
	virtual void run() {
		cout << "系统启动..." << endl;
	}
};

//必须要权限验证，不是所有人都能来启动我的系统，提供用户名和密码

class MySystemProxy : public AbstractCommonInterface
{
public:
	MySystemProxy(string username, string password) {
		this->mUsername = username;
		this->mPassword = password;
		pSystem = new MySystem;
	}

	bool checkUsernameAndPassword() {
		if (mUsername == "admin" && mPassword == "admin")
		{
			return true;
		}
		return false;
	}

	virtual void run() {
		if (checkUsernameAndPassword() == true)
		{
			this->pSystem->run();
		}

		else
		{
			cout << "启动失败" << endl;
		}
	}
	~MySystemProxy()
	{
		if (pSystem != NULL)
		{
			delete pSystem;
		}
	}
	string mUsername;
	string mPassword;

private:
	MySystem* pSystem;
};



void test01()
{
	MySystemProxy* proxy = new MySystemProxy("admin", "admin");
	proxy->run();
}


int main()
{
	test01();
	return 0;
}
