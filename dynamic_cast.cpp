#include<iostream>
using namespace std;

class base
{
public :
// 必须存在虚函数,才能保证动态转换
    virtual void m(){cout<<"m"<<endl;}
};

class derived : public base
{
public:
    virtual void f(){cout<<"f"<<endl;}
};

int main()
{
    // 基类转派生类,不安全,因为子类中存在基类不知道的成员函数
    derived * d;
    d = dynamic_cast<derived *>(new base);
    if(d)
    {
        cout<<"Base to Derived is ok"<<endl;
        delete d;
    }
    else
        cout<<"Base to Derived is error"<<endl;
        
    // 派生类转基类,是安全的,可以把派生类的成员函数丢掉
    base * b;
    b = dynamic_cast<base *>(new derived);
    if(b)
    {
        cout<<"Derived to Base is ok"<<endl;
        delete b;
    }
    else
        cout<<"Derived to Base is error"<<endl;

    return 0;
}