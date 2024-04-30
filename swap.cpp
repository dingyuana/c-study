#include <iostream>
using namespace std;

//函数的声明
int swap_int(int a, int b);

// 全局变量
int res;
int main()
{
    int a,b;
    std::cout << "pls input first arr:"<< std::endl;
    cin>>a;
    std::cout << "pls input second arr:"<< std::endl;
    cin>>b;

    //函数的调用
    res = swap_int(a, b);//实参

    // int s=0;
    // s = a;
    // a = b;
    // b = s;

    cout<<"arry1 = "<<a<<endl;
    cout<<"arry2 = "<<b<<endl;
    return 0;
}

int swap_int(int a, int b){//形参 入参
    int s;
    s = a;
    a = b;
    b = s;
    
    // cout<<"arry1 = "<<a_swap<<endl;
    // cout<<"arry2 = "<<b_swap<<endl;

    return 0;//出参
}