//#define _CRT_SECURE_NO_WARNI
#include <iostream>
using namespace std;
#include <math.h>
//构造函数
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.SetDate(2019, 1, 15);
//	d1.Print();
//	system("pause");
//	return 0;
//}
//
//class Date
//{
//public:
//	//无参构造
//	Date()
//	{}
//	//带参构造
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void test()
//	{
//		Date d1;
//		Date d2(2019, 1, 15);
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(2019, 1, 15);
//	system("pause");
//	return 0;
//}
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	//基本类型
//	int _year;
//	int _month;
//	int _day;
//	//自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	system("pause");
//	return 0;
//}
//析构函数
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	system("pause");
//	return 0;
//}
class Date
{
public:

	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
			return 29;
		else
			return monthArray[month];
	}
	Date(int year = 2019, int month = 2, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month < 13 &&
			day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}
	}
	//拷贝构造
	Date(const Date&d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)
	{
		/*return _year != d._year &&
			_month != d._month &&
			_day != d._day;*/
		return !(*this == d);
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		return false;
	}
	bool operator<(const Date& d)
	{
		/*if (_year < d._year)
			return 1;
		else if (_year == d._year && _month < d._month)
			return 1;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return 1;
		return 0;*/
		return !(*this>=d);
	}
	bool operator>=(const Date& d)
	{
		/*if (_year > d._year)
			return 1;
		else if (_year == d._year && _month > d._month)
			return 1;
		else if (_year == d._year && _month == d._month && _day >= d._day)
			return 1;
		return 0;*/
		return *this == d && *this > d;
	}
	bool operator<=(const Date& d)
	{
		/*if (_year < d._year)
			return 1;
		else if (_year == d._year && _month < d._month)
			return 1;
		else if (_year == d._year && _month == d._month && _day <= d._day)
			return 1;
		return 0;*/
		return !(*this > d);
	}

	//d1 + 10
	Date operator+(int day)
	{
		//int month=_month;
		//int year=_year;
		//Date z;
		//day += _day;
		//int ret = GetMonthDay( _year,_month);//获取当年当月的天数
		//while (day > ret)
		//{
		//	month++;
		//	if (month > 12)
		//	{
		//		year++;
		//		month = 1;
		//	}
		//	day = day - ret;
		//	ret = GetMonthDay(year, month);
		//}
		//z._day = day;
		//z._year = year;
		//z._month = month;
		//return z;
		Date ret(*this);//把this指针拷贝到ret对象中
		return (ret += day);
	}
	//+=改变this指针，+不改变this指针，但是两者都返回的是(d+day)之后的和
	Date operator+=(int day)
	{
		if (day < 0)
			return *this -= (-day);
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day = _day - GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	Date operator-(int day)
	{
		Date ret(*this);
		return ret -= day;
	}
	Date operator-=(int day)
	{
		if (day < 0)
			return *this += (-day);
		_day -= day;
		while (_day<0)
		{
			--_month;
			_day = _day + GetMonthDay(_year, _month);
			if (_month <1)
			{
				_month = 12;
				_year--;
			}
		}
		return *this;
	}
	// 前置
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// 后置
	Date operator++(int)
	{
		Date ret(*this);
		return ret += 1;
	}
	Date operator--(int)
	{
		Date ret(*this);
		return ret -= 1;
	}

	// d1-d2
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int day = 0;
		int flag = -1;
		if (*this < d)
		{
			min = *this;
			max = d;
			flag = 1;
		}
		while (min != max)
		{
			++day;
			++max;
		}
		return day*flag;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date d1(2019, 1, 2);
	Date d2(2018, 2, 3);
	//cout << (d1 == d2) << endl;
	///d2.Print();
	//cout << (d1 != d2) << endl;
	//cout << (d1 >d2) << endl;
	cout << (d1 <d2) << endl;
	//cout << (d1 <=d2) << endl;
	/*d.Print();
	(d + 31).Print();*/
	/*d1.Print();
	(d1 += 32).Print();*/
	/*d1.Print();
	(d1 - 2).Print();*/
	//d1.Print();
	//(d1++).Print();
}
void test2()
{
	Date d1(2019, 12, 5);
	Date d2(2019, 12, 1);
	//d1.Print();
	//(d1 += (-2)).Print();
	//(d1 + 100).Print();
	//(d1 -= (-2)).Print();
	//(d1 - 100).Print();
	//(++d1).Print();
	//(--d1).Print();
	//(d1++).Print();
	cout<<(d1 - d2)<<endl;
}
int main()
{
	test2();
	system("pause");
	return 0;
}
