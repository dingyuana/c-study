#include<iostream>
using namespace std;

class time;
//1. date 类的定义必须出现在 time 类之前，这么做是为了使得 display() 函数的函数声明能够在声明为友元函数之前；
class date
{
		public:
		    date(int y,int m,int d);
		    void display(time &t);
		private:
		    int year;
		    int month;
		    int day;
};

//2. display() 函数的形参为 time 类对象的引用，而 time 类又必须定义在 date 类之后，
// 如此一来只能先将 time 类声明在 date 类之前了，如class time;这一语句即是为了声明time类；
class time
{
		public:
		    time(int s,int m,int h);
		    friend void date::display(time & t);
		private:
		    int second;
		    int minute;
		    int hour;
};

time::time(int s,int m,int h)
{
    second = s;
    minute = m;
    hour = h;
}

date::date(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
}

// 3. display() 函数的定义需要放到 time 类定义的后面，
// 这是因为 display() 函数中必须用到 time 类中的私有成员变量，因此在使用之前，这些成员变量必须先声明出来
void date::display(time &t)
{
    cout<<"The time is:"<<endl;
    cout<<year<<"/"<<month<<"/"<<day<<" ";
    cout<<t.hour<<":"<<t.minute<<":"<<t.second<<endl;
}

int main()
{
    date d(2024,4,16);
    time t(20,2,30);
    d.display(t);
    return 0;
}