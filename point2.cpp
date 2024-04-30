#include <iostream>
using namespace std;

int main ()
{
   int  var = 20;   // 实际变量的声明
    //1.不要使用未赋值的指针
//   两种赋值方式
//    int *ip= &var;
   int  *ip = nullptr ; //NULL       // 指针变量的声明

   ip = &var;       // 在指针变量中存储 var 的地址

   std::cout << "Value of var variable: ";
   std::cout << var << endl;

   // 输出在指针变量中存储的地址
   std::cout << "Address stored in ip variable: ";
   std::cout << "first address: "<<ip << endl;

   // 访问指针中地址的值
   std::cout << "Value of *ip variable: ";
   std::cout << *ip << endl;


    //   2 改变ip的值
   int s=10;
   ip = &s;


   std::cout << "Value of s variable: ";
   std::cout << s << endl;

   std::cout << "Value of var variable: ";
   std::cout << var << endl;

   // 输出在指针变量中存储的地址
   std::cout << "Address stored in ip variable: ";
   std::cout << "Second address:"<< ip << endl;

   // 访问指针中地址的值
   std::cout << "Value of *ip variable: ";
   std::cout << *ip << endl;

   // int arr[5]={0,1,2,3,4};
   // in
   // int array[5], *p = array;
   std::cout << "=========================================================" << endl;
   int array[5]={0,10,20,30,40};
   // 访问数组中地址的值
   std::cout << "Address stored in array variable: ";
   std::cout << "array address:"<< &array << endl;
   // int *p=array;
   int *p = &array[0]; 
   // 访问指针中地址的值
   std::cout << "Address stored in p variable: ";
   std::cout << "*p address:"<< p << endl;
   *p++;

   // 访问数组中的值
   std::cout << "Value of *p variable: ";
   std::cout << *p << endl;

   // 访问指针中地址的值
   std::cout << "Value of p variable: ";
   std::cout << p << endl;
   
   std::cout << "=========================================================" << endl;

   return 0;
}
