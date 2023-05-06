﻿
#include <iostream>
using  namespace std;

class Time
{

public:
    Time(int year = 2023, int month = 4, int day = 21)
    {
        if (month > 12 || month < 0 || day<0 || day>getmonthday(month))
        {
            cout << "日期错误" << endl;

        }
        else
        {
            _year = year;
            _month = month;
            _day = day;
        }

    }

    int getmonthday(int month)
    {
        month = month - 1;
        int monthday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return monthday[month];
    }


    bool operator==(const Time& d2)
    {
        return this->_year == d2._year
            && this->_month == d2._month
            && this->_day == d2._day;

    }

    bool operator>(const Time& d2)
    {

        if (this->_year > d2._year)
            return true;
        else if (this->_year == d2._year && this->_month > d2._month)
            return true;
        else if (this->_year == d2._year && this->_month == d2._month && this->_day > d2._day)
            return true;


        return false;



    }

    bool operator<(const Time& d2)
    {
        return !((*this) == d2 || (*this) > d2);

    }
    bool operator<=(const Time& d2)
    {
        return !((*this) > d2);

    }

    bool operator>=(const Time& d2)
    {
        return (*this > d2) || (*this) == d2;

    }
    Time& operator+=(int day)
    {
        this->_day += day;
        while (this->_day > getmonthday(this->_month))
        {
            this->_day -= getmonthday(this->_month);
            this->_month++;
            if (this->_month == 13)
            {
                this->_year++;
                this->_month = 1;

            }
        }


        return (*this);
    }

    Time operator+(int day)
    {

        Time ret;
        ret._day += day;
        while (ret._day > getmonthday(ret._month))
        {
            ret._day -= getmonthday(ret._month);
            ret._month++;
            if (ret._month == 13)
            {
                ret._year++;
                ret._month = 1;

            }
        }
        return (*this);
    }



    void Show()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    ~Time()
    {
        _year = 0;
        _month = 0;
        _day = 0;
    }




    void f1()
    {
    
        f2();

    
    }
 static void f2()
    {
    
        cout << "可以" << endl;
    
    }


private:
    int _year;
    int _month;
    int _day;

   


};











class Sum
{
public:
    Sum()
    {
        _sum += _i;
        _i++;



    }

    static void Init()
    {
        _i = 1;
        _sum = 0;
    
    }
    static int Getsum()
    {

        return _sum;


    }
private:
    static int _i;
    static int _sum;


};

int Sum::_i = 1;
int Sum::_sum = 0;


class solution
{
public:
    int sum_solution(int n)
    {
       // Sum a[n];//c99支持，变长数组的定义

        Sum::Init();

        Sum* p = new Sum[n];
        return Sum::Getsum();



    }



};



int main()
{
    //Time d1(2024, 5, 12);
    //Time d2(2024, 12);
    //Time d3 = d2 + 70;
    //d3.Show();
    //d3.f2();

    int tmp = 5;

    solution a1;
    


    cout << a1.sum_solution(5) << endl;
      cout <<a1.sum_solution(5)  << endl;
}
