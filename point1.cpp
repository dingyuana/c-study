#include <iostream> 
using namespace std;
 
int main ()
{
   // 所有的数据/变量都有二个元素：地址和数值，这和编程语言无关，和是否指针无关
   // 只有c/c++使用指针，把地址的概念提了出来
   // 可是我们并不需要真正知道地址的具体数值是多少，都交给了底层去处理
   int  v1=1;
   cout<<"v1="<<v1<<endl;
   cout<<"v1 address: "<<&v1<<endl;

   // 指针的具体操作符
   // 1.声明定义指针
   // int *p;   
   // p = &v1;

//语法错误，赋值与地址混淆了
   // *p=&v1;  

   // 2.声明与初始化一起完成
   int *p = &v1;



   cout<<"address of p: "<< p <<endl;
   cout<<"value of *p: "<< *p <<endl;

 

   return 0;
}