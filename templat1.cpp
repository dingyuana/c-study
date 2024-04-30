#include <iostream>
using namespace std;
#include <string>

// 函数模板,编译时都不知道T是什么类型.只有到了运行时才能知道T的类型.
// 模板参数T可以代表任何类型.
template<typename T> 
void Swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T> 
void Swap2(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
//交换 int 变量的值
// void Swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
int main(){
    //交换 int 变量的值
    int n1 = 100, n2 = 200;
    Swap(&n1, &n2);
    cout<<n1<<", "<<n2<<endl;
    Swap2(n1, n2);
    cout<<n1<<", "<<n2<<endl;
   
    //交换 float 变量的值
    float f1 = 12.5, f2 = 56.93;
    Swap(&f1, &f2);
    cout<<f1<<", "<<f2<<endl;
   
    //交换 char 变量的值
    char c1 = 'A', c2 = 'B';
    Swap(&c1, &c2);
    cout<<c1<<", "<<c2<<endl;
   
    //交换 bool 变量的值
    bool b1 = false, b2 = true;
    Swap(&b1, &b2);
    cout<<b1<<", "<<b2<<endl;

    string s1="123",s2="abc";
    Swap(&s1, &s2);
    cout<<s1<<", "<<s2<<endl;

    return 0;
}