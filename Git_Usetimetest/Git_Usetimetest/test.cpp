#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

long begintime, endtime;

class S
{

private:
	int du;
	int yun;
	int fei;

public:
	S(int _du = 1995, int _yun = 8, int _fei = 2) :
		du(_du), yun(_yun), fei(_fei)
	{
		begintime = clock();
	}
	~S()
	{
		endtime = clock();
	}
};

void test()
{
	S test1;
	int i = 0;
	for (i = 0; i <= 10000; i++)
	{
		cout << i << endl;
	}
}

int main()
{
	test();
	cout << "use time=" << endtime - begintime << endl;
	system("pause");
	return 0;
}