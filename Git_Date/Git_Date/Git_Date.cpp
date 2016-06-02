#include <iostream>
#include <windows.h>

using namespace std;


class Date
{
public:
	Date(int _year = 1990, int _month = 1, int _day = 1) :
		year(_year), month(_month), day(_day)
	{
		if (!((year >= 1990) && (0 < month < 13) && (0<day <= _GetMonthDay(month))))
		{
			year = 1990;
			month = 1;
			day = 1;
		}
	}
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	bool IsLeap()             //判断是否为闰年
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, const Date& d);

private:
	int _GetMonthDay(int month)//返回某月的天数上限
	{
		int Mday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((1 == IsLeap()) && (2 == month))
		{
			return 29;
		}
		return Mday[month];
	}

private:
	int year;
	int month;
	int day;
};


int main()
{
	Date Now(1981, 8, 23);
	system("pause");
	return 0;
}