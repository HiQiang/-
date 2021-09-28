#include<iostream>
using namespace std;

//外观模式
class AbstractDevice {
public:
	virtual void on() = 0;
	virtual void off() = 0;
};

//电视机类
class TeleVision : public AbstractDevice{
public:
	virtual void on()
	{
		cout << "TV on" << endl;
	}
	virtual void off()
	{
		cout << "TV off" << endl;
	}
};

//灯类
class Light : public AbstractDevice {
public:
	virtual void on()
	{
		cout << "Light on" << endl;
	}
	virtual void off()
	{
		cout << "Light off" << endl;
	}
};

//音响类
class Audio : public AbstractDevice {
public:
	virtual void on()
	{
		cout << "Audio on" << endl;
	}
	virtual void off()
	{
		cout << "Audio off" << endl;
	}
};

//麦克风类
class MicroPhone : public AbstractDevice {
public:
	virtual void on()
	{
		cout << "MicroPhone on" << endl;
	}
	virtual void off()
	{
		cout << "MicroPhone off" << endl;
	}
};

//DVD类
class DVD : public AbstractDevice {
public:
	virtual void on()
	{
		cout << "DVD on" << endl;
	}
	virtual void off()
	{
		cout << "DVD off" << endl;
	}
};

//游戏机类
class PlayStation : public AbstractDevice {
public:
	virtual void on()
	{
		cout << "PlayStation on" << endl;
	}
	virtual void off()
	{
		cout << "PlayStation off" << endl;
	}
};

class KTVMode {
public:
	KTVMode()
	{
		pTV = new TeleVision;
		pLight = new Light;
		pAudio = new Audio;
		pMicroPhone = new MicroPhone;
		pDVD = new DVD;
	}
	void onKTV()
	{
		pTV->on();
		pLight->off();
		pAudio->on();
		pMicroPhone->on();
		pDVD->on();
	}

	void offKTV()
	{
		pTV->off();
		pLight->on();
		pAudio->off();
		pMicroPhone->off();
		pDVD->off();
	}
	~KTVMode()
	{
		delete pTV;
		delete pLight;
		delete pAudio;
		delete pMicroPhone;
		delete pDVD;
	}
	AbstractDevice* pTV;
	AbstractDevice* pLight;
	AbstractDevice* pAudio;
	AbstractDevice* pMicroPhone;
	AbstractDevice* pDVD;
};

void test01()
{
	KTVMode* ktv = new KTVMode;
	ktv->onKTV();
	ktv->offKTV();
}


int main()
{
	test01();
	return 0;
}
