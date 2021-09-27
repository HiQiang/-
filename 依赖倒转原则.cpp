#include<iostream>
using namespace std;

//依赖倒转原则

class BankWorker {
public:
	void saveService()
	{
		cout << "办理存款业务" << endl;
	}
	void payService()
	{
		cout << "办理支付业务" << endl;
	}
	void transferService()
	{
		cout << "办理转账业务" << endl;
	}
};

void doSaveBussiness(BankWorker* worker)
{
	worker->saveService();
}

//中层模块
void doPayBussiness(BankWorker* worker)
{
	worker->payService();
}
void doTransferBussiness(BankWorker* worker)
{
	worker->transferService();
}
void test01()
{
	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker);
	doPayBussiness(worker);
	doTransferBussiness(worker);
	delete worker;
}


//单一职责原则
class AbstractWorker {
public:
	virtual void doBussiness() = 0;
};

//专门负责存款业务的工作人员
class SaveBankWorker:public AbstractWorker {
public:
	virtual void doBussiness()
	{
		cout << "办理存款业务" << endl;
	}
};

//专门办理付款支付业务的工作人员
class PayBankWorker :public AbstractWorker {
public:
	virtual void doBussiness()
	{
		cout << "办理支付业务" << endl;
	}
};

//专门负责转账业务的工作人员
class TransferBankWorker :public AbstractWorker {
public:
	virtual void doBussiness()
	{
		cout << "办理转账业务" << endl;
	}
};

//中层业务
void doNewBusiness(AbstractWorker* worker)
{
	worker->doBussiness();
}

void test02()
{
	AbstractWorker* worker = new TransferBankWorker;
	doNewBusiness(worker);
	delete worker;
}


int main()
{
	test01();
	cout << "********" << endl;
	test02();
	return 0;
}
