// lesson2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using  namespace std;

class Time
{

public:
    Time(int year=2023, int month=4, int day=21)
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
        int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return monthday[month];
    }


    bool operator==(const Time & d2)
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
        return (*this > d2)||(*this) == d2;

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
        cout << _year << "-" << _month << "-" << _day<<endl;
    }

    ~Time()
    {
        _year = 0;
        _month = 0;
        _day = 0;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Time d1(2024,5,12);
    Time d2(2024, 12);
    Time d3=d2 + 70;
    d3.Show();
   
      //  cout <<  << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
