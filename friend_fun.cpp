#include<iostream>
using namespace std;

class book
{
private:
    string name;
    double price;
public:
// 通过 friend 关键字，可以成为当前类的友元函数。
	friend void display(book &b);
    book(string n, double p)
    {
        name = n;
        price = p;
    }
};

//1. 友元函数的形参是类对象的引用
void display(book &b){
    //2. 在访问私有成员变量时必须要加上对象名
    cout<<b.name<<" "<<b.price<<endl;

}
int  main() {
    book book1("C++", 100);
    display(book1);
    return 0;
}























// #include<iostream>
// using namespace std;

// class book
// {
// 		public:
// 		    book(){}
// 		    book(char* a, double p);
// 		    friend void display(book &b);
// 		private:
// 		    double price;
// 		    char * title;
// };

// book::book(char* a, double p) 
// {
//     title = a;
//     price = p;
// }
