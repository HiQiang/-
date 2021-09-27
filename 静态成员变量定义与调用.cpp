#include<iostream>
using namespace std;

class A {
private:
	static int mA;
	static void setmB(int b);
public:
	static int mB;
};


int A::mA = 1;
int A::mA = 2;
int A::mB = 1;
void A::setmB(int b) {
	A::mB = b;
}

void test01()
{
	A* a = new A;
	//cout << a->mA << endl;//不可访问
	cout << a->mB << endl;
	a->mB = 2;
	cout << a->mB << endl;
	//a->setmB(10);//不可访问

}


int main()
{
	test01();
	return 0;
}
